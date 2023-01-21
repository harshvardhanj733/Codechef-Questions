// 2303. Calculate Amount Paid in Taxes

// You are given a 0-indexed 2D integer array brackets where brackets[i] = [upperi, percenti] means that the ith tax bracket has an upper bound of upperi and is taxed at a rate of percenti. The brackets are sorted by upper bound (i.e. upperi-1 < upperi for 0 < i < brackets.length).

// Tax is calculated as follows:

// The first upper0 dollars earned are taxed at a rate of percent0.
// The next upper1 - upper0 dollars earned are taxed at a rate of percent1.
// The next upper2 - upper1 dollars earned are taxed at a rate of percent2.
// And so on.
// You are given an integer income representing the amount of money you earned. Return the amount of money that you have to pay in taxes. Answers within 10-5 of the actual answer will be accepted.

// Solution 1

class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double tax = 0; int i = 0, prev = 0;
        int t = 1;
        while(t){
            if(income + prev - brackets[i][0] > 0){
                tax += (double)(brackets[i][0] - prev)*brackets[i][1]/100;
                income -= brackets[i][0] - prev;
                prev = brackets[i][0];
                i++;
            }
            else{
                tax += (double)income*brackets[i][1]/100;
                break;
            }
        }
        return tax;
    }
};

// Total Time Complexity : O(brackets.length);
// Total Space Complexity : O(1);

// Solution 2

class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double tax = 0; int i = 0, prev = 0;
        while(income>=0){
            if(income + prev - brackets[i][0] > 0){
                tax += (double)(brackets[i][0] - prev)*brackets[i][1]/100;
                income -= brackets[i][0] - prev;
                prev = brackets[i][0];
                i++;
            }
            else{
                tax += (double)income*brackets[i][1]/100;
                break;
            }
        }
        return tax;
    }
};

// Total Time Complexity : O(brackets.length);
// Total Space Complexity : O(1);
