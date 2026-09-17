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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* l=list1;
        ListNode* r=list1;
        for(int i=0;i<a-1;i++){
            l=l->next;
        }
        for(int i=0;i<b+1;i++){
            r=r->next;
        }
        l->next=list2;
        ListNode* l2tail=list2;
        while(l2tail->next){
            l2tail=l2tail->next;
        }
        l2tail->next=r;
        return list1;
    }
};