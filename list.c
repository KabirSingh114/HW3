#include <assert.h>
#include <stdlib.h>

#include "list.h"

// Takes a valid, sorted list starting at `head` and adds the element
// `new_element` to the list. The list is sorted based on the value of the
// `index` member in ascending order. Returns a pointer to the head of the list
// after the insertion of the new element.
list_t* insert_sorted(list_t* head, list_t* new_element) {
	assert(head != NULL);
	assert(new_element != NULL);
	
	list_t *current = head;
	
	if(head->index > new_element->index){
		new_element->next = head;
		return new_element;
	}

	while(1){
		if(current->next == NULL){
			current->next = new_element;
			return head;
		}else if(current->next->index >= new_element->index){
			new_element->next = current->next;
			current->next = new_element;
			return head;
		}
		current = current->next;
	}
	return head;   
}

// Reverses the order of the list starting at `head` and returns a pointer to
// the resulting list. You do not need to preserve the original list.
list_t* reverse(list_t* head) {
	assert(head != NULL);
    if(head == NULL || head->next == NULL)
        return head;
    
    list_t *prev, *current, *nextNode;
    prev = head;
    current = head;
    nextNode = head->next;
    
    while(nextNode!=NULL){
        current = nextNode;
        nextNode = nextNode->next;
        current->next = prev;
        prev = current;
    }
    head->next=NULL;
head=prev;

	return head;
}

