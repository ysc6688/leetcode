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

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        int size = word.size();
        int i;
        TrieNode* ptr = root;
        for(i = 0; i < size; ++ i)
        {
            int key = word[i] - 'a';
            if( !ptr->getChild(key) ) break;
            else
                ptr = ptr->getChild(key);
        }
        for(; i < size; ++ i)
        {
            int key = word[i] - 'a';
            ptr->createChild(key);
            ptr = ptr->getChild(key);
        }
        ptr->setEnd();
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        int size = word.size();
        TrieNode* ptr = root;
        for(int i = 0; i < size; ++ i)
        {
            int key = word[i] - 'a';
            if( !ptr->getChild(key) ) return false;
            else
                ptr = ptr->getChild(key);
        }
        return ptr->getEnd();
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        int size = prefix.size();
        TrieNode* ptr = root;
        for(int i = 0; i < size; ++ i)
        {
            int key = prefix[i] - 'a';
            if( !ptr->getChild(key) ) return false;
            else
                ptr = ptr->getChild(key);
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
