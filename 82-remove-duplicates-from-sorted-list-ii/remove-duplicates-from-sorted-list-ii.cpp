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
ListNode* deleteDuplicates(ListNode* head) {//mine solution
if(head==NULL || head->next==NULL) return head;
ListNode *dummy=new ListNode(10);
dummy->next=head;//add new node to head
ListNode *temp=dummy;
while(head){
if(head->next && head->val==head->next->val){
while( head->next && head->val==head->next->val){//move head until head->next->val is diff
head=head->next;
}
temp->next=head->next;//
head=temp;
}
else temp=temp->next;
head=head->next;
}
return dummy->next;
}
};