void solve(vector<string>& res, string temp, int i, string& s){
    if(i == s.size()){
        res.push_back(temp);
        return;
    }

    solve(res, temp, i+1, s);
    temp.push_back(s[i]);
    solve(res, temp, i+1, s);
}

vector<string> generateSubsequences(string s)
{
    // Write your code here.
    vector<string> res;
    string temp = "";
    solve(res, temp, 0, s);

    return res;
}

//TC: O(2^n);
//SC: O(n^2);