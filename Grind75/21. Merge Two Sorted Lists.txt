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
        if(list1 == NULL){
            return list2;
        }
        if(list2 == NULL){
            return list1;
        }

        ListNode *mergeList = list1;
        if(list1->val > list2->val){
            mergeList = list2;
            list2 = list2->next;
        }
        else{
            list1 = list1->next;
        }
        ListNode *tmp = mergeList;

        while(list1 && list2 ){
            if(list1->val <= list2->val){
                tmp->next = list1;
                list1 = list1->next;
            }
            else{
                tmp->next = list2;
                list2 = list2->next;
            }
            tmp = tmp ->next;
        }

        if(!list1){
            tmp->next = list2;
        }
        else{
            tmp->next = list1;
        }

        return mergeList;
    }
};