#include "tree.hpp"
#include "queue.hpp"

void treeInit (Tree **t) {
    *t = NULL;
}

void treeInsert (Tree **t, Data content) {
    int cont = (*t) -> item.level;

    if (*t == NULL) {
        new Tree;
        (*t) -> fd = NULL;
        (*t) -> fe = NULL;
        content.level = 1;
        (*t) -> item = content;
    } else {
        content.level = cont + 1;
        if ((*t) -> item.value > content.value) {
            treeInsert((*t) -> fe, content);
        } else {
            treeInsert((*t)->fd, content);
        }
    }
}

int getHeight(Tree **t) {
    if (t == NULL) {
        return 0;
    }

    Queue aQueue;
    MEQueue(&aQueue);
    // doQueue(&aQueue, t);
    Tree aux;

    while(!isQueueEmpty(&aQueue)) {
        deQueue(&aQueue, &aux);
        if ((*t) -> fe != NULL) {
            doQueue(&aQueue, t);
        }

        if ((*t) -> fd != NULL) {
            doQueue(&aQueue, t);
        }
    }

    return aux.item.level;
}