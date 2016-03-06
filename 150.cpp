class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int size = tokens.size();
        std::stack<int> s;
        int result;
        for(int i = 0; i < size; ++ i)
        {
            if(tokens[i].size() > 1) s.push(atoi(tokens[i].c_str()));
            else if(tokens[i][0] >= '0' && tokens[i][0] <= '9')
                s.push(atoi(tokens[i].c_str()));
            else
            {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                switch (tokens[i][0])
                {
                    case '+':
                        result = b + a;
                        break;
                    case '-':
                        result = b - a;
                        break;
                    case '*':
                        result = b * a;
                        break;
                    case '/':
                        result = b / a;
                        break;
                    default :
                        break;
                }
                s.push(result);
            }
        }
        result = s.top();
        return result;
    }
};
