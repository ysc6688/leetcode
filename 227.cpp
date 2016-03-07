class Solution {
public:
    int calculate(string s) {
        int size = s.size();
        string ss;
        deque<int> v;
        deque<char> op;
        for(int i = 0; i < size; ++ i)
        {
            if(s[i] != ' ') ss += s[i];
        }
        
        size = ss.size();
        for(int i = 0; i < size; ++ i)
        {
            if(ss[i] >= '0' && ss[i] <= '9')
            {
                int num = 0;
                while(i < size && (ss[i] >= '0' && ss[i] <= '9') )
                {
                    num = num * 10 + ss[i] - '0';
                    ++ i;
                }
                -- i;
                if( !op.empty() && (op.back() == '*' || op.back() == '/') )
                {
                    int first = v.back();
                    v.pop_back();
                    if(op.back() == '*') num = num * first;
                    else num = first / num;
                    op.pop_back();
                }
                v.push_back(num);
            }
            else op.push_back(ss[i]);
        }
        while( !op.empty() )
        {
            int first = v.front();
            v.pop_front();
            int second = v.front();
            v.pop_front();
            if(op.front() == '+') first += second;
            else first -= second;
            
            v.push_front(first);
            op.pop_front();
        }
        return v.back();
    }
};
