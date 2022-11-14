//lista dwukierunkowa
//2022-11-12

#include <stdio.h>
#include <stdlib.h>
#include <float.h>

struct item {
        float value;
        struct item *next;
        struct item *prev;
};

int Emptylist(struct item *head);
void Insert(struct item **item, float value);
void Printlist(struct item *head);
float Max(struct item *head);
float Min(struct item *head);
int Nodecount(struct item *head);
struct item *find(float value, struct item *head);
struct item *Previous(struct item *item);
void Delete(struct item **item);

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
        Delete(&tmp);
        Printlist(tmp);

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
        struct item *tmp;
        newitem        = (struct item *)malloc(sizeof(struct item));
        newitem->next  = NULL;
        newitem->value = value;

        if ((*item == NULL)) {
                (*item) = newitem;
                (*item)->prev = NULL;
                
        } else {
                tmp = *item;
                while (tmp->next != NULL) {
                        tmp = tmp->next;
                }
                tmp->next = newitem;
                newitem->prev=tmp;
        }
}
void Printlist(struct item *head)
{
        if (head) {
                while (head->next != NULL) {
                               printf("%f\n", head->value);
                        head = head->next;
                }
                printf("%f\n", head->value);
        }
}
float Max(struct item *head)
{
        float max = FLT_MIN;
        while (head) {
                if (head->value > max) {
                        max = head->value;
                }
                head = head->next;
        }
        return max;
}
float Min(struct item *head)
{
        float min = FLT_MAX;
        while (head) {
                if (head->value < min) {
                        min = head->value;
                }
                head = head->next;
        }
        return min;
}
int Nodecount(struct item *head)
{
        int k = 0;
        if (head) {
                while (head != NULL) {
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
struct item *Previous(struct item *item)
{       
        if(item!=NULL){
        return item->prev;
        } else {
                return NULL;
        }
}
void Delete(struct item **item)
{
        struct item *tmp;

        if ((*item)->next == NULL) {
                if (Previous(*item)) {
                        Previous(*item)->next = (*item)->next;
                }
                free(*item);
                *item = NULL;
                return;

        } else {
                tmp=*item;
                if (Previous(*item)) {
                Previous(*item)->next = (*item)->next;
                } else {
                        (*item)=(*item)->next;
                }
                free(tmp);
                tmp = NULL;
        }
}
