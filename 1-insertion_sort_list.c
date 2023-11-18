#include "sort.h"
/**
  * insertion_sort_list - insertion sort clone uisng list
  * @list: linked list
  */
void insertion_sort_list(listint_t **list)
{

listint_t *current, *temp;

if (list == NULL || *list == NULL || (*list)->next == NULL)
return;

for (current = (*list)->next; current != NULL; current = current->next)
{
temp = current;
while (temp->prev != NULL && temp->n < temp->prev->n)
{
/* Swap the nodes */
if (temp->next != NULL)
temp->next->prev = temp->prev;
temp->prev->next = temp->next;
temp->next = temp->prev;
temp->prev = temp->prev->prev;
temp->next->prev = temp;
if (temp->prev != NULL)
temp->prev->next = temp;
else
*list = temp;

/* Print list after each swap */
print_list(*list);
}
}
}
