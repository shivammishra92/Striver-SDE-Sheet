/* Link for the question:
   https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

                                **EXPLANATION**
   
Approach-
Following are the steps:
1.In order to track the path of the rat we are required for a matrix named visited in which all the cells are initialized as false where false means that a particular cell is unvisited and 
true means it is visited 
2.Then we are required with a vector of strings to return the all possible valid paths and a string named output to store any valid path
3.Start from cell(0,0) and call the solveMaze function
4.In the solveMaze function if the rat reaches the last cell i.e. (row-1,col-1) then push the valid path into the paths vector and return from that point(This will be our base case)
5.Being in a particular cell check for all the possible directions i.e. up,down,left,rigth so as to move safely to the destination by calling solveMaze function recursively
6.Next to check if a particular cell is safe to move or not call the isSafe function where 3 cases are checked:
  (i)If the next cell to move is within the boundaries of matrix or not
  (ii)If the next cell in the given matrix does not has a close path i.e. it is marked as '1'
  (iii)If the next cell of visited matrix is marked as false i.e. that cell has not been visited yet
  If all the above cases evaluates to true then return true
  Else return false
7.If the cell is safe to go then mark that cell as visisted in the visisted matrix
8.Recursively Call for other directions(down,up,left,right)
9.While backtracking again mark the cells of visited matrix as unvisisted i.e. false
10.Return all the possible valid paths     

*/

class Solution{
    public:
    
    bool isSafe(int i,int j,int row,int col,vector<vector<int>> &m,
    vector<vector<bool>>&visited){
        
    //checking for 3 cases
    if(((i >= 0 and i < row ) and (j >= 0 and j < col)) and m[i][j] == 1 and visited[i][j] == false)
    {
        return true;
    }
    else{
        return false;
    }
        
    }
    
    void solveMaze(vector<vector<int>> &m,int row,int col,int i,int j,
    vector<vector<bool>>&visited,vector<string>&paths,string output){
       
      //base case
      if(i == row-1 and j == col-1){
          paths.push_back(output);
          return;
      }
           
      //down -> i+1,j 
      if(isSafe(i+1,j,row,col,m,visited)){
          visited[i+1][j] = true;
          //possible path
          solveMaze(m,row,col,i+1,j,visited,paths,output + 'D');
          //backtrack
          visited[i+1][j] = false;
      }
       
      //left -> i,j-1 
      if(isSafe(i,j-1,row,col,m,visited)){
          visited[i][j-1] = true;
          //possible path
          solveMaze(m,row,col,i,j-1,visited,paths,output + 'L');
          //backtrack
          visited[i][j-1] = false;
      }
       
      //right -> i,j+1 
      if(isSafe(i,j+1,row,col,m,visited)){
          visited[i][j+1] = true;
          //possible path
          solveMaze(m,row,col,i,j+1,visited,paths,output + 'R');
          //backtrack
          visited[i][j+1] = false;
      }
       
      //up -> i-1,j 
      if(isSafe(i-1,j,row,col,m,visited)){
          visited[i-1][j] = true;
          //possible path
          solveMaze(m,row,col,i-1,j,visited,paths,output + 'U');
          //backtrack
          visited[i-1][j] = false;
      }
       
     }

       
    vector<string> findPath(vector<vector<int>> &m, int n) {
        
        int row = n;
        int col = n;
        
        vector<string>paths;
        string output = "";
       
        vector<vector<bool>>visited(row,vector<bool>(col,false));

        //edge case
        if(m[0][0] == 0)
        return paths;
        
        visited[0][0] = true;

        solveMaze(m,row,col,0,0,visited,paths,output);
        
        return paths;
    }
    
};

