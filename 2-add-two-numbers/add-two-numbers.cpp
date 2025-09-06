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
// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         ListNode* ans=new ListNode(0);
//         ListNode* temp=l1;
//         ListNode* temp1=l2;
//         long long a=0;
//         long long b=0;
//         while(temp!=NULL){
//             a=a*10+temp->val;
//             temp=temp->next;
//         }
//          while(temp1!=NULL){
//             b=b*10+temp1->val;
//             temp1=temp1->next;
//         }
//         int c=a+b;
//         ListNode* temp2=ans;
//         if(c==0){
//             temp2->next=new ListNode(0);
//         }
//         while(c!=0){
//             int mod=c%10;
//             temp2->next=new ListNode(mod);
//             temp2=temp2->next;
//             c=c/10;
//         }
//         return ans->next;
//     }
// };
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        int carry = 0;
        
        while (l1 != nullptr || l2 != nullptr || carry) {
            int sum = carry;
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            current = current->next;
        }
        
        return dummy->next;
    }
};