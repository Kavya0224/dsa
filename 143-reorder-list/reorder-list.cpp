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
    // void reorderList(ListNode* head) {
    //     if(head==NULL || head->next==NULL) return;
    //     ListNode* curr=head;
    //     ListNode* temp=head;
    //     while(temp->next!=NULL){
    //         temp=temp->next;
    //     }
    //     temp->next=curr->next;
    //     curr->next=temp;
    //     reorderList(temp->next);
    // }
    void reorderList(ListNode* head) {
    if (!head || !head->next || !head->next->next)
        return;

    // Find the second last node
    ListNode* prev = head;
    while (prev->next->next)
        prev = prev->next;

    // Last node
    ListNode* tail = prev->next;

    // Disconnect last node
    prev->next = nullptr;

    // Insert last node after head
    tail->next = head->next;
    head->next = tail;

    // Recurse on the sublist
    reorderList(tail->next);
}

};