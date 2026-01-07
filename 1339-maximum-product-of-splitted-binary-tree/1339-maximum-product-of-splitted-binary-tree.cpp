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
    long maxp = INT_MIN;

    long sumfind(TreeNode* root){
        if(root == NULL) return 0;

        int l = sumfind(root->left);
        int r = sumfind(root->right);

        return l + r + root->val;
    }

    long find(TreeNode* root, long sum){
        if(root == NULL)return 0;
        int l = find(root->left, sum);
        int r = find(root->right, sum);
        long s1 = l + r + root->val;
        long s2 = sum - s1;
        maxp = max(maxp,s1*s2);
        return s1;
    }

    int maxProduct(TreeNode* root) {
        long sum = sumfind(root);
        int mod = 1e9+7;
        find(root,sum);
        return maxp%mod;
    }
};