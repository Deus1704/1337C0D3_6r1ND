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
    ListNode* deleteMiddle(ListNode* head) {
        int count = 0;
        ListNode* temp = head;
        while (temp!=nullptr){
            count++;
            temp = temp->next;
        }
        if (count <= 1){
            return nullptr;
        }
        // cout<<count/2<<endl;
        ListNode* newtemp = head;
        ListNode* prev = nullptr;
        int newcount = 0;
        while (newcount < count/2){
            newcount++;
            cout<<newcount<<endl;
            prev = newtemp;
            newtemp = newtemp->next;
        }
        if (newtemp->next){
            prev->next = newtemp->next;
        }else{
            prev->next = nullptr;
        }
        return head;
    }
};