#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct list {
	int val;
	struct list *next;
}List;

void swap(List* head, List* a, List* b){

	if (a == b ) return;
	//you can use assert function to check
	assert(a);
	assert(b);
	assert(head);

	List* prev_a = NULL;
	List* prev_b = NULL;
	List* curr = head;
	
	while (curr && curr->next != a){
		prev_a = curr;
		curr = curr->next;
	}
	
	curr=head;
	while (curr && curr->next != b){
		prev_b = curr;
		curr = curr->next;
	} 
	
	if(prev_a != NULL)
		prev_a->next = b;
	else 
		head = b;

	if(prev_b != NULL)
		prev_b->next = a;
	else
		head = a;
	
	List* tmp = b->next;
	b->next = a->next;
	a->next = tmp;
}

List* swap1 (List *head, List *a, List *b){
	assert(head);
	assert(a);
	assert(b);
	// a = b
	if (a == b)
		return NULL;
	// a | b is head
	/*if(a == head){
		//a is head 
		head = b;
		List *tmp = head->next;
		head->next = b->next;
		b->next = tmp;
	}else if (b == head){
		head = a;
		List *tmp = head->next;
		head->next = a->next;
		a->next = tmp;
	}*/

	//better solution 
	if (a == head || b == head){
		List *prev = head;
		List *nohead = (a = head)? b:a;
		for (;prev->next != nohead; prev= prev->next);
		if (!prev)
			return NULL;
		head = nohead;
		prev->next = head;
		prev = nohead->next;
		nohead->next = head->next;
		head->next = prev;
	}

	List *prev_a = head;
        List *prev_b = head;

        for (;prev_a->next != a; prev_a = prev_a->next);
        for (;prev_b->next != b; prev_b = prev_b->next);

	// a and b are not all head
	//protection code 

	if (!prev_a || !prev_b)
		return NULL;

	 prev_a->next = b;
         prev_b->next = a;
         prev_a = a->next;
         a->next = b->next;
         b->next = prev_a;

	return head;
}


//delete ine list
List*  delete (List *head, List *a){
	assert (head);
	assert(a);
	//a = head
	if (a == head){
		head = a->next;
		free(a);
	}else{
	//a != head
		List *prev = head;
		for (;prev->next != a; prev= prev->next);
		if(!prev)
			return NULL;
		prev->next = a->next;
		free(a);
	}

	return head;
}

List * search(List *head, int value){
	assert (head);
	List *tmp;
	while (head){
		if(head->val == value){
			tmp = head;
			return tmp;
		}
		head = head->next;	
	}
	
	return NULL;
}



List * insert (List* head, List* a){	
	assert(a);

	//add to last
	if (head){
		//add to last
		List *curr = head;	
		for (;curr->next != NULL;curr=curr->next);
		curr->next = a;
	}else{
		head = a;
	}

	return head;
}

int listSize (List* head){
	assert(head);
	int size = 0;
	while (head->next != NULL)
		size++;
	return size;
}

List* bubble_sort(List* head){
	List* tmp = head;
	int size = listSize(tmp);
	int i,j;
	for ( i = 0; i < (size -1);i++){
		for(j = 0; j < (size-i-1); j++)
			if((head+j)->val > (head+j+1)->val){
				swap(head, head+j, head+j+1);
			}
	}
	return head;
	
}

List* create(List* head, int value){
	
	//assert(head);
	List* list;
	List* curr = head;

	list = (List *)malloc(sizeof(List *));
	if(!list)
		return NULL;
	printf ("create function\n ");

	if (curr){
		//add to last
		while (curr->next != NULL){
			curr = curr->next;
		}
		curr -> next = list;
		list->val = value;
		return head;

	}else {
		curr = list;
		curr->val = value;
		return curr;
	}

}

void freeList (List* head){
	assert(head);
	
	List* curr = head;
//	printf ("free function");
	while (curr){
		free(curr);
		curr = curr->next;
		printf("free function\n");
	}
}


void printList (List *head){

	assert (head);
	List *tmp = head;
	printf("printList\n");
	while(tmp){
		printf ("List value is %d\n",tmp->val);
		tmp = tmp->next;
	}
}

int main (void){
	//just a test 
	int i;
	int max = 5;
	//List *head = (List *)malloc(sizeof(List *));
	//assert(head);
	List *head;
	for (i = 0; i < max; i++){		
		head = create(head,i);
	}
	
	printList(head);
	
	List *tmp = search(head, 3);
	if (!tmp)
		printf("cannot find tmp\n");

	freeList(head);

	//print list
	//swap()
	return 0;
	
}
