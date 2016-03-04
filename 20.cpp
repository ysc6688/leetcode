class Solution {
public:
    bool isValid(string s) {
        if( !s.size() )
            return true;
        vector<char> v;
        for(size_t i=0;i<s.size();++i)
        {
            switch(s[i]){
                case '(' :
                    v.push_back('(');
                    break;
                case '[' :
                    v.push_back('[');
                    break;
                case '{' :
                    v.push_back('{');
                    break;
                case ')' :
                    if( v.size()==0 || v.back() != '(' )
                        return false;
                    else
                        v.pop_back();
                    break;
                case ']' :
                    if( v.size()==0 || v.back() != '[' )
                        return false;
                    else
                        v.pop_back();
                    break;
                case '}' :
                    if( v.size()==0 || v.back() != '{' )
                        return false;
                    else
                        v.pop_back();
                    break;
            }
        }
        if( v.size()==0 )
            return true;
        else
            return false;
    }
};
