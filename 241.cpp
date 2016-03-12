class Solution {
public:
    int compute(int a, int b, char op)
    {
        switch(op) {
            case '+':
                return a + b;
            case '-':
                return a - b;
            case '*':
                return a * b;
            default :
                return 0;
        }
    }
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        int size = input.size();
        if( !size ) return res;
        
        int index = 0, num = 0;
        while(index < size && isdigit(input[index]))
            num = num * 10 + input[index++] - '0';
        if(index == size) return vector<int>(1,num);
        
        vector<int> left;
        vector<int> right;
        for(int i = 0; i < size; ++ i)
        {
            if( !isdigit(input[i]) )
            {
                left = diffWaysToCompute(input.substr(0,i));
                right = diffWaysToCompute(input.substr(i + 1, size - i - 1));
                
                for(int j = 0; j < left.size(); ++ j)
                    for(int k = 0; k < right.size(); ++ k)
                        res.push_back(compute(left[j],right[k],input[i]));
            }
        }
        return res;
    }
};
