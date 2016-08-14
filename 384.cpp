class Solution {
public:
    Solution(vector<int> nums) {
        original = nums;
        srand(time(0));
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return original;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> res(original);
        int len = res.size();
        for(int i = 1; i < len; ++ i)
        {
            int idx = rand() % (i + 1);
            std::swap(res[i],res[idx]);
        }
        
        return res;
    }
private:
    vector<int> original;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
