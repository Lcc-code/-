/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 * 最低公祖先
 */
#include "TreeNode.hpp"
#include <vector>
using namespace std;
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode *> v1;
        vector<TreeNode *> v2;
        vector<TreeNode *> result_1;
        vector<TreeNode *> result_2;
        TreeNode* result;
        int finish = 0;
        show_path(root, p, v1, result_1, finish);
        finish = 0;
        show_path(root, q, v2, result_2, finish);
        int i = 0;
        int path_len = min(result_1.size(), result_2.size());
        for (; i < path_len;i++)
        {
            if (result_1[i] == result_2[i])
                result = result_1[i];
            else 
                break;
        }

        return result;


    }
private:
    void show_path(TreeNode *node, TreeNode *search_node, vector<TreeNode *> &vc, vector<TreeNode *> &result,
                 int finish)
    {
        if (!node || finish == 1)
            return;
        vc.push_back(node);
        if (node == search_node)
        {
            finish = 1;
            result = vc;
        }
        show_path(node->left, search_node, vc, result, finish);

        show_path(node->right, search_node, vc, result, finish);
        vc.pop_back();
          
    }
};