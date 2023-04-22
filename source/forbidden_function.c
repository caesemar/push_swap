
#include "../headers/push_swap.h"

void print_stack(t_stack *s) {
    while (s != NULL) {
        t_lst *head = s->first;
        while (head != NULL) {
            printf("%d ", head->content);
            head = head->next;
        }
        printf("\n");
        s = s->next;
    }
}
