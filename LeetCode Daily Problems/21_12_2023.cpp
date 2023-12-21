//Problem No 1637 - Widest Vertical Area Between Two Points Containing No Points

//Approach: In this problem, essentially we just need to find the maximum width between any 2 sets of points. So we are sorting the points according to their x coordinates and calculating the maximum width between any 2 consecutive points and returning it.

class Solution {
private:
    static bool cmp(vector<int> p1, vector<int> p2){
        if(p1[0] != p2[0]){
            return p1[0] < p2[0];
        }
        return p1[1] < p2[1];
    }
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cmp);
        int res = 0;
        for(int i = 0; i < points.size() - 1; i++){
            res = max(res, points[i+1][0] - points[i][0]);
        }
        return res;
    }
};

//TC: O(nlogn);
//SC: O(1);