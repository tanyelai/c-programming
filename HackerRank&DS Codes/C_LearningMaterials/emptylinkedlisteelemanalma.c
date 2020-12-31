#include <stdio.h>
#include <stdlib.h>

/*
  Insert Node at the end of a linked list 
  head pointer input could be NULL as well for empty list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Insert(Node *head,int data)
{
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = data;
    p->next = NULL;
    
    if (head == NULL) {
        return p;
    } else {
        Node* curr = head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = p;
    }
    return head;

