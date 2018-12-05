/**
 * CS 2110 - Fall 2018 - Homework #8
 *
 * @author YOUR NAME HERE
 *
 * struct list.c: Complete the functions!
 */

/**
 * !!!!!!!!!!!!!!!!!!!!!!!!!!!!-IMPORTANT-!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 * For any function that must use malloc, if malloc returns NULL, the function
 * itself should return NULL if needs to return something (or return 0 if
 * the function returns a int).
 */

// Do not add ANY additional includes!!!
#include <stdlib.h>
#include <stdio.h>
#include "list.h"

// This is just to remove compiler warnings associated with unused variables.
// Delete calls to this as you implement functions.
#define UNUSED_PARAMETER(x) (void)(x)

/* The struct list_node struct. Has a next pointer, and data. */
/* DO NOT MODIFY THIS STRUCTURE */
/* Only this file should deal with the struct list_node struct */
struct list_node
{
    struct list_node *next;
    struct person *data;
};

/* You should NOT have any global variables. */

/* The create_node function is static because this is the only file that should
   have knowledge about the nodes backing the linked struct list. */
static inline struct list_node *create_node(struct person *data);

/** create_node
  *
  * Helper function that creates a struct list_node by allocating memory for it on the heap.
  * Be sure to set its next pointer to NULL.
  *
  * If malloc returns NULL, you should return NULL to indicate failure.
  *
  * @param data a void pointer to data the user wants to store in the struct list
  * @return a struct list_node
  */
static struct list_node* create_node(struct person *data)
{
    struct list_node *temp = malloc(sizeof(struct list_node));
    if(temp == NULL){
      free(temp);
      return NULL;
    } 

    /*temp->data = malloc(sizeof(struct person));
    if(temp->data == NULL){
      free(temp-> data);
      return NULL;
    }*/
    temp->data = (struct person* )data;
    temp->next = NULL;
    //free(temp);

    return temp;
}

/** create_list
  *
  * Creates a struct list by allocating memory for it on the heap.
  * Be sure to initialize size to zero and head and tail to NULL.
  *
  * If malloc returns NULL, you should return NULL to indicate failure.
  *
  * @return a pointer to a new struct list or NULL on failure
  */
struct list *create_list(void)
{
    struct list *l = malloc(sizeof(struct list));
    if(l == NULL){
      return NULL;
    }
    /**l->head = malloc(sizeof(struct list_node));
    if(l->head == NULL){
      free(l);
      free(l->head);
      return NULL;
    }
    l->tail = malloc(sizeof(struct list_node));
    if(l->tail == NULL){
      free(l-> head);
      free(l);
      return NULL;
    }
    */
    l->head = NULL;
    l->tail = NULL;
    l->size = 0;

    return l;
}

/** copy_list
  *
  * Create a new struct list structure, new nodes, and new copies of the data
  * by using the person_copy function (check out the description for this in
  * person.c).
  *
  * If listToCopy is NULL return NULL. For memory allocations
  * failures, including if person_copy returns 0 (indicating a memory
  * allocation failure), your code must not leak memory. This means that if any
  * memory allocation failures occur, before you return NULL, you must go back
  * and free all data in the new struct list, nodes in the new struct list, and
  * the new struct list itself (you may find the empty_list function useful for
  * this).
  *
  * If you need to free a newly allocated person struct created by person_copy,
  * you should use person_free.
  *
  * @param listToCopy A pointer to the struct list structure to make a copy of
  * @return The struct list structure created by copying the old one, or NULL on
  *         failure (includes any of the parameters being null)
  */
struct list *copy_list(struct list *listToCopy)
{
    UNUSED_PARAMETER(listToCopy);
    /**  
    if(listToCopy == NULL){
      return NULL;
    }

    struct list copy =  create_list();
    if(copy == NULL){
      return NULL;
    }
    struct list_node current_node = malloc(sizeof(list_node));

    if(current_node == NULL){
      return NULL;
    }

    struct list_node holding_node = malloc(sizeof(list_node));
    if(current_node == NULL){
      return NULL;
    }

    current_node = listToCopy -> head;
    copy -> head, copy -> tail = create_node(current_node -> data);
    current_node = current_node -> next;
    holding_node = copy -> head;

    while(current_node != NULL){
      struct person pcopy = malloc(sizeof(struct person));
      if(pcopy == NULL){
        return NULL;
      }
      pcopy = 
      struct list_node temp_node = create_node();
      holding_node -> next = temp_node;
      current_node = current_node -> next;
    } */
    return 0;
}

