class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>>meetings;
        for(int i=0;i<n;i++){
            meetings.push_back({end[i],start[i]});
        }
        sort(meetings.begin(),meetings.end());
        int ans = 1;
        int limit = meetings[0].first;
        for(int i=1;i<meetings.size();i++){
            
            if(limit<meetings[i].second){
                ans++;
                limit = meetings[i].first;
            }
        }
        return ans;
    }
};