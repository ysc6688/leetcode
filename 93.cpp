class Solution {
public:
    void dfs(string &s,vector<string> &result,int p,int c,string &ip)
    {
        if(s.size() - p > 12 - 3*c || s.size() - p < 4 - c)
            return ;
        if(c == 3)
        {
            if(s[p] == '0' && p < s.size() - 1)
                return ;
            string seg(s.begin()+p,s.end());
            if(atoi(seg.c_str()) <= 255)
            {
                string temp;
                temp = ip + "." + seg;
                temp = temp.substr(1);
                result.push_back(temp);
            }
        }
        else
        {
            for(int i=1;i<=3;++i)
            {
                string seg(s.begin()+p,s.begin()+p+i);
                if(atoi(seg.c_str()) <= 255)
                {
                    ip += "." + seg;
                    p += i;
                    c += 1;
                    dfs(s,result,p,c,ip);
                    p -= i;
                    c -= 1;
                    int size = ip.size();
                    ip.resize(size - 1 - i);
                }
                if(s[p] == '0')
                    break;
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        if(s.size() < 4) return result;
        
        string ip;
        dfs(s,result,0,0,ip);
        return result;
    }
};
