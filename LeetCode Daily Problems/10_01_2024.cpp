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
    void findParent(TreeNode* root, map<TreeNode*, TreeNode*>& parent){
        if(root == NULL){
            return;
        }
        if(root->left){
            parent[root->left] = root;
        }
        if(root->right){
            parent[root->right] = root;
        }
        findParent(root->left, parent);
        findParent(root->right, parent);
    }

    TreeNode* findStart(TreeNode* root, int start){
        if(root == NULL){
            return NULL;
        }

        if(root->val == start){
            return root;
        }

        TreeNode* left = findStart(root->left, start);
        TreeNode* right = findStart(root->right, start);

        if(left){
            return left;
        }
        if(right){
            return right;
        }

        return NULL;
    }

public:
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*, TreeNode*> parent;
        parent[root] = NULL;
        findParent(root, parent);
        TreeNode* startNode = findStart(root, start);

        queue<pair<TreeNode*, int>> findTime;
        findTime.push({startNode, 0});
        int time = 0;

        map<int, bool> isInfected;
        isInfected[startNode->val] = true;

        while(!findTime.empty()){
            pair<TreeNode*, int> p = findTime.front();
            TreeNode* n = p.first;
            int t = p.second;

            if(n->left && !isInfected[n->left->val]){
                findTime.push({n->left, t+1});
                time = max(time, t+1);
                isInfected[n->left->val] = true;
            }
            if(n->right && !isInfected[n->right->val]){
                findTime.push({n->right, t+1});
                time = max(time, t+1);
                isInfected[n->right->val] = true;
            }

            if(parent[n] != NULL && !isInfected[parent[n]->val]){
                findTime.push({parent[n], t+1});
                time = max(time, t+1);
                isInfected[parent[n]->val] = true;
            }

            findTime.pop();
        }

        return time;
    }
};

//TC: O(n);
//SC: O(n);