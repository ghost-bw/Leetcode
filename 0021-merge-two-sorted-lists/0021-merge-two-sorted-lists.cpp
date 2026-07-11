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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* curr=new ListNode(0);
        ListNode* dummy=curr;
        
        while(list1!=nullptr && list2!=nullptr){
            int val=0;
            if(list1->val<=list2->val){
                val=list1->val;
                list1=list1->next;
            }else{
                val=list2->val;
                list2=list2->next;
            }
            dummy->next=new ListNode(val);
            dummy=dummy->next;
        }
         while (list1 != nullptr) {

            dummy->next = new ListNode(list1->val);

            dummy = dummy->next;

            list1 = list1->next;
        }

        while (list2 != nullptr) {

            dummy->next = new ListNode(list2->val);

            dummy = dummy->next;

            list2 = list2->next;
        }
        return curr->next;
    }
};