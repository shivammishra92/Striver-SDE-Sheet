public:
    //Function to find minimum number of pages.
    bool isPossible(int A[],int n,int m,int mid)
    {
        int studentCount=1;
        int pgSum=0;
        for(int i=0;i<n;i++) 
        {
            if(pgSum+A[i]<=mid)
            pgSum+=A[i];
            
            else
            {  studentCount++;
            
               if(studentCount>m||A[i]>mid)
               {return false;
               }
               pgSum=A[i];
                
            }
        }
        return true;
    }
    int findPages(int A[], int n, int m) 
    {
        if(m>n)return -1;
        
        int s=0,e=0,ans=-1;
        for(int i=0;i<n;i++)
        {
            e=e+A[i];
        }
        int mid=(s+e)/2;
        while(s<=e)
        {
            if(isPossible(A,n,m,mid))
            {
                ans=mid;
                e=mid-1;
            }
            else
            {
                s=mid+1;
            }
            mid=(s+e)/2;
        }
        return ans;
    }
