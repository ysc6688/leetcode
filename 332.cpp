class Solution {
public:
    bool dfs(unordered_map<string,multimap<string,bool>>& map, vector<string>& res, string start, int len)
    {
        if(res.size() == len + 1)
            return true;

        unordered_map<string,multimap<string,bool>>::iterator it;
        it = map.find(start);
        if(it == map.end()) return false;
        
        multimap<string,bool>::iterator nit = it->second.begin();
        while(nit != it->second.end())
        {
            if(nit->second == false) {
                nit ++;
                continue;
            }
            else
            {
                nit->second = false;
                res.push_back(nit->first);

                if(dfs(map,res,nit->first,len)) return true;
                
                nit->second = true;
                res.pop_back();
                nit ++;
            }
        }
        return false;
    }
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        vector<string> res;
        int len = tickets.size();
        if( !len ) return res;
        unordered_map<string,multimap<string,bool>> map;
        
        for(int i = 0; i < len; ++ i)
        {
            unordered_map<string,multimap<string,bool>>::iterator it;
            it = map.find(tickets[i].first);
            if(it == map.end())
            {
                multimap<string,bool> next;
                next.insert(make_pair(tickets[i].second,true));
                map.insert(make_pair(tickets[i].first,next));
            }
            else
            {
                it->second.insert(make_pair(tickets[i].second,true));
            }
        }
        
        res.push_back("JFK");

        dfs(map,res,"JFK",len);
        
        return res;
    }
};
