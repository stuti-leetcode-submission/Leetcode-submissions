class Solution {
public:
    int lb1(vector<int>nums,int target){
        int low=0,high=nums.size()-1,ans=-1;
    //    if(nums[0]==target)return 0;
    //    if(nums[nums.size()-1]<target)return nums.size();
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                high=mid-1;
                ans=mid;
            }
            else if(nums[mid]>target){
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
     int ub1(vector<int>nums,int target){
        int low=0,high=nums.size()-1,ans=-1;
        //if(nums[0]==target)return 0;
    //    if(nums[nums.size()-1]==target)return nums.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                low=mid+1;
                ans=mid;
            }
            else if(nums[mid]>target){
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int lb=lb1(nums,target);
          int ub=ub1(nums,target);
      ub;
        if(lb==-1 || lb==nums.size() || ub==-1 || nums[lb]!=target || nums[ub]!=target)return {-1,-1};
        else return {lb,ub};
    }
};