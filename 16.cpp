class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int i,j,left,right,closest,dist,sum;
        closest = 100000;
        
        sort(num.begin(),num.end());
        for(i=0;i<num.size();i++)
        {
            if(i>0 && num.at(i)==num.at(i-1))
                continue;
            left = i+1;
            right = num.size()-1;
            while(left<right)
            {
                dist = num.at(i) + num.at(left) + num.at(right);
                if(dist == target)
                    return target;
                if(abs(dist-target) < closest)
                {
                    closest = abs(dist-target);
                    sum = dist;
                }
                if(dist > target)
                    right--;
                else
                    left++;
            }
        }
        return sum;
    }
};
