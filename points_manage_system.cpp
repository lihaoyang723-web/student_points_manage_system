#include <iostream>
#include <cstring>
#include <algorithm>
#include "changes_info.h"
#include "search_and_print_info.h"
using namespace std;
int main()
{
    points_manage_system student[1000];
    char id_num[50];
    int score1;
    int score2;
    int score3;
    char name[51];
    int num,flag = 0;
    while(cin>>num)
    {
        if(num==0) break;
        switch (num)
        {
        case 1: cin>>id_num>>score1>>score2>>score3;
                cin.ignore();
                cin.getline(name,51);
                add_info(student,flag,id_num,score1,score2,score3,name);
                break;
        case 2: cin>>id_num>>score1>>score2>>score3;
                cin.ignore();
                cin.getline(name,51);
                change_info(student,flag,id_num,score1,score2,score3,name);
                break;
        case 3: cin>>(id_num);
                del_info(student,flag,id_num);
                break;
        case 4: cin>>id_num;
                search_id(student,flag,id_num);
                break;
        case 5: cin.ignore();
                cin.getline(name,51);
                search_name(student,flag,name);
                break;
        case 6: id_print(student,flag);
                break;
        case 7: point_print(student,flag);
                break;
        }
    }
    return 0;
}