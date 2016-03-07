class Solution {
public:
    int getTheKth(int num, int k)
    {
        int i = 0;
        while(i < k) {
            num /= 10;
            ++ i;
        }
        return num % 10;
    }
    int maximumGap(vector<int>& nums) {
        int size = nums.size();
        if( size < 2 ) return 0;

        int bin[10][size + 1];

        int count = 0,max = -1;

        for(int i = 0; i < size; ++ i)
            if( max < nums[i]) max = nums[i];

        while(max > 0)
        {
            ++ count;
            max /= 10;
        }
        for(int i = 0; i < count; ++ i)
        {
            for(int j = 0; j < 10 ; ++ j)
                bin[j][0] = 0;
            for(int j = 0; j < size; ++ j)
            {
                int k = getTheKth(nums[j],i);
                //cout << "the " << i << " th " << k << " of " << nums[j] << endl;
                bin[k][0] ++;
                int p = bin[k][0];
                bin[k][p] = nums[j];
            }

            int n = 0, p = 0;
            while(n < size)
            {
                int num = bin[p][0];
                if( num != 0)
                    for(int j = 1; j <= num; ++j) nums[n++] = bin[p][j];
                ++ p;
            }
        }

        int gap = -1;
        for(int i = 1; i < size; ++ i)
        {
            int g = nums[i] - nums[i - 1];
            if( g > gap ) gap = g;
        }
        return gap;
    }
};
