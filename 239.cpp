class Solution {
public:
    int findmax(deque<int>& dq){
        int max = dq[0];
        for(int i = 1; i < dq.size(); ++ i)
            if(max < dq[i]) max = dq[i];
        return max;
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        int size = nums.size();
        if( !size ) return res;
        
        deque<int> dq;
        int max = INT_MIN;
        for(int i = 0; i < k; ++ i)
        {
            dq.push_back(nums[i]);
            if(nums[i] > max) max = nums[i];
        }
        res.push_back(max);
        
        for(int i = k; i < size; ++ i)
        {
            int front = dq.front();
            dq.pop_front();
            
            dq.push_back(nums[i]);
            
            if(nums[i] > max) max = nums[i];
            else if(front == max) max = findmax(dq);
            
            res.push_back(max);
        }
        
        return res;
    }
};
