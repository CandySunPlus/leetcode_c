#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *createNode(int data) {
    struct ListNode *newNode = malloc(sizeof(struct ListNode));
    newNode->val = data;
    newNode->next = NULL;
    return newNode;
}

struct ListNode *reverseKGroup(struct ListNode *head, int k) {
    int len = 0;
    struct ListNode dummy;
    struct ListNode *currentNode;
    struct ListNode *prevNode = &dummy;

    dummy.next = head;
    for (currentNode = head; currentNode != NULL; currentNode = currentNode->next) {
        if (++len % k == 0) {
            // k的整倍数时
            struct ListNode *beginNode = prevNode->next;
            for (int i = 1; i < k; i++) {
                struct ListNode *nextNode = beginNode->next;
                beginNode->next =nextNode->next;
                nextNode->next = prevNode->next;
                prevNode->next = nextNode;
            }
            // beginNode 已被移动到最后
            currentNode = beginNode;
            prevNode = currentNode;
        }
    }
    return dummy.next;
}

void printList(struct ListNode *head) {
    struct ListNode *p = head;
    while (p) {
        printf("%d->", p->val);
        p = p->next;
    }
    printf("NIL\n");

}

int main() {
    const int n = 5;
    const int k = 2;

    struct ListNode *head = createNode(1);
    struct ListNode *p = head;
    for (int i = 2; i <= n; i++) {
        p->next = createNode(i);
        p = p->next;
    }
    printList(head);

    struct ListNode *newHead = reverseKGroup(head, k);
    printList(newHead);

    return 0;
}