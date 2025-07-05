class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int, int> mp;
        for(int num : arr){
            mp[num]++;
        }

        int res = -1;
        for(auto pair : mp){
            if(pair.first == pair.second){
                res = pair.first;
            }
        }
        return res;
    }
};