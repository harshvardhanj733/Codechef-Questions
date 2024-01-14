class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size())
            return false;

        map<char, int> m1;
        map<char, int> m2;

        for(int i = 0; i < word1.size(); i++){
            m1[word1[i]]++;
        }
        for(int i = 0; i < word2.size(); i++){
            if(m1[word2[i]] == 0){
                return false;
            }
            m2[word2[i]]++;
        }

        vector<int> v1;
        vector<int> v2;
        for(auto i: m1){
            if(i.second != 0){
                v1.push_back(i.second);
            }
        }
        for(auto i: m2){
            if(i.second != 0){
                v2.push_back(i.second);
            }
        }

        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());

        for(int i = 0; i < v1.size(); i++){
            if(v1[i] != v2[i]){
                return false;
            }
        }

        return true;
    }
};

//TC: O(n);
//SC: O(n);