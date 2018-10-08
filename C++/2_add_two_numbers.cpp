// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // handle special inputs
        if (!l1 && l2) 
            return l2;
        else if (!l2 && l1)
            return l1;
        else if (!l1 && !l2)
            return 0;
        
        // use a int for carry flag, a cycling node and a counter for ending
        int add = 0, count = 0;
        ListNode node(0);
        ListNode* endNode = &node;
        endNode->next = endNode;
        ListNode* head = l1;
        
        // when both numbers are not exhausted
        while (count < 2) {
            int sum = l1->val + l2->val + add;
            add = sum / 10;    // update carry flag
            l1->val = sum % 10;
            if (!l1->next){
                l1 = endNode;
                count += 1;
            }
            else
                l1 = l1->next;
            if (!l2->next){
                l2 = endNode;
                count += 1;
            }
            else
                l2 = l2->next;
        }
        
        // handle the carry flag
        if (add) {
            endNode->val = add;
            endNode->next = nullptr;
            l1->next = endNode;
        }
        
        return head;
    }
};