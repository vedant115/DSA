class NumArray {
public:
    int n;
    vector<int> bit;
    vector<int> nums;

    NumArray(vector<int>& input) {
        n = input.size();
        bit.assign(n + 1, 0);
        nums = input;

        for (int i = 0; i < n; ++i) {
            add(i, nums[i]);
        }
    }

    void add(int index, int val) {
        for (++index; index <= n; index += (index & -index)) {
            bit[index] += val;
        }
    }

    void update(int index, int val) {
        int delta = val - nums[index];
        nums[index] = val;
        add(index, delta);
    }

    int prefixSum(int index) {
        int res = 0;
        for (++index; index > 0; index -= (index & -index)) {
            res += bit[index];
        }
        return res;
    }

    int sumRange(int left, int right) {
        return prefixSum(right) - prefixSum(left - 1);
    }
};