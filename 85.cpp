class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        int max = 0;
        int size = height.size() + 1;
        stack<int> s;
        vector<int> temp = height;
        temp.push_back(0);
        
        for(int i=0;i<size;++i)
        {
            if(s.empty() || temp[i] >= temp[s.top()])
                s.push(i);
            else
            {
                while( !s.empty() && temp[s.top()] >= temp[i])
                {
                    int h = s.top();
                    s.pop();
                    int area = ( s.empty() ) ? i * temp[h] : (i - s.top() - 1) * temp[h];
                    if(area > max)
                        max = area;
                }
                s.push(i);
            }
        }
        
        return max;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return 0;
        
        int m = matrix.size();
        int n = matrix[0].size();
        int i,j;
        int max = 0;
        vector<int> h;
        h.resize(n);
        
        for(i=0;i<n;++i)
            h[i] = 0;
        
        for(i=0;i<m;++i)
        {
            for(j=0;j<n;++j)
                if(matrix[i][j] == '1')
                    h[j] += 1;
                else
                    h[j] = 0;
            int temp = largestRectangleArea(h);
            if(temp > max)
                max = temp;
        }
        return max;
    }
};
