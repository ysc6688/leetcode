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
};
