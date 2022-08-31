#include "tree.hpp"
#include "queue.hpp"

void treeInit (Tree **t) {
    *t = NULL;
}

void treeInsert (Tree **t, Data content, int *previousLevel) {
    if (*t == NULL) {
        (*t) = new Tree;
        (*t) -> fd = NULL;
        (*t) -> fe = NULL;
        content.level = *previousLevel + 1;
        (*t) -> item = content;
    } else {
        if ((*t) -> item.value > content.value) {
            treeInsert(&(*t) -> fe, content, &(*t) -> item.level);
        } else {
            treeInsert(&(*t) -> fd, content, &(*t) -> item.level);
        }
    }
}

int getHeight(Tree **t) {
    if (*t == NULL) {
        return 0;
    }

    Queue aQueue;
    MEQueue(&aQueue);
    qData aux;
    aux.val = *t;
    doQueue(&aQueue, aux);
    
    int cont = 0;
    while(!isQueueEmpty(&aQueue)) {
        deQueue(&aQueue, &aux);
        *t = aux.val;
        cout << (*t) -> item.value << "\t" << (*t) ->item.level << endl;

        if ((*t) -> fe != NULL) {
            aux.val = (*t) -> fe;
            doQueue(&aQueue, aux);
        }

        if ((*t) -> fd != NULL) {
            aux.val = (*t) -> fd;
            doQueue(&aQueue, aux);
        }
        cont++;
    }

    return aux.val -> item.level;
}