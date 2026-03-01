//栈的顺序结构实现
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 100
typedef int Elemtype;

typedef struct stack
{
    Elemtype Data[MAXSIZE];
    int location;   //location表示数组元素下标
}STACK,*PSTACK;

void Sequence_Stack_Init(PSTACK p);         //初始化顺序结构栈
void Push(PSTACK p,Elemtype value);         //压栈
int Pop(PSTACK p,Elemtype* value);          //出栈,并返回要出栈的元素
int Get_TopElem(PSTACK p,Elemtype* value);  //获取栈顶元素
void Traverse(PSTACK p);                    //遍历整个顺序结构栈
bool Stack_Is_Full(PSTACK p);               //判断栈是否为满
bool Stack_Is_Empty(PSTACK p);              //判断栈是否为空

int main(void)
{
    Elemtype value;
    Elemtype Top_value;

    STACK stack;
    Sequence_Stack_Init(&stack);

    Push(&stack,100);   
    Push(&stack,200); 
    Push(&stack,300);
    Push(&stack,400);
    Push(&stack,500);

    Traverse(&stack);

    printf("\n");

    if(Pop(&stack,&value))
    {
        printf("%d ",value);
    } 

    if(Get_TopElem(&stack,&Top_value))
    {
        printf("%d\n",Top_value);
    }
}

//初始化顺序结构栈
void Sequence_Stack_Init(PSTACK p)
{
    //将location初始化为-1
    p->location = -1;
    //将数组的每个元素的值都初始化为0
    for(int i = 0;i < MAXSIZE;i++)
    {
        p->Data[i] = 0;
    }
}

//压栈
void Push(PSTACK p,Elemtype value)
{
    //首先需要判断栈是否已满
    if(Stack_Is_Full(p))
    {
        printf("栈已满，无法继续压栈！");
        exit(-1);
    }
    p->location++;
    p->Data[p->location] = value;
}

//出栈,并返回要出栈的元素
int Pop(PSTACK p,Elemtype* value)
{
    //首先判断栈是否为空
    if(Stack_Is_Empty(p))
    {
        printf("栈为空，无法继续出栈！");
        return 0;
    }
    *value = p->Data[p->location];
    p->location--;
    return 1;
}

//获取栈顶元素
int Get_TopElem(PSTACK p,Elemtype* value)
{
    if(Stack_Is_Empty(p))
    {
        printf("栈为空，无法获取栈顶元素！");
        return 0;
    }
    *value = p->Data[p->location];
    p->location--;
    return 1;
}

//遍历整个顺序结构栈
void Traverse(PSTACK p)
{
    int i;
    for(i = 0;i < MAXSIZE;i++)
    {
        printf("%d ",p->Data[i]);
    }
}

//判断栈是否为满
bool Stack_Is_Full(PSTACK p)
{
    if(p->location == MAXSIZE - 1)
    {
        return true;
    }
    return false;
}

//判断栈是否为空
bool Stack_Is_Empty(PSTACK p)
{
    if(p->location == -1)
    {
        return true;
    }
    return false;
}
