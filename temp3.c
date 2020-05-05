#include <stdio.h>

struct student{
    int id;
    char gg[20];
};

void print(int id, void *persons, int type){
    student gg[2] = (student)persons;
    printf("%d %d\n", xd, &persons[0].gg);
}

int main(){
    struct student students[2] = {
        {20, "nabil"},
        {21, "tanha"}
    };
    print(1, students, 1);
    //printf("%d\n", students[0]+4);
}