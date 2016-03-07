class Solution {
public:
    int calculate(string s) {
        int size = s.size();
        if( !size ) return 0;
        
        stack<int> stk;
        stack<char> op;
        
        string ss;
        for(int i = 0; i < size; ++ i)
        {
            if(s[i] == ' ') continue;
            else ss += s[i];
        }
        
        size = ss.size();
        
        for(int i = 0; i < size; ++ i)
        {
            if(ss[i] >= '0' && ss[i] <= '9')
            {
                int num = 0;
                while( i < size && ss[i] >= '0' && ss[i] <= '9' )
                {
                    num = num * 10 + ss[i] - '0';
                    ++ i;
                }
                -- i;
                if(op.empty() || op.top() == '(') stk.push(num);
                else if(op.top() == '+')
                {
                    num += stk.top();
                    stk.pop();
                    op.pop();
                    stk.push(num);
                }
                else if(op.top() == '-')
                {
                    num = stk.top() - num;
                    stk.pop();
                    op.pop();
                    stk.push(num);
                }
            }
            else if(ss[i] == ')')
            {
                op.pop();
                while( !op.empty() && op.top() != '(' && stk.size() != 1 )
                {
                    int num1 = stk.top();
                    stk.pop();
                    int num2 = stk.top();
                    stk.pop();
                    if(op.top() == '+') num1 += num2;
                    else num1 = num2 - num1;
                    
                    op.pop();
                    stk.push(num1);
                }
            }
            else op.push(ss[i]);
        }
        return stk.top();
    }
};
