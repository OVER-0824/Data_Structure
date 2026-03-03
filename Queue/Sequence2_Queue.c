//队列的顺序结构->循环队列
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSiZE 5
typedef int Elemtype;

typedef struct queue
{
    //这里的front和rear表示队列元素下标
    Elemtype data[MAXSiZE];
    int front;
    int rear;
}QUEUE,*PQUEUE;

void Circular_Queue(PQUEUE p);              //循环队列的初始化
void EQueue(PQUEUE p,Elemtype value);       //入队
void DeQueue(PQUEUE p,Elemtype* value);     //出队，并保存出队元素
bool Queue_Is_Empty(PQUEUE p);              //判断队列是否为空
bool Queue_Is_Full(PQUEUE p);               //判断队列是否为满
void Traverse(PQUEUE p);                    //遍历当前队列的所有元素

int main()
{
    Elemtype value;

    QUEUE queue;
    //初始化队列
    Circular_Queue(&queue);

    //入队
    EQueue(&queue,100);
    EQueue(&queue,200);
    EQueue(&queue,300);
    EQueue(&queue,400);

    //遍历队列
    Traverse(&queue);
    printf("\n");

    //出队
    DeQueue(&queue,&value);
    printf("%d\n",value);

    Traverse(&queue);

}

//循环队列的初始化
void Circular_Queue(PQUEUE p)
{
    //将p->front和p->rear都初始化为0
    p->front = 0;
    p->rear = p->front;
    //将循环队列中的所有元素都初始化为0
    for(int i = 0;i < MAXSiZE;i++)
    {
        p->data[i] = 0;
    }
}

//入队
void EQueue(PQUEUE p,Elemtype value)
{
    if(Queue_Is_Full(p))
    {
        printf("队列已满，无法继续入队！");
        return;
    }
    p->data[p->rear] = value;
    p->rear = (p->rear + 1) % MAXSiZE;
}

//出队，保存出队元素，并将出队位置元素值清零
void DeQueue(PQUEUE p,Elemtype* value)
{
    if(Queue_Is_Empty(p))
    {
        printf("队列为空，无法继续出队！");
        return;
    }
    *value = p->data[p->front];
    p->data[p->front] = 0;
    p->front = (p->front + 1) % MAXSiZE;
}

//判断队列是否为空
bool Queue_Is_Empty(PQUEUE p)
{
    if(p->front == p->rear)
    {
        return true;
    }
    return false;
}

//判断队列是否为满
bool Queue_Is_Full(PQUEUE p)
{
    if((p->rear + 1) % MAXSiZE == p->front)
    {
        return true;
    }
    return false;
}

//遍历当前队列的所有元素
void Traverse(PQUEUE p)
{
    for(int i = 0;i < MAXSiZE;i++)
    {
        printf("%d ",p->data[i]);
    }
}