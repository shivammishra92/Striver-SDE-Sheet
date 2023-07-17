class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>>res;
        sort(intervals.begin(),intervals.end());

        // for(int i=0;i<n;i++){
        //     int start = intervals[i][0];
        //     int end = intervals[i][1];
        //     skip all merged intervals
        //     if(!res.empty() and end<=res.back()[1])
        //     continue;

        //     for(int j=i+1;j<n;j++){
        //         if(end >= intervals[j][0]){
        //             end = max(end,intervals[j][1]);
        //         }
        //         else
        //         break;
        //     }
        //     res.push_back({start,end});
            
        // }
       
        // return res;

       //approach-02
        for(int i=0;i<n;i++){
            
            //first interval or any other interval which does not overlap will be inserted here
            if(res.empty() || res.back()[1] < intervals[i][0]){
                res.push_back(intervals[i]);
            }
            else{
                res.back()[1] = max(res.back()[1],intervals[i][1]);
            }

        }
        return res;
    }
};