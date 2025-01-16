class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int m = flights.size();
        vector<vector<vector<int>>> adj(n);
        for(int i=0; i<m; i++){
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }

        //{stops, {node, distance}}
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});

        vector<int> dist(n, 1e9);
        dist[src] = 0;

        while(!q.empty()){
            int city = q.front().second.first;
            int cityDist = q.front().second.second;
            int stops = q.front().first;
            q.pop();

            for(auto adjCity : adj[city]){
                if(stops <= k && cityDist + adjCity[1] < dist[adjCity[0]]){
                    dist[adjCity[0]] = cityDist + adjCity[1];
                    q.push({stops+1, {adjCity[0], dist[adjCity[0]]}});
                }
            }
        }

        if(dist[dst] == 1e9) return -1;

        return dist[dst];
    }
};