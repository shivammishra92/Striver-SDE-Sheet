//https://practice.geeksforgeeks.org/problems/merge-k-sorted-arrays/1
typedef pair<int,pair<int,int>>triplet;
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        int size = K;
        //min heap
        priority_queue<triplet,vector<triplet>,greater<triplet>>pq;
        for(int i=0;i<size;i++){
            pq.push({arr[i][0],{i,0}});
        }

        vector<int>res;
        while(!pq.empty()){
            triplet curr=pq.top();
            pq.pop();
            res.push_back(curr.first);
            int ap=curr.second.first;
            int vp=curr.second.second;

            if(vp+1 < size){
                pq.push({arr[ap][vp+1],{ap,vp+1}});
            }
        }
        return res;
    }
