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
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  merge 2 sorted link list in ascending order, inplace xxxxxxxxxxxxxxxxxxxx
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if(!l1) return l2; // if any of the l1 list is empty
        if(!l2) return l1;  // if any of the l2 list is empty
        ListNode* head;  ListNode* prev; ListNode* a; ListNode* s;
        if(l1->val > l2->val) swap(l1,l2);  // l1 is always starting point
        head= l1; //starts from first node of l1
        prev=l1; // starting point is alwasy l1
        l1= l1->next;
        while(l1 && l2)
        {
            if(l1->val<= l2->val)
            {
                 prev->next=l1;
                prev=l1;
                l1=l1->next;
            }
            else
            {
                prev->next= l2;
                prev=l2;
                l2=l2->next;
            }
        }
        
        if(!l1)// l1 finsihes
            prev->next=l2;
        if(!l2)
            prev->next= l1;
        return head;
    }
    xxxxxxxxxxxxxxxxxxxxxxxxx   sort list in place, constant space : merge sortxxxxxxxxxxxxxxxxxxxx
    
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
        // find middle and devide into 2 l1 and l2
        // send to recur (base),  l1 and l2 are now sorted
        //merge l1 and l2
        
        if(!head) return head; // empty list
        if(head->next == NULL) return head; // only 1 element in list
        
        ListNode* slow=head; ListNode* fast=head;
        ListNode* mid;
        
        while(fast!=NULL && fast->next!= NULL)
        {
            mid=slow; //
            slow=slow->next;
            fast=fast->next->next;
        }
        mid->next= NULL; 
         ListNode* l1=head;  // devided into 2 list
        ListNode* l2=slow;
       l1= sortList(l1); // hypothesis sorted
       l2= sortList(l2);
        ListNode* start=mergelist(l1,l2);
        return start;
    }
    
     ListNode* mergelist(ListNode* l1,ListNode* l2)  // merge two sorted link list in place
     {
        
         if(!l1) return l2; // if any of the l1 list is empty
        if(!l2) return l1;  // if any of the l2 list is empty
        ListNode* head;  ListNode* prev; ListNode* a; ListNode* s;
        if(l1->val > l2->val) swap(l1,l2);  // l1 is always starting point
        head= l1; //starts from first node of l1
        prev=l1; // starting point is alwasy l1
        l1= l1->next;
        while(l1 && l2)
        {
            if(l1->val<= l2->val)
            {
                 prev->next=l1;
                prev=l1;
                l1=l1->next;
            }
            else
            {
                prev->next= l2;
                prev=l2;
                l2=l2->next;
            }
        }
        
        if(!l1)// l1 finsihes
            prev->next=l2;
        if(!l2)
            prev->next= l1;
        return head;
     }
    
    void print(ListNode* l1)
               {
                   while(l1!= NULL)
                   {
                       cout<<l1->val<<" ";
                       l1=l1->next;
                   }
                   cout<<endl;
               }
};
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
