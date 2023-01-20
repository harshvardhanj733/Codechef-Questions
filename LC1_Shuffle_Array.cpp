// 1470. Shuffle the Array

// Given the array nums consisting of 2n elements in the form [x1,x2,...,xn,y1,y2,...,yn].

// Return the array in the form [x1,y1,x2,y2,...,xn,yn].

// Solution 1
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> nums_final; //O(3n)
        int j = 0, k = n;
        // for(int i = 0; i<n; i++){ //O(n)
        //     nums2.push_back(nums[i]);
        // }
        // for(int i = n; i<2*n; i++){ //O(n)
        //     nums3.push_back(nums[i]);
        // }
        for(int i = 0; i<2*n; i++){ //O(2n)
            if(i%2==0){
                nums_final.push_back(nums[j]);
                j++;
            }
            else{
                nums_final.push_back(nums[k]);
                k++;
            }
        }
        return nums_final;
    }
};

// Solution 2
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> nums2, nums3, nums_final;
        int j = 0, k = 0;
        for(int i = 0; i<n; i++){
            nums2.push_back(nums[i]);
        }
        for(int i = n; i<2*n; i++){
            nums3.push_back(nums[i]);
        }
        for(int i = 0; i<2*n; i++){
            if(i%2==0){
                nums_final.push_back(nums2[j]);
                j++;
            }
            else{
                nums_final.push_back(nums3[k]);
                k++;
            }
        }
        return nums_final;
    }
};