/** push_front
  *
  * Adds the element at the front of the struct list.
  *
  * @param listToPrependTo a pointer to the struct list structure.
  * @param data the data to add to the struct list.
  * @return 0 if the struct list is NULL, 1 if successful.
  */
int push_front(struct list *listToPrependTo, struct person *data)
{
    if(listToPrependTo == NULL){
      return 0;
    }
    //UNUSED_PARAMETER(listToPrependTo);
    //UNUSED_PARAMETER(data);
    struct list_node *new_head = create_node(data);
    if(new_head == NULL){
      //free(new_head);
      return 0;
    }
    struct list *list = (struct list*) listToPrependTo;
    //struct list *list = (struct list*) listToPrependTo;
    if(list-> size == 0){
      list -> head = new_head;
      list -> tail = new_head;
      list -> size++;
    } else{
      new_head -> next = list->head;
      listToPrependTo -> head = new_head; 
      list -> size++;
    }
    //free(new_head -> data);
    //free(new_head -> next);
    //free(new_head);
    return 1;
}

/** push_back
  *
  * Adds the element to the back of the struct list.
  *
  * @param listToAppendTo a pointer to the struct list structure.
  * @param data the data to add to the struct list.
  * @return 0 if the struct list is NULL, 1 if successful.
  */
int push_back(struct list *listToAppendTo, struct person *data)
{
    //UNUSED_PARAMETER(listToAppendTo);
    //UNUSED_PARAMETER(data);
      if(listToAppendTo == NULL){
      return 0;
    }
    //UNUSED_PARAMETER(listToPrependTo);
    //UNUSED_PARAMETER(data);
    struct list_node *new_tail = create_node(data);
    if(new_tail == NULL){
      //free(new_tail);
      return 0;
    }
    struct list *list = (struct list*) listToAppendTo;
    if(list -> size == 0){
      list -> tail = new_tail;
      list -> head  = new_tail;
      list -> size++;
    } else{
      list -> tail -> next = new_tail; 
      list -> tail = new_tail;
      list -> size++;
    }
    return 1;

}

/** add
  *
  * Add the element at the specified index in the struct list. This index must lie in
  * the inclusive range [0,size].
  * For example, if you have no elements in the struct list,
  * you should be able to add to index 0 but no further.
  * If you have two elements in the struct list,
  * you should be able to add to index 2 but no further.
  *
  * @param listToAddTo a pointer to the struct list structure
  * @param index 0-based, starting from the head in the inclusive range
  *              [0,size]
  * @param data the data to add to the struct list
  * @return 0 if the index is out of bounds or the struct list is NULL
  *         (do not add the data in this case)
  *         otherwise return 1
  */
int add(struct list *listToAddTo, int index, struct person *data)
{
  if( listToAddTo == NULL){
    return 0;
  } 
  else if(index > listToAddTo -> size || index < 0){
    return 0;
  }

  struct list_node *new_node = create_node(data);
  if(new_node == NULL){
    return 0;
  }
  struct list_node *current_node = listToAddTo -> head;
  int i;
  if(index == 0){
    if(listToAddTo -> tail == NULL && listToAddTo -> head == NULL){
      listToAddTo -> tail = new_node;
      listToAddTo -> head = new_node;
    }else{
      new_node -> next = listToAddTo-> head;
      listToAddTo -> head = new_node;

    }
  } else if(index == listToAddTo -> size){
    if(listToAddTo -> head == NULL){
      listToAddTo -> head = new_node;
      listToAddTo -> tail = new_node;
    }else{
      listToAddTo-> tail -> next = new_node;
      listToAddTo -> tail = new_node;
    }
  } else{
    for(i = 0; i < index; i++){
      current_node = current_node->next;
    }
    new_node -> next = current_node-> next;
    current_node -> next =  new_node;
    struct person *temp = current_node -> data;
    current_node -> data = new_node -> data;
    new_node -> data = temp;
  }
    listToAddTo -> size++;
 

    return 1;
}

/** front
  *
  * Gets the data at the front of the struct list
  * If the struct list is empty or the struct list is NULL, return 0.
  *
  * @param listToGetFrontOf a pointer to the struct list
  * @param dataOut A pointer to a pointer used to return the data at the first
  *                struct list_node in the struct list or NULL on failure.
  * @return 0 if dataOut is NULL or the struct list is NULL or empty, 1 if
  *         successful.
  */
int front(struct list *listToGetFrontOf, struct person **dataOut)
{
  if(dataOut == NULL ){
    return 0;
  }else if(listToGetFrontOf == NULL){
    *dataOut = NULL;
    return 0;
  }else if(listToGetFrontOf -> size == 0){
    *dataOut = NULL;
    return 0;
  }
  *dataOut = (listToGetFrontOf -> head -> data);
    //UNUSED_PARAMETER(listToGetFrontOf);
    //UNUSED_PARAMETER(dataOut);
    return 1;
}

