class Solution {
public:
    vector<vector<int>> ans;

    void sum2(int i, vector<int> &curr, vector<int> &candidates, int sum, int target){
        if(sum > target) return;
        if(i == candidates.size()){
            if(sum == target){
                ans.push_back(curr);
            }
            return;
        }

        curr.push_back(candidates[i]);
        sum += candidates[i];

        sum2(i+1, curr, candidates, sum, target);

        sum -= candidates[i];
        curr.pop_back();

        int j = i + 1;
        while (j < candidates.size() && candidates[j] == candidates[i]) {
            j++;
        }

        sum2(j, curr, candidates, sum, target);
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> curr;
        sum2(0, curr, candidates, 0, target);
        return ans;
    }
};