class Solution
{
public:
     
    void subsetsum(vector<int>arr,vector<int>output,vector<int>&ans,int index,int n)
    {
        if(index>=n)
        {
          int sum=0;
          for(auto it=output.begin();it!=output.end();it++){
         
          sum = sum + *it;
          
           }
        ans.push_back(sum);
        return;
        
      }
        //exclude 
        subsetsum(arr,output,ans,index+1,n);
        
        //include
        int elem=arr[index];
        output.push_back(elem);
        subsetsum(arr,output,ans,index+1,n);
        
    }
    
    vector<int> subsetSums(vector<int> arr, int n)
    {
        
        vector<int>output;
        vector<int>ans;
        int index=0;
        subsetsum(arr,output,ans,index,n);
        
        return ans;
    }
};