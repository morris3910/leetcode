class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix[0].size()-1, col = 0;
        while(row >= 0 && col < matrix.size()){
            if(matrix[col][row] == target)
                return true;

            if(matrix[col][row] > target)
                row--;
            else
                col++;
            
        }
        return false;
    }
};