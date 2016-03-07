class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int size = nums.size();
        
        if( !size ) return res;
        
        int begin = nums[0];
        int last = begin;
        char buf[50];
        for(int i = 1; i < size; ++ i)
        {
            if(nums[i] - last == 1) last = nums[i];
            else if(last != begin)
            {
                sprintf(buf,"%d->%d",begin,last);
                string s(buf);
                res.push_back(s);
                begin = last = nums[i];
            }
            else
            {
                sprintf(buf,"%d",begin);
                string s(buf);
                res.push_back(s);
                begin = last = nums[i];
            }
        }
        if(last != begin)
            {
                sprintf(buf,"%d->%d",begin,last);
                string s(buf);
                res.push_back(s);  
            }
            else
            {
                sprintf(buf,"%d",begin);
                string s(buf);
                res.push_back(s);  
            }

        return res;
        
    }
};
