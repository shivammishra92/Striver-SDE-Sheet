class Solution {
  public:
    vector<int> maxCombinations(int n, int k, vector<int> &a, vector<int> &b) {
        
        vector<int>ans;
        sort(a.begin(),a.end(),greater<int>());
        sort(b.begin(),b.end(),greater<int>());
        set<pair<int,int>>set;
        priority_queue<pair<int,pair<int,int>>>pq;
        
        pq.push(make_pair(a[0]+b[0],make_pair(0,0)));
        set.insert({0,0});
        
        for(int i=0;i<k;i++){
           pair<int,pair<int,int>>p = pq.top();
           pq.pop();
           ans.push_back(p.first);
           
           if(p.second.first+1<n and set.find({p.second.first+1,p.second.second}) == set.end()){
               pq.push({a[p.second.first+1]+b[p.second.second],{p.second.first+1,p.second.second}});
               set.insert({p.second.first+1,p.second.second});
           }
           
           if(p.second.second+1<n and set.find({p.second.first,p.second.second+1}) == set.end()){
               pq.push({a[p.second.first]+b[p.second.second+1],{p.second.first,p.second.second+1}});
               set.insert({p.second.first,p.second.second+1});
           }
        }
        return ans;
    }
};