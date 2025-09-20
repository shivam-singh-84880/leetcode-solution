class StockSpanner {
    stack<pair<int,int>> st;
    int ind = 0;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        ind++;
        while(!st.empty() && st.top().first <= price){
            st.pop();
        }
        int ans = !st.empty() ? ind - st.top().second : ind;
        st.push({price,ind});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */