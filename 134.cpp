class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int size = gas.size();
        vector<int> v(size);
        int count = 0,max = -1,index = -1,total = 0;
        for(int i = 0; i < size; ++ i)
        {
            total += gas[i] - cost[i];
            count += gas[i] - cost[i];
            if(count >= 0)
            {
                v[i] = count;
                if(max < count)
                {
                    max = count;
                    index = i;
                }
            }
            else 
            {
                count = 0;
                v[i] = -1;
            }
        }
        if(index == -1) return -1;
        while(index >= 0)
        {
            if(v[index] < 0) break;
            else --index;
        }
        if(index == -1)
        {
            index = size - 1;
            while(index >= 0)
            {
                if(v[index] < 0) break;
                else --index;
            }
        }
        int begin = index + 1;

        return total < 0 ? -1 : begin;
    }
};
