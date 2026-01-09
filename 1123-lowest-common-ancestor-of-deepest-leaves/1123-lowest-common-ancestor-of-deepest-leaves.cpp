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
    int depth(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        // maxd = max(maxd,currd);
        // mp[root->val] = currd;

        int l = depth(root->left);
        int r = depth(root->right);

        return max(l,r)+1;
    }

    TreeNode* lca(TreeNode* root, int currd){
        if(root == NULL || currd == maxd){
            return root;
        }

        TreeNode* l = lca(root->left,currd+1);
        TreeNode* r = lca(root->right,currd+1);

        if(l && r) return root;

        return l != NULL ? l : r;
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        maxd = depth(root);
        return lca(root,1);
    }
};