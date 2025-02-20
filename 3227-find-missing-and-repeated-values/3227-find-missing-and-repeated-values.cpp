class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();

        int xr = 0;
        for(int i=0; i<n*n; i++){
            xr ^= grid[i/n][i%n];
            xr ^= (i+1);
        }

        int firstSetBit = (xr & ~(xr - 1));
        int num1 = 0, num2 = 0;
        for(int i=0; i<n*n; i++){
            if((grid[i/n][i%n] & firstSetBit) != 0){
                num1 ^= grid[i/n][i%n];
            }
            else{
                num2 ^= grid[i/n][i%n];
            }
            if(((i+1) & firstSetBit) != 0){
                num1 ^= (i+1);
            }
            else{
                num2 ^= (i+1);
            }
        }

        int cnt = 0;
        for(int i=0; i<n*n; i++){
            if(grid[i/n][i%n] == num1) cnt++;
        }

        if(cnt == 2){
            return {num1, num2};
        }
        return {num2, num1};
    }
};