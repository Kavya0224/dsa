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
 unordered_map<int,int> map;
 int index=0;
 TreeNode* helper(int start,int end,vector<int> preorder){
    if(start>end) return NULL;
    int rootVal=preorder[index++];
    TreeNode* node= new TreeNode(rootVal);
    int mid=map[rootVal];
    node->left=helper(start,mid-1,preorder);
    node->right=helper(mid+1,end,preorder);
    return node;
 }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       
        for(int i=0;i<inorder.size();i++){
            map[inorder[i]]=i;
        }
        return helper(0,inorder.size()-1,preorder);
    }
};