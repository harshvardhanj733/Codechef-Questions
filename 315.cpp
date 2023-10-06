class Solution {
public:

    void merge(vector<pair<int, int>>& temp, map<int, int>& m, int low, int mid, int high){
        int i = low, j = mid+1;
        for(i = low; i <= mid; i++){
            while(j<=high && temp[i].first > temp[j].first){
                j++;
            }
            m[temp[i].second] += j-(mid+1);
        }

        i = low, j = mid+1;
        vector<pair<int, int>> t;
        while(i<= mid && j<= high){
            if(temp[i].first <= temp[j].first){
                t.push_back(temp[i]);
                i++;
            }
            else{
                t.push_back(temp[j]);
                j++;
            }
        }
        while(i<=mid){
            t.push_back(temp[i]);
            i++;
        }
        while(j<=high){
            t.push_back(temp[j]);
            j++;
        }

        for(int k = low; k<=high; k++){
            temp[k] = t[k-low];
        }

    }

    void divide(vector<pair<int,int>>& temp, map<int, int>& m, int low, int high){
        if(low<high){
            int mid = low + (high-low)/2;
            divide(temp, m, low, mid);
            divide(temp, m, mid+1, high);
            merge(temp, m, low, mid, high);
        }
    }

    vector<int> countSmaller(vector<int>& nums) {
        map<int, int> m;
        vector<pair<int, int>> temp;

        for(int i = 0; i<nums.size(); i++){
            pair<int, int> input = make_pair(nums[i], i);
            temp.push_back(input);
        }

        divide(temp, m, 0, nums.size()-1);

        vector<int> res;
        for(int i = 0; i < nums.size(); i++){
            res.push_back(m[i]);
        }

        return res;
    }
};

//Time Complexity: O(nlogn);
//Space Complexity: O(n);