class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> res(2);
        vector<int> v0; vector<int> v1;
        unordered_map<int, int> m;
        for(int i = 0; i < matches.size(); i++){
            if(m.find(matches[i][0]) == m.end()){
                m[matches[i][0]] = 0;
            }
            m[matches[i][1]]++;
        }

        for(auto i: m){
            if(i.second == 0){
                v0.push_back(i.first);
            }
            else if(i.second == 1){
                v1.push_back(i.first);
            }
        }

        sort(v0.begin(), v0.end());
        sort(v1.begin(), v1.end());
        
        res[0] = v0; res[1] = v1;
        return res;
    }
};

//TC: O(nlogn); (because of sorting)
//SC: O(n);