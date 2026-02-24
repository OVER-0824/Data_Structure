//创建一个顺序表，并实现相关功能
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
typedef int Elemtype;

typedef struct
{
    Elemtype Data[MAXSIZE];     //该线性表有MAXSIZE个元素，元素类型为Elemtype
    int length;     //length表示线性表中当前元素的个数
}SeqList,*PSeqList;

void Sequence_List_Init(PSeqList p);
int Append(PSeqList p,Elemtype value);
void Insert(PSeqList p,int position,Elemtype value);
Elemtype Delete(PSeqList p,int position,Elemtype* value);
int find_Elem(PSeqList p,Elemtype value);
void Traverse(PSeqList p);

int main()
{
    Elemtype value;
    int position;
    SeqList SequenceList;

    Sequence_List_Init(&SequenceList);
    for(int i=0;i<3;i++)
    {
        if(Append(&SequenceList,i))
        {
            printf("添加元素成功！\n");
        }
    }
    Traverse(&SequenceList);
   
    printf("\n");

    Insert(&SequenceList,3,3);
    Insert(&SequenceList,4,4);
    Traverse(&SequenceList);

    printf("\n");

    Delete(&SequenceList,1,&value);
    printf("删除的元素为：%d\n",value);
    Traverse(&SequenceList);

    position = find_Elem(&SequenceList,4);
    printf("4在顺序表中第一次出现的位置下表为：%d",position);
}

//线性表初始化
void Sequence_List_Init(PSeqList p)
{
    //将顺序表中当前元素个数赋值为0
    p->length = 0;
}

//在顺序表尾部添加元素，返回0表示添加失败，返回1表示添加成功
int Append(PSeqList p,Elemtype value)
{
    if(p->length >= MAXSIZE)
    {
        printf("顺序表已满，无法继续添加元素！");
        return 0;
    }
    p->Data[p->length] = value;
    p->length++;
    return 1;
}

//在顺序表的指定位置插入数据
void Insert(PSeqList p,int position,Elemtype value)
{
    int cnt;
    //position表示元素下标
    if(p->length >= MAXSIZE)
    {
        printf("顺序表已满，无法继续插入元素！");
    }
    else if(p->length < MAXSIZE && position == p->length)
    {
        p->Data[position] = value;
        p->length++;
    }
    else 
    {
        //cnt表示需要移动的元素个数
        cnt = p->length - position;
        for(int i = 0;i < cnt;i++)
        {
            p->Data[p->length - i] = p->Data[p->length - i - 1];
        }
        p->Data[position] = value;
        p->length++;
    }
}

//删除顺序表中指定位置的元素,并返回该元素的值
Elemtype Delete(PSeqList p,int position,Elemtype* value)
{
    if(p->length == 0)
    {
        printf("顺序表为空，无法继续删除元素！");
    }
    *value = p->Data[position];
    //cnt表示需要移动的元素个数
    int cnt = (p->length - 1) - position;
    for(int i = 0;i < cnt;i++)
    {
        p->Data[position + i] = p->Data[position + i +1];
    }
    p->length--;
    return *value;
}

//查找元素（传入一个元素，返回该元素在顺序表中第一次出现的位置下标）
int find_Elem(PSeqList p,Elemtype value)
{
    int i;
    for(i = 0;i < p->length;i++)
    {
        if(p->Data[i] == value)
        {
            //查找成功，返回该元素下标。
            return i;
        }
        continue;
    }
    //查找失败，顺序表中没有这个元素。
    return MAXSIZE+1;
}

//遍历整个顺序表
void Traverse(PSeqList p)
{
    int cnt;
    for(cnt = 0;cnt < MAXSIZE;cnt++)
    {
        printf("%d ",p->Data[cnt]);
    }
}