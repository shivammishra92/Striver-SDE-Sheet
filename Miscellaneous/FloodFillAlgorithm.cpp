class Solution {
private:
    void dfs(int sr,int sc,int newcolor,int delRow[],int delCol[],vector<vector<int>>& ans,vector<vector<int>>& image,int iniColor){
        ans[sr][sc] = newcolor;
        int m = image.size();
        int n = image[0].size();
        for(int i=0;i<4;i++){
            int nbrRow = sr+delRow[i];
            int nbrCol = sc+delCol[i];

            if(nbrRow>=0 && nbrRow<m && nbrCol>=0 && nbrCol<n && 
            image[nbrRow][nbrCol] == iniColor
            && ans[nbrRow][nbrCol] != newcolor){

                dfs(nbrRow,nbrCol,newcolor,delRow,delCol,ans,image,iniColor);
            }
        }
    }    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>ans = image;
        int delRow[] = {-1,0,+1,0};
        int delCol[] = {0,+1,0,-1};
        int iniColor = image[sr][sc];
        dfs(sr,sc,color,delRow,delCol,ans,image,iniColor);
        return ans;
    }
};