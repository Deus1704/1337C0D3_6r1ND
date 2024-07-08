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
        ListNode* ans = new ListNode(0);
        ListNode* cur = ans;
        if (!list1) return list2;
        else if (!list2) return list1;
        while(list1 && list2){
            if (list1->val <= list2->val){
                cur->next = list1;
                list1 = list1->next;
            }else{
                cur->next = list2;
                list2 = list2->next;
            }
            cur = cur->next;
        }
        if (list1){
            cur->next = list1;
        }else{
            cur->next = list2;
        }
        return ans->next;
    }
};

// RECURSION BASED SOLN:
// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//         if(!list1) return list2;
//         if(!list2) return list1;

//         if (list1->val <= list2->val){
//             list1->next = mergeTwoLists(list1->next, list2);
//             return list1;
//         }else{
//             list2->next = mergeTwoLists(list1, list2->next);
//             return list2;
//         }
//     }
// };