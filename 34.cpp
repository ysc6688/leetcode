class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int l,r,m;
        l = 0;
        r = n - 1;
        while(l <= r)
        {
            m = l + (r-l)/2;
            if(A[m] >= target)
                r = m-1;
            else
                l = m+1;
        }
        int left = l;
        l = 0;
        r = n - 1;
        while(l <= r)
        {
            m = l + (r-l)/2;
            if(A[m] > target)
                r = m - 1;
            else
                l = m + 1;
        }
        int right = r;
        vector<int> v;
        if(A[left]!=target || A[right]!=target)
        {
            v.push_back(-1);
            v.push_back(-1);
        }
        else {
            v.push_back(left);
            v.push_back(right);
        }
        
        return v;
    }
};
