bool cmp(const string &a, const string &b)
{
    string ab = a + b;
    string ba = b + a;
    
    return ab < ba;
}


class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int size = nums.size();
        //if( !size ) return "0";
        
        vector<string> v;
        char buf[15];
        
        for(int i = 0; i < size; ++ i)
        {
            sprintf(buf,"%d",nums[i]);
            v.push_back(string(buf));
        }
        
        sort(v.begin(),v.end(),cmp);
        string res = "";
        
        for(int i = size - 1; i >= 0; -- i)
            res += v[i];
            
        int pos = 0;
        while(res[pos] == '0') ++ pos;
        if( pos != size )
        {
            res = res.substr(pos);
            return res;
        }
        else return "0";
    }
};
