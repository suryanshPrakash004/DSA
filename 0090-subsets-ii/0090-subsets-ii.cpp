
class Solution {
public:
    vector<vector<int>> ans;

    void sub2(int i, vector<int>& curr, vector<int>& nums) {
        

        if (i == nums.size()) {
            ans.push_back(curr);
            return;
        }

        
        curr.push_back(nums[i]);
        sub2(i + 1, curr, nums);

        
        curr.pop_back();

    
        int j = i + 1;
        while (j < nums.size() && nums[j] == nums[i]) {
            j++;
        }

        sub2(j, curr, nums);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        ans.clear();

        vector<int> curr;
        sub2(0, curr, nums);

        return ans;
    }
};
