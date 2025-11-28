#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
struct points_manage_system{
    char id_num[50];
    int score1;
    int score2;
    int score3;
    int sum_score;
    char name[51];
};
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
void search_id(points_manage_system student[],int flag,char *id_num)
{
    //cout<<4<<endl;
    for(int i = 0;i<flag;i++)
    {
        if(strcmp(student[i].id_num,id_num)==0)
        {
            cout<<student[i].id_num<<" "<<student[i].name<<" "<<student[i].score1<<" "<<student[i].score2<<" "<<student[i].score3<<" "<<endl;
            break;
        }
    }
}
void search_name(points_manage_system student[],int flag,char* name)
{
    //cout<<5<<endl;
    sort(student, student + flag, [](const points_manage_system& a, const points_manage_system& b) {
        return strcmp(a.id_num, b.id_num) < 0;
    });
    for(int i = 0;i<flag;i++)
    {
        
        if(strcmp(student[i].name,name)==0) cout<<student[i].id_num<<" "<<student[i].name<<" "<<student[i].score1<<" "<<student[i].score2<<" "<<student[i].score3<<" "<<endl;
    }
}
void id_print(points_manage_system student[],int flag)
{
    //cout<<6<<endl;
    sort(student, student + flag, [](const points_manage_system& a, const points_manage_system& b) {
        return strcmp(a.id_num, b.id_num) < 0;
    });
    for(int i = 0;i<flag;i++)
    {
        cout<<student[i].id_num<<" "<<student[i].name<<" "<<student[i].score1<<" "<<student[i].score2<<" "<<student[i].score3<<" "<<endl;
    }
}
void point_print(points_manage_system student[],int flag)
{
    //cout<<7<<endl;
    sort(student, student + flag, [](const points_manage_system& a, const points_manage_system& b) {
        if(a.sum_score==b.sum_score) return strcmp(a.id_num, b.id_num) < 0;
        return a.sum_score > b.sum_score;
    });
    for(int i = 0;i<flag;i++)
    {
        cout<<student[i].id_num<<" "<<student[i].name<<" "<<student[i].score1<<" "<<student[i].score2<<" "<<student[i].score3<<" "<<endl;
    }
}
int main()
{
    points_manage_system student[1000];
    char id_num[50];
    int score1;
    int score2;
    int score3;
    //int sum_score;
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