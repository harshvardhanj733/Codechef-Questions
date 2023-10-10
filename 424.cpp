class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char, int> freq;
        int firstPointer = 0, secondPointer = 0;
        int maxFreq = 0, maxLength = -1;

        while(secondPointer < s.size()){
            freq[s[secondPointer]]++;
            maxFreq = max(maxFreq, freq[s[secondPointer]]);
            
            if((secondPointer-firstPointer+1) - maxFreq > k){
                freq[s[firstPointer]]--;
                firstPointer++;
            }

            int length = secondPointer-firstPointer+1;
            maxLength = max(length, maxLength);
            secondPointer++;
        }

        return maxLength;
    }
};

//Time Complexity: O(n);
//Space Complexity: O(26);