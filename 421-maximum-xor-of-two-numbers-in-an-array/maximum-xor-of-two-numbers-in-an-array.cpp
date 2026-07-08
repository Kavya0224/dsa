class TrieNode{
public:
    TrieNode* left;
    TrieNode* right;
    TrieNode(){
        left=NULL;
        right=NULL;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        TrieNode* root=new TrieNode();
        for(int i=0;i<nums.size();i++){
            TrieNode* temp=root;
            for(int j=31;j>=0;j--){
                int bit=(nums[i]>>j)&1;
                if(bit==0){
                    if(!temp->left){
                        TrieNode* node=new TrieNode();
                        temp->left=node;
                    }
                    temp=temp->left;
                }
                else{
                    if(!temp->right){
                        TrieNode* node=new TrieNode();
                        temp->right=node;
                    }
                    temp=temp->right;
                }
            }
        }

        int ans=0;
        for(int i=0;i<nums.size();i++){
            TrieNode* temp=root;
            int sum=0;
            for(int j=31;j>=0;j--){
                int bit=(nums[i]>>j)&1;
                if(bit==1){
                    if(temp->left){
                        sum+=1<<j;
                        temp=temp->left;
                    }
                    else temp=temp->right;
                    
                }
                else{
                    if(temp->right){
                        sum+=1<<j;                      
                        temp=temp->right;
                    }
                    else temp=temp->left;
                }
            }
            ans=max(ans,sum);
        }
        return ans;
    }
};