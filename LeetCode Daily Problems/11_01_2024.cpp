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
private:
    vector<int> solve(TreeNode* root){
        if(root == NULL){
            return {0, INT_MIN, INT_MAX};
        }

        vector<int> v1 = solve(root->left);
        vector<int> v2 = solve(root->right);

        int maxi = max(root->val, max(v1[1], v2[1]));
        int mini = min(root->val, min(v1[2], v2[2]));

        int diff1 = 0, diff2 = 0, diff3 = 0, diff4 = 0;
        if(v1[1] != INT_MIN){
            diff1 = abs(root->val - v1[1]);
        }
        if(v1[2] != INT_MAX){
            diff2 = abs(root->val - v1[2]);
        }
        if(v2[1] != INT_MIN){
            diff3 = abs(root->val - v2[1]);
        }
        if(v2[2] != INT_MAX){
            diff4 = abs(root->val - v2[2]);
        }

        int diff = max(max(diff1, diff2), max(diff3, diff4));
        int maxDiff = max(diff, max(v1[0], v2[0]));

        return {maxDiff, maxi, mini};
    }

    //TC: O(n);
    //TC: O(n);
public:
    int maxAncestorDiff(TreeNode* root) {
        vector<int> v = solve(root);
        return v[0];
    }
};