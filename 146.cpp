struct listnode{
    listnode *pre;
    listnode *post;
    int key;
    int value;
    listnode(int k,int v) : key(k), value(v), pre(NULL), post(NULL) {};
};

class LRUCache{
public:
    LRUCache(int capacity) {
        head = tail = NULL;
        this->capacity = capacity;
    }
    
    int get(int key) {
        unordered_map<int,listnode*>::iterator it = m.find(key);
        if(it != m.end()) 
        {
            listnode *node = it->second;
            if( node == tail) return node->value;
            else if(node == head)
            {
                head = node->post;
                head->pre = NULL;
                tail->post = node;
                node->pre = tail;
                node->post = NULL;
                tail = node;
                return node->value;
            }
            else
            {
                node->pre->post = node->post;
                node->post->pre = node->pre;
                tail->post = node;
                node->pre = tail;
                node->post = NULL;
                tail = node;
                return node->value;
            }
        }
        else return -1;
    }
    
    void set(int key, int value) {
        unordered_map<int,listnode*>::iterator it = m.find(key);
        if(it != m.end())
        {
            listnode *node = it->second;
            node->value = value;
            
            if(node == head && node != tail)
            {
                head = node->post;
                head->pre = NULL;
                tail->post = node;
                node->pre = tail;
                node->post = NULL;
                tail = node;
            }
            else if( node != head && node != tail)
            {
                node->pre->post = node->post;
                node->post->pre = node->pre;
                tail->post = node;
                node->pre = tail;
                node->post = NULL;
                tail = node;
            }
        }
        else if(m.size() < this->capacity)
        {
            listnode *node = new listnode(key,value);
            if( !tail )
            {
                head = tail = node;
            }
            else
            {
                tail->post = node;
                node->pre = tail;
                tail = node;
            }
            
            m.insert(make_pair(key,node));
        }
        else
        {
            int hk = head->key;
            unordered_map<int,listnode*>::iterator ri = m.find(hk);
            m.erase(ri);
            
            listnode *temp = head->post;
            delete head;
            head = temp;
            if( !head ) tail = NULL;
            
            listnode *node = new listnode(key,value);
            if( !tail )
            {
                head = tail = node;
            }
            else
            {
                tail->post = node;
                node->pre = tail;
                tail = node;
            }
            
            m.insert(make_pair(key,node));
        }
    }
private:
    unordered_map<int,listnode*> m;
    listnode* head;
    listnode* tail;
    int capacity;
};
