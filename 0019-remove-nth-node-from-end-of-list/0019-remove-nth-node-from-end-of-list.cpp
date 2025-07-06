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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return head;

        int cnt = 0;
        ListNode* temp = head;
        while(temp){
            cnt++;
            temp = temp->next;
        }

        if(cnt == n){
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        else if(cnt-n > 0){
            ListNode* temp = head;
            for(int i=1; i<(cnt-n) && temp; i++){
                temp = temp->next;
            }
            temp->next = temp->next->next;
            return head;
        }

        return head;
    }
};