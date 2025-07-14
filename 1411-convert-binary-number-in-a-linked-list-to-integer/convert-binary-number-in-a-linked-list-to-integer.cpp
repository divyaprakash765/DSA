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
    int getDecimalValue(ListNode* head) {
        
      ListNode* temp = head;
      
      int size = 0;
      while(temp != nullptr){
        size++;
        temp = temp->next;
      }

      temp = head;
      int ans = 0;

      while(temp != nullptr){
        ans += (temp->val)<<(size-1);
        size--;
        temp = temp->next;
      }

      return ans;

    }
};