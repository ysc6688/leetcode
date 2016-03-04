class Solution {
    vector<string> result;
public:
    void add(string s,int left,int right) {
        if( !left && !right)
            result.push_back(s);
        else{
                if(left == right)
                {
                    s += '(';
                    --left;
                    add(s,left,right);
                }
                else{
                    string sl,sr;
                    if(left > 0)
                    {
                        sl = s + '(';
                        --left;
                        add(sl,left,right);
                        ++left;
                    }
                    if(right > 0)
                    {
                        sr = s + ')';
                        --right;
                        add(sr,left,right);
                    }
                }
        }
    }
    vector<string> generateParenthesis(int n) {
        int left,right;
        left = right = n;
        
        string s;
        s += '(';
        --left;
        add(s,left,right);
        
        return result;
    }
};
