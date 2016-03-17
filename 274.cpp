class Solution {
public:
    int hIndex(vector<int>& citations) {
        int size = citations.size();
        if( !size ) return 0;
        
        vector<int> count(size + 1,0);
        
        for(int i = 0; i < size; ++ i)
        {
            if(citations[i] >= size) ++ count[size];
            else count[citations[i]]++;
        }
        
        if(count[size] == size) return size;
        
        for(int i = size - 1; i >= 0; -- i)
        {
            count[i] = count[i] + count[i + 1];
            if(count[i] >= i) return i;
        }
        return 0;
    }
};
