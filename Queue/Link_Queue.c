//队列的链式结构
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Elemtype;

typedef struct queuenode
{
    struct queuenode* pNext;
    Elemtype data;
}QUEUENODE,*PQUEUENODE;

typedef struct 
{
    //front和rear表示指向队头和队尾节点的指针
    PQUEUENODE front;
    PQUEUENODE rear;
}QUEUE,*PQUEUE;

PQUEUE Link_Queue_Init(void);           //初始化链式队列
void EQueue(PQUEUE p,Elemtype value);   //入队
int DeQueue(PQUEUE p,Elemtype* value);  //出队，并保存出队元素
Elemtype Get_Front_Elem(PQUEUE p);      //获取对头元素
bool LinkQueue_Is_Empty(PQUEUE p);      //判断链式队列是否为空
void Traverse(PQUEUE p);                //遍历链式队列

int main()
{
    Elemtype value;

    PQUEUE p;
    //初始化链式队列
    p = Link_Queue_Init();

    //入队
    EQueue(p,100);
    EQueue(p,200);
    EQueue(p,300);
    EQueue(p,400);
    EQueue(p,500);
    //遍历
    Traverse(p);
    printf("\n");

    //出队
    if(DeQueue(p,&value));
    {
        printf("出队元素为：%d\n",value);
        Traverse(p);
    }
}

//初始化链式队列
PQUEUE Link_Queue_Init(void)
{
    PQUEUENODE pNode = (PQUEUENODE)malloc(sizeof(QUEUENODE));
    PQUEUE p = (PQUEUE)malloc(sizeof(QUEUE));
    if(pNode == NULL || p == NULL)
    {
        printf("初始化失败！");
        exit(-1);
    }
    pNode->data = 0;
    pNode->pNext = NULL;
    p->front = pNode;
    p->rear = pNode;
    return p;
}

//入队
void EQueue(PQUEUE p,Elemtype value)
{
    PQUEUENODE pNew = (PQUEUENODE)malloc(sizeof(QUEUENODE));
    if(pNew == NULL)
    {
        printf("pNew动态开辟内存失败！");
        exit(-1);
    }
    pNew->data = value;
    p->rear->pNext = pNew;
    p->rear = pNew;
    pNew->pNext = NULL;
}

//出队，并保存出队元素
int DeQueue(PQUEUE p,Elemtype* value)
{
    if(LinkQueue_Is_Empty(p))
    {
        return 0;
    }
    //定义一个QueueNode的节点指针，指向首节点
    PQUEUENODE QueueNode = p->front->pNext;
    *value = QueueNode->data;
    p->front->pNext = QueueNode->pNext;
    if(QueueNode == p->rear)
    {
        p->rear = p->front;
    }
    free(QueueNode);
    return 1;
}

//获取对头元素
Elemtype Get_Front_Elem(PQUEUE p)
{
    if(LinkQueue_Is_Empty(p))
    {
        return 0;
    }
    return (p->front->pNext->data);
}

//判断链式队列是否为空
bool LinkQueue_Is_Empty(PQUEUE p)
{
    if(p->front == p->rear)
    {
        return true;
    }
    return false;
}

//遍历链式队列
void Traverse(PQUEUE p)
{
    PQUEUENODE q = p->front->pNext;
    while(q != NULL)
    {
        printf("%d ",q->data);
        q = q->pNext;
    }
}