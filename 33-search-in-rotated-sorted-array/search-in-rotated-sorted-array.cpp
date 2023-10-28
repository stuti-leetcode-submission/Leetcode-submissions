class Solution {
public:
    int search(vector<int>& nums, int k) {
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==k)return mid;
            //left sorted
            else if(nums[mid]<nums[high]){
                if(nums[mid]<k && nums[high]>=k){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
            //right sorted
            else{
                 if(nums[mid]>k && nums[low]<=k){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
        }
        return -1;
    }
};