/** back
  *
  * Gets the data at the back of the struct list
  * If the struct list is empty or the struct list is NULL, return 0.
  *
  * @param listToGetBackOf a pointer to the struct list
  * @param dataOut A pointer to a pointer used to return the data at the last
  *                struct list_node in the struct list or NULL on failure.
  * @return 0 if dataOut is NULL or the struct list is NULL or empty, 1
  *         otherwise
  */
int back(struct list *listToGetBackOf, struct person **dataOut)
{
   
  if(dataOut == NULL ){
    return 0;
  }else if(listToGetBackOf == NULL){
    *dataOut = NULL;
    return 0;
  } else if(listToGetBackOf -> head == NULL && listToGetBackOf -> tail == NULL && listToGetBackOf -> size == 0){
    *dataOut = NULL;
    return 0;
  }
  *dataOut = (listToGetBackOf -> tail -> data);
    //UNUSED_PARAMETER(listToGetFrontOf);
    //UNUSED_PARAMETER(dataOut);
    return 1;
}

/** get
  *
  * Gets the data at the specified index in the struct list
  *
  * @param listToGetDataFrom a pointer to the struct list structure
  * @param index 0-based, starting from the head.
  * @param dataOut A pointer to a pointer used to return the data from the
  *        specified index in the struct list or NULL on failure.
  * @return 0 if dataOut is NULL or index is out of range of the struct list or
  *         the struct list is NULL, 1 otherwise
  */
int get(struct list *listToGetDataFrom, int index, struct person **dataOut)
{
    if(dataOut == NULL){
      return 0;
    } else if(listToGetDataFrom  == NULL){
      *dataOut = NULL;
      return 0;
    }else if( index < 0 || index >= listToGetDataFrom -> size){
      *dataOut = NULL;
      return 0;
    }

    struct list_node *current_node = malloc(sizeof(struct list_node));
    current_node = listToGetDataFrom -> head;
    int i = 0;
    while(current_node != NULL){
      if(i == index){
        *dataOut = current_node->data;
        //free(current_node);
        return 1;
      }
      i++;
      current_node = current_node -> next;
    }
    *dataOut = NULL;
    //free(current_node);
    return 0;
}

/** size
  *
  * Gets the size of the struct list
  *
  * if the struct list is NULL, return 0.
  *
  * @param listToGetSizeOf a pointer to the struct list structure
  * @param A pointer used to return the size of the struct list, set to -1 on NULL struct list
  * @return 0 if sizeOut is NULL or struct list is NULL, 1 otherwise
  */
int size(struct list *listToGetSizeOf, int *sizeOut)
{
    if(sizeOut == NULL){
      return 0;
    }else if(listToGetSizeOf == NULL){
      *sizeOut = -1;
      return 0;
    } 
  *sizeOut = listToGetSizeOf -> size;
  return 1;
}

/** contains
  *
  * Traverses the struct list, trying to see if the struct list contains some
  * data.
  *
  * The "data" parameter may not necessarily point to the same address as the
  * equal data you are returning from this function, it's just data which the
  * comparator (person_eq_name in this case) says is equal.
  *
  * If there are multiple pieces of data in the struct list which are equal to
  * the "data" parameter, return the one at the lowest index.
  *
  * Use person_eq_name to compare person structs. Be sure to take a look at that
  * function before you use it! Also be sure not to use person_eq.
  *
  * @param listToSearch a pointer to the struct list structure
  * @param data The data, to see if it exists in the struct list
  * @param dataOut A pointer to a pointer used to return the data contained in
  *                the struct list or NULL on failure
  * @return int    0 if dataOut is NULL, the list is NULL, or the list
  *                does not contain data, else 1
  */
int contains(struct list *listToSearch, struct person *data, struct person **dataOut)
{
   if(dataOut == NULL ){
    return 0;
  }else if(listToSearch == NULL){
    *dataOut = NULL;
    return 0;
   } else if(listToSearch -> size == 0){
    *dataOut = NULL;
    return 0;
   } 
   struct list_node *current_node = malloc(sizeof(struct list_node));
   current_node = listToSearch -> head;

   while(current_node != NULL){
    if(person_eq_name(current_node->data, data) == 0){
      *dataOut = current_node -> data;
      //free(current_node);
      return 1;
    }
    current_node = current_node -> next;
   }
    *dataOut = NULL;
    //free(current_node);
    return 0;
}


