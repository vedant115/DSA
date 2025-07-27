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
private:
    int getHeight(TreeNode* root, int& ans){
        if(!root) return 0;

        int left = getHeight(root->left, ans);
        int right = getHeight(root->right, ans);

        int h = 1 + max(left, right);
        ans = max(ans, left+right);
        return h;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;

        int ans = 0;
        getHeight(root, ans);
        return ans;
    }
};