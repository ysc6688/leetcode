class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int size = nums.size();
        if( size < 2 ) return size;
        
        unordered_set<int> exist;
        unordered_set<int> visit;
        int count,max = 0;
        for(int i=0;i<size;++i)
            exist.insert(nums[i]);
        
        for(int i=0;i<size;++i)
        {
            if( visit.find(nums[i]) != visit.end() ) continue;
            count = 1;
            int left = nums[i] - 1;
            while(exist.find(left) != exist.end())
            {
                ++count;
                visit.insert(left);
                --left;
            }
            int right = nums[i] + 1;
            while(exist.find(right) != exist.end())
            {
                ++count;
                visit.insert(right);
                ++right;
            }
            if(count > max) max = count;
        }
        return max;
    }
};
