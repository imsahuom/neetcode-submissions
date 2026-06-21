class StockSpanner {
    vector<int> st;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        st.push_back(price);
        int r = st.size() - 1;
        int ans = 0;
        while (r >=0 && st[r] <= price){
            ans++;
            r--;
        }
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */