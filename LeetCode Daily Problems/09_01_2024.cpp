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
    void inOrder(TreeNode* root, vector<int>& v){
        if(root == NULL){
            return;
        }

        inOrder(root->left, v);
        if(root->left == NULL && root->right == NULL){
            v.push_back(root->val);
        }
        inOrder(root->right, v);
    }

    bool isSimilar(vector<int>& v1, vector<int>& v2){
        if(v1.size() != v2.size()){
            return false;
        }
        for(int i = 0; i < v1.size(); i++){
            if(v1[i] != v2[i]){
                return false;
            }
        }
        return true;
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1; vector<int> v2;
        inOrder(root1, v1);
        inOrder(root2, v2);

        return isSimilar(v1, v2);
    }
};

//TC: O(n);
//SC: O(n);