#include <cstring>
#include "changes_info.h"

//添加学生信息（若已有则覆盖原信息）
void add_info(points_manage_system student[],int &flag,char *id_num,int score1,int score2,int score3,char *name)
{
    for(int i = 0;i<flag;i++)
    {
        if(strcmp(student[i].id_num,id_num)==0) 
        {
            student[i].score1 = score1;
            student[i].score2 = score2;
            student[i].score3 = score3;
            strcpy(student[i].name,name);
            student[i].sum_score = score1 + score2 + score3;
            return;
        }
    }
    strcpy(student[flag].id_num,id_num); 
    student[flag].score1 = score1;
    student[flag].score2 = score2;
    student[flag].score3 = score3;
    strcpy(student[flag].name,name);
    student[flag].sum_score = score1 + score2 + score3;
    flag++;
}

//按学号查找，修改对应学生信息
void change_info(points_manage_system student[],int &flag,char *id_num,int score1,int score2,int score3,char *name)
{
    for(int i = 0;i<flag;i++)
    {
        if(strcmp(student[i].id_num,id_num)==0) 
        {
            student[i].score1 = score1;
            student[i].score2 = score2;
            student[i].score3 = score3;
            strcpy(student[i].name,name);
            student[i].sum_score = score1 + score2 + score3;
        }
    }
}

//按学号查找，删除对应学生信息
void del_info(points_manage_system student[],int &flag,char *id_num)
{
    for (int i = 0; i < flag; i++) {
        if (strcmp(student[i].id_num, id_num) == 0) {
            student[i] = student[flag - 1];
            flag--;
            break;
        }
    }
}