class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(), col = matrix[0].size(), mid;
        int start = 0, end = row*col-1, row_ind, col_ind;

        while(start<=end){
            mid=end+(start-end)/2;
            row_ind = mid/col;
            col_ind = mid%col;

            if(matrix[row_ind][col_ind] == target){
                return true;
            }
            else if(matrix[row_ind][col_ind] < target){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return false;
    }
};