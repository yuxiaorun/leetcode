//
// Created by yxr on 2018/7/15.
//
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m==n)return head;
        int i=1;
        ListNode* p = head;
        ListNode* prev = head;
        ListNode* start=NULL;
        ListNode* start_prev=NULL;
        ListNode* end=NULL;
        ListNode* end_fron=NULL;
        if(i==m){
            start=p;
            start_prev=NULL;
        }
        while(p!=NULL){
            p=p->next;
            i++;
            if(i==m){
                start=p;
                start_prev=prev;
            }
            if(i==n){
                end=p;
                end_fron=p->next;
            }
            prev=prev->next;
        }
        end->next=NULL;
        if(!start_prev)head=reverse(start);
        else start_prev->next=reverse(start);
        start->next=end_fron;
        return head;

    }
private:
    ListNode* reverse(ListNode* head){
        ListNode* p=NULL;
        ListNode* q=head;
        while(q!=NULL){
            ListNode* tmp=q->next;
            q->next=p;
            p=q;
            q=tmp;
        }
        return p;
    }
};
