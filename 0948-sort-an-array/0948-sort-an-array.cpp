class Solution {
private:
    int partition(vector<int>& nums, int low, int high){
        int randInd = low + (rand() % (high - low + 1));
        swap(nums[high], nums[randInd]);
        int pivot = nums[high];

        int ind = low-1;
        for(int i=low; i<high; i++){
            if(nums[i] < pivot){
                ind++;
                swap(nums[i], nums[ind]);
            }
        }
        swap(nums[ind+1], nums[high]);

        return ind+1;
    }
    void quickSort(vector<int>& nums, int low, int high){
        if(low >= high) return;

        int pivot = partition(nums, low, high);

        quickSort(nums, low, pivot-1);
        quickSort(nums, pivot+1, high);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        quickSort(nums, 0, n-1);
        return nums;
    }
};