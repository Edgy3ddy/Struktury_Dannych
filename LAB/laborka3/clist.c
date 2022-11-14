// Lista cykliczna niesortowana
// 2022-11-12:
#include <stdio.h>
#include <stdlib.h>
#include <float.h>

struct item {
	float value;
	struct item *next;
};

int Emptylist(struct item *head);
void Insert(struct item **item, float value);
void Printlist(struct item *head);
float Max(struct item *head);
float Min(struct item *head);
int Nodecount(struct item *head);
struct item *find(float value, struct item *head);
struct item *Previous(struct item *item, struct item *head);
void Delete(struct item **item, struct item *head);

int main()
{
	struct item *head = NULL, *tmp = NULL;
	int i, n;
	float value;

	printf("The list is: %d\n", Emptylist(head));
	printf("Enter the number of elements: ");
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		printf("Enter value ");
		scanf("%f", &value);
		Insert(&head, value);
	}
	printf("The list is:\n");
	Printlist(head);
	printf("MAX is: %f \n", Max(head));
	printf("MIN is: %f \n", Min(head));
	printf("Node count: %d \n", Nodecount(head));
	printf("Find by value: ");
	scanf("%f", &value);
	printf("Searched item: %f \n", find(value, head)->value);
	tmp = find(value, head);
	Delete(&tmp, head);
	Printlist(head);

	return 0;
}
int Emptylist(struct item *head)
{
	if (head == NULL) {
		return 1;
	} else {
		return 0;
	}
}
void Insert(struct item **item, float value)
{
	struct item *newitem;
	struct item *tmp=*item;
	newitem	       = (struct item *)malloc(sizeof(struct item));
	newitem->next  = *item;
	newitem->value = value;

	if (*item == NULL) {
		(*item) = newitem;
        (*item)->next=*item;
	} else {
		tmp = *item;
		while (tmp->next != *item) {
			tmp = tmp->next;
		}
		tmp->next = newitem;
        tmp->next->next=*item;
	}
}
void Printlist(struct item *head)
{
    struct item *tmp = head;

	if (head) {
		while (head->next != tmp) {
			printf("%f\n", head->value);
			head = head->next;
		}
		printf("%f\n", head->value);
	}
}
float Max(struct item *head)
{
    struct item *tmp=head;
	float max = FLT_MIN;
	while (head->next != tmp) {
		if (head->value > max) {
			max = head->value;
		}
		head = head->next;
	}
        if (head->value > max) {
			max = head->value;
		}       
	return max;
}
float Min(struct item *head)
{
    struct item *tmp=head;
	float min = FLT_MAX;
	while (head->next != tmp) {
		if (head->value < min) {
			min = head->value;
		}
		head = head->next; 
	}
    if (head->value < min) {
			min = head->value;
		}       
	return min;
}
int Nodecount(struct item *head)
{
    struct item *tmp = head;
	int k = 0;
	if (head) {
		while (head->next != tmp) {
			k++;
			head = head->next;
		}
		return k;
	}
}
struct item *find(float value, struct item *head)
{
	while (head) {
		if (value == head->value) {
			return head;
		}
		head = head->next;
	}
	return NULL;
}
struct item *Previous(struct item *item, struct item *head)
{
	if (head->next) {
		while (head->next != item) {
			head = head->next;
		}
		return head;
	} else {
		return NULL;
	}
}
void Delete(struct item **item, struct item *head)
{
	if ((*item)->next == NULL) {
		if (Previous(*item, head)) {
			Previous(*item, head)->next = (*item)->next;
		}
		free(*item);
		*item = NULL;
		return;

	} else {
		if (Previous(*item, head)) {
		Previous(*item, head)->next = (*item)->next;
		}
		free(*item);
		*item = NULL;
	}
}
