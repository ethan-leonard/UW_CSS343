struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// 101. Symmetric Tree
class Solution {
public:
    bool isSymmetric(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;
        if (p == nullptr || q == nullptr) return false;
        if (p->val != q->val) return false;

        return isSymmetric(p->left, q->right) && isSymmetric(p->right, q->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        } return isSymmetric(root->left, root->right);
    }
};

// 98. Validate Binary Search Tree
class Solution {
public:
    bool isValidBST(TreeNode* curr, TreeNode* min, TreeNode* max) {
        if (curr == nullptr) return true;
        if (min != nullptr && curr->val <= min->val) return false;
        if (max != nullptr && curr->val >= max->val) return false;
        return isValidBST(curr->left, min, curr) &&
            isValidBST(curr->right, curr, max);
    }

    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;
        return isValidBST(root->left, nullptr, root) &&
            isValidBST(root->right, root, nullptr);
    }
};