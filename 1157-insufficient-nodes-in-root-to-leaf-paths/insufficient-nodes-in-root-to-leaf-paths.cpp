class Solution {
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        // Reached Leaf Node
        if(!root->left && !root->right){
            return root->val<limit?NULL:root;
        }
        
        if(root->left){
            root->left=sufficientSubset(root->left,limit-root->val);
        }
        if(root->right){
            root->right=sufficientSubset(root->right,limit-root->val);
        }

        /* Dry Run Example 3 You will see we have to return NULL if
           tree below current node is insufficient */
        return (!root->left && !root->right)?NULL:root;
    }
};