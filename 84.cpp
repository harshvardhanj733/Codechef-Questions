//Approach: Step 1: Find the INDEXES of NextMin and PrevMin for each element of the array using stacks
        //  Step 2: For each element of the array, it's biggest area can be found by heights[i]*(next[i]-prev[i]-1);

class Solution {
public:

    void findNextMin(vector<int> heights, vector<int>& next){
        stack<pair<int, int>> st;
        pair<int, int> temp;
        temp.first = -1;
        temp.second = heights.size();
        st.push(temp);

        for(int i = heights.size()-1; i>=0; i--){
            while(st.top().first >= heights[i]){
                st.pop();
            }
            next[i] = st.top().second;
            temp.first = heights[i];
            temp.second = i;
            st.push(temp);
        }
    }

    void findPrevMin(vector<int> heights, vector<int>& prev){
        stack<pair<int, int>> st;
        pair<int, int> temp;
        temp.first = -1;
        temp.second = -1;
        st.push(temp);

        for(int i = 0; i<heights.size(); i++){
            while(st.top().first >= heights[i]){
                st.pop();
            }
            prev[i] = st.top().second;
            temp.first = heights[i];
            temp.second = i;
            st.push(temp);
        }
    }

    int result(vector<int> heights, vector<int> prev, vector<int> next){
        int maxArea = 0;
        for(int i = 0; i<heights.size(); i++){
            int area = heights[i] * (next[i]-prev[i]-1);
            maxArea = max(area, maxArea);
        }

        return maxArea;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> prev(heights.size());
        vector<int> next(heights.size());

        findPrevMin(heights, prev);
        findNextMin(heights, next);

        return result(heights, prev, next);
    }
};

// Time Complexity: O(n);
// Space Complexity: O(n);
