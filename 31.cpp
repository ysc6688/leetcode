class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int i,last,flag;
        if(num.size()<2)
            return ;
        last = num[num.size()-1];
        flag = 0;
        for(i=num.size()-2;i>=0;--i)
        {
            if(num[i] < last)
            {
                int index = i+1;
                for(int j=i+1;j<num.size();++j)
                    if(num[index]>num[j] && num[j]>num[i])
                        index = j;
                int tmp = num[index];
                num[index] = num[i];
                num[i] = tmp;
                sort(num.begin()+i+1,num.end());
                flag = 1;
                break;
            }
            last = num[i];
        }
        if(!flag)
            sort(num.begin(),num.end());
    }
};
