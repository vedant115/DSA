class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        unordered_map<char, int> lastSeen;
        for(int i=0; i<n; i++){
            lastSeen[s[i]] = i;
        }

        int size = 0, end = -1;
        vector<int> res;
        for(int i=0; i<n; i++){
            if(end < lastSeen[s[i]]){
                end = lastSeen[s[i]];
            }
            if(i == end){
                res.push_back(size+1);
                size = -1;
            }
            size++;
        }
        return res;
    }
};