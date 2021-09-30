// 112. 路径总和
// 给你二叉树的根节点 root 和一个表示目标和的整数 targetSum ，判断该树中是否存在 根节点到叶子节点 的路径，这条路径上所有节点值相加等于目标和 targetSum 。

// 叶子节点 是指没有子节点的节点。
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        return traversal(root, targetSum - root->val);
    }
private:
    bool traversal(TreeNode *cur, int count)
    {
        if (!cur->left && !cur->right && count == 0)  return true;
        if (!cur->left && !cur->right) return false;

        if (cur->left) {if (traversal(cur->left, count - cur->left->val)) return true;}
        if (cur->right) {if (traversal(cur->right, count- cur->right->val)) return true;}
        return false;

         
    }
};