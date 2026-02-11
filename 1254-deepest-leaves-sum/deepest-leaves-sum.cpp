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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans;
        while(!q.empty()){
            int n = q.size();
            vector<int> v;
            int sum=0;
            for(int i =0;i<n;i++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp!=NULL){
                    sum+=temp->val;
                    if(temp->left)
                        q.push(temp->left);
                    if(temp->right)
                        q.push(temp->right);    
                }       
            }
            if(sum!=0) ans=sum;
        }
        return ans;
    }
};