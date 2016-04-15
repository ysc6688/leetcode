class NumArray {
public:
    NumArray(vector<int> &nums) {
        int size = nums.size();
        sum.resize(size);
        int total = 0;
        for(int i = 0; i < size; ++ i)
        {
            total += nums[i];
            sum[i] = total;
        }
    }

    int sumRange(int i, int j) {
        if(i > j) return 0;
        if(i == 0) return sum[j];
        else return sum[j] - sum[i - 1];
    }
private:
    vector<int> sum;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
