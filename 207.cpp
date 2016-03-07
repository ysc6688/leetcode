class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        int in_degree[numCourses] = { 0 };
        int vsize = prerequisites.size();
        
        for(int i = 0; i < vsize; ++ i)
            in_degree[prerequisites[i].second]++;
            
        queue<int> q;
        
        for(int i = 0; i < numCourses; ++ i)
            if(in_degree[i] == 0) q.push(i);

        bool edge[vsize];
        memset(edge,false,vsize);
        int count = 0;
        while( !q.empty() )
        {
            int node = q.front();
            q.pop();
            
            for(int i = 0; i < vsize; ++i)
            {
                if(!edge[i] && prerequisites[i].first == node)
                {
                    edge[i] = true;
                    in_degree[prerequisites[i].second]--;
                    if(in_degree[prerequisites[i].second] == 0) q.push(prerequisites[i].second);
                    ++ count;
                }
            }
        }
        return count == vsize;
    }
};
