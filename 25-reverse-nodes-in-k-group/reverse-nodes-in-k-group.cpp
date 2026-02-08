
class Solution {
public:
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL) return head;
        if(k==1) return head;
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forw = head->next;
        if(forw == NULL) return head;
        ListNode* mult = head;
        for(int j = 1; j<=k; j++){
            if(mult!=NULL)mult = mult->next;
            else{return head;}
        }
        while(curr!=mult){
            curr->next = prev;
            prev = curr;
            curr = forw;
            if(forw!=NULL) forw=forw->next;
        }
        head->next = reverseKGroup(mult, k);
        return prev;
    }
};