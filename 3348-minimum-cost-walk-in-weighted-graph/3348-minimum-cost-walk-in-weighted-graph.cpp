class Solution {
private:
    void dfs(int node, vector<vector<int>>& adj, int compNo, vector<int>& vis, unordered_map<int, int>& nodeComp){
        vis[node] = 1;
        nodeComp[node] = compNo;

        for(int adjNode : adj[node]){
            if(!vis[adjNode]){
                dfs(adjNode, adj, compNo, vis, nodeComp);
            }
        }

    }
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {

        vector<vector<int>> adj(n, vector<int>(0));
        for(auto& edge : edges){
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        unordered_map<int, int> nodeComp;
        vector<int> vis(n, 0);
        int compNo = 0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(i, adj, compNo, vis, nodeComp);
                compNo++;
            }
        }

        vector<int> compANDScore(compNo+1, pow(2,31)-1);
        for(auto& edge : edges){
            int nodesComp = nodeComp[edge[0]];
            compANDScore[nodesComp] = compANDScore[nodesComp] & edge[2];
        }

        vector<int> ans;
        for(auto& q : query){
            if(q[0] == q[1]){
                cout << "In same nodes query :" << q[0] << " " << q[1];
                ans.push_back(0);
            }
            else if(nodeComp[q[0]] == nodeComp[q[1]]){
                ans.push_back(compANDScore[nodeComp[q[0]]]);
            }
            else{
                ans.push_back(-1);
            }
        }

        return ans;
    }
};