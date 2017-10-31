#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
    char data[256];
    struct node *next;
} node;

node *list_create(char data[256]){
    node* list=malloc(sizeof(node));
    strcpy(list->data,data);
    list->next=NULL;
    return list;
}
void list_add(node *list, char data[256]) {
    if(list==NULL)
        return;
    while (list->next!=NULL)
        list = list->next;
    node *buf=malloc(sizeof(node));
    buf->next=NULL;
    strcpy(buf->data,data);
    list->next=buf;
}
node *list_delete(node *list,char data[256]){
    if(list==NULL)
        return NULL;
    node *buf;
    node *buf2;
    while (list!=NULL && !strcmp(list->data,data)){
        buf=list;
        list=list->next;
        free(buf);
    }
    if(list==NULL)
        return NULL;
    buf=list;
    while (buf!=NULL ){
        while (buf->next!=NULL &&!strcmp(buf->next->data,data)){
            buf2=buf->next;
            buf->next=buf2->next;
            free(buf2);
        }
        buf=buf->next;
    }
    return list;
}
void list_show(node *list){
    while (list!=NULL){
        printf("%s -> ",list->data);
        list=list->next;
    }
    printf("NULL\n");
}
int main() {
    node *list = list_create("I'd like to live");
    list_add(list, "I'd like to DIE");
    list_add(list, "I would like to sleep");
    list_add(list, "I'd like to DIE");
    list_add(list, "I'd like to eat");
    list_add(list, "I'd like a Ferrari");
    list_show(list);
    list=list_delete(list,"I'd like to DIE");

    list_show(list);

    return 0;
}