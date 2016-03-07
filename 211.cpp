class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        end = false;
        for(int i = 0; i < 26; ++ i)
            child[i] = NULL;
    }
    void createChild(int k)
    {
        child[k] = new TrieNode;
    }
    void setEnd()
    {
        end = true;
    }
    bool getEnd()
    {
        return end;
    }
    TrieNode* getChild(int k)
    {
        return child[k];
    }
private:
    bool end;
    TrieNode* child[26];
};

class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode;
    }

    // Adds a word into the data structure.
    void addWord(string word) {
        int size = word.size();
        TrieNode* ptr = root;
        int i = 0;
        for( ; i < size; ++ i)
        {
            int key = word[i] - 'a';
            if( ptr->getChild(key) == NULL) break;
            else ptr = ptr->getChild(key);
        }
        for(; i < size; ++ i)
        {
            int key = word[i] - 'a';
            ptr->createChild(key);
            ptr = ptr->getChild(key);
        }
        ptr->setEnd();
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return traversal(root,word);
    }
    
private:
    TrieNode *root;
    bool traversal(TrieNode* node, string word)
    {
        int size = word.size();
        if(size == 0) return node->getEnd();
        
        TrieNode* ptr = node;
        
        for(int i = 0; i < size; ++ i)
        {
            if(word[i] == '.')
            {
                for(int j = 0; j < 26; ++ j)
                {
                    TrieNode* p = ptr->getChild(j);
                    if( !p ) continue;
                    if( traversal(p,word.substr(i + 1)) ) return true;
                }
                return false;
            }
            else
            {
                int key = word[i] - 'a';
                TrieNode* p = ptr->getChild(key);
                if( !p ) return false;
                else
                    ptr = p;
            }
        }
        return ptr->getEnd();
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
