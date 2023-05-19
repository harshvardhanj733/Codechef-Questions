class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string sample = strs[0];
        int a = 1; vector<char> res;
        for(int i = 0; i<sample.size(); i++){
            for(int j = 1; j<strs.size(); j++){
                if(strs[j].size()<i || strs[j][i]!=sample[i]){
                    a = 0;
                    break;
                }
            }
            if(a == 0){
                break;
            }
            else{
                res.push_back(sample[i]);
            }
        }
        if(res.size()!=0){
            char result[200];
            int i;
            for(i = 0; i<res.size(); i++){
                result[i] = res[i];
            }
            result[i] = '\0';
            return result;
        }
        else{
            return "";
        }
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)

// Used Brute Force Approach

// Further Enhancements Possible...including using a string algo approach