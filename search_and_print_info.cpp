#include <iostream>
#include <cstring>
#include <algorithm>
#include "search_and_print_info.h"

//按学号查找对应学生信息并输出
void search_id(points_manage_system student[],int flag,char *id_num)
{
    for(int i = 0;i<flag;i++)
    {
        if(strcmp(student[i].id_num,id_num)==0)
        {
            std::cout<<student[i].id_num<<" "<<student[i].name<<" "<<student[i].score1<<" "<<student[i].score2<<" "<<student[i].score3<<" "<<std::endl;
            break;
        }
    }
}

//按姓名查找学生信息 并按学号升序输出
void search_name(points_manage_system student[],int flag,char* name)
{
    std::sort(student, student + flag, [](const points_manage_system& a, const points_manage_system& b) {
        return strcmp(a.id_num, b.id_num) < 0;
    });
    for(int i = 0;i<flag;i++)
    {
        
        if(strcmp(student[i].name,name)==0) std::cout<<student[i].id_num<<" "<<student[i].name<<" "<<student[i].score1<<" "<<student[i].score2<<" "<<student[i].score3<<" "<<std::endl;
    }
}

//按学号升序输出所有学生信息
void id_print(points_manage_system student[],int flag)
{
    std::sort(student, student + flag, [](const points_manage_system& a, const points_manage_system& b) {
        return strcmp(a.id_num, b.id_num) < 0;
    });
    for(int i = 0;i<flag;i++)
    {
        std::cout<<student[i].id_num<<" "<<student[i].name<<" "<<student[i].score1<<" "<<student[i].score2<<" "<<student[i].score3<<" "<<std::endl;
    }
}

//按成绩降序输出所有学生信息（若成绩相同则按学号升序输出）
void point_print(points_manage_system student[],int flag)
{
    std::sort(student, student + flag, [](const points_manage_system& a, const points_manage_system& b) {
        if(a.sum_score==b.sum_score) return strcmp(a.id_num, b.id_num) < 0;
        return a.sum_score > b.sum_score;
    });
    for(int i = 0;i<flag;i++)
    {
        std::cout<<student[i].id_num<<" "<<student[i].name<<" "<<student[i].score1<<" "<<student[i].score2<<" "<<student[i].score3<<" "<<std::endl;
    }
}