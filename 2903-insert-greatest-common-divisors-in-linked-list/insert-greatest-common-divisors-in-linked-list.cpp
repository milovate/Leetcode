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
    
    int gcd(int a, int b)
{
    // Find Minimum of a and b
    int result = ((a < b) ? a : b);
    while (result > 0) {
        if (a % result == 0 && b % result == 0) {
            break;
        }
        result--;
    }
 
    // Return gcd of a and b
    return result;
}
    

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        
  
        ListNode* front_pointer = head;
        
        ListNode* prev_pointer = front_pointer;
        
        int prev = head -> val;
        
        front_pointer = front_pointer -> next;
        
        while (front_pointer != NULL){
            
            
            int num = gcd(front_pointer->val,prev_pointer->val);
            prev_pointer -> next = new ListNode(num);
            
            prev_pointer = prev_pointer -> next;
            prev_pointer -> next = front_pointer;
            prev_pointer = front_pointer;
            front_pointer = front_pointer -> next;
            
        }
        
        return head;
        
        
    }
};