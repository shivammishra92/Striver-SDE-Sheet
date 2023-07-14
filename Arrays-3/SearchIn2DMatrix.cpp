class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int s = 0;
        int e = (n*m)-1;
        int mid = (s+e)/2;
        int col = matrix[0].size();
        while(s<=e){
            
            int rowIndex = mid/col;
            int colIndex = mid%col;

            if(matrix[rowIndex][colIndex] == target)
            return true;

            else if(matrix[rowIndex][colIndex] < target)
            s = mid+1;
            else
            e = mid-1;

            mid = (s+e)/2;
        }
        return false;
    }
};