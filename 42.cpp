class Solution {
public:
    int trap(vector<int>& height) {
        if( height.size() <= 1 )
            return 0;
        int i = 0, sum = 0, j;
        while(i<height.size() && height[i] == 0) ++i;
        vector<int> stack;
        while(i < height.size())
        {
            stack.push_back(height[i]);
            j = i + 1;
            int max = -1,maxp = j;
            while(j<height.size() && height[j]<=height[i])
            {
                if(height[j] > max){
                    max = height[j];
                    maxp = j;
                }
                stack.push_back(height[j++]);
            }
            if(j == height.size())
                j = maxp;
                
            int width = j - i - 1;
            int h = (height[i] <= height[j] ) ? height[i] : height[j];
            sum += width * h;
            for(int k=i+1;k<j;++k)
                sum -= height[k];
            i = j;
            stack.clear();
                
        }
        return sum;
    }
};
