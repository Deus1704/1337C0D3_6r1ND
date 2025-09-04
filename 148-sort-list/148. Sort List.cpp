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
    ListNode* sortList(ListNode* head) {
        vector<int>order;
        auto dumy = head;
        while (dumy){
            order.push_back(dumy->val); dumy= dumy->next;
        }
        sort(order.begin(), order.end());
        auto d1 = head; int i=0;
        while (d1 && i<order.size()){
            d1->val = order[i]; d1= d1->next; i++;
        }
        return head;
    }
};