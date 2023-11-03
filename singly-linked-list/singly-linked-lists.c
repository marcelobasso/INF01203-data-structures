#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAME_SIZE 100

// struct that's responsible for storing the information of the node
typedef struct nodeInfo {
    char name[NAME_SIZE];
    int age;
} NodeInfo;

// node of the list, wich contains infos and the address of the next node.
typedef struct node {
    NodeInfo info;
    struct node *next;
} Node;

// initializes the list
Node* initList(void) {
    return ((void *) 0);
}

// prints all the elements in the linked list.
void printList(Node *firstNode) {
    Node *ptAux;

    if (firstNode == ((void *) 0)) {
        puts("Lista vazia");
    } else {
        for (ptAux = firstNode; ptAux; ptAux = ptAux->next)
            printf("Name: %s\nAge: %i", ptAux->info.name, ptAux->info.age);
    }
}

// searches for a name in the list
Node* search(Node *firstNode, char name[NAME_SIZE]) {
    Node *ptAux;

    for (ptAux = firstNode; ptAux && !strcmp(ptAux->info.name, name); ptAux = ptAux->next);

    return ptAux ? ptAux : ((void *) 0);
}

// inserts a node before all the nodes (in the begining)
Node* insertBefore(Node *firstNode, NodeInfo info) {
    Node *newNode;

    newNode = (Node *) malloc(sizeof(Node));
    newNode->info = info;
    newNode->next = firstNode;
    firstNode = newNode;

    return firstNode;
}

// inserts a node after all the nodes (in the end)
Node* insertAfter(Node *firstNode, NodeInfo info) {
    Node *newNode, *ptAux;

    newNode = (Node *) malloc(sizeof(Node));
    newNode->info = info;
    newNode->next = ((void *)0);

    if (ptAux) {
        for (ptAux = firstNode; ptAux->next; ptAux = ptAux->next);
        ptAux->next = newNode;
    } else {
        firstNode = newNode;
    }

    return firstNode;
}

// inserts a node after a given name on the list
Node* insertBetween(Node *firstNode, NodeInfo info) {

}

Node* removeNode(Node *firstNode, char name[NAME_SIZE]) {
    Node *ptLastNode = ((void *) 0);
    Node *ptAux = firstNode;

    while (ptAux && !strcmp(ptAux->info.name, name)) {
        ptLastNode = ptAux;
        ptAux = ptAux->next;
    }

    // if the name wasn't in the list
    if (!ptAux)
        return firstNode;
    
    if (!ptLastNode)
        firstNode = firstNode->next;
    else
        ptLastNode->next = ptAux->next;
    
    free(ptAux);

    return firstNode;
}

Node* destroy(Node *firstNode) {
    Node *ptAux;

    while (firstNode) {
        ptAux = firstNode;
        firstNode = firstNode->next;
        free(ptAux);
    }

    free(firstNode);

    return ((void *) 0);
}

int main() {

    return 0;
}
