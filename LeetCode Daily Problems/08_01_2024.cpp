/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root == NULL){
            return 0;
        }

        int data = 0, left = 0, right = 0;
        if(root->val >= low && root->val <= high){
            data = root->val;
        }
        if(root->val > low){
            left = rangeSumBST(root->left, low, high);
        }
        if(root->val < high){
            right = rangeSumBST(root->right, low, high);
        }

        return data + left + right;
    }

    //TC: O(n);
    //SC: O(1);
};