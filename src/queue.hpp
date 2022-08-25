#ifndef QUEUE_HPP
#define QUEUE_HPP
#include <iostream>
using namespace std;
typedef struct qData qData;
typedef struct qBlock qBlock;
typedef struct Queue Queue;

struct qData {
    int val;
};

struct qBlock {
    qData data;
    qBlock *prox;
};

struct Queue {
    qBlock *first;
    qBlock *last;
};

void MEQueue(Queue *q);
void doQueue(Queue *q, qData value);
void deQueue(Queue *q, qData *value);
bool isQueueEmpty(Queue *q);

#endif