/** pop_front
  *
  * Removes the struct list_node at the front of the struct list, and returns its data to the user
  *
  * @param listToPopFrom a pointer to the struct list.
  * @param dataOut A pointer to a pointer used to return the data in the first
  *                struct list_node or NULL on failure
  * @return 0 if dataOut is NULL or the struct list is NULL or empty, else 1
  */
int pop_front(struct list *listToPopFrom, struct person **dataOut)
{
  if(dataOut == NULL ){
    return 0;
  }else if(listToPopFrom == NULL){
    *dataOut = NULL;
    return 0;
  }else if(listToPopFrom -> head == NULL || listToPopFrom -> tail == NULL){
    *dataOut = NULL;
    return 0;
  } 
    *dataOut = listToPopFrom -> head -> data;
    listToPopFrom -> head = listToPopFrom -> head ->  next;
    listToPopFrom -> size--;
    if(listToPopFrom -> size == 1){
      listToPopFrom -> tail = listToPopFrom -> head; 
    }
    else if(listToPopFrom -> size == 0){
      listToPopFrom -> head = NULL;
      listToPopFrom -> tail = NULL;
    }
    //UNUSED_PARAMETER(listToPopFrom);
    //UNUSED_PARAMETER(dataOut);
    return 1;
}

/** pop_back
  *
  * Removes the struct list_node at the back of the struct list, and returns its data to the user
  *
  * @param listToPopFrom a pointer to the struct list.
  * @param dataOut A pointer to a pointer used to return the data in the last
  *                struct list_node or NULL on failure
  * @return 0 if dataOut is NULL or the struct list is NULL or empty, else 1
  */
int pop_back(struct list *listToPopFrom, struct person **dataOut)
{  if(dataOut == NULL ){
    return 0;
  }else if(listToPopFrom == NULL){
    *dataOut = NULL;
    return 0;
  }else if(listToPopFrom -> head == NULL || listToPopFrom -> tail == NULL){
    *dataOut = NULL;
    return 0;
  }
    *dataOut = listToPopFrom -> tail -> data;
    struct list_node *current_node = malloc(sizeof(struct list_node));
    current_node = listToPopFrom -> head;
    int i;
    for(i = 0;i < listToPopFrom -> size -2; i++){
      current_node = current_node -> next;
    }
    listToPopFrom -> tail = current_node;
    current_node = current_node -> next;
    listToPopFrom -> tail -> next = NULL;

    listToPopFrom -> size--;
    if(listToPopFrom -> size == 1){
      listToPopFrom -> tail = listToPopFrom -> head; 
    }
    else if(listToPopFrom -> size == 0){
      listToPopFrom -> head = NULL;
      listToPopFrom -> tail = NULL;
    }

    free(current_node);
 
    return 1;
}

/** list_remove
  *
  * Removes a specified data element from the struct list.
  *
  * The element to be removed is the one that is equal to the data_to_remove
  * parameter by way of the comparator function passed in. This function
  * returns 0 when its arguments are equal.
  *
  * If the struct list contains multiple elements that are equal to data_to_remove,
  * then the one with the lowest index only is to be removed.
  *
  * Use person_eq_name to compare person structs. Be sure to take a look at that
  * function before you use it! Also be sure not to use person_eq.
  *
  * @param listToRemoveFrom             a pointer to the struct list structure
  * @param data_to_remove               The element to remove from the struct list.
  * @param dataOut                      A pointer to a pointer used to
  *                                     return the data from the specified
  *                                     index in the struct list or NULL on failure
  *
  * @return int                         0 if dataOut is NULL, or the list is
  *                                     NULL, else 1.
  */
int list_remove(struct list *listToRemoveFrom,
                 struct person *data_to_remove,
                 struct person **dataOut)
{
  if(dataOut == NULL ){
    return 0;
  } else if(listToRemoveFrom == NULL){
    *dataOut = NULL;
    return 0;
  }

  if(person_eq_name(listToRemoveFrom -> head -> data, data_to_remove) == 0){
    *dataOut  = listToRemoveFrom -> head -> data;
    //person_free()
    listToRemoveFrom -> head = listToRemoveFrom -> head -> next;
    listToRemoveFrom -> size--;

    return 1;
    
  }
  struct list_node *current_node = malloc(sizeof(struct list_node));
  struct list_node *prev_node = malloc(sizeof(struct list_node));
  
  current_node = listToRemoveFrom -> head -> next;
  prev_node = listToRemoveFrom -> head;

