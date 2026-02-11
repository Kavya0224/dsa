class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        // Special case
        if(depth == 1){
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }

        queue<TreeNode*> q;
        q.push(root);
        int lvl = 1;

        while(!q.empty()){
            int n = q.size();

            if(lvl == depth - 1){
                for(int i = 0; i < n; i++){
                    TreeNode* temp = q.front();
                    q.pop();

                    TreeNode* oldLeft = temp->left;
                    TreeNode* oldRight = temp->right;

                    temp->left = new TreeNode(val);
                    temp->right = new TreeNode(val);

                    temp->left->left = oldLeft;
                    temp->right->right = oldRight;
                }
                break;
            }

            for(int i = 0; i < n; i++){
                TreeNode* temp = q.front();
                q.pop();

                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }

            lvl++;
        }

        return root;
    }
};
