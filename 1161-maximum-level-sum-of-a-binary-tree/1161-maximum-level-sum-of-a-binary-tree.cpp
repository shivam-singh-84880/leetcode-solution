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
    int find(TreeNode* root){
        int maxsum=INT_MIN;
        queue<TreeNode*> q;
        q.push(root);
        int currlev=0;
        int lev=0;

        while(!q.empty()){
            int n = q.size();
            int sum = 0;
            currlev++;
            for(int i=0; i<n; i++){
                TreeNode* data = q.front();
                q.pop();
                sum += data->val;
                if(data->left){
                    q.push(data->left);
                }
                if(data->right){
                    q.push(data->right);
                }
            }
            if(sum > maxsum){
                maxsum = sum;
                lev = currlev;
            }
        }

        return lev;
    }

    int maxLevelSum(TreeNode* root) {
        return find(root);
    }
};