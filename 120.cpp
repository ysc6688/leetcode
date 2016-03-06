class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int n = triangle.size();
        if(n == 0) return 0;
        
        int *sum = new int[n + 1];
        sum[0] = triangle[0][0];
        for(int i = 1;i < n;i++)
        {
            sum[i] = sum[i - 1] + triangle[i][i];
            for(int j = i - 1;j > 0;j--)
                sum[j] = min(sum[j], sum[j - 1]) + triangle[i][j];
            sum[0] = sum[0] + triangle[i][0];
        }
        int minS = 2147483647;
        for(int i = 0;i < n;i++)
            if(sum[i] < minS)
                minS = sum[i];

        return minS;
    }
};
