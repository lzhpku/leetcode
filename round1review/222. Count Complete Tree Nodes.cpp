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
    int countNodes(TreeNode* root) {
        if(root == NULL)
            return 0;
        if(root -> left == NULL)
            return 1;
        int h = 0, sum = 0;
        TreeNode* cur = root;
        while(cur -> left != NULL) {
            sum += (1 << h);
            h ++;
            cur = cur -> left;
        }
        return sum + countLastLevel(root, h);
    }
    
    int countLastLevel(TreeNode* root, int h) {
        if(h == 1) {
            if(root -> right != NULL)
                return 2;
            else if(root -> left != NULL)
                return 1;
            else
                return 0;
        }
        TreeNode* mid = root -> left;
        int curH = 1;
        while(curH < h) {
            curH ++;
            mid = mid -> right;
        }
        if(mid == NULL)
            return countLastLevel(root -> left, h - 1);
        else
            return (1 << (h - 1)) + countLastLevel(root -> right, h - 1);
    }
};