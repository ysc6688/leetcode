class Solution {
public:
    struct Node {
        int val, smaller;
        Node *left, *right;
        Node(int value, int small) { 
            left=right=NULL, val=value, smaller=small; 
        }
    };

    int insert(Node *&root, int value) {
        if (root==NULL)
            return (root=new Node(value, 0)), 0;

        if (value < root->val) 
            return root->smaller++, insert(root->left, value);
        else
            return insert(root->right, value) + root->smaller + (value>root->val ? 1 : 0);
    }

    vector<int> countSmaller(vector<int>& nums) {
        Node *root = NULL;
        int size=  nums.size();
        vector<int> res(size);
        for (int i=size-1; i>=0; i--)
            res[i] = insert(root, nums[i]);
            
        return res;
    }
};
