#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct _List{
	struct _List *next;
	int val;
} List;


List **head = NULL;

List * New(int a){

	List *tmp = (List *)malloc(sizeof(List));
	tmp-> val = a;
	tmp-> next = NULL;
	return tmp;
}


void print(List **head){

	assert(head);
	List *curr = *head;
	while(curr){
		printf("val %d\n", curr->val);
		curr = curr->next;
	}
}

int swap (List **head, List *a, List *b){

	assert(head);
	assert(a);
	assert(b);
	/*head = a or b */
	if (a == *head || b == *head){
		List *nohead = (a = *head) ? b:a;
		List *curr = *head;

		for (;curr->next != nohead; curr = curr->next);
		curr->next = *head;
		curr = nohead->next;
		nohead->next = (*head)->next; 
		(*head)->next = curr;
		*head = nohead;
		return 0;
	}


	List *prev_a = *head;
	List *prev_b = *head;

	for(; prev_a->next != a; prev_a = prev_a->next);
	for(; prev_b->next != b; prev_b = prev_b->next);

	prev_a ->next = b;
	prev_b ->next = a;

	prev_a = b->next;
	b->next = a->next;
	a->next = prev_a;
	return 0;

}

int bubblesort(List **head)
{

	assert(head);

	List *tmp = *head;

	while (tmp){
		List *tmp1 = tmp->next;
		while(tmp1){
			if(tmp->val > tmp1->val){
				swap(head, tmp, tmp1);
			}
			tmp1 = tmp1->next;
		}

		tmp = tmp->next;
	}

	return 0;
}


int main (void){
	
	List *tmp0 = New(0);
	List *tmp1 = New(1);
	List *tmp2 = New(2);
	List *tmp3 = New(3);

	tmp0->next = tmp1;
	tmp1->next = tmp2;
	tmp2->next = tmp3;
	
	head = &tmp0;
	
	print(head);

	swap(head, tmp0, tmp1);
	printf("swap \n");

	print(head);

	printf("bubble sort\n");
	bubblesort(head);
	print(head);

	return 0;
}