  while(current_node != NULL ){
    if(person_eq_name(current_node->data, data_to_remove) == 0){
      if(current_node -> next == NULL){
        //free(current_node);
        listToRemoveFrom -> tail = prev_node;
        *dataOut = current_node -> data;
        //free(current_node -> data);
        //person_free(current_node -> data);
        //free(current_node -> next);
       //free(current_node);
       prev_node -> next = NULL;
      } 
      else {
        prev_node -> next = current_node -> next;
        *dataOut = current_node -> data;
        //free(current_node);
      }
      //person_free(current_node -> data);
      //free(current_node -> next);
      //free(current_node -> data);
      listToRemoveFrom -> size--;
      free(current_node);
      //free(prev_node);
      return 1;
    }
    prev_node = current_node;
    current_node = current_node-> next;
  }   
  free(current_node);
  //free(prev_node);
  *dataOut = NULL;
  return 0;
}

/** empty_list
  *
  * Empties the struct list. After this is called, the struct list should be
  * empty. This does not free the struct list struct itself, just all nodes and
  * data within. Make sure to check that listToEmpty and is not NULL before
  * using it.
  *
  * Call person_free to free a person struct.
  *
  * @param listToEmpty a pointer to the struct list structure
  */
void empty_list(struct list *listToEmpty)
{

  if(listToEmpty != NULL){
    struct list_node *next_node = malloc(sizeof(struct list_node));
    struct list_node *current_node = malloc(sizeof(struct list_node));
    //free(current_node);
    current_node = listToEmpty -> head;

    //free(current_node);
    while(current_node  != NULL){

      next_node =  current_node-> next;

      person_free(current_node -> data);
      //free(listToEmpty-> head-> data);
      //free(listToEmpty -> head -> next);
      //free(current_node);
      free(current_node);
      current_node  = next_node;
      //free(next_node);
    }
 
    //free(current_node);
    //free(next_node);
    listToEmpty -> head = NULL;
    listToEmpty -> tail = NULL;
    listToEmpty -> size = 0;
   // next_node = NULL;
   // current_node = NULL;
  }
   
    //UNUSED_PARAMETER(listToEmpty);
}

/** reverse
  *
  * Reverses the singly linked struct list in place.
  *
  * @param listToReverse to append to.
  * @return 1 if the operation was a success, 0 otherwise (listToReverse
  *         was NULL)
  */
int reverse(struct list *listToReverse)
{
      if(listToReverse == NULL){
        return 0;
      }
    struct list *reverse_list = create_list();
    struct list_node *current_node = malloc(sizeof(struct list_node));
    current_node = listToReverse -> head;
    while(current_node != NULL){
      push_front(reverse_list, current_node-> data);
      current_node  = current_node -> next;
      free(current_node);
    }

    listToReverse = reverse_list;

    free(reverse_list);
    //free(current_node);
    //UNUSED_PARAMETER(listToReverse);
    //free(current_node -> next);
    //person_free(current_node -> data);
    //free(current_node -> data);
    //free(current_node);
    //free(reverse_list -> head);
    //free(reverse_list -> tail);
    //free(reverse_list);
    return 1;
}

/** concat
  *
  * Concatinates firstList and secondList. This function should append
  * secondList to the end of firstList.
  *
  * NOTE: this function will effectively empty lastList onto firstList which
  *       means that lastList will be empty (head == tail == NULL and size == 0)
  *       at the end of the function and firstList will contain all the elements
  *       from both lists. Be sure to update the size, head, and tail pointers
  *       accordingly.
  *
  * example: if firstList is a->b->c and second struct list is d->e->f
  * after the function call, firstList will be a->b->c->d->e->f and
  * secondList will be empty.
  *
  *
  * @param firstList to append to.
  * @param secondList the struct list to append to firstList
  * @return 1 if the operation was a success, 0 otherwise (firstList or
  *         secondList is null)
  */
int concat(struct list *firstList, struct list *lastList)
{
    if(firstList == NULL || lastList == NULL){
      return 0;
    }
    if(firstList -> size == 0){
      firstList -> head = lastList -> head;
      firstList -> tail = lastList -> tail;
      firstList -> size = lastList -> size;
      lastList -> head = NULL;
      lastList -> tail = NULL;
      lastList -> size = 0;

    } else if( lastList -> size == 0){
      return 1;
    } else{
      firstList -> tail -> next = lastList -> head;
      firstList -> tail = lastList -> tail;
      firstList -> size = firstList -> size + lastList -> size;
      lastList -> head = NULL;
      lastList -> tail = NULL;
      lastList -> size = 0;
    }

   
    //free(lastList)
    //UNUSED_PARAMETER(firstList);
    //UNUSED_PARAMETER(lastList);
    return 1;
}
