#include "double_linked_list.h"
#include <string.h>

bool killStudent (struct student stu) {
    free(stu.name);
    return true;
}

int cmpStudentAll (DLL_ELEM_TYPE a,DLL_ELEM_TYPE b) {
    if(a.age==b.age) return strcmp(a.name,b.name);
    else return a.age-b.age;
}

int cmpStudentAge (DLL_ELEM_TYPE a,DLL_ELEM_TYPE b) {
    return a.age-b.age;
}

void printStudent (struct student stu) {
    printf("[%s:%d] ",stu.name,stu.age);
}

int main (void) {
    struct dll_node* list0 = dllNewHead();
    for (int i=1;i<=1024;i<<=1) {
        struct student clone;

        clone.name = (char*)malloc(sizeof(char)*32);
        sprintf(clone.name,"clone%d",i);
        clone.age = i;

        dllInsertAfter(list0->prev,clone);
    }

    dllPrint(list0,printStudent);

    struct student temp = {name:"clone256",age:256};
    dllDeleteNode(dllIndexByVal(list0,temp,cmpStudentAll),killStudent);
    dllPrint(list0,printStudent);

    temp.age = 32;
    dllDeleteNode(dllIndexByVal(list0,temp,cmpStudentAge),killStudent);
    dllPrint(list0,printStudent);

    dllDestoryList(list0,killStudent);
}