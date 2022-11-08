#include<stdio.h>
#include<stdlib.h>

struct data{
    int val;
    struct data *next;   
};

void initialize(struct data **head);
struct data *find_last(struct data *node);
int insert(struct data **head, int val);
void Printlist(struct data *head);

int main() { 

    int val;
    struct data *head = NULL;

    initialize(&head);
    do{
        printf("val:\n");
        scanf("%d",&val);
        insert(&head, val); 
        Printlist(head);
    }
    while(val);
     

    return 0;
}

struct data *find_last(struct data *node){ 
    
    while (node->next!=NULL)
    {
        node=node->next;
    }

    return node;
}

int insert(struct data **head, int val){
    
    int chopped_head=(*head)->val; 
    struct data *oldhead = (*head);
    struct data *tmp = find_last(*head);
    struct data *new = malloc(sizeof(struct data));
    new->val=val;
    new->next=NULL;
    (*head)=(*head)->next;
    tmp->next=new;

    free(oldhead);
}

void initialize(struct data **head)
{   
    *head = malloc(sizeof(struct data));
    (*head)->val=1;
    (*head)->next=malloc(sizeof(struct data));
    (*head)->next->val=2;
    (*head)->next->next=malloc(sizeof(struct data));
    (*head)->next->next->val=3;
}

void Printlist(struct data *head)
{
        if (head) {
                while (head->next != NULL) {
                        printf("%d\n", head->val);
                        head = head->next;
                }
                printf("%d\n", head->val);
        }
}
