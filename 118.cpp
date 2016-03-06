class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        if( !numRows ) return result;
        
        for(int i=0;i<numRows;++i)
        {
            vector<int> line;
            line.push_back(1);
            for(int j=2;j<i+1;++j)
            {
                int k = result[i-1][j-2] + result[i-1][j-1];
                line.push_back(k);
            }
            if(i != 0) line.push_back(1);
            result.push_back(line);
        }
        return result;
    }
};
