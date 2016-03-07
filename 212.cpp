struct TrieNode
{
    TrieNode* child[26];
    bool end;
    TrieNode() {
        end = false;
        for(int i = 0; i < 26; ++ i)
            child[i] = NULL;
    }
};


class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        int row = board.size();
        if( !row ) return res;
        int col = board[0].size();
        if( !col ) return res;
        
        vector<vector<bool>> flag;
        
        flag.resize(row);
        for(int i = 0; i < row; ++ i)
            flag[i].resize(col);
        
        for(int i = 0; i < row; ++ i)
            for(int j = 0; j < col; ++ j)
                flag[i][j] = false;
        
        
        int size = words.size();
        TrieNode *root = new TrieNode;
        for(int i = 0; i < size; ++ i)
        {
            buildtree(root,words[i]);
        }
        
        string str;
        unordered_set<string> s;
        for(int i = 0; i < row; ++ i)
            for(int j = 0; j < col; ++ j)
                visit(board,i,j,row,col,str,root,s);
        
        unordered_set<string>::iterator it;
        for(it = s.begin(); it != s.end(); ++ it)
            res.push_back(*it);
        return res;
    }
private:
    void buildtree(TrieNode* node, string word)
    {
        int size = word.size();
        
        for(int i = 0; i < size; ++ i)
        {
            int key = word[i] - 'a';
            if( !node->child[key] )
            {
                TrieNode *child = new TrieNode;
                node->child[key] = child;
            }
            node = node->child[key];
        }
        
        node->end = true;
    }
    void visit(vector<vector<char>>& board, int x, int y, int row, int col, string str, TrieNode* node, unordered_set<string> &s)
    {
        int key = board[x][y] - 'a';
        if( !node->child[key] ) return;
        
        str += board[x][y];
        if( node->child[key]->end && s.find(str) == s.end() ) s.insert(str);
        
        char tmp = board[x][y];
        board[x][y] = '*';
        
        //left
        if( y > 0 && board[x][y - 1] != '*')
        {
            visit(board,x,y - 1,row,col,str,node->child[key],s);
        }
        //right
        if( y < col - 1 && board[x][y + 1] != '*')
        {
            visit(board,x,y + 1,row,col,str,node->child[key],s);
        }
        //up
        if( x > 0 && board[x - 1][y] != '*')
        {
            visit(board,x - 1,y,row,col,str,node->child[key],s);
        }
        //down
        if( x < row - 1 && board[x + 1][y] != '*')
        {
            visit(board,x + 1,y,row,col,str,node->child[key],s);
        }
        
        board[x][y] = tmp;
    }
};
