class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if( !row ) return false;
        int col = matrix[0].size();
        if( !col ) return false;
        
        int i,j;
        i = 0;
        j = col - 1;
        
        while( i < row && j >= 0 )
        {
            if(matrix[i][j] == target) return true;
            else if(matrix[i][j] > target) -- j;
            else ++ i;
        }
        return false;
    }
};
