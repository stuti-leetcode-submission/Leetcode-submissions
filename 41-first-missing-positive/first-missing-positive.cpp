class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            while(nums[i]>0 && nums[i]<=n && nums[i]!=(i+1) && nums[i]!=nums[nums[i]-1] ){
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=(i+1))return i+1;
        }
        return n+1;
        //o(n) time and o(1) space
    }
};