class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;

        while(!q.empty()){
            int n = q.size();
            vector<int> v;

            for(int i = 0; i < n; i++){
                TreeNode* temp = q.front();
                q.pop();

                v.push_back(temp->val);

                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }

            ans.push_back(v);
        }

        for(int i = 0; i < ans.size(); i++){
            
            // Even level -> odd values & strictly increasing
            if(i % 2 == 0){
                
                // parity check for all elements
                for(int j = 0; j < ans[i].size(); j++){
                    if(ans[i][j] % 2 == 0) return false;
                }

                // strictly increasing
                for(int j = 0; j < ans[i].size() - 1; j++){
                    if(ans[i][j] >= ans[i][j+1]) return false;
                }
            }
            
            // Odd level -> even values & strictly decreasing
            else{
                
                // parity check for all elements
                for(int j = 0; j < ans[i].size(); j++){
                    if(ans[i][j] % 2 != 0) return false;
                }

                // strictly decreasing
                for(int j = 0; j < ans[i].size() - 1; j++){
                    if(ans[i][j] <= ans[i][j+1]) return false;
                }
            }
        }

        return true;
    }
};
