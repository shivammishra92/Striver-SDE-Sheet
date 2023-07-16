 //https://leetcode.com/problems/course-schedule/

class Solution {
public:
    bool chkDfs(int src,int parent,unordered_map<int,bool>&visited,
    unordered_map<int,bool>&dfsVisited,vector<int> adj[]){
        visited[src] = true;
        dfsVisited[src] = true;

        for(auto nbr:adj[src]){
            if(!visited[nbr]){
                bool chkAagekaAns = chkDfs(nbr,src,visited,dfsVisited,adj);
                if(chkAagekaAns == true)
                return true;
            }
            //cycle present
            if(visited[nbr] and dfsVisited[nbr] == true){
                return true;
            }
        }
        dfsVisited[src] = false;
        return false;
    }
    //this is a question related to  a Directed graph
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
         vector<int>adj[numCourses];
         for(auto it:prerequisites){
             adj[it[1]].push_back(it[0]);
         }

        //cycle hai to false return karna hai anyatha return true
        unordered_map<int,bool>visited;
        unordered_map<int,bool>dfsVisited;
        bool loop = false;

        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                loop = chkDfs(i,-1,visited,dfsVisited,adj);
                if(loop)
                return false;
            }
        }
        return true;
    }
};