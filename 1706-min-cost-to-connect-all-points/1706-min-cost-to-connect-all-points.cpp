class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        // Array to track if a point is included in the MST
        vector<bool> visited(n, false);
        // Count of visited points
        int count = 0;
        // Total cost for MST
        long long totalCost = 0;
        
        // Min-heap: each element is a pair {cost, point_index}
        priority_queue<pair<long long, int>, vector<pair<long long,int>>, greater<pair<long long,int>>> minHeap;
        // Start with point 0 with a cost of 0
        minHeap.push({0, 0});
        
        while (!minHeap.empty() && count < n) {
            auto [cost, curr] = minHeap.top();
            minHeap.pop();
            
            // Skip if already visited
            if (visited[curr]) {
                continue;
            }
            
            // Add the cost and mark current point as visited
            totalCost += cost;
            visited[curr] = true;
            count++;
            
            // Update the distances (edge costs) for all points not in the MST yet
            for (int next = 0; next < n; ++next) {
                if (!visited[next]) {
                    long long nextCost = abs(points[curr][0] - points[next][0]) + abs(points[curr][1] - points[next][1]);
                    minHeap.push({nextCost, next});
                }
            }
        }
        
        return totalCost;
    }
};