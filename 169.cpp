class Solution {
    public int majorityElement(int[] nums) {
        int count = 1, candidate = nums[0];
        for(int i = 1; i<nums.length; i++){
            if(count == 0){
                count++;
                candidate = nums[i];
            }
            else if(nums[i] == candidate){
                count++;
            }
            else{
                count--;
            }
        }
        return candidate;
    }
}

//Moore Voting Algorithm

//Time Complexity: O(N);
//Space Complexity: O(1);