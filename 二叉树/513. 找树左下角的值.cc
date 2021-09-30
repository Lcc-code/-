// 假设二叉树中至少有一个节点。

 

// 示例 1:

// ￼

// 输入: root = [2,1,3]
// 输出: 1
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        if (!root)
            return 0;
        queue<TreeNode*> Q;
        Q.push(root);
        int res;
        while (!Q.empty())
        {
            TreeNode *node = Q.front();
            res = node->val;
            Q.pop();
            if (node->right) Q.push(node->right);
            if (node->left) Q.push(node->left);
        }
        return res;
    }
};