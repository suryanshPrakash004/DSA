class Solution {
public:
    void sum3(int i, vector<int> &curr, vector<vector<int>> &ans, int k , int n){

        if(k == 0){
            if(n == 0){
                ans.push_back(curr);
            }
            return;
        }
        if(i > 9 || n < 0) return;

        curr.push_back(i);
        sum3(i+1, curr, ans, k-1, n-i);

        curr.pop_back();
        sum3(i+1, curr, ans, k, n);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> curr;
        vector<vector<int>> ans;

        sum3(1, curr, ans, k, n);
        return ans;
    }
};