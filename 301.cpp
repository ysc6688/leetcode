class Solution {
public:
    bool isInvalid(string s)
    {
        stack<char> stk;
        int size = s.size();
        for(int i = 0; i < size; ++ i)
        {
            if(s[i] == '(') stk.push('(');
            else if(s[i] == ')')
            {
                if( !stk.empty() ) stk.pop();
                else return false;
            }
        }
        return stk.empty();
    }

    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        int size = s.size();
        if( !size ) {
            res.push_back("");
            return res;
        }

        unordered_set<string> set;
        queue<string> q;

        q.push(s);
        set.insert(s);

        bool found = false;

        while( !q.empty() )
        {
            string front = q.front();
            q.pop();
            if(isInvalid(front))
            {
                found = true;
                res.push_back(front);
            }

            if(found) continue;

            for(int i = 0; i < front.size(); ++ i)
            {
                if(front[i] == ')' || front[i] == '(')
                {
                    string tmp = front;
                    tmp.erase(i,1);
                    if(set.find(tmp) == set.end())
                    {
                        set.insert(tmp);
                        q.push(tmp);
                    }
                }
            }
        }

        return res;
    }
};
