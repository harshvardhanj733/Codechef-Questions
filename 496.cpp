class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        stack<int> s;
        map<int, int> m;

        for(int i = nums2.size()-1; i >= 0; i--){
            while(!s.empty() && nums2[i] >= s.top()){
                s.pop();
            }
            if(s.empty()){
                m[nums2[i]] = -1;
            }
            else{
                m[nums2[i]] = s.top();
            }

            s.push(nums2[i]);
        }

        for(int i = 0; i<nums1.size(); i++){
            res.push_back(m[nums1[i]]);
        }

        return res;
    }
};

//Time Complexity: O(nums1.size() + nums2.size());
//Space Complexity: O(nums1.size() + nums2.size());