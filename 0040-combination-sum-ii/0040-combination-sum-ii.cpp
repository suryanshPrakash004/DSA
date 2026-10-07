class Solution {
public:
    vector<vector<int>> ans;
       void generate(int i, vector<int>& candidates, int target,int sum, vector<int>& curr) {
        if(sum == target){
            ans.push_back(curr);
            return;
        }



        for(int j = i; j < candidates.size(); j++){
            if(j > i && candidates[j]==candidates[j-1]){
                continue;
            }
            if (sum + candidates[j] > target)
            break;
        
        curr.push_back(candidates[j]);
        sum += candidates[j];

        generate(j+1, candidates, target, sum, curr);
        
        curr.pop_back();
        sum -= candidates[j];
        }

        
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> curr;
        generate(0, candidates, target, 0, curr);
        return ans;
    }
};