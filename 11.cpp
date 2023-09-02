//Intuition: Try to reduce the problem's complexity from O(n^2). Maybe 2-pointer approach can be used in it since area needs to be calculated between 2 points.

//Approach: The shorter of the 2 points locks the height of the maximum area possible, hence it is useless to check for any other distance apart from the longest one. Hence, move the shorter point (out of i and j) to its right and left respectively and calculate the area again.

//Time Complexity: O(n)
//Space Complexity: O(1)

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size()-1;

        int max = 0;
        while(i<j){
            int area = min(height[i], height[j])*(j-i);
            (area > max)?max=area:max=max;
            (height[i]<=height[j]) ? i++ : j--;
        }

        return max;
    }
};