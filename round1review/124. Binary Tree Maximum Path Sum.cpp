/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int ret;
    int maxPathSum(TreeNode* root) {
        ret = INT_MIN;
        dfs(root);
        return ret;
    }
    
    int dfs(TreeNode* root) {
        if(root == NULL)
            return 0;
        int left = max(0, dfs(root -> left));
        int right = max(0, dfs(root -> right));
        ret = max(ret, left + right + root -> val);
        return max(left, right) + root -> val;
    }
};