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
    int solve(TreeNode* root, int& res){
        if(!root) return 0;

        int leftMaxPath = max(0, solve(root->left, res));
        int rightMaxPath = max(0, solve(root->right, res));

        res = max(res, leftMaxPath + rightMaxPath + root->val);

        return root->val + max(leftMaxPath, rightMaxPath);
    }
public:
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        solve(root, res);
        return res;
    }
};