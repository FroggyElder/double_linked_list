#ifndef _DOUBLE_LINKED_LIST
#define _DOUBLE_LINKED_LIST

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//edit the type to your needs
typedef struct student{
    char* name;
    int age;
}DLL_ELEM_TYPE;

struct dll_node{
    struct dll_node* prev;
    DLL_ELEM_TYPE data;
    struct dll_node* next;
};

struct dll_node* dllNewNode(DLL_ELEM_TYPE data);

struct dll_node* dllNewHead(void);

bool dllInsertAfter (struct dll_node* node,DLL_ELEM_TYPE data);

bool dllDestoryList (struct dll_node* node,bool (* cleanData)(DLL_ELEM_TYPE a));

bool dllDeleteNode (struct dll_node* node,bool (* cleanData)(DLL_ELEM_TYPE a));

struct dll_node* dllIndexByVal (struct dll_node* node,DLL_ELEM_TYPE data,int dllCmp(DLL_ELEM_TYPE a,DLL_ELEM_TYPE b));

void dllPrint (struct dll_node* head,void (* Print)(DLL_ELEM_TYPE data));

#endif //_DOUBLE_LINKED_LIST