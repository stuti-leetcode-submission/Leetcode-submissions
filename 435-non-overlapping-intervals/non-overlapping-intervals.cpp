class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b){
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //overlapping here meant that inside it like 1,2 and 1,3
        // we can use the reverse cyclogy of groups which doesnt overlap
        sort(intervals.begin(),intervals.end(),comp);
        int cnt=1;
        int a=intervals[0][0],b=intervals[0][1],diff=b-a;
        for(int i=1;i<intervals.size();i++){
            if(b<=intervals[i][0]){
                //no change in count just we have to change a and b
                a=intervals[i][0];
                b=intervals[i][1];
                diff=b-a;
                cnt++;
            }
        }
        return intervals.size()-cnt;
    }
};