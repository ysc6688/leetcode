class Solution {
public:
    string simplifyPath(string path) {
        if(path.size() == 0) return "";
        
        vector<string> stack;
        string result = "/";
        int i = 1;
        string dir = "";

        while(i < path.size())
        {
            if(path[i] != '/')
                dir += path[i];
            else
            {
                if(dir == ".." && stack.size() > 0)
                    stack.pop_back();
                else if(dir == ".." && stack.size() == 0)
                    ;
                else if(dir != "." && dir != "")
                    stack.push_back(dir);
                dir = "";
            }
            ++i;
        }
        if( dir == ".." && stack.size() > 0 )
            stack.pop_back();
        else if(dir == ".." && stack.size() == 0)
            ;
        else if(dir != "." && dir != "")
            stack.push_back(dir);
        for(i=0;i<stack.size();++i)
        {
            result += stack[i];
            if(i != stack.size() - 1) result += "/";
        }
        return result;
    }
};
