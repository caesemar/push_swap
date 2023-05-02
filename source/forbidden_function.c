
#include "../headers/push_swap.h"

void print_stack(t_lst* head) 
{
    t_lst* current_node = head;
    while (current_node != NULL) {
        printf("content :%d\n", current_node->content);
        printf("index :%d\n", current_node->index);
				printf("\n");
        current_node = current_node->next;
    }
    printf("\n");
}
