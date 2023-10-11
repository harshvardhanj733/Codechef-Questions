class StockSpanner {
    stack<pair<int, int>> s;
    int count;
    pair<int, int> temp;
public:
    StockSpanner() {
        count = 0;
    }
    
    int next(int price) {
        count += 1;
        temp.first = price;
        temp.second = count;
        while(!s.empty() && temp.first >= s.top().first){
            s.pop();
        }

        int ans;
        if(s.empty()){
            ans = temp.second;
        }
        else{
            ans = temp.second - s.top().second;
        }

        s.push(temp);

        return ans;

    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */