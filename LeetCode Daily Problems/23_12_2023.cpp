//Approach: The idea is to have an x and a y coordinate initally at 0, 0. There would be a map of visited coordinated which will be used to check whether a coordinate has been visited or not. Initally, we'll increase the value of the key having the coordinates 0, 0 to 1, indicating that it has been visited. Then, according to the path string, we'll update the x and y coordinates and check if it's visited. If yes, then we'll return true. If not, we'll mark the x and y coordinates as visited. If the loop ends, it means that there were no repeating coordinates. So, we'll return false.

class Solution {
public:
    bool isPathCrossing(string path) {
        map<pair<int, int>, int> m;
        int x = 0, y = 0;
        m[{0, 0}]++;

        for(int i = 0; i < path.size(); i++){
            if(path[i] == 'E'){
                x++;
            }
            else if(path[i] == 'W'){
                x--;
            }
            else if(path[i] == 'N'){
                y++;
            }
            else{
                y--;
            }

            if(m[{x, y}] == 1){
                return true;
            }
            m[{x, y}]++;
        }

        return false;
    }
};

//TC: O(n);
//SC: O(n);