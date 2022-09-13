#include<stdio.h>
#include<stdlib.h>

typedef int elemType;
#define MAXSIZE 100;
typedef struct{
    elemType* base;
    elemType* top;
    int stackSize;
}sqStack;

//初始化栈
void initStack(sqStack s){
    s.base = (elemType*)malloc(sizeof(elemType));
    if(!s.base){
        printf("初始化栈失败");
        exit(0);
    }
    s.top = s.base;
    s.stackSize = MAXSIZE;
}

//判断栈是否为空
int isEmpty(sqStack s){
    return s.top == s.base;
}

//计算栈的长度
int stackLength(sqStack s){
    return s.top - s.base;
}

//销毁栈
void destroyStack(sqStack s){
    if(s.base){
        free(s.base);
        s.base = NULL;
        s.top = NULL;
        s.stackSize = 0;
    }
}

//把栈清空
void clearStack(sqStack s){
    if(s.base){
        s.top = s.base;
    }
}

//进栈
void push(sqStack s, elemType e){
    if(s.top - s.base == s.stackSize){
        printf("栈已满");
    }

    *s.top = e;
    s.top++;
}

//出栈
elemType pop(sqStack s){
    if(s.top == s.base){
        printf("栈为空");
        exit(0);
    }
    s.top--;
    return *s.top;
}
