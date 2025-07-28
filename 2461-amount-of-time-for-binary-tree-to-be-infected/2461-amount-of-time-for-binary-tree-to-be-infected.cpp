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
    int amountOfTime(TreeNode* root, int start) {
        TreeNode* targetNode = NULL;
        unordered_map<TreeNode*, TreeNode*> parentMap;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            
            if(node->val == start) targetNode = node;

            if(node->left){ 
                parentMap[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                parentMap[node->right] = node;
                q.push(node->right);
            }
        }

        unordered_set<TreeNode*> visited;
        q.push(targetNode);
        visited.insert(targetNode);
        int currLevel = 0;
        while(!q.empty()){

            int size = q.size();
            for(int i=0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();

                if(node->left && !visited.count(node->left)){
                    q.push(node->left);
                    visited.insert(node->left);
                }
                if(node->right && !visited.count(node->right)){
                    q.push(node->right);
                    visited.insert(node->right);
                }
                if(parentMap[node] && !visited.count(parentMap[node])){
                    q.push(parentMap[node]);
                    visited.insert(parentMap[node]);
                }
            }
            currLevel++;
        }
        return currLevel-1;
    }
};