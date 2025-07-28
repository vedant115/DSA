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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
    	queue<tuple<TreeNode*, int, int>> q;
        map<int, map<int, priority_queue<int, vector<int>, greater<int>>>> mpp;

        q.push({root, 0, 0});
        while(!q.empty()){
            auto [node, x, y] = q.front();
            q.pop();

            mpp[y][x].push(node->val);

            if(node->left) q.push({node->left, x+1, y-1});
            if(node->right) q.push({node->right, x+1, y+1});
        }

        vector<vector<int>> result;
        for(auto [col, mp] : mpp){

            vector<int> column;
            for(auto [row, pq] : mp){
                while(!pq.empty()){
                    column.push_back(pq.top());
                    pq.pop();
                }
            }
            result.push_back(column);
        }
        return result;
    }
};