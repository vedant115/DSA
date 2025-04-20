class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> uniqRabbits;
        int res = 0;
        for(int num : answers){
            if(num == 0){
                res++;
                continue;
            }
            uniqRabbits[num]++;
        }

        for(auto& rabbit : uniqRabbits){
            if(rabbit.second > rabbit.first+1){
                res += ((rabbit.second / (rabbit.first+1))*(rabbit.first+1));
                if(rabbit.second % (rabbit.first+1) > 0)
                    res += (rabbit.first+1);
            }
            else
                res += rabbit.first+1;
        }
        return res;
    }
};