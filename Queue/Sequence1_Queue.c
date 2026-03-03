//队列的顺序结构
//这种方式不能避免数据搬迁的开销，顺序队列最好使用循环队列
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

void Sequence_Queue_Init(PQUEUE p);             //顺序结构队列的初始化
void Equeue(PQUEUE p,Elemtype value);           //入队
Elemtype Dequeue(PQUEUE p);                     //出队，并返回出队元素
int Get_RearElem(PQUEUE p,Elemtype* value);     //获取队头元素
bool Queue_Is_Empty(PQUEUE p);                  //判断队列是否为空
bool Queue_Is_Full(PQUEUE p);                   //判断队列是否已满（该函数只能判断队尾是不是不能继续入队，并不能判断队列是否真的已满）
void Traverse(PQUEUE p);                        //遍历当前队列的所有元素

int main()
{
    Elemtype value;

    QUEUE queue;
    Sequence_Queue_Init(&queue);

    Equeue(&queue,100);
    Equeue(&queue,200);
    Equeue(&queue,300);
    Equeue(&queue,400);
    Equeue(&queue,500);
    
    value = Dequeue(&queue);
    printf("%d\n",value);

    Traverse(&queue);
    printf("\n");

    Equeue(&queue,600);
    Traverse(&queue);
}

//顺序结构队列的初始化
void Sequence_Queue_Init(PQUEUE p)
{
    //front和rear表示队列元素下标，初始化为0
    p->front = 0;
    p->rear = 0;
    //将队列所有元素的值初始化为0
    for(int i = 0;i < MAXSiZE;i++)
    {
        p->data[i] = 0;
    }
}

//入队
void Equeue(PQUEUE p,Elemtype value)
{
    if(Queue_Is_Full(p))
    {
        if(p->front > 0)
        {
            int step = p->rear - p->front;
            for(int i = 0;i < step;i++)
            {
                p->data[i] = p->data[p->front + i];
            }
            p->front = 0;
            p->rear = step - p->front;
        }
        else if(p->front == 0)
        {
            printf("队列真的已满！");
            return;
        }
    }
    else
    {
        p->data[p->rear] = value;
        p->rear++;
    }
}

//出队，并返回出队元素
Elemtype Dequeue(PQUEUE p)
{
    if(Queue_Is_Empty(p))
    {
        printf("队列为空，出队失败！");
        return 0;
    }
    Elemtype value = p->data[p->front];
    p->data[p->front] = 0;  //出队后，将该位置元素赋值为0
    p->front++;
    return value;
}

//获取队头元素
int Get_RearElem(PQUEUE p,Elemtype* value)
{
    if(Queue_Is_Empty(p))
    {
        return 0;
    }
    *value = p->data[p->front];
    return 1;
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

//判断队列是否已满（该函数只能判断队尾是不是不能继续入队，并不能判断队列是否真的已满）
bool Queue_Is_Full(PQUEUE p)
{
    if(p->rear >= MAXSiZE)
    {
        return true;
    }
    return false;
}

//遍历当前队列的所有元素
void Traverse(PQUEUE p)
{
    for(int i = 0;i <= p->rear - p->front;i++)
    {
        printf("%d ",p->data[i]);
    }
}