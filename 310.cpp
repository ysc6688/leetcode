class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> res;
        int size = edges.size();
        if(n <= 0) return res;

        vector<vector<int>> path(n);
        
        int degree[n] = { 0 };

        for(int i = 0; i < size; ++ i)
        {
            int x = edges[i].first;
            int y = edges[i].second;
            path[x].push_back(y);
            path[y].push_back(x);
            degree[x] ++;
            degree[y] ++;
        }

        queue<int> q;
        unordered_set<int> us;
        for(int i = 0; i < n; ++ i)
            us.insert(i);

        unordered_set<int>::iterator it;
        while(us.size() > 2)
        {
            //leaf
            for(it = us.begin(); it != us.end(); ++ it)
            {
                if(degree[*it] == 1) {
                    q.push(*it);
                    degree[*it] --;
                }
            }
                    
            while( !q.empty() )
            {
                int v = q.front();
                q.pop();
                
                us.erase(us.find(v));
                
                for(int i = 0; i < path[v].size(); ++ i)
                    degree[path[v][i]] --;
            }
        }
        
        for(it = us.begin(); it != us.end(); ++ it)
            res.push_back(*it);

        return res;
    }
};
