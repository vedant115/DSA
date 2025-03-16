class Solution {
private:
    bool isTimeSuff(vector<int>& ranks, int cars, long long time){
        long long carsRepaired = 0;
        for(auto r : ranks){
            long long c2 = time/r;
            long long c = floor(sqrt(c2));
            carsRepaired += c;
        }
        return carsRepaired >= cars;
    }
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long l = 1, r = 1e14;

        while(l < r){
            long long mid = (l+r)/2;
            if(isTimeSuff(ranks, cars, mid)){
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        return l;
    }
};