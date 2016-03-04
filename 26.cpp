class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int count,dup = A[n-1] + 1,i,j;
        i = count = 0;
        while(i < n)
        {
            j = i + 1;
            while(A[j]==A[i] && j<n)
                A[j++] = dup;
            i = j;
            ++count;
        }
        sort(A,A+n);
        return count;
    }
};
