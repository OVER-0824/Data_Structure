#include <stdio.h>
#include <stdlib.h>

typedef int Elemtype;   //将int用Elemtype表示，后面代码中的Elemtype都会被替换为int。

typedef struct Node
{
    struct Node* pNext;
    Elemtype data;
}NODE,*PNODE;

//相关函数声明
PNODE LinkList_Init(void);                                  //初始化单链表，返回头节点地址
void Insert_Head(PNODE pHead,Elemtype value);               //在单链表中插入一个结点（头插法：每次插入的结点都位于头节点之后，其它结点之前）
void Insert_End(PNODE pHead,Elemtype value);                //在单链表中插入一个新节点（尾插法；每次插入的元素都位于最后一个元素的后面）
void Insert(PNODE pHead,int position,Elemtype value);       //在单链表的指定位置插入一个新节点
Elemtype Delete(PNODE pHead,int position,Elemtype* value);  //删除单链表中的指定节点，并返回该节点的值
void Traverse(PNODE pHead);                                 //遍历整个单链表
PNODE Get_EndNode_Address(PNODE pHead);                     //获取尾结点的地址
int Get_LinkList_Length(PNODE pHead);                       //获取链表的长度
void Release_LinkList(PNODE pHead);                         //释放整个链表

int main()
{
    Elemtype value;
    int length;
    PNODE pHead = LinkList_Init();
    // //头插法
    // Insert_Head(pHead,100);
    // Insert_Head(pHead,200);
    // Insert_Head(pHead,300);

    //尾插法
    Insert_End(pHead,100);
    Insert_End(pHead,200);
    Insert_End(pHead,300);
    Traverse(pHead);
    //指定位置插入新节点
    Insert(pHead,2,150);
    Traverse(pHead);
    //删除指定节点
    Delete(pHead,2,&value);
    printf("删除的节点值为：%d\n",value);
    //获取链表的长度
    length = Get_LinkList_Length(pHead);
    printf("链表的长度为：%d\n",length);
    Traverse(pHead);
    //释放整个链表
    Release_LinkList(pHead);
}


//初始化单链表，返回头节点地址
PNODE LinkList_Init(void)
{
    PNODE pHead = (PNODE)malloc(sizeof(NODE));
    if(pHead == NULL)
    {
        printf("pHead动态分配内存失败！");
        exit(-1);
    }
    pHead->pNext = NULL;
    return pHead;
}

//在单链表中插入一个结点（头插法：每次插入的结点都位于头节点之后，其它结点之前）
void Insert_Head(PNODE pHead,Elemtype value)
{
    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    if(pNew == NULL)
    {
        printf("pNew_Head动态分配内存失败！");
        exit(-1);
    }
    pNew->data = value;
    pNew->pNext = pHead->pNext;
    pHead->pNext = pNew;
}

//在单链表中插入一个新节点（尾插法；每次插入的元素都位于最后一个元素的后面）
void Insert_End(PNODE pHead,Elemtype value)
{
    PNODE pEnd = Get_EndNode_Address(pHead);
    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    if(pNew == NULL)
    {
        printf("pNew_End动态分配内存失败！");
        exit(-1);
    }
    pNew->data = value;
    pEnd->pNext = pNew;
    pNew->pNext = NULL;
}

//在单链表的指定位置插入一个新节点
void Insert(PNODE pHead,int position,Elemtype value)    //position表示第几个节点
{
    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    if(pNew == NULL)
    {
        printf("pNew动态分配内存失败！");
        exit(-1);
    }
    //先找到插入位置节点的前驱节点
    PNODE ptr = pHead;
    while(--position)
    {
        ptr = ptr->pNext;
    }
    //找到前驱节点，插入新节点
    pNew->data = value;
    pNew->pNext = ptr->pNext;
    ptr->pNext = pNew;
}

//删除单链表中的指定节点，并返回该节点的值
Elemtype Delete(PNODE pHead,int position,Elemtype* value)   //position表示第几个节点
{
    PNODE ptr = pHead;
    //先找到要删除节点的前驱节点
    while(--position)
    {
        ptr = ptr->pNext;
    }
    //找到前驱节点，删除节点
    PNODE delete_node = (PNODE)malloc(sizeof(NODE));
    if(delete_node == NULL)
    {
        printf("delete_node动态分配空间失败！");
        exit(-1);
    }
    delete_node = ptr->pNext;
    *value = delete_node->data;
    ptr->pNext = delete_node->pNext;
    free(delete_node);
    return *value;
}

//遍历整个单链表
void Traverse(PNODE pHead)
{
    PNODE ptr = pHead;
    while(ptr->pNext != NULL)
    {
        ptr = ptr->pNext;
        printf("%d ",ptr->data);
    }
    printf("\n");
}


//获取尾结点的地址
PNODE Get_EndNode_Address(PNODE pHead)
{
    PNODE ptr = pHead;
    while(ptr->pNext != NULL)
    {
        ptr = ptr->pNext;
    }
    return ptr;
}

//获取链表的长度
int Get_LinkList_Length(PNODE pHead)
{
    int length;
    PNODE ptr = pHead;
    while(ptr->pNext != NULL)
    {
        ptr = ptr->pNext;
        length++;
    }
    return length;
}

//释放整个链表
void Release_LinkList(PNODE pHead)
{
    PNODE ptr = pHead->pNext;
    PNODE qtr = NULL;
    while(ptr != NULL)
    {
        qtr = ptr->pNext;
        free(ptr);
        ptr = qtr;
    }
    pHead->pNext = NULL;
}

