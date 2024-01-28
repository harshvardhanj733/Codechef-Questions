class Solution {
private:
    vector<int> temp;
    int findLocal(vector<int>& nums){
        int ans = 0;
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] > nums[i+1]){
                ans++;
            }
        }
        return ans;
    }

    long long merge(vector<int>& nums, int l, int mid, int r){
        long long ans = 0;
        int i = l, j = mid+1;
        while(i <= mid && j <= r){
            if(nums[i] > nums[j]){
                ans += 1LL*(mid-i+1);
                j++;
            }
            else{
                i++;
            }
        }

        i = l, j = mid+1;
        temp.clear();
        while(i <= mid && j <= r){
            if(nums[i] <= nums[j]){
                temp.push_back(nums[i]);
                i++;
            }
            else{
                temp.push_back(nums[j]);
                j++;
            }
        }
        while(i <= mid){
            temp.push_back(nums[i]);
            i++;
        }
        while(j <= r){
            temp.push_back(nums[j]);
            j++;
        }

        for(int k = 0; k < temp.size(); k++){
            nums[k+l] = temp[k];
        }

        return ans;
    }

    long long findGlobal(vector<int>& nums, int l, int r){
        if(l >= r){
            return 0;
        }
        int mid = l + (r - l)/2;
        long long a = findGlobal(nums, l, mid);
        long long b = findGlobal(nums, mid+1, r);

        return a + b + merge(nums, l, mid, r);
    }

public:
    bool isIdealPermutation(vector<int>& nums) {
        int localInversion = findLocal(nums);
        int globalInversion = findGlobal(nums, 0, nums.size()-1);

        return localInversion == globalInversion;
    }
};


//TC: O(nlogn);
//SC: O(n);