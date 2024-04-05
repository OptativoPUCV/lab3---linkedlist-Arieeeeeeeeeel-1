#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
  List* nuevaLista = (List*)malloc(sizeof(List));
  if (nuevaLista == NULL) {
      exit(EXIT_FAILURE);
  }
  nuevaLista->head = NULL; 
  nuevaLista->tail = NULL; 
  nuevaLista->current = NULL; 
  
  return nuevaLista;
}

void * firstList(List * list) {
  if (list == NULL || list->head == NULL) {  //Lista vacía retorna NULL
    return NULL;
  }
  return list->current->data; //Retorna primer dato de la Lista
}

void * nextList(List * list) {
  if (list == NULL || list->current == NULL || list->current->next == NULL) { 
    return NULL;  //Misma lógica que arriba.
  }
  list->current = list->current->next;   //Actualiza el current del struct para que apunte al nodo next (siguiente).
  return list->current->data; //Retornar dato del nodo next (siguiente).
}

void * lastList(List * list) {
    return NULL;
}

void * prevList(List * list) {
    return NULL;
}

void pushFront(List * list, void * data) {
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}