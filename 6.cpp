class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1){
            return s;
        }
        vector<string> v(numRows);
        string res = "";
        int count = 0, flag = 1;
        for(int i = 0; i < s.size(); i++){
            v[count].push_back(s[i]);
            count += flag;
            if(count == 0){
                flag = 1;
            }
            else if(count == numRows - 1){
                flag = -1;
            }
        }
        for(auto i: v){
            for(int j = 0; j < i.size(); j++){
                res.push_back(i[j]);
            }
        }

        return res;
    }
};

//TC: O(n);
//SC: O(n);