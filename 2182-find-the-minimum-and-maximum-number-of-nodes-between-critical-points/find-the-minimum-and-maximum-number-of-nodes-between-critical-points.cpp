/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* temp=head;
        ListNode* prev=head;
        temp=temp->next;
        if(temp==NULL || temp->next==NULL) return {-1,-1};
        int idx=0;
        vector<int> ans(2);
        ans[0]=INT_MAX;
        ans[1]=-1;
        vector<int> mx,mn;
        while(temp->next){
            if(temp->val>prev->val && temp->val>temp->next->val ||  temp->val<prev->val && temp->val<temp->next->val) mx.push_back(idx);
          
            if(mx.size()>1){
                ans[0]=min(ans[0],abs(mx[mx.size()-2]-mx.back()));
            }
            prev=prev->next;
            idx++;
            temp=temp->next;
        }
        if(mx.size()>1) ans[1]=abs(mx[0]-mx.back());
        else return {-1,-1};
        return ans;
    }
};