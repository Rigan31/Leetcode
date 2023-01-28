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
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return NULL;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *rootTmp = q.front();
            q.pop();
            TreeNode *tmp = rootTmp->left;
            rootTmp->left = rootTmp->right;
            rootTmp->right = tmp;

            if(rootTmp->left != NULL) q.push(rootTmp->left);
            if(rootTmp->right != NULL) q.push(rootTmp->right);

        }

        return root;
    }
};