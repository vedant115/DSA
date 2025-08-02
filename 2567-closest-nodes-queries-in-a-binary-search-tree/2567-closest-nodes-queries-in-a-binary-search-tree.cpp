/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
    void sortedOrder(TreeNode* root, vector<int>& nums) {
        if (!root)
            return;

        sortedOrder(root->left, nums);
        nums.push_back(root->val);
        sortedOrder(root->right, nums);
    }

public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> sortedNums;
        sortedOrder(root, sortedNums);

        vector<vector<int>> res;
        for (int q : queries) {
            auto it = lower_bound(sortedNums.begin(), sortedNums.end(), q);

            int floor = -1, ceil = -1;

            // Ceiling
            if (it != sortedNums.end()) {
                ceil = *it;
            }

            // Floor
            if (it != sortedNums.begin()) {
                if (it == sortedNums.end() || *it > q)
                    --it;
                floor = *it;
            } else if (it != sortedNums.end() && *it == q) {
                floor = *it;
            }

            res.push_back({floor, ceil});
        }
        return res;
    }
};