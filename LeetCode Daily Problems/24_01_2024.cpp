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
    int solve(TreeNode* root, map<int, int>& m){
        if(root == NULL){
            return 0;
        }
        if(root->left == NULL && root->right == NULL){
            m[root->val]++;
            bool isOdd = false;
            for(auto i: m){
                if((i.second&1) && isOdd){
                    m[root->val]--;
                    return 0;
                }
                else if(i.second&1){
                    isOdd = true;
                }
            }
            m[root->val]--;
            return 1;
        }
        m[root->val]++;
        int ans =  solve(root->left, m) + solve(root->right, m);
        m[root->val]--;

        return ans;
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        map<int, int> m;
        return solve(root, m);
    }
};

//TC: O(n);
//SC: O(1); //since the size of the map is fixed (9)