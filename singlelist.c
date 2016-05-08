#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct list {
	int val;
	struct list *next;
}List;

List* swap(List* head, List* a, List* b){

	if (a == b ) return;
	//you can use assert function to check
	assert(a);
	assert(b);
	assert(head);

	//a or b are head
	if (a == head || b == head){
		List *nohead = (a = head)?b:a;
		List *curr = head;
		
		for (;curr->next != nohead; curr=curr->next);
		if (!curr)
			printf ("cannot find node\n");

		
		curr->next = head;
		curr = b->next;
		b->next = head->next;
		head->next = curr;	
		head = nohead;
		return head;
	}

	List* prev_a = head;
	List* prev_b = head;
	for (;prev_a->next != a; prev_a = prev_a->next);
	for (;prev_b->next != b; prev_b = prev_b->next);

	if (!prev_a || !prev_b)
		printf("one of two node are error\n");

	prev_a->next = b;
	prev_b->next = a;
	prev_b = b->next;
	b->next = a->next;
	a->next = prev_b;

	return head;
}

//delete ine list
List*  delete (List *head, List *a){
	assert (head);
	assert(a);
	//a = head

	printf ("delete \n");
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

//search function 
List * search(List *head, int value){
	assert (head);
	List *tmp = head;

	while (tmp){
		if(tmp->val == value){
			printf ("find tmp node value %d \n", tmp->val);
			return tmp;
		}
		tmp = tmp->next;	
	}
	
	return NULL;
}

//insert function
List * insert (List* head, int value){	
	assert(head);
	List *list = (List *) malloc(sizeof(List *));
	if(!list)
		printf ("create failed");	
	//add to last
	if (head){
		//add to last
		List *curr = head;	
		for (;curr->next != NULL;curr=curr->next);
		curr->next = list;
		list->val = value;
		list->next = NULL; // this is important
	}else{
		head = list;
		head->val = value;
	}
	printf ("insert a node");
	return head;
}
	
int listsize(List *head){
	assert(head);
	int i = 0;
	List *tmp = head;
	while (tmp){
		tmp = tmp->next;
		i++;
	}
	
	return i;
}



List *bubblesort(List *head){
	assert (head);
	List *tmp = head;
	while (tmp){		
		assert (tmp->next);
		List *tmp1 = tmp->next;
		while (tmp1){
			if (tmp->val > tmp1->val)
				swap(head, tmp, tmp1);
			tmp1 = tmp1->next;
		}
	
		tmp = tmp->next;
	}	

	return head;

}

List* create(List* head, int value){
	
	//assert(head);
	List* list = NULL;
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
		curr->next = list;
		list->val = value;
		list->next = NULL;
		return head;

	}else {
		curr = list;
		curr->val = value;
		curr->next = NULL;
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

void test (List *head){
	assert(head);
	List *tmp = head;
	tmp++;
	printf ("value = %d\n", tmp->val);	


}

int main (void){
	//just a test 
	int i;
	int max = 3;
	int a[]	= {1,3,2};
 
	List *head = NULL;
	for (i = 0; i < max; i++){		
		head = create(head,a[i]);
	}
	
	printList(head);
	
/*	List *tmp = search(head, 3);
	if (!tmp)
		printf("cannot find tmp\n");
	head = delete(head, tmp);
	printList(head);

	head = insert(head, 7);
	printList(head);
	printf ("List size %d\n", listsize(head));
	//test(head);
*/
	head = bubblesort(head);
	printList(head);
	
	freeList(head);

	return 0;
	
}
