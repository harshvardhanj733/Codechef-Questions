class Solution {
public:
    string convertToTitle(int columnNumber) {
        string str = "";
        while(columnNumber != 0){
            int rem = columnNumber%26;
            if(rem == 0){
                str.push_back('Z');
                columnNumber = columnNumber/26 - 1;
            }
            else{
                char column = (char)'A' - 1 + rem;
                str.push_back(column);
                columnNumber = columnNumber/26;
            }
        }

        reverse(str.begin(), str.end());

        return str;
    }
};