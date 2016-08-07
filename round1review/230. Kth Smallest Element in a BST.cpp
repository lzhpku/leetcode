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
    int ret = 0;
    int kthSmallest(TreeNode* root, int k) {
        count(root, k);
        return ret;
    }
    
    int count(TreeNode* root, int k) {
        if(root == NULL)
            return 0;
        int lc = count(root -> left, k);
        int rc = count(root -> right, k - lc - 1);
        if(k == lc + 1)
            ret = root -> val;
        return lc + rc + 1;
    }
};