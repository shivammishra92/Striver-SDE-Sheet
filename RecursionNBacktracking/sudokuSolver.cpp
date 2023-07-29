/* Link for the question:
   https://practice.geeksforgeeks.org/problems/solve-the-sudoku-1587115621/1

                                **EXPLANATION**
   
Approach-
Following are the steps:
 In the SolveSudoku function-
  (i)Firstly check if the cell is empty or not before inserting a value
  (ii)If the particluar cell has '0' in it that means you can insert the value from 1 to 9,use a loop for that
  (iii)Now while inserting the value,check whether it is safe to insert or not->call for isSafe() function-
       Here 3 cases arises:
       (i)The whole row corresponding to the current column should not have the same value as the value that is to be inserted
       (ii)The whole column corresponding to the current row should not have the same value as the value that is to be inserted
       (iii)The 3x3 box corresponding to the position of value to be inserted should not have the same value as the value that is to be inserted
  (iv)If safe, insert the value
  (v)Recursively call the function to check whether next cell can be filled or not following all the constraints as explained above
  (vi)If the next cell can be filled return true 
      Else backtrack(Are bhaiya! correct value nahi mile insert karne ke liye -> to phir vapis pichle cell me chalo)
  (vii)If after trying all the values from 1 to 9 nothing could be inserted then return false
  (viii)At the end when you come out of the outer two loops return true since sudoku is solved    

*/
//self-explanatory code :)
class Solution 
{
    public:
    bool isSafe(int currRow,int currCol,int grid[N][N],int val){
        //3 cases arises
        for(int i=0;i<N;i++){
         //checking for all the rows for a particular column 
         if(grid[i][currCol] == val)
         return false;
         //checking for all the columns for a particular row 
         if(grid[currRow][i] == val)
         return false;
         //checking for a particular 3x3 box
         if(grid[3*(currRow/3) + i/3][3*(currCol/3) + i%3] == val)
         return false;
         
        }
        //if you reach here that means it is safe to put the value in a particular cell
        return true;
    }
    //Function to find a solved Sudoku. 
    bool SolveSudoku(int grid[N][N])  
    { 
        
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                //check for empty cell
                if(grid[i][j] == 0)
                {
                 //now try to fill all the values ranging from 1 to 9
                 for(int val=1;val<=9;val++){
                     
                  //check for safety
                  if(isSafe(i,j,grid,val)){
                     //insert the value
                     grid[i][j] = val;
                     //recursion bhaiya aage ka sambhal lenge
                     bool aageKaSolution = SolveSudoku(grid);
                     //next solution is correct
                     if(aageKaSolution == true){
                         return true;
                     }
                     else{
                         //backtrack
                         grid[i][j] = 0;
                     }
                   }
                   
                 }
                 
                 //If after trying all the values from 1 to 9 nothing could be inserted then return false
                 return false;
               }
            }
        }
        //all cells filled i.e. puzzle solved
        return true;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        SolveSudoku(grid);
        
        //printing the solved sudoku
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cout<<grid[i][j]<<" ";
            }
        }
    }
};

