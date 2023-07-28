class Solution {
public:
    bool isPossible(int k,vector<int>&stalls,int mid,int n)
    {
        int cowsCount=1;
        int lastPos=stalls[0];
        
        for(int i=0;i<stalls.size();i++)
        {
            if(stalls[i]-lastPos>=mid)
            {
                cowsCount++;
                if(cowsCount==k)
                {
                    return true;
                }
                lastPos=stalls[i];
            }
        }
     
     return false;
    }

    int solve(int n, int k, vector<int> &stalls) {
    
        int s=0;
        sort(stalls.begin(),stalls.end());
        int e = *max_element(stalls.begin(),stalls.end());
    //   int maxi=-1;
    //   for(int i=0;i<stalls.size();i++)
    //   {
    //       maxi=max(stalls[i],maxi);
    //   }
    //     int e=maxi;
        
        int mid=(s+e)/2;
        int ans=-1;
        
        while(s<=e)
        {
            if(isPossible(k,stalls,mid,n))
            {
                ans=mid;
                s=mid+1;
            }
            else{
                e=mid-1;
            }
            mid=(s+e)/2;
        }
        return ans;
    }
};