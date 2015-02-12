#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

node* list_insert_tail(node* list, char* new_data) {
  node* current;
  if(!list) {
    list = malloc(sizeof(node));
    current = list;
  }
  else {
    current = list;
    while(current->next != NULL)
      current = current->next;
    current->next = malloc(sizeof(node));
    current = current->next;
  }
  current->next = NULL;
  current->data = malloc(sizeof(char) * (1 + strlen(new_data)));
  strcpy(current->data, new_data);
  return list;
}

node* list_insert_head(node* list, char* new_data) {
  node* rtn = malloc(sizeof(node));
  rtn->next = list;
  rtn->data = malloc(sizeof(char) * (1 + strlen(new_data)));
  strcpy(rtn->data, new_data);
  return rtn;
}

node* list_insertn(node* list, char* new_data, int n) {
  if(n == 1) {
    return list_insert_head(list, new_data);
  }
  node* current = list;
  int i = 2;
  while(i < n && current->next != NULL) {
    current = current->next;
    i++;
  } 
  node* new = malloc(sizeof(node));
  new->data = malloc(sizeof(char) * (1 + strlen(new_data)));
  strcpy(new->data, new_data);
  new->next = current->next;
  current->next = new;
  return list;
}

node* list_remove(node* list, char* data) {
  if(list == NULL)
    return NULL;
  node* current = list;
  // if node is the head, deal with it:
  if(!strcmp(current->data, data)) {
    node* rtn = current->next;
    free(current->data);
    free(current);
    return rtn;
  }
  // if node is in the middle or the tail, deal with it:
  while(current->next != NULL) {
    if(!strcmp(current->next->data, data)) {
      node* nxt = current->next->next;
      free(current->next->data);
      free(current->next);
      current->next = nxt;
      return list;
    }
    current = current->next;
  }
  return list;
}

node* list_removen(node* list, int n) {
  if(n < 0)
    return list;
  if(n == 1) {
    node* rtn = list->next;
    free(list->data);
    free(list);
    return rtn;
  }
  int i = 2;
  node* current = list;
  while(i < n && current->next != NULL) {
    i++;
    current = current->next;
  }
  if(i < n || current->next == NULL) {
    printf("Could not remove item #%d\n", n);
    return list;
  }
  node* nxt = current->next->next;
  free(current->next->data);
  free(current->next);
  current->next = nxt;
  return list;
}

void list_print(node* list) {
  node* current = list;
  while(current != NULL) {
    printf("%s\n", current->data);
    current = current->next;
  }
}

void list_printn(node* list, int n) {
  node* current = list;
  int i = 1;
  while(i < n && current != NULL) {
    current = current->next;
    i++;
  }
  if(i != n) {
    printf("Error trying to print item %d; only %i items in the list\n", n, i);
    return;
  }
  printf("%s\n", current->data);
}

char* list_get(node* list, int n) {
  int i = 1;
  node* current = list;
  while(i < n && current != NULL) {
    current = current->next;
    i++;
  }
  if(i < n) {
    printf("Error trying to retrieve item %d\n", n);
    return NULL;
  }
  return current->data;
}

void list_destroy(node* list) {
  node* current = list;
  while(current != NULL) {
    node* nxt = current->next;
    free(current->data);
    free(current);
    current = nxt;
  }
}

int list_length(node* list){
    int size = 0;
    node* current = list;
    while(current->next != NULL){
        current = current->next;
        size++;
    }
    return size;
}
