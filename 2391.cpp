class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int G = 0, M = 0, P = 0, mG = 0, mM = 0, mP = 0;
        for(int i = 0; i < garbage[0].size(); i++){
            if(garbage[0][i] == 'G'){
                G++;
            }
            else if(garbage[0][i] == 'M'){
                M++;
            }
            else{
                P++;
            }
        }
        mG = G; mM = M; mP = P;

        for(int i = 1; i < garbage.size(); i++){
            int cG = 0, cM = 0, cP = 0;
            for(int j = 0; j < garbage[i].size(); j++){
                if(garbage[i][j] == 'G'){
                    cG++;
                }
                else if(garbage[i][j] == 'M'){
                    cM++;
                }
                else{
                    cP++;
                }
            }
            mG += travel[i-1] + cG;
            if(cG != 0){
                G = mG;
            }
            mM += travel[i-1] + cM;
            if(cM != 0){
                M = mM;
            }
            mP += travel[i-1] + cP;
            if(cP != 0){
                P = mP;
            }
        }
        return G+M+P;
    }
};

//TC: O(N^N.size());
//SC: O(1);