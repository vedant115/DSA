class StockSpanner {
private:
    stack<int> st;
    vector<int> prices;
public:
    StockSpanner() {
        st = stack<int>();
        prices = vector<int>();
    }
    
    int next(int price) {
        prices.push_back(price);
        while(!st.empty() && prices[st.top()] <= price){
            st.pop();
        }
        int count = st.empty() ? prices.size() : prices.size() - st.top() -1;
        st.push(prices.size()-1);
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */