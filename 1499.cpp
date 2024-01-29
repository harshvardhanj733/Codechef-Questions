class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int n = points.size();
        int maxi = INT_MIN;
        
        int i = 0, j = 1;
        while(j < n){
            int diff = points[j][0] - points[i][0];
            if(diff <= k && (points[i][1]-points[i][0] > points[j][1]-points[j][0])){
                maxi = max(maxi, diff+points[i][1]+points[j][1]);
                j++;
            }
            else if(diff <= k){
                maxi = max(maxi, diff+points[i][1]+points[j][1]);
                i = j;
                j++;
            }
            else{
                i++;
                j = i+1;
            }
        }

        return maxi;
    }
};

//TC: O(n);
//SC: O(1);