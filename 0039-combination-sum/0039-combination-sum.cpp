class Solution {
public:
    vector<vector<int>> ans;
       void generate(int i, vector<int>& candidates, int target,int sum, vector<int>& curr) {
        if(sum == target){
            ans.push_back(curr);
            return;
        }

        if(i >= candidates.size() || sum > target){
            return;
        }

        
        
        curr.push_back(candidates[i]);
        sum += candidates[i];

        generate(i, candidates, target, sum, curr);
        
        curr.pop_back();
        sum -= candidates[i];

        generate(i+1, candidates, target, sum, curr);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        generate(0, candidates, target, 0, curr);
        return ans;
    }
};