class Solution {
public:

    void soln(string temp, set<string> & s, int index, int count, int n){
        if(index == n){
            // temp.push_back('(');
            // temp.push_back(')');
            // count++;
            while(count < n){
                temp.push_back(')');
                count++;
            }
            s.insert(temp);
            return;
        }

        //handling '(' insertion
        temp.push_back('(');
        soln(temp, s, index+1, count, n);
        
        //handling ')' insertion
        temp.pop_back();
        if(count < index){
            temp.push_back(')');
            soln(temp, s, index, count+1, n);
        }

    }

    vector<string> generateParenthesis(int n) {
        set<string> s;
        int count = 0, index = 1;
        string temp = "(";

        soln(temp, s, index, count, n);

        vector<string> res;
        for(auto i : s){
            res.push_back(i);
        }

        return res;
    }
};