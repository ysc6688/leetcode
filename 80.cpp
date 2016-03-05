class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if( !size ) return 0;
        int i,count,num;
        i = 1;
        num = nums[0];
        count = 1;
        while(i < size)
        {
            if(nums[i] == num)
            {
                count++;
                if( count > 2 )
                {
                    nums.erase(nums.begin()+i);
                    count--;
                    --i;
                    size--;
                }
            }
            else{
                num = nums[i];
                count = 1;
            }
            ++i;
        }
        return nums.size();
    }
};
