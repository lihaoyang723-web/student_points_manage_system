//本文件声明了四个要实现寻找相关对应的同学并输出相关信息的函数
#include "changes_info.h"
#ifndef SEARCH_AND_PRINT_INFO
#define SEARCH_AND_PRINT_INFO
void search_id(points_manage_system student[],int flag,char *id_num);
void search_name(points_manage_system student[],int flag,char* name);
void id_print(points_manage_system student[],int flag);
void point_print(points_manage_system student[],int flag);
#endif