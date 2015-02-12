typedef struct s_node {
  char* data;
  struct s_node* next;
} node;

/* list_insert_tail: create a new node at the end of the linked list
   Parameters
   - node*: a pointer to the head of a linked list
   - char*: data to be stored in the new node
   Return: a pointer to the head of the linked list */
node* list_insert_tail(node*, char*);

/* list_insert_head: create a new node and insert it at the head of the linked
    list
   Parameters
   - node*: a pointer to the head of a linked list
   - char*: data to be stored in the new node
   Return: a pointer to the new head of the linked list */
node* list_insert_head(node*, char*);

/* list_insertn: create a new node and insert it at the <n>th position,
    where the head is at position 1
   Parameters
   - node*: a pointer to the head of a linked list
   - char*: data to be stored in the new node
   - int: the position in which to insert the new node
   Return: a pointer to the head of the linked list */
node* list_insertn(node*, char*, int);

/* list_remove: remove the node containing specific data; if multiple nodes
    contain the data, remove the node nearest to the head
   Parameters
   - node*: a pointer to the head of a linked list
   - char*: data that, if found in one of the nodes in the list, indicates
      the node to remove (in the case of multiple nodes containing the data,
      remove the node nearest to the head)
   Return: a pointer to the head of the linked list */
node* list_remove(node*, char*);

/* list_removen: remove the <n>th node in the list
   Parameters
   - node*: a pointer to the head of a linked list
   - int: the position of the node to remove, where the head is at position 1
   Return: a pointer to the head of the linked list */
node* list_removen(node*, int);

/* list_print: print the data contained in each node in the linked list,
    starting with the head, where each node's data is printed on a separate
    line
   Parameter: node*: a pointer to the head of a linked list */
void list_print(node*);

/* list_printn: print the data contained in the <n>th node of the list
   Parameters:
   - node*: a pointer to the head of a linked list
   - int: the position of the node with the data to print, where the head is
       at position 1 */
void list_printn(node*, int);

/* list_get: retrieve the data stored in the <n>th node in the list
   Parameters:
   - node*: a pointer to the head of a linked list
   - int: the position of the node with the data to retrieve, where the head is
       at position 1
   Return: the data */
char* list_get(node*, int);

/* list_destroy: free all malloc'd memory used in the linked list,
    including char*'s and node*'s
   Parameter: node*: a pointer to the head of a linked list */
void list_destroy(node*);

/* list_length() gets the number of nodes in the list
   Parameters:
   - node*: a pointer to the head of a linked list
   Return: length */
int list_length(node*);
