class Solution {
public:
    set<int> s;

    void helper(TreeNode* root){
        if(!root) return;
        s.insert(root->val);
        helper(root->left);
        helper(root->right);
    }

    int findSecondMinimumValue(TreeNode* root) {
        helper(root);

        if(s.size() < 2) return -1;

        auto it = s.begin();
        it++;  // second smallest

        return *it;
    }
};