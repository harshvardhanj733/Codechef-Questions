vector<int> bitManipulation(int num, int i){
    // Write your code here.
    vector<int> res;
    int num1 = 0, num2 = 0;
    for(int j = 1; j <= 32; j++){
        if(j == i){
            res.push_back(num&1);
            num1 += pow(2, j-1);
        }
        else if(num&1){
            num1 += (int)pow(2, j-1);
            num2 += (int)pow(2, j-1);
        }
        num >>= 1;
    }
    res.push_back(num1);
    res.push_back(num2);

    return res;
}

//TC: O(1);
//SC: O(n);