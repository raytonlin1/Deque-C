///////////////////////////////////////////////////////////////////////////// 
// INTEGRITY STATEMENT (v3)
//
// By signing your name and ID below you are stating that you have agreed
// to the online academic integrity statement:
// https://student.cs.uwaterloo.ca/~cs136/current/assignments/integrity.shtml
/////////////////////////////////////////////////////////////////////////////
// I received help from and/or collaborated with: 
 
// None
//  
// Name: Rayton Lin 
// login ID: r56lin 
///////////////////////////////////////////////////////////////////////////// 

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "deque.h"

/////////////////////////////////////////////////////////////////////////////
// DO NOT MODIFY THIS STRUCTURE
/////////////////////////////////////////////////////////////////////////////
struct llnode {
  int item;
  struct llnode *prev;
  struct llnode *next;
};

struct deque {
  struct llnode *front;
  struct llnode *back;
};
/////////////////////////////////////////////////////////////////////////////

// For all functions, see deque.h for documentation

struct deque *deque_create(void) {
  struct deque *output = malloc(sizeof(struct deque));
  output->front = NULL;
  output->back = NULL;
  return output;
}

void deque_destroy(struct deque *deq) {
  assert(deq);
  
  struct llnode *curnode = deq->front;
  struct llnode *nextnode = NULL;
  while (curnode) {
    nextnode = curnode->next;
    free(curnode);
    curnode = nextnode;
  }
  free(deq);
}

bool deque_is_empty(const struct deque *deq) {
  assert(deq);
  
  if (deq->front == NULL) { //Checks if the front node is NULL.
    return true;
  } else {
    return false;
  }
}

void deque_insert_front(int item, struct deque *deq) {
  assert(deq);
  
  struct llnode *newnode = malloc(sizeof(struct llnode));
  newnode->item = item;
  newnode->prev = NULL;
  if (!deque_is_empty(deq)) {
    deq->front->prev = newnode;
  } else {
    deq->back = newnode;
  }
  newnode->next = deq->front;
  deq->front = newnode;
}

int deque_front(const struct deque *deq) {
  assert(deq);
  assert(!deque_is_empty(deq));
  
  return deq->front->item;
}

int deque_remove_front(struct deque *deq) {
  assert(deq);
  assert(!deque_is_empty(deq));
  
  struct llnode *frontnode = deq->front;
  int frontitem = frontnode->item;
  if (deq->front == deq->back) {
    //As deq isn't empty, this means that it only has 1 node.
    deq->front = NULL;
    deq->back = NULL;
  } else {
    deq->front = frontnode->next;
    frontnode->next->prev = NULL;
  }
  free(frontnode);
  return frontitem;
}

void deque_insert_back(int item, struct deque *deq) {
  assert(deq);
  
  struct llnode *newnode = malloc(sizeof(struct llnode));
  newnode->item = item;
  newnode->next = NULL;
  if (!deque_is_empty(deq)) {
    //As deq isn't empty, this means that it only has 1 node.
    deq->back->next = newnode;
  } else {
    deq->front = newnode;
  }
  newnode->prev = deq->back;
  deq->back = newnode;
}

int deque_back(const struct deque *deq) {
  assert(deq);
  assert(!deque_is_empty(deq));
  
  return deq->back->item;
}

int deque_remove_back(struct deque *deq) {
  assert(deq);
  assert(!deque_is_empty(deq));
  
  struct llnode *backnode = deq->back;
  int backitem = backnode->item;
  if (deq->front == deq->back) {
    //As deq isn't empty, that means that deq has 1 item.
    deq->front = NULL;
    deq->back = NULL;
  } else {
    deq->back = backnode->prev;
    backnode->prev->next = NULL;
  }
  free(backnode);
  return backitem;
}

void deque_print(const struct deque *deq) {
  assert(deq);
  
  if (deque_is_empty(deq)) {
    printf("[empty]\n");
  } else if (deq->front == deq->back) {
    //As deq isn't empty, that means that deq has 1 item.
    printf("[%d]\n",deq->front->item);
  } else {
    struct llnode *curnode = deq->front;
    printf("[%d",curnode->item);
    while (curnode->next) {
      curnode = curnode->next;
      printf(",%d",curnode->item);
    }
    printf("]\n");
  }
}

void deque_print_reverse(const struct deque *deq) {
  assert(deq);
  
  if (deque_is_empty(deq)) {
    printf("[empty]\n");
  } else if (deq->front == deq->back) {
    //As deq isn't empty, that means that deq has 1 item.
    printf("[%d]\n",deq->front->item);
  } else {
    struct llnode *curnode = deq->back;
    printf("[%d",curnode->item);
    while (curnode->prev) {
      curnode = curnode->prev;
      printf(",%d",curnode->item);
    }
    printf("]\n");
  }
}
