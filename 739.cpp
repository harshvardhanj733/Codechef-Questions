class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size());
        stack<int> s;

        for(int i = temperatures.size()-1; i >= 0; i--){
            while(!s.empty() && temperatures[i] >= temperatures[s.top()]){
                s.pop();
            }

            if(s.empty()){
                res[i] = 0;
            }
            else{
                res[i] = s.top() - i;
            }

            s.push(i);
        }

        return res;
    }
};