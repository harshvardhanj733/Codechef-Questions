class Solution {
public:
    int myAtoi(string s) {
        long long res = 0;
        bool signFlag = true;
        bool signDone = false;

        int i = 0;
        while(i < s.size()){
            if(s[i] == '-'){
                if(!signDone){
                    signFlag = false;
                    signDone = true;
                }
                else{
                    return 0;
                }
            }
            else if(s[i] == '+'){
                if(!signDone){
                    signFlag = true;
                    signDone = true;
                }
                else{
                    return 0;
                }
            }
            else if(s[i] >= '0' && s[i] <= '9'){
                while(i < s.size() && s[i] >= '0' && s[i] <= '9'){
                    if(INT_MAX/10 < res){
                        if(!signFlag){
                            return INT_MIN;
                        }
                        return INT_MAX;
                    }
                    res *= 10;
                    res += (int)(s[i] - '0');
                    i++;
                }
                if(signFlag){
                    return res > INT_MAX ? INT_MAX : res;
                }
                return res*-1 < INT_MIN ? INT_MIN : res*-1;
            }
            else if(s[i] != ' ' || (s[i] == ' ' && signDone)){
                return 0;
            }
            i++;
        }

        return 0;
    }
};