class Solution {
private:
    int calcDaysReq(vector<int>& weights, int weight){
        int n = weights.size();
        int days = 1;
        int currWeight = 0;
        for(int i=0; i<n; i++){
            if(currWeight + weights[i] <= weight){
                currWeight += weights[i];
            }
            else{
                days++;
                currWeight = weights[i];
            }
        }
        return days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while(low <= high){
            int mid = (low + high)/2;
            int daysReq = calcDaysReq(weights, mid);
            if(daysReq > days){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return low;
    }
};