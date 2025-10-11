class Solution {
private:
    ListNode* reverseList(ListNode* head){
        ListNode *prev = nullptr;
        while(head){
            ListNode *temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }
public:
    ListNode* removeNodes(ListNode* head) {
        head = reverseList(head);
        ListNode* p = head;
        while(p && p->next){
            if(p->val > p->next->val) p->next = p->next->next;
            else p = p->next;
        }
        return reverseList(head);
    }
};