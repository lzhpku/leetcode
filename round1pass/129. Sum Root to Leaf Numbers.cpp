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
    int sumNumbers(TreeNode* root) {
        return getsum(root, 0);
    }
    
    int getsum(TreeNode* root, int sum) {
        if(root == NULL)
            return 0;
        if(root -> left == NULL && root -> right == NULL)
            return sum + root -> val;
        sum += root -> val;
        return getsum(root -> left, sum * 10) + getsum(root -> right, sum * 10);
    }
};