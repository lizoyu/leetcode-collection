// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

#include <iostream>
#include <cstdlib>
using namespace std;

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
        ListNode *endNode = new ListNode(0), *head = new ListNode(0), *p = head;
        endNode->next = endNode;

        // when both numbers are not exhausted
        while (count < 2) {
            int sum = l1->val + l2->val + add;
            add = sum / 10;    // update carry flag
            p->next = new ListNode(sum % 10);
            p = p->next;

            // if l1 or/and l2 ends, replace with the cycling node, and count
            if (!l1->next) {
                l1 = endNode;
                count += 1;
            }
            else
                l1 = l1->next;
            if (!l2->next) {
                l2 = endNode;
                count += 1;
            }
            else
                l2 = l2->next;
        }
        
        // handle the carry flag
        if (add)
            p->next = new ListNode(add);
        
        return head->next;
    }
};

// driver
int main(){
    ListNode *l1 = new ListNode(6), *l2 = new ListNode(5);
    Solution s;

    ListNode* l3 = s.addTwoNumbers(l1, l2);

    while(l3) {
        cout << l3->val << endl;
        l3 = l3->next;
    }

    system("pause");
    return 0;
}