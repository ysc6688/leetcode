class Solution {
public:
    string next(string s, int& index)
    {
        string res;
        int len = s.size();
        if(index >= len) return res;
        
        while(index < len && s[index] != ',')
        {
            res += s[index];
            ++ index;
        }
        ++ index;
        return res;
    }
    bool isValidSerialization(string preorder) {
        int len = preorder.size();
        if( !len ) return true;

        stack<char> stk;
        int index = 0;
        string node = next(preorder,index);

        while(node != ""){
            if(node != "#")
            {
                stk.push('(');
            }
            else
            {
                if(stk.empty() && index > len) return true;

                if(stk.empty()) return false;
                else if(stk.top() == '(')
                {
                    stk.push(')');
                }
                else
                {
                    stk.pop();
                    if(stk.empty()) return false;
                    stk.pop();
                    node = "#";
                    continue;
                }
            }
            node = next(preorder,index);
        }
        return stk.empty();
    }
};
