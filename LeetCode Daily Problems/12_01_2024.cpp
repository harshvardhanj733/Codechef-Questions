class Solution {
private:
    bool isVowel(char c){
        c = tolower(c);
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
            
    }
public:
    bool halvesAreAlike(string s) {
        int i = 0, j = s.size()-1;
        int count1 = 0, count2 = 0;
        while(i < j){
            if(isVowel(s[i])){
                count1++;
            }
            if(isVowel(s[j])){
                count2++;
            }
            i++; j--;
        }

        return count1 == count2;
    }
};

//TC: O(n);
//SC: O(1);