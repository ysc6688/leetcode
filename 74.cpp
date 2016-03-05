class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i,r,l,mid;

        int m = matrix.size();
        int n = matrix[0].size();
        
        l = 0;
        r = m - 1;
        
        while(l <= r)
        {
            mid = (l + r) / 2;
            if( matrix[mid][n-1] == target)
                return true;
            else if( matrix[mid][n-1] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        int line = l;
        
        if( line == m )
            return false;
        
        l = 0;
        r = n - 1;
        
        while(l <= r)
        {
            mid = (l + r) / 2;
            if( matrix[line][mid] == target)
                return true;
            else if( matrix[line][mid] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return false;
    }
};
