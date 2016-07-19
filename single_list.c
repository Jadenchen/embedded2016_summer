#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct _List {
    struct _List *next;
    int val;
} List;


void print_list(List *head)
{
	if (head == NULL)
		printf("head is null\n");
    assert(head);
    List *curr = head;

    while(curr) {
        printf("%d\n", curr->val);
        curr = curr->next;
    }


}

int swap (List **head, List *a, List *b)
{

    assert(head);
    assert(a);
    assert(b);
    /*head = a or b */
    if (a == *head || b == *head) {
        List *nohead = (a = *head) ? b:a;
        List *curr = *head;

        for (; curr->next != nohead; curr = curr->next);
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

int bubble_sort(List **head)
{

    assert(head);

    List *tmp = *head;

    while (tmp) {
        List *tmp1 = tmp->next;
        while(tmp1) {
            if(tmp->val > tmp1->val) {
                swap(head, tmp, tmp1);
            }
            tmp1 = tmp1->next;
        }

        tmp = tmp->next;
    }

    return 0;
}

List *list_append (List **list, int val)
{
    List *tmp = (List *)malloc(sizeof(List));
    if (tmp == NULL) {
        printf("can not create memory \n");
        return NULL;
    }

    tmp-> val = val;
    tmp-> next = NULL;

    List *curr = *list;

	/*chech head is null */
    if (curr == NULL) {
        curr = tmp;
        return tmp;
    }

    //r(; curr==MNULLcurr= curr->next);
    for(;curr->next != NULL; curr = curr->next);

    curr->next = tmp;
	
    return *list;
}


int main (int argc, char *argv[])
{

    int test_count = atoi(argv[1]);
    char *test_input = argv[2];

    FILE *file = fopen(test_input, "r");

    List *list = NULL;

    int num;

    int i;
    for(i = 0; i < test_count; i++) {
        fscanf(file, "%d", &num);
        list = list_append(&list, num);
    }

  	fclose(file);

    bubble_sort(&list);

    print_list(list);
	

	
/*	int i;
	List *list = NULL;
	for (i = 0; i < 5; i++)
		list = list_append(&list, i);

	print_list(list);
*/
    return 0;
}
