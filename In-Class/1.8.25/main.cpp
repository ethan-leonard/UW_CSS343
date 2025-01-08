#include <vector>
#include <queue>
#include <algorithm>


// 102. Binary Tree Level Order Traversal
class Solution {
public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> levels;
        std::queue<TreeNode*> q;

        if (root == nullptr) return levels;

        q.push(root);
        while(!q.empty()) {
            std::vector<int> level;

            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                if (node->left != nullptr) {
                    q.push(node->left);
                } if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            levels.push_back(level);
        }
        return levels;
    }
};


// 94. Binary Tree Inorder Traversal
class Solution {
public:
    std::vector<int> nodes;

    std::vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr) {
            return nodes;
        }
        inorderTraversal(root->left);
        nodes.push_back(root->val);
        inorderTraversal(root->right);

        return nodes;
    }

};


// 145. Binary Tree Postorder Traversal
class Solution {
public:
    std::vector<int> nodes;

    std::vector<int> postorderTraversal(TreeNode* root) {
        if (root == nullptr) {
            return nodes;
        }

        postorderTraversal(root->left);
        postorderTraversal(root->right);
        nodes.push_back(root->val);
        return nodes;
    }
};

// 268. Missing Number
class Solution {
public:
    int missingNumber(std::vector<int>& nums) {
        stable_sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i) {
                return i;
            }
        }

        return nums.size();
    }
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
