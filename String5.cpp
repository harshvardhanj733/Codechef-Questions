class Solution {
public:
    bool pass = false;
    bool validPalindrome(string s) {
        int left =0, right = s.size()-1; bool check = true;
        while(left < right){
            if(s[left] == s[right]){
                left++; right--;
            }
            else if(!pass){
                pass = true;
                check = validPalindrome(s.substr(left, right-left)) || validPalindrome(s.substr(left+1, right - left));
                break;
            }
            else{
                check = false;
                break;
            }
        }
        return check;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)