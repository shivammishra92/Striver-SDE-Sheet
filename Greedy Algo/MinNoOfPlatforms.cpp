class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	int maxPlatforms = 1;
    	int currPlatformCount=1;
    	int i=1,j=0;
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	
    	while(i<n and j<n){
    	    
    	    if(arr[i]<=dep[j]){
    	        currPlatformCount++;
    	        maxPlatforms = max(currPlatformCount,maxPlatforms);
    	        i++;
    	    }
    	    else{
    	        currPlatformCount--;
    	        //i++;
    	        j++;
    	    }
    	    
    	}
    	return maxPlatforms;
    }
};