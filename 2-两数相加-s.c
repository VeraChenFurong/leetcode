/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *p1 = l1;
    struct ListNode *p2 = l2;
    
    struct ListNode *head = malloc(sizeof(struct ListNode));
    head->val = 0;
    head->next = 0;
    
    struct ListNode *pre = head;
    int z = 0;
    while(p1!=0||p2!=0)
    {
        int x = p1?p1->val:0;
        int y = p2?p2->val:0;
        
        int sum = x+y+z;
        
        struct ListNode *node= malloc(sizeof(struct ListNode));
        node->val = sum%10;
        node->next = 0;
        
        pre->next = node;
        pre = node;
        z = sum/10;

        if (p1) p1 = p1->next;
        if (p2) p2 = p2->next;
    }
    
    if(z>0)
    {
        struct ListNode *node= malloc(sizeof(struct ListNode));
        node->val = z;
        node->next = 0;
        pre->next = node;
    }
    
    struct ListNode *result = head->next;
    free(head);
    
    return result;
}

