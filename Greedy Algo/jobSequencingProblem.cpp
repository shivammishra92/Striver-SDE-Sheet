/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    bool static cmp(Job a,Job b){
        
        return a.profit>b.profit;
        
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        //sort jobs based on the profits
        sort(arr,arr+n,cmp);
        //find the maximum deadline
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            maxi = max(maxi,arr[i].dead);
        }
        int slot[maxi+1];
        //initialize all the slot values with -1
        for(int i=1;i<=maxi;i++){
            slot[i] = -1;
        }
        
        vector<int>ans;
        int jobCount = 0,maxProfit = 0;
        for(int i=0;i<n;i++){
            
            for(int j=arr[i].dead;j>0;j--){
                if(slot[j] == -1){
                    slot[j] = arr[i].id;
                    jobCount++;
                    maxProfit += arr[i].profit;
                    break;
                }
            }
            
        }
        ans.push_back(jobCount);
        ans.push_back(maxProfit);
        
        return ans;
    } 
};