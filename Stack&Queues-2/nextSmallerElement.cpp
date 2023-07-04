class Solution{
public:
    vector<int> leftSmaller(int n, int a[]){
        // code here
        
        int revArr[n];
        int j=0;
        //reverse the array
        for(int i=n-1;i>=0;i--)
        {
            
            revArr[j++] = a[i];
        }
        // Using algorithm same as of next smaller element
        stack<int>st;
        vector<int>ans(n);
        st.push(-1);
        
        for(int i=n-1;i>=0;i--)
        {
            if(st.top()<revArr[i])
            ans[i]=st.top();
            else
            {
                while(st.top()>=revArr[i] && st.size() != 1)
                {
                    st.pop();
                }
                
                ans[i]=st.top();
                
            }
            st.push(revArr[i]);
            
            
        }
        //again reversing the vector to get the desired answer
        reverse(ans.begin(),ans.end());
        
        return ans;
        
    }
};