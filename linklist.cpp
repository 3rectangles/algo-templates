xxxxx leet code, check for starting point of cyle, tortoise , 2 pointers
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
    // if(!head) return NULL;
        
        ListNode *slow=head,*fast=head;
        
        //cycle checking
        do{
            //move slow by one
            if(slow!= NULL)
            slow = slow->next;
            if(!slow) return NULL;
            
            //move fast by 2, 
            // caution: move fast one by one bec to check for no cycle. if  moved 2 steps at once when possible. there is a case when fast doesnt move ahead but slow catches to slow. and while loop breaks.
            if(fast!=NULL )
              fast= fast->next;
            if(!fast) return NULL;
            if(fast!= NULL)
                 fast= fast->next;
            if(!fast) return NULL;
                
                    
            
        }while(slow!=fast);
        
        
        //check the entry point
        fast = head;
        while(fast !=slow)
            fast=fast->next, slow=slow->next;
        return fast;
    }
        
    
};
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
