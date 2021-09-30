// 257. 二叉树的所有路径
// 给你一个二叉树的根节点 root ，按 任意顺序 ，返回所有从根节点到叶子节点的路径。

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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        vector<int> path;
        if (!root) return res;
        BFS(root, res, path);
        return res;

    }
private:
    void BFS(TreeNode *node, vector<string> &res, vector<int> &path)
    {
        path.push_back(node->val);
        if (!node->left && !node->right)
        {
            string tmp;
            int i = 0;
            for (; i < path.size() - 1; i++)
            {
                tmp += to_string(path[i]);
                tmp += "->";
            }
            tmp += to_string(path[i]);
            res.push_back(tmp);
            return;
        }
        if (node->left) { BFS(node->left, res, path); path.pop_back();}
        if (node->right) { BFS(node->right, res, path); path.pop_back(); }
        
    }
};