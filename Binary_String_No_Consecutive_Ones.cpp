void solve(vector<string>& res, string str, int N){
    if(N == 0){
        res.push_back(str);
        return;
    }

    str.push_back('0');
    solve(res, str, N-1);
    str.pop_back();
    if(str.size() == 0 || str[str.size() - 1] == '0'){
        str.push_back('1');
        solve(res, str, N-1);
    }
}

vector<string> generateString(int N) {
    // Write your code here.
    vector<string> res;
    string str = "";
    solve(res, str, N);
    return res;
}

//TC: O(2^n);
//SC: O(n*2^n);