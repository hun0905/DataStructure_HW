#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
struct Node* top = NULL;
int Empty();
void push(int data);
int pop();
int main(){
    push(1);
    printf("%d",top->data);
    push(2);
    printf("%d",top->data);
    pop();
    printf("%d",top->data);
    return 0;
}
int Empty(){
    if(top == NULL)return 1;
    else return 0;
}
void push(int data){
    struct Node* new_node;
    new_node=(struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = top;
    top = new_node;
}
int pop(){
    struct Node *ptr;
    int tmp;
    if(Empty()){
        printf("Empty");
        return -1;
    }
    else{
        ptr = top;
        top = top->next;
        tmp = ptr->data;
        free(ptr);
        return tmp;
    }
}
