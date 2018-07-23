//
// Created by yxr on 2018/7/23.
//
*/
class Solution {
public:
    ListNode* reverseList(ListNode *head) {
        ListNode *previous = NULL, *current = NULL, *next = head;

        while(next) {
            previous = current;
            current = next;
            next = next->next;
            current->next = previous;
        }

        return current;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1 && !l2)
            return l1;
        if(!l1)
            return l2;
        if(!l2)
            return l1;

        ListNode *new1 = reverseList(l1);
        ListNode *new2 = reverseList(l2);
        ListNode *result = NULL;
        int carry = 0;
        while(new1 || new2) {
            int sum = carry;

            if(new1) {
                sum += new1->val;
                new1 = new1->next;
            }

            if(new2) {
                sum += new2->val;
                new2 = new2->next;
            }

            carry = sum / 10;
            sum = sum % 10;
            ListNode *temp = new ListNode(sum);

            temp->next =  result;
            result = temp;
        }

        if(carry) {
            ListNode *temp = new ListNode(carry);
            temp->next = result;
            result = temp;
        }

        return result;
    }
};
