class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int left = 1, right = *max_element(candies.begin(), candies.end());

        while(left <= right){
            int mid = (left + right)/2;

            long long children_count = 0;
            for(int pile : candies){
                children_count += (pile/mid);
            }

            if(children_count >= k){
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        return right;
    }
};