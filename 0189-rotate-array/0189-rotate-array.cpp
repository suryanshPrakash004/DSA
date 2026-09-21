class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1) return;
        k = k % n;
        vector<int> temp;
        for(int i = n-k; i<n ; i++){
            temp.push_back(nums[i]);
        }

        int j = n-1;
        for(int i = n-k-1; i>=0; i--){
            nums[j] = nums[i];
            j--;
        }

        for(int i = 0; i<k; i++){
            nums[i] = temp[i];
        }

    }
};