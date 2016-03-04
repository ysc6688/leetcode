class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int left = 0,right = n-1,count = 0;
        while(left <= right)
        {
            if( A[left]==elem && A[right]!=elem )
            {
                int tmp = A[right];
                A[right] = A[left];
                A[left] = tmp;
                ++left;
                --right;
                ++count;
            }
            else if(A[left]!=elem && A[right]==elem)
            {
                ++left;
                --right;
                ++count;
            }
            else if(A[left]==elem && A[right]==elem)
            {
                --right;
                ++count;
            }
            else
            {
                ++left;
            }
        }
        return n-count;
    }
};
