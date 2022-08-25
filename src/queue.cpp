#include "queue.hpp"

void MEQueue(Queue *q) {
    q -> first = new qBlock;
    q -> last = q -> first;
    q -> first -> prox = NULL;
}

void doQueue(Queue *q, qData value) {
    q -> last -> prox = new qBlock;
    q -> last = q -> last -> prox;
    q -> last -> data = value;
    q -> last -> prox = NULL;
}

void deQueue(Queue *q, qData *value) {
    qBlock *aux;

    if (q -> first == q -> last || q == NULL || q -> first -> prox == NULL) {
        cout << "Nothing in queue" << endl;
        return;
    }

    aux = q -> first -> prox;
    q -> first -> prox = aux -> prox;
    if (q -> first -> prox == NULL) {
        q -> last = q -> first;
    }

    value ->val = aux -> data.val;
    free(aux);
}

bool isQueueEmpty(Queue *q) {
    if (q -> first == q -> last || q -> first-> prox == NULL || q == NULL) {
        return true;
    } 

    return false;
}