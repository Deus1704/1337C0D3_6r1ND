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
    int pairSum(ListNode* head) {
        vector<int> vals;
        int count = 0;
        while (head != NULL){
            count++;
            vals.push_back(head->val);
            head = head->next;
        }
        int mts = 0;
        for (int i =0; i<= (count/2)-1 ; i++){
            mts = max(mts, vals[i]+vals[count-i-1]);
        }
        return mts;
    }
};