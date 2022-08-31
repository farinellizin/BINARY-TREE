#include "tree.hpp"

int main () {
    Tree *teste;
    Data val;
    val.level = 0;  

    treeInit(&teste);

    val.value = 5;
    treeInsert(&teste, val, &(val.level));

    val.value = 17;
    treeInsert(&teste, val, &(val.level));

    val.value = 2;
    treeInsert(&teste, val, &(val.level));

    val.value = 3;
    treeInsert(&teste, val, &(val.level));

    val.value = 4;
    treeInsert(&teste, val, &(val.level));

    val.value = 35;
    treeInsert(&teste, val, &(val.level));

    val.value = 42;
    treeInsert(&teste, val, &(val.level));

    val.value = 23;
    treeInsert(&teste, val, &(val.level));
    
    val.value = 18;
    treeInsert(&teste, val, &(val.level));

    int testing = getHeight(&teste);
    cout << endl << "PEGANDO A ALTURA DA MATRIZ: " << testing;
}