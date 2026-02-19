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
    ListNode* helper(ListNode* head1,ListNode* head2){
        ListNode* head=NULL;
        if (!head1) return head2;
        if (!head2) return head1;

        if(head1->val<head2->val){
            head=head1;
            head1=head1->next;
        }
        else{
            head=head2;
            head2=head2->next;
        }
        ListNode* temp=head;
        while(head1!=NULL && head2!=NULL){
            if(head1->val>head2->val){
                head->next=head2;
                head=head->next;
                head2=head2->next;
            }
            else{
                head->next=head1;
                head=head->next;
                head1=head1->next;
            }
        }
        head->next = (head1 ? head1 : head2);

        return temp;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;

        int n=lists.size();
        for(int i=0;i<n-1;i++){
            ListNode* head1=lists[i];
            ListNode* head2=lists[i+1];
            lists[i+1]=helper(head1,head2);
        }
        return lists[n-1];
    }
};