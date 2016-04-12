class Codec {
public:


// Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if( !root ) return string("[]");
        queue<TreeNode*> q;
        vector<TreeNode*> v;
        string res = "[";
        q.push(root);
        TreeNode *p = root;

        char buf[25];

        while(!q.empty())
        {
            p = q.front();
            q.pop();

            if( !p ) {
                v.push_back(NULL);
                continue;
            }

            v.push_back(p);
            q.push(p->left);
            q.push(p->right);
        }
        int i = v.size() - 1;
        while(v[i] == NULL) -- i;
        v.resize(i + 1);

        for(int i = 0; i < v.size(); ++ i)
        {
            if(v[i] == NULL) res += "null,";
            else
            {
                int val = v[i]->val;
                char buf[25];
                sprintf(buf,"%d",val);
                string next(buf);
                res += next;
                res += ",";
            }
        }

        res[res.size() - 1] = ']';

        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if( data == "[]") return NULL;
        int size = data.size();

        TreeNode *root = NULL;
        TreeNode *pre = NULL;
        TreeNode *p = NULL;
        int count = 0;

        int i = 1, length = 0;
        int begin = 1;
        while(i < size - 1 && data[i] != ',')
        {
            ++ length;
            ++ i;
        }
        string next = data.substr(begin,length);
        int val = atoi(next.c_str());
        root = new TreeNode(val);
        pre = root;

        queue<TreeNode*> q;

        for( ; i < size - 1; )
        {
            ++ i;
            begin = i;
            length = 0;
            while(i < size - 1 && data[i] != ',')
            {
                ++ length;
                ++ i;
            }
            next = data.substr(begin,length);
            if(next == "null")
            {
                if(count == 0) {
                    pre->left = NULL;
                    ++ count;
                }
                else {
                    pre->right = NULL;
                    count = 0;
                    pre = q.front();
                    q.pop();
                }
            }
            else
            {
                val = atoi(next.c_str());
                p = new TreeNode(val);
                q.push(p);
                if(count == 0)
                {
                    pre->left = p;
                    ++ count;
                }
                else
                {
                    pre->right = p;
                    count = 0;
                    pre = q.front();
                    q.pop();
                }
            }
        }
        return root;
    }
};
