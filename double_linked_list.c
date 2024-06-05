#include "double_linked_list.h"

struct dll_node* dllNewHead(void) {
    DLL_ELEM_TYPE empty;
    struct dll_node* new_node = dllNewNode(empty);
    if(new_node==NULL) return NULL;
        
    new_node->prev=new_node;
    new_node->next=new_node;
}

struct dll_node* dllNewNode(DLL_ELEM_TYPE data) {
    struct dll_node* new_node = (struct dll_node*)malloc(sizeof(struct dll_node));
    if(new_node == NULL) {
        perror("failed to malloc for dll node");
        return NULL;
    }

    new_node->data=data;
    return new_node;
}

bool dllInsertAfter (struct dll_node* node,DLL_ELEM_TYPE data) {
    struct dll_node* new_node = dllNewNode(data);
    if(new_node==NULL) {
        printf("in: %s",__func__);
        return NULL;
    }

    new_node->next=node->next;
    new_node->prev=node;
    node->next->prev=new_node;
    node->next=new_node;
    
    return true;
}

bool dllDestoryList (struct dll_node* node,bool (* cleanData)(DLL_ELEM_TYPE a)) {
    if(node==NULL) {
        printf("invalid list to destory\n");
        return false;
    }

    if(node->next==node) {free(node); return true;};

    struct dll_node* current = node;
    struct dll_node* next;

    while (current!=node) {
        next=current->next;
        if(cleanData!=NULL)
            if (cleanData(current->data)==false){
                printf("%s: ",__func__);
                return false;
            }
        free(current);
        current=next;
    }

    return true;
}

bool dllDeleteNode (struct dll_node* node,bool (* cleanData)(DLL_ELEM_TYPE a)) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
    if(cleanData!=NULL)
        if(cleanData(node->data)==false){
            printf("%s ",__func__);
            return false;
        }

    free(node);
}

struct dll_node* dllIndexByVal (struct dll_node* node,DLL_ELEM_TYPE data,int dllCmp(DLL_ELEM_TYPE a,DLL_ELEM_TYPE b)) {
    if (node==NULL) {
        printf ("invalid node to delete!\n");
        return false;
    }

    for (struct dll_node* p = node->next;p!=node;p=p->next)
        if(dllCmp(p->data,data)==0) return p;
    
    return NULL;
}

void dllPrint (struct dll_node* head,void (* Print)(DLL_ELEM_TYPE data)) {
    if(head==NULL||head->next==head) return;

    struct dll_node* p = head->next;

    while(p!=head) {
        Print(p->data);
        p=p->next;
    }

    printf("\n");
}