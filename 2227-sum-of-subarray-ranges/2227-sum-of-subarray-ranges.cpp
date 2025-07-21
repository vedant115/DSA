class Solution {
private:
    vector<int> findNSE(vector<int> &arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return ans;
    }
    
    vector<int> findPSEE(vector<int> &arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> findNGE(vector<int> &arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i]) st.pop();
            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return ans;
    }
    
    vector<int> findPGEE(vector<int> &arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) st.pop();
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }

public:
    long long subArrayRanges(vector<int> &arr) {
        vector<int> nse = findNSE(arr);
        vector<int> psee = findPSEE(arr);
        vector<int> nge = findNGE(arr);
        vector<int> pgee = findPGEE(arr);

        int n = arr.size(), mod = 1e9 + 7;
        long long sumS = 0, sumG = 0;

        for (int i = 0; i < n; i++) {
            int leftS = i - psee[i];
            int rightS = nse[i] - i;
            int leftG = i - pgee[i];
            int rightG = nge[i] - i;

            sumS += 1LL * leftS * rightS * arr[i];
            sumG += 1LL * leftG * rightG * arr[i];
            
        }
        return sumG-sumS;
    }
};