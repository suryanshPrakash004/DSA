class Solution {
public:
    vector<vector<int>> ans;
    void generate(int i, vector<int> curr, vector<int>& nums){
        if(i == nums.size()){
            ans.push_back(curr);
            return;
        }
        
        
            curr.push_back(nums[i]);
            generate(i+1, curr, nums);
       

        
            curr.pop_back();
            generate(i+1, curr, nums);
        
    } 

    vector<vector<int>> subsets(vector<int>& nums) {
        generate(0, {}, nums);
        return ans;
    }
};