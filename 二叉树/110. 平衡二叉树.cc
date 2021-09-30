//  给定一个二叉树，判断它是否是高度平衡的二叉树。  本题中，一棵高度平衡二叉树定义为：  一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。
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
    bool isBalanced(TreeNode* root) {
        int res = getDepth(root);
        return res != -1 ? true : false;
    }
private:
    int getDepth(TreeNode *node)
    {
        if (!node)
            return 0;
        int left = getDepth(node->left);
        if (left == -1) return -1;
        int right = getDepth(node->right);
        if (right == -1) return -1;
        return abs(left - right) > 1 ? -1 : 1 + max(left, right);

    }
};