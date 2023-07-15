class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int N) {
        vector<int>ans;
        long long x,y;
        long long n = N;
        long long S_ar= 0,S_sq_ar = 0;
        for(long long i=0;i<n;i++){
            S_ar += (long long)arr[i];
            S_sq_ar += (long long)arr[i]*(long long)arr[i];
        }
        
        long long Sn = (n*(n+1))/2;
        long long Sn_sq = (n*(n+1)*(2*n+1))/6;
        
        long long val1 = S_ar-Sn;//x-y
        long long val2 = S_sq_ar - Sn_sq;
        val2 = val2/val1;//x+y
        
        x = (val1+val2)/2;
        y = val2-x;
        
        // ans.push_back((int)x);
        // ans.push_back((int)y);
        
        // return ans;
        return {(int)x,(int)y};
    }
};