/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
 
struct hash_func  
{  
    size_t operator()(const UndirectedGraphNode* node) const  
    {  
         return node->label*31;  
    }  
};

typedef unordered_map<UndirectedGraphNode *,UndirectedGraphNode *,hash_func> HASH;

class Solution {
public:
    UndirectedGraphNode *dfs(UndirectedGraphNode* node, HASH &hash) {
        UndirectedGraphNode *root = new UndirectedGraphNode(node->label);
        hash.insert(make_pair(node,root));
        
        vector<UndirectedGraphNode *> &nbrs = node->neighbors;
        
        for(int i = 0; i < nbrs.size(); ++ i)
        {
            if(nbrs[i] == node)
                root->neighbors.push_back(root);
            else
            {
                HASH::iterator it = hash.find(nbrs[i]);
                if(it != hash.end())
                    root->neighbors.push_back(it->second);
                else
                    root->neighbors.push_back(dfs(nbrs[i],hash));
            }
        }
        return root;
    }
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if( !node ) return NULL;
        
        HASH hash;

        return dfs(node,hash);
    }
};
