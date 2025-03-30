class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gasInTank = 0, gasBalance = 0;
        int start = 0;
        for(int i=0; i<gas.size(); i++){
            gasInTank += (gas[i] - cost[i]);
            gasBalance += (gas[i] - cost[i]);

            if(gasInTank < 0){
                gasInTank = 0;
                start = i+1;
            }
        }
        return gasBalance >= 0 ? start : -1;
    }
};