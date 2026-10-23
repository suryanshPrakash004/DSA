class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int maxCnt = 0;
        int currCnt = 0;

        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == 1){
                currCnt++;
                maxCnt = max(maxCnt, currCnt);
            }
            else currCnt = 0;
        }
        return maxCnt;
    }
};