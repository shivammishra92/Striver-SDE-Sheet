class Solution 
{
    private:
    bool knows(vector<vector<int> >&M,int a,int b)
    {
        if(M[a][b] == 1)
        return true;
        else
        return false;
    }
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        //step 1  push all elements in the stack
        stack<int>s;
        for(int i=0;i<n;i++)
        {
            s.push(i);
        }
        // step 2  jab tak stack me ek element nahi bachta
        while(s.size()>1)
        {
            int a=s.top();
            s.pop();
            
            int b=s.top();
            s.pop();
            
            if(knows(M,a,b))
            {
                s.push(b);
            }
            else{
                s.push(a);
            }
        }
        
        int potentialCeleb=s.top();
        //step3 at last when the single element remains 
        //verify it
        
        bool rowCheck=false;
        int zeroCount=0;
        for(int i=0;i<n;i++)
        {
            if(M[potentialCeleb][i]==0)
            zeroCount++;
        }
        if(zeroCount==n)
        rowCheck=true;
        
        
        bool columnCheck=false;
        int oneCount=0;
        for(int i=0;i<n;i++)
        {
            if(M[i][potentialCeleb]==1)
            oneCount++;
        }
        if(oneCount==n-1)
        columnCheck=true;
        
        
        if(rowCheck== true && columnCheck==true)
        return potentialCeleb;
        else
        return -1;
    
    }
};