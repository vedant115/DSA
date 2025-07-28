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
    void dfsRight(TreeNode* root, int level, map<int, int>& mpp){
        if(!root) return;

        if(mpp.find(level) == mpp.end())
            mpp[level] = root->val;

        if(root->right) dfsRight(root->right, level+1, mpp);
        if(root->left) dfsRight(root->left, level+1, mpp);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        map<int, int> mpp;
        vector<int> res;
        dfsRight(root, 0, mpp);
        for(auto& [row, val] : mpp) res.push_back(val);
        return res;
    }
};