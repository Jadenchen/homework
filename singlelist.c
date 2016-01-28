
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

int listSize (List* head){
	assert(head);
	int size = 0;
	while (head->next != NULL)
		size++;
	return size;
}

List* bubble_sort(List* head){
	List* head = head;
	int size = listSize(head);
	int i,j;
	for ( i = 0; i < (size -1);i++){
		for(j = 0; j < (size-i-1); j++)
			if((head+j)->val > (head+j+1)->val){
				swap(head, head+j, head+j+1);
			}
	}
	return head;
	
}


// not finish test case 

List* head creat(int value){
	List* list;
	List* first;
	list = (List *)malloc(sizeof(List *));
	if (first)
		list = first->next;

	else {
		first = list;
	}

	list-> val = value;

}

int main (void){
	//just a test 
	int i =0;
	
	swap()
	return 0;
	}
}
