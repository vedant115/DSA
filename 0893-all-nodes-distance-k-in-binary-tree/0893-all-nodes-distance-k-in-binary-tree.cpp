/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parentMap;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

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
        q.push(target);
        visited.insert(target);
        int currLevel = 0;
        vector<int> res;
        while(!q.empty()){
            if(currLevel == k){
                while(!q.empty()){
                    res.push_back(q.front()->val);
                    q.pop();
                }
                return res;
            }

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
        return res;
    }
};