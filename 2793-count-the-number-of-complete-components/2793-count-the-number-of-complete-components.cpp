class Solution {
private:
    void dfs(int node, vector<vector<int>>& adjList, int& nodes, int& edges, vector<int>& visited){
        visited[node] = 1;
        nodes++;
        edges += adjList[node].size();
        for(int adjNode : adjList[node]){
            if(!visited[adjNode]){
                dfs(adjNode, adjList, nodes, edges, visited);
            }
        }
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n, vector<int>(0));
        for(auto& edge : edges){
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        vector<int> visited(n, 0);
        int res = 0;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                int nodes = 0, edges = 0;
                dfs(i, adjList, nodes, edges, visited);
                if(nodes*(nodes-1) == edges) res++;
            }
        }

        return res;
    }
};