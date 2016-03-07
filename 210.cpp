class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> res;
        int inDegree[numCourses] = { 0 };
        int psize = prerequisites.size();
        
        for(int i = 0; i < psize; ++ i)
            inDegree[prerequisites[i].first] ++;
        
        queue<int> q;
        for(int i = 0; i < numCourses; ++ i)
            if( !inDegree[i] ) q.push(i);
            
        bool flag[psize];
        memset(flag,false,psize);

        while( !q.empty() )
        {
            int num = q.front();
            q.pop();
            res.push_back(num);
            
            for(int i = 0; i < psize; ++ i)
            {
                if(!flag[i] && prerequisites[i].second == num)
                {
                    flag[i] = true;
                    inDegree[prerequisites[i].first]--;
                    if( inDegree[prerequisites[i].first] == 0 )
                        q.push(prerequisites[i].first);
                }
            }
        }
        if(res.size() < numCourses) res.clear();
        return res;
    }
};
