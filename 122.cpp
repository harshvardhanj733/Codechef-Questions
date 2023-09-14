class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum = 0;
        int temp = 0;
        for(int i = 0; i<prices.size()-1; i++){
            int oldTemp = temp;
            temp += prices[i+1]-prices[i];
            if(oldTemp > temp){
                sum += oldTemp;
                temp = 0;
            }
        }
        sum += temp;

        return sum;
    }
};

//Time Complexity: O(n);
//Space Complexity: O(1);