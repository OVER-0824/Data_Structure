//栈的链式结构实现
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define Elemtype int

typedef struct stack
{
    struct stack* pNext;
    Elemtype data;
}STACK,*PSTACK;

PSTACK Link_Stack_Init(void);                   //初始化链式栈
void Push(PSTACK pHead,Elemtype value);         //压栈（栈的特点是先进后出，相当于链表的头插法）
int Pop(PSTACK pHead,Elemtype* value);         //出栈（并返回出栈元素的值）
int Get_TopElem(PSTACK pHead,Elemtype* value);  //获取栈顶元素
bool Stack_Is_Empty(PSTACK pHead);              //判断栈是否为空
void Traverse(PSTACK pHead);                    //遍历整个栈
void Destroy_Stack(PSTACK* pHead);              //销毁栈

int main()
{
    Elemtype value;

    PSTACK pHead = Link_Stack_Init();

    Push(pHead,100);
    Push(pHead,200);
    Push(pHead,300);
    Push(pHead,400);
    Push(pHead,500);

    Traverse(pHead);
    printf("\n");

    if(Pop(pHead,&value))
    {
        printf("%d ",value);
    }

    Destroy_Stack(&pHead);
}

//初始化链式栈
PSTACK Link_Stack_Init(void)
{
    PSTACK pHead = (PSTACK)malloc(sizeof(STACK));
    if(pHead == NULL)
    {
        printf("pHead动态分配内存失败！");
        exit(-1);
    }
    pHead->data = 0;
    pHead->pNext = NULL;
    return pHead;
}

//压栈（栈的特点是先进后出，相当于链表的头插法）
void Push(PSTACK pHead,Elemtype value)
{
    PSTACK pNew = (PSTACK)malloc(sizeof(STACK));
    if(pNew == NULL)
    {
        printf("pNew动态开辟内存失败！");
        exit(-1);
    }
    pNew->data = value;
    pNew->pNext = pHead->pNext;
    pHead->pNext = pNew;
}

//出栈（并返回出栈元素的值）
int Pop(PSTACK pHead,Elemtype* value)
{
    if(Stack_Is_Empty(pHead))
    {
        printf("栈空，无法出栈！");
        return 0;
    }
    PSTACK ptr = pHead->pNext;
    *value = ptr->data;
    pHead->pNext = ptr->pNext;
    //释放出栈元素的那片空间
    free(ptr);
    return 1;
}

//获取栈顶元素
int Get_TopElem(PSTACK pHead,Elemtype* value)
{
    if(Stack_Is_Empty(pHead))
    {
        return 0;
    }
    *value = pHead->pNext->data;
    return 1;
}

//判断栈是否为空
bool Stack_Is_Empty(PSTACK pHead)
{
    if(pHead->pNext == NULL)
    {
        return true;
    }
    return false;
}

//遍历整个栈
void Traverse(PSTACK pHead)
{
    PSTACK p = pHead->pNext;
    while(p != NULL)
    {
        printf("%d ",p->data);
        p = p->pNext;
    }
}

//销毁栈
void Destroy_Stack(PSTACK* pHead)
{
    if(pHead == NULL || *pHead == NULL)
    {
        return;
    }
    PSTACK p = (*pHead)->pNext;
    PSTACK q = p;
    while(q != NULL)
    {
        p = q->pNext;
        free(q);
        q = p;
    }
    free(*pHead);
    *pHead = NULL;
}
