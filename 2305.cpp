class Solution {
public:

    int solve(vector<int> cookies, vector<int>& distribution, int k, int index){
        if(index == cookies.size()){
            int maxi = 0;
            for(int i = 0; i < k; i++){
                maxi = max(maxi, distribution[i]);
            }
            return maxi;
        }

        int ans = INT_MAX;
        for(int i = 0; i < k; i++){
            distribution[i] += cookies[index];
            vector<int> temp;
            ans = min(ans, solve(cookies, distribution, k, index+1));
            distribution[i] -= cookies[index];
            if(distribution[i] == 0){
                break;
            }
        }

        return ans;
    }

    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> distribution(k, 0);
        return solve(cookies, distribution, k, 0);
    }
};