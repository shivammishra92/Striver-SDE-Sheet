class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        //transpose
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        //reverse each row by swaping first and last element
        for(int i=0;i<n;i++){
              int k = 0;
            for(int j=n-1;j>=n/2;j--){
                swap(matrix[i][j],matrix[i][k++]);

            }
        }
    }
};