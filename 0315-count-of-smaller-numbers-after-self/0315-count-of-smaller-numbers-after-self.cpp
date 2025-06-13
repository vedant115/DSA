class Solution {
private:
    void merge(vector<pair<int, int>>& nums, int low, int mid, int high, vector<int>& res){
        int left = low, right = mid+1;

        vector<pair<int, int>> temp;
        while(left <= mid && right <= high){
            if(nums[left].first <= nums[right].first){
                temp.push_back(nums[right]);
                right++;
            }
            else{
                res[nums[left].second] += high-right+1;
                temp.push_back(nums[left]);
                left++;
            }
        }

        while(left <= mid){
            temp.push_back(nums[left]);
            left++;
        }

        while(right <= high){
            temp.push_back(nums[right]);
            right++;
        }

        for(int i=low; i<=high; i++){
            nums[i] = temp[i-low];
        }
    }
    void mergeSortHelper(vector<pair<int, int>>& nums, int low, int high, vector<int>& res){
        if(low >= high) return;

        int mid = (low + high)/2;
        mergeSortHelper(nums, low, mid, res);
        mergeSortHelper(nums, mid+1, high, res);
        merge(nums, low, mid, high, res);
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();

        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
            v.push_back({nums[i], i});

        vector<int> res(n, 0);
        mergeSortHelper(v, 0, n-1, res);

        return res;
    }
};