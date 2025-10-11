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
  ListNode* swapPairs(ListNode* head) {
    // Base case: if the list has 0 or 1 node, nothing to swap
    if (!head || !head->next) return head;

    // Nodes to be swapped
    ListNode* first = head;
    ListNode* second = head->next;

    // Recursively call for the rest of the list beyond the first two nodes
    first->next = swapPairs(second->next);

    // Perform the swap
    second->next = first;

    // Now the head is the second node
    return second;
}

//   ListNode* swapPairs(ListNode* head) {
//     ListNode* dummy = new ListNode(0);
//     dummy->next = head;
//     ListNode* prev = dummy;

//     while (head && head->next) {
//         ListNode* first = head;
//         ListNode* second = head->next;

//         // Swapping
//         first->next = second->next;
//         second->next = first;
//         prev->next = second;

//         // Re-positioning pointers for next swap
//         prev = first;
//         head = first->next;
    // }

    // return dummy->next;

};