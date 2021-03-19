#include <stdio.h>
#include <stdlib.h>
#define MAXSTACK  10
int stack[MAXSTACK];
int top = -1;
int Empty();
int push(int data);
int pop();
int main(){
    push(1);
    push(2);
    printf("%d",stack[top]);
    pop();
    printf("%d",stack[top]);
    return 0;
}
int Empty(){
    if(top == -1)return 1;
    else return 0;
}
int push(int data){
    if(top >=MAXSTACK){
        printf("it is full");
        return 0;
    }
    else{
        stack[++top] = data;
        return 1;
    }
}
int pop(){
    if(Empty())
        return -1;
    else
        return stack[top--];    
}

