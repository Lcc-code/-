/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     int deep;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// 给定一个二叉树，找出其最小深度。

// 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

// 说明：叶子节点是指没有子节点的节点。
#include "TreeNode.hpp"
#include <pair>

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root)
            return 0;
        
        std::queue<std::pair<TreeNode *, int>> Q;
        
        Q.push(make_pair(root, 1));
        while (!Q.empty())
        {
            std::pair<TreeNode*, int> node = Q.front();
            Q.pop();
            if (!node.first->left && !node.first->right)
                return node.second;
            if (node.first->left)
            {
            
                Q.push(make_pair(node.first->left, node.second+1));
            }    
            if (node.first->right)
            {
                Q.push(make_pair(node.first->right, node.second+1));
            }
        }
        return 0;

        
        
    }
};