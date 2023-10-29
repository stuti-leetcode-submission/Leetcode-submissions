class Solution {
public:
    bool pos(vector<int>& weights, int days,int mid){
        int sum=0;
        int d=1;//day starts as soon as you start
     //   cout<<endl<<mid<<"--";
        for(int i=0;i<weights.size();i++){
           // sum+=weights[i];
            if(sum+weights[i]>mid){
                sum=weights[i];
                d++;
            }
            else sum+=weights[i];
        //    cout<<d <<"---"<<i<<" ";
            if(d>days)return false;
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {

        //first find low and high
        int low=INT_MIN,high=0;
        for(auto i:weights){
            high+=i;
            low=max(low,i);
        }
        int ans=INT_MAX;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(pos(weights,days,mid)){
                high=mid-1;
                ans=min(ans,mid);
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};