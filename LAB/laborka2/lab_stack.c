                                        
#include<stdio.h>
#include<stdlib.h>


struct data {
        int pancake;
        struct data *next;
};

void add_to_stack();
void print_stack();
void delete_from_top();
int check_stack();
void delete_stack();

int main(){

        struct data *head = NULL;
        //head = malloc(sizeof(struct data));

        add_to_stack(&head,1);
        add_to_stack(&head,2);
        add_to_stack(&head,3);
        print_list(head);
        delete_by_index(&head);
        print_list(head);
        printf("The stack is: %d\n",check_stack(head));
        delete_list(&head);
        print_list(head);

        return 0;
}

void add_to_stack(struct data **head, int pancake){

        if (*head) {
                    struct data *new = (struct data *)malloc(sizeof(struct data));
                        new->pancake = (*head)->pancake;
                        new->next = (*head)->next;
                        (*head)->pancake = pancake;
                        (*head)->next = new;

                }else{
                        (*head) = malloc(sizeof(struct data));
                        (*head)->pancake = pancake;
                        (*head)->next = NULL;

                }
                
      }

void print_stack(struct data *head) {
    if(head){
        while (head->next != NULL) {
            printf("%d\n\n", head->pancake);
                head = head->next;
        }
            printf("%d\n\n", head->pancake);
    }
}
void delete_from_top(struct data **head) {

        struct data *to_delete = NULL;

            if((*head)->next == NULL){
                free(*head);
                *head = NULL;
                return;
        }
                (*head)->pancake = (*head)->next->pancake;
                (*head)->next = (*head)->next->next;

}   
int check_stack(struct data *head) {

        if(head == NULL){

                return 0;

        }else{

                return 1;
        }

} 
void delete_stack(struct data **head) {

            struct data *tmp = *head;
            struct data *next;

            if(tmp != NULL){
            while(!tmp) {
                next = tmp->next;
                free(tmp);
                tmp = next;
            }
            *head = NULL;
            printf("stack deleted\n");
            }else{
            printf("No existing stack\n");
            }
}
