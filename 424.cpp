class Solution {
public:
    int characterReplacement(string s, int k) {
        // map<char, int> freq;
        // int firstPointer = 0, secondPointer = 0;
        // int maxFreq = 0, maxLength = -1;

        // while(secondPointer < s.size()){
        //     freq[s[secondPointer]]++;
        //     maxFreq = max(maxFreq, freq[s[secondPointer]]);
            
        //     if((secondPointer-firstPointer+1) - maxFreq > k){
        //         freq[s[firstPointer]]--;
        //         firstPointer++;
        //     }

        //     int length = secondPointer-firstPointer+1;
        //     maxLength = max(length, maxLength);
        //     secondPointer++;
        // }

        // return maxLength; 


        int l = 0, r = 0, maxF = 0, len  = 0;
        map<int, int> count;

        while(r < s.size()){
            count[s[r]]++;
            maxF = max(maxF, count[s[r]]);
            if(r - l + 1 - maxF <= k){
                len = max(len, r - l + 1);
            }
            else{
                while(r - l + 1 - maxF > k){
                    count[s[l]]--;
                    // maxF = 0;
                    // for(auto i: count){
                    //     maxF = max(maxF, i.second);
                    // }
                    l++;
                }
            }
            r++;
        }

        return len;
    }
};

//TC: O(N);
//SC: O(26);