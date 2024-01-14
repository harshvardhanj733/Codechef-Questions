class Solution {
public:
    int minSteps(string s, string t) {
        map<char, int> m;
        for(int i = 0; i < s.size(); i++){
            m[s[i]]--;
        }
        for(int i = 0; i < t.size(); i++){
            m[t[i]]++;
        }
        int sum = 0;
        for(auto i: m){
            if(i.second < 0){
                sum -= i.second;
            }
        }

        return sum;
    }
};

//TC: O(n);
//SC: O(n);