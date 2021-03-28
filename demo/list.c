#include "list.h"
#include <stdio.h>
/* Add a node to the end of the linked list. Assume head_ptr is non-null. */
void append_node (node** head_ptr, int new_data) {
	node * newNode = (node *)malloc(sizeof(node));
  newNode->val = new_data;
  newNode->next = NULL;

	/* If the list is empty, set the new node to be the head and return */
	if (*head_ptr == NULL) {
		*head_ptr = newNode;
		return;
	}
	node* curr = *head_ptr;
	while (curr->next != NULL) {
		curr = curr->next;
	}
	curr->next = newNode;
}

/* Reverse a linked list in place (in other words, without creating a new list).
   Assume that head_ptr is non-null. */
void reverse_list (node** head_ptr) {
  if(*head_ptr == NULL) {
    return;
  }
	node* prev = NULL;
	node* curr = *head_ptr;
	node* post = curr->next;
	while (post != NULL) {
    prev = curr;
		curr = post;
		post = curr->next;
		curr->next = prev;
    if(prev->next == curr) {
      prev->next = NULL;
    }
    
    /*iris':
    post = curr->next;
    curr->next = prev;
    prev = curr;
    curr = post;
    */

	}

	/* Set the new head to be what originally was the last node in the list */
	*head_ptr = curr;
  //*head_ptr = prev; //iris'
}



