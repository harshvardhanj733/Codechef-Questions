//Approach: Take 2 values leftScore and rightScore. First find out the number of 1's in the right substring consisting of all the elements except the first element and store it in rightScore. In the leftScore, store 1 if the first element is 0, otherwise 0. Compare the sum of leftScore and rightScore with the max value. Now, iterate over the string s from the 2nd element until the 2nd last element. If s[i] is 0, it means that we are adding a 0 to the left substring, so we'll add 1 to the leftScore and now compare leftScore + rightScore to the max value. But if s[i] is 1, it means we are subtracting from the right subarray, so we'll subtract 1 from the rightScore. Again we'll compare the sum of leftScore and the rightScore with the max value. Finally, after the iteration ends, return the max value.

class Solution {
public:
    int maxScore(string s) {
        int leftScore = 0, rightScore = 0, maxi = 0;
        if(s[0] == '0'){leftScore++;}
        for(int i = 1; i < s.size(); i++){
            if(s[i] == '1'){rightScore++;}
        }
        maxi = max(maxi, (rightScore + leftScore));

        for(int i = 1; i < s.size() - 1; i++){
            if(s[i] == '1'){
                rightScore--;
                maxi = max(maxi, (rightScore + leftScore));
            }
            else{
                leftScore++;
                maxi = max(maxi, (rightScore + leftScore));
            }
        }

        return maxi;
    }
};

//TC: O(n);
//SC: O(1);