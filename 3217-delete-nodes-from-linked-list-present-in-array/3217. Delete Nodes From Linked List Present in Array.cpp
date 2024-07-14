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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode temp(0,head);
        ListNode* cur = &temp;
        unordered_set<int> sat(begin(nums),end(nums));
        if (nums.empty() || !head) return head;
        while (cur->next!=nullptr){
            if (sat.contains(cur->next->val)){
                    cur->next = cur->next->next;
            }else{
                cur= cur->next;    
            }
        }
        return temp.next;
    }
};

//Other way:
// class Solution {
// public:
//     ListNode* modifiedList(vector<int>& nums, ListNode* head) {
//         ListNode* prev = nullptr;
//         ListNode* dummy = new ListNode(0,head);
//         ListNode* cur = dummy;
//         if (nums.empty() || !head) return head;
//         while(cur->next != nullptr){
//             if (find(nums.begin(), nums.end(), cur->next->val)!=nums.end()){
//                 cur->next = cur->next->next; 
//             }else{
//                 cur = cur->next;
//             }
//         }
//         return dummy->next;
//     }
// };