#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//结构体保存学生信息
struct student
{

    char studentname[100];
    int studentid;
    char studentsex[200];
    int studentage;
};

struct Node
{
    //int data;

    struct student data;

    struct Node *next;
};

//创建表

struct Node *createlist()
{

    //结构体变量表示表头，指针-变量，动态内存申请
    struct Node *headnode = (struct Node *)malloc(sizeof(struct Node));
    headnode->next = NULL; //表头差异化处理；数据域不做处理
    return headnode;
}

//创建节点
struct Node *creatnode(struct student data)
{
    struct Node *headnode = (struct Node *)malloc(sizeof(struct Node));

    headnode->data = data;
    headnode->next = NULL;
    return headnode;
};

//打印链表
void printflist(struct Node *headnode)
{

    struct Node *pmove = headnode->next;

    printf("姓名\t年龄\t性别\t学号\n");

    while (pmove)
    {
        printf("%s\t%d\t%s\t%d\n", pmove->data.studentname, pmove->data.studentage, pmove->data.studentsex, pmove->data.studentid);
        pmove = pmove->next;
    }

    printf("\n");
}

//指定位置删除

void deletenode(struct Node *headnode, char *name)
{
    struct Node *posnode = headnode->next;
    struct Node *posfrontnode = headnode;
    if (posnode == NULL)
    {
        printf("数据为空，无法删除\n");
        return;
    }
    while (strcmp(posnode->data.studentname, name))

    {
        posfrontnode = posnode;
        posnode = posnode->next;
        if (posnode == NULL)
        {
            printf("未找到位置\n");
            return;
        }
    }

    posfrontnode->next = posnode->next;
    free(posnode);
}
//查找
struct Node *searchnodedata(struct Node *headnode, char *name)
{

    struct Node *pmove = headnode->next;
    if (pmove == NULL)
        return NULL;
    while (strcmp(pmove->data.studentname, name))
    {
        pmove = pmove->next;
    }

    return pmove;
}

//插入链表
void insertnodehead(struct Node *headnode, struct student data)
{
    struct Node *newnode = creatnode(data);
    newnode->next = headnode->next;
    headnode->next = newnode;
}

//文件写操作
void readinfofile(struct Node *headnode, char *filename)
{
    // 打开文件
    FILE *fp;
    struct student data;
    fp = fopen(filename, "r");
    if (fp == NULL)
    {

        fp = fopen(filename, "w+");
    }
    //读文件
    while (fscanf(fp, "%s\t%d\t%S\t%d\t", data.studentname, &data.studentage, data.studentsex, &data.studentid) != EOF)
    {
        insertnodehead(headnode, data);
    }

    //关闭文件
    fclose(fp);
}

//文件读操作
void writeinfofile(struct Node *headnode, char *filename)
{
    FILE *fp;
    fp = fopen(filename, "w");
    struct Node *pmove = headnode->next;
    while (pmove)
    {
        fprintf(fp, "%s\t%d\t%S\t%d\t", pmove->data.studentname, pmove->data.studentage, pmove->data.studentsex, pmove->data.studentid);
        pmove = pmove->next;
    }
    fclose(fp);
}