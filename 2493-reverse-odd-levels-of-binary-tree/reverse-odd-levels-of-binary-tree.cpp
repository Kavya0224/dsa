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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int lvl=0;
        while(!q.empty()){
            int n=q.size();
            vector<TreeNode*> v;
            if(lvl%2==1){
                
                for(int i=0;i<n;i++){
                    TreeNode* temp=q.front();
                    q.pop();
                    if(temp){
                        v.push_back(temp);
                        if(temp->left) q.push(temp->left);
                        if(temp->right) q.push(temp->right);
                    }
                }
                int i=0;
                int j=v.size()-1;
                while(i<j){
                    swap(v[i]->val,v[j]->val);
                    i++; j--;
                }
                lvl++;
            }
            else{
                for(int i=0;i<n;i++){
                    TreeNode* temp=q.front();
                    q.pop();
                    if(temp){
                        v.push_back(temp);
                        if(temp->left) q.push(temp->left);
                        if(temp->right) q.push(temp->right);
                    }
                }
                lvl++;
            }
        }
        return root;
    }
};