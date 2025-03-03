struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// 617. Merge Two Binary Trees
class Solution {
    public:
        TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
            if (root1 == nullptr) { return root2; }
            if (root2 == nullptr) { return root1; } 
            
            root2->val += root1->val;
    
            root2->left = mergeTrees(root1->left, root2->left);
            root2->right = mergeTrees(root1->right, root2->right);
            return root2;
        }
    
    };