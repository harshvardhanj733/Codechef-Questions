//Approach: We are checking for both the cases, if the string starts with 0 or if it starts with 1, and then returning the one which requires the least number of changes in the string to make it alternate.

class Solution {
public:
    int minOperations(string s) {
        int zeroFirst = 0, oneFirst = 0;
        for(int i = 0; i < s.size(); i++){
            if((i&1) && s[i] == '0'){
                zeroFirst++;
            }
            else if(!(i&1) && s[i] == '1'){
                zeroFirst++;
            }
        }

        oneFirst = s.size() - zeroFirst;
        return min(zeroFirst, oneFirst);
    }
};

//TC: O(n);
//SC: O(1);