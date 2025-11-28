//本文件定义了实现学生成绩管理所需要的结构体，并声明了三个用于修改学生信息的函数
#ifndef CHANGES_INFO
#define CHANGES_INFO
struct points_manage_system{
    char id_num[50];
    int score1;
    int score2;
    int score3;
    int sum_score;
    char name[51];
};
void add_info(points_manage_system student[],int &flag,char *id_num,int score1,int score2,int score3,char *name);
void change_info(points_manage_system student[],int &flag,char *id_num,int score1,int score2,int score3,char *name);
void del_info(points_manage_system student[],int &flag,char *id_num);
#endif