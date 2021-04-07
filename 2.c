/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){

    struct ListNode* answer = malloc(sizeof(struct ListNode));
    struct ListNode* x;
    struct ListNode* y;
    struct ListNode* z;
    struct ListNode* back;
    int c = 0;
    x = l1;
    y = l2;
    z = answer;
    z->val = 0;
    z->next = NULL;
    do {
        if (x->val + y->val + c >= 10) {
            z->val = x->val + y->val + c- 10;
            c = 1;
        } else {
            z->val = x->val + y->val + c;
            c = 0;
        }
        z->next = malloc(sizeof(struct ListNode));
        x = x->next;
        y = y->next;
        back = z;
        z = z->next;
        z->val = NULL;
        z->next = NULL;
    } while (x != NULL && y != NULL);
    if (x == NULL && y == NULL) {
        if (c == 1) {
            z->val = c;
        } else {
            back->next = NULL;
        }
    } else if (x == NULL) {
        while (y != NULL) {
            if (y->val + c >= 10) {
                z->val = y->val + c - 10;
                c = 1;
            } else {
                z->val = y->val + c;
                c = 0;
            }
            y = y->next;
            z->next = malloc(sizeof(struct ListNode));
            back = z;
            z = z->next;
            z->next = NULL;
        }
    } else {
        while (x != NULL) {
            if (x->val + c >= 10) {
                z->val = x->val + c - 10;
                c = 1;
            } else {
                z->val = x->val + c;
                c = 0;
            }
            x = x->next;
            z->next = malloc(sizeof(struct ListNode));
            back = z;
            z = z->next;
            z->next = NULL;
        }
    }
    if (c == 1) {
        z->val = c;
    } else {
        back->next = NULL;
    }
    
    return answer;
}
