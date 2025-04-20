class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> freq;
        int res = 0;
        
        for(int ans : answers) {
            freq[ans]++;
        }

        for(auto& [k, count] : freq) {
            int groupSize = k + 1;
            int groups = (count + groupSize - 1) / groupSize;  // ceiling division
            res += groups * groupSize;
        }

        return res;
    }
};
