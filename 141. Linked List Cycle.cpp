//
// Created by yxr on 2018/7/17.
//
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* n1=head;
        ListNode* n2=head;

        while(n2!=NULL && n1!=NULL && n1->next!=NULL ){
            n1=n1->next->next;
            n2=n2->next;
            if(n1==n2){
                return true;
            }
        }
        return false;
    }
};
