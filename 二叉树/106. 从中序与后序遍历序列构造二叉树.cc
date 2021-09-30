// 106. 从中序与后序遍历序列构造二叉树
// 根据一棵树的中序遍历与后序遍历构造二叉树。

// 注意:
// 你可以假设树中没有重复的元素。

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return traversal(inorder, postorder);
    }
private:
    TreeNode* traversal(vector<int>& inorder, vector<int>& postorder)
    {
        if (postorder.size() == 0) return nullptr;

        int rootValue = postorder[postorder.size() - 1];
        TreeNode *root = new TreeNode(rootValue);
        
        if (postorder.size() == 1) return root;

        int delimiterIndex;
        for (delimiterIndex = 0; delimiterIndex < inorder.size(); delimiterIndex++)
        {
            if (inorder[delimiterIndex] == rootValue) break;
        }
        // 切割中序数组
        // 构造数组左闭右开
        vector<int> leftInorder(inorder.begin(), inorder.begin() + delimiterIndex);
        vector<int> rightInorder(inorder.begin() + delimiterIndex + 1, inorder.end());
        postorder.resize(postorder.size() - 1);

        vector<int> leftPostorder(postorder.begin(),postorder.begin() + 
                    leftInorder.size());
        vector<int> rightPostorder(postorder.begin() + leftInorder.size(),
                                postorder.end());
        root->left = traversal(leftInorder, leftPostorder);
        root->right = traversal(rightInorder, rightPostorder);
        return root;
    }
};












