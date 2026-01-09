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
    int maxd = 0;
    unordered_map<int,int> mp;
    void depth(TreeNode* root, int currd){
        if(root == NULL){
            return;
        }
        maxd = max(maxd,currd);
        mp[root->val] = currd;

        depth(root->left,currd+1);
        depth(root->right,currd+1);

    }

    TreeNode* lca(TreeNode* root){
        if(root == NULL || mp[root->val] == maxd){
            return root;
        }

        TreeNode* l = lca(root->left);
        TreeNode* r = lca(root->right);

        if(l && r) return root;

        return l != NULL ? l : r;
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        depth(root,0);
        return lca(root);
    }
};