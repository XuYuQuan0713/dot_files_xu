
#define _CRT_SECURE_NO_WARNINGS
#include "mylist.h"
struct Node *list = createlist();
struct student data;

void menu()
{

    int num;
    printf("**********************************\n");
    printf("*******学生管理系统****************\n");
    printf("**********************************\n");
    printf("          功能选择菜单             \n");
    printf("--------------------------------------\n");
    printf("0.退出系统");
    printf("**1.录入学生信息,2.浏览学生信息**\n");
    printf("**3.修改学生信息,4.删除学生信息**\n");
    printf("**5.查找学生信息,6.保存当前学生信息**\n");
    printf("--------------------------------------\n");

    while (1)
    {
        printf("请选择菜单编号");
        scanf("%d", &num);

        switch (num)
        {
        case 0:
            printf("正常退出");
            exit(0);
            break;

        case 1:
            printf("请输入学生姓名，年龄，性别，学号：");
            fflush(stdin); //清空缓冲区
            scanf("%s%d%s%d", data.studentname, &data.studentage, data.studentsex, &data.studentid);
            insertnodehead(list, data); //插入链表
            break;
        case 2:
            printflist(list); //打印链表
            break;
        case 3:

            break;
        case 4:
            printf("请输入删除的姓名");
            scanf("%s", data.studentname);
            deletenode(list, data.studentname);
            break;
        case 5:
            printf("请输入查找学生的姓名");
            scanf("%s", data.studentname);
            if (searchnodedata(list, data.studentname))
            {

                printf("没有找到,无法删除\n");
            }
            else
            {
                printf("姓名\t年龄\t性别\t学号\n");
                printf("%s\t%d\t%s\t%d\n", searchnodedata(list, data.studentname)->data.studentname, searchnodedata(list, data.studentname)->data.studentage, searchnodedata(list, data.studentname)->data.studentsex, searchnodedata(list, data.studentname)->data.studentid);
            }

            break;

        default:
            printf("输入错误，请重新输入");
            break;
        }

        writeinfofile(list, "1.txt");
    }
}
int main()
{
    readinfofile(list, "1.txt");
    menu();

    system("pause");
    system("cls");

    return 0;
    /*struct Node* list = createlist();
	insertnodehead(list, 1);
	insertnodehead(list, 2);
	insertnodehead(list, 3);
	printflist(list);
	printf("删除链表后的链表\n");
	deletenode(list, 2);
	printflist(list);*/
}
