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
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return 1;
        int left = 0;
        int right = 0;
        if (root->left)
            left = maxDepth(root->left);
        if (root->right)
            right = maxDepth(root->right);
        
        return std::max(left, right) + 1;
    }
};

// Definition for a Node.
/*
给定一个 N 叉树，找到其最大深度。

最大深度是指从根节点到最远叶子节点的最长路径上的节点总数。

N 叉树输入按层序遍历序列化表示，每组子节点由空值分隔（请参见示例）。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-depth-of-n-ary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution_2 {
public:
    int maxDepth(Node* root) {
        if (!root)
            return 0;
        if (root->children.size() == 0)
            return 1;
        int max = 0;
        for (int i = 0; i < root->children.size(); i++)
        {
            max = std::max(maxDepth(root->children[i]), max);
        }
        
        return max + 1;
    }
};