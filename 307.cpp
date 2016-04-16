class NumArray {
public:
    NumArray(vector<int> &nums) {
        n = nums.size();
        tree.resize(n << 1);
        for(int i = n, j = 0; j < n; ++ i, ++ j)
            tree[i] = nums[j];
        for(int i = n - 1; i > 0; -- i)
            tree[i] = tree[i << 1] + tree[(i << 1) + 1];
    }

    void update(int i, int val) {
        i += n;
        tree[i] = val;
        while(i > 0)
        {
            int l,r;
            l = r = i;
            if((i&1) == 0) r = i + 1;
            else l = i - 1;
            tree[i >> 1] = tree[l] + tree[r];
            i >>= 1;
        }
    }

    int sumRange(int i, int j) {
        int l = i + n;
        int r = j + n;
        int sum = 0;
        while(l <= r)
        {
            if((l&1) == 1)
            {
                sum += tree[l];
                ++ l;
            }
            if((r&1) == 0)
            {
                sum += tree[r];
                -- r;
            }
            l >>= 1;
            r >>= 1;
        }
        return sum;
    }
private:
    vector<int> tree;
    int n;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);
