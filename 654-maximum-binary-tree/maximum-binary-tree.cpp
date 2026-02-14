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
unordered_map<int ,int> m;
 TreeNode* buildTree(vector<int>& nums,int st,int end){
    if(st>=end) return NULL;
    int mx=0;
    for(int i=st;i<end;i++){
        mx=max(nums[i],mx);
    }
    TreeNode* root=new TreeNode(mx);
    root->left=buildTree(nums,st,m[mx]);
    root->right=buildTree(nums,m[mx]+1,end);
    return root;
 }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        for(int i=0;i<nums.size();i++) m[nums[i]]=i;
        return buildTree(nums,0,nums.size());
    }
};