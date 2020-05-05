#include<stdio.h>

void printstd(long y, int a, struct student std[]);
void printteach(long y, int b, struct teacher teach[]);
void printoff(long y, int c, struct officer off[]);
void printstf(long y, int d, struct staff stf[]);
void inputstd(int a, struct student std[]);
void inputteach(int b, struct teacher teach[]);
void inputoff(int c, struct officer off[]);
void inputstf(int d, struct staff stf[]);

struct town{
    int house_no;
    int road_no;
    char street_name[30];
};

struct vill{
    char village[40];
    char upazilla[40];
};

struct info{
    struct town tow;
    struct vill vil;
};

struct address{
    struct info inf;
    char police_station[40];
    char post_office[40];
    char district[40];
    char country[20];
};

struct joining_date{
    int day;
    int month;
    int year;
};

struct student{
    long int reg;
    char name[30];
    int session;
    struct address add;
    int age;
    double weight;
    char result[3];
    double cgpa;
};

struct teacher{
    long int ID;
    char name[30];
    char designation[30];
    char dept_name[40];
    struct address add;
    int age;
    double weight;
    double height;
    int salary;
    struct joining_date date;
};

struct officer{
    long int ID;
    char name[30];
    char designation[30];
    char office_name[40];
    struct address add;
    int age;
    double weight;
    double height;
    int salary;
    struct joining_date date;
};

struct staff{
    long int ID;
    char name[30];
    char designation[30];
    char office_name[40];
    struct address add;
    int age;
    double weight;
    double height;
    int salary;
    struct joining_date date;
};

int main(){
    int m, x, a, b, c, d;
    long y;

    printf("How many students, teachers, officer and staffs?");
    scanf("%d %d %d %d", &a, &b, &c, &d);
    
    struct student std[a];
    struct teacher teach[b];
    struct officer off[c];
    struct staff stf[d];
    
    for(int i=0; i<a; i++)
        std[i].add.inf.tow.house_no=0;
    
    for(int i=0; i<b; i++)
        teach[i].add.inf.tow.house_no=0;
    
    for(int i=0; i<c; i++)
        off[i].add.inf.tow.house_no=0;
    
    for(int i=0; i<d; i++)
        stf[i].add.inf.tow.house_no=0;
    
    printf("Plese input your information in order. when writing address, both type will be taken. enter 0 if you want to leave any info empty");
    
    inputstd(a, std);
    inputteach(b, teach);
    inputoff(c, off);
    inputstf(d, stf);
    
    printf("Enter query number:");
    scanf("%d", &m);
    
    for(int i=0; i<m; i++){
        scanf("%d %d", &x, &y);
        switch(x){
            case 1: printstd(y,a, std);
                    break;
            case 2: printteach(y,b, teach);
                    break;
            case 3: printoff(y,c, off);
                    break;
            case 4: printstf(y,d, stf);
                    break;
        }
    }
    
    return 0;
}

void printstd(long y, int a, struct student std[]){
    
    for(int i=0; i<a; i++){
        if(y==std[i].reg){
            printf("%ld %s %d ", std[i].reg, std[i].name, std[i].session);
            if(std[i].add.inf.tow.house_no != 0){
                printf("%d %d %s", std[i].add.inf.tow.house_no, std[i].add.inf.tow.road_no, std[i].add.inf.tow.street_name);
            } else{
                printf("%s %s", std[i].add.inf.vil.village, std[i].add.inf.vil.upazilla);
            }
            printf(" %s %s %s %s %d %lf %s %lf\n", std[i].add.police_station, std[i].add.post_office, std[i].add.district, std[i].add.country, std[i].age, std[i].weight, std[i].result, std[i].cgpa);
        }
    }
}

void printteach(long y, int b, struct teacher teach[]){
    
    for(int i=0; i<b; i++){
        if(y==teach[i].ID){
            printf("%ld %s %s %d ", teach[i].ID, teach[i].name, teach[i].designation, teach[i].dept_name);
            if(teach[i].add.inf.tow.house_no != 0){
                printf("%d %d %s", teach[i].add.inf.tow.house_no, teach[i].add.inf.tow.road_no, teach[i].add.inf.tow.street_name);
            } else{
                printf("%s %s", teach[i].add.inf.vil.village, teach[i].add.inf.vil.upazilla);
            }
            printf(" %d %lf %lf %d %d %d %d", teach[i].age, teach[i].weight, teach[i].height, teach[i].salary, teach[i].date.day, teach[i].date.month, teach[i].date.year);
        }
    }
}

void printoff(long y, int c, struct officer off[]){
    
    for(int i=0; i<c; i++){
        if(y==off[i].ID){
            printf("%ld %s %s %d ", off[i].ID, off[i].name, off[i].designation, off[i].office_name);
            if(off[i].add.inf.tow.house_no != 0){
                printf("%d %d %s", off[i].add.inf.tow.house_no, off[i].add.inf.tow.road_no, off[i].add.inf.tow.street_name);
            } else{
                printf("%s %s", off[i].add.inf.vil.village, off[i].add.inf.vil.upazilla);
            }
            printf(" %d %lf %lf %d %d %d %d", off[i].age, off[i].weight, off[i].height, off[i].salary, off[i].date.day, off[i].date.month, off[i].date.year);
        }
    }
}

void printstf(long y, int d, struct staff stf[]){
    
    for(int i=0; i<d; i++){
        if(y==stf[i].ID){
            printf("%ld %s %s %d ", stf[i].ID, stf[i].name, stf[i].designation, stf[i].office_name);
            if(stf[i].add.inf.tow.house_no != 0){
                printf("%d %d %s", stf[i].add.inf.tow.house_no, stf[i].add.inf.tow.road_no, stf[i].add.inf.tow.street_name);
            } else{
                printf("%s %s", stf[i].add.inf.vil.village, stf[i].add.inf.vil.upazilla);
            }
            printf(" %d %lf %lf %d %d %d %d", stf[i].age, stf[i].weight, stf[i].height, stf[i].salary, stf[i].date.day, stf[i].date.month, stf[i].date.year);
        }
    }
}

void inputstd(int a, struct student std[]){
    
    for(int i=0; i<a; i++){
        scanf("%lu %s %d %d %d %s %s %s %s %s %s %s %d %lf %lf %s %lf", std[i].reg, std[i].name, std[i].session,std[i].add.inf.tow.house_no, std[i].add.inf.tow.road_no, std[i].add.inf.tow.street_name, std[i].add.inf.vil.village, std[i].add.inf.vil.upazilla, std[i].add.police_station, std[i].add.post_office, std[i].add.district, std[i].add.country, std[i].age, std[i].weight, std[i].result, std[i].cgpa);
    }
}

void inputteach( int b, struct teacher teach[]){
    
    for(int i=0; i<b; i++){
        scanf("ld %s %s %d %d %d %s %s %s %d %lf %lf %d %d %d %d", teach[i].ID, teach[i].name, teach[i].designation, teach[i].dept_name,teach[i].add.inf.tow.house_no, teach[i].add.inf.tow.road_no, teach[i].add.inf.tow.street_name,teach[i].add.inf.vil.village, teach[i].add.inf.vil.upazilla, teach[i].age, teach[i].weight, teach[i].height, teach[i].salary, teach[i].date.day, teach[i].date.month, teach[i].date.year);
    }
}

void inputoff(int c, struct officer off[]){
    
    for(int i=0; i<c; i++){
        scanf("ld %s %s %d %d %d %s %s %s %d %lf %lf %d %d %d %d", off[i].ID, off[i].name, off[i].designation, off[i].office_name,off[i].add.inf.tow.house_no, off[i].add.inf.tow.road_no, off[i].add.inf.tow.street_name,off[i].add.inf.vil.village, off[i].add.inf.vil.upazilla, off[i].age, off[i].weight, off[i].height, off[i].salary, off[i].date.day, off[i].date.month, off[i].date.year);
    }
}

void inputstf(int d, struct staff stf[]){
    
    for(int i=0; i<d; i++){
        scanf("ld %s %s %d %d %d %s %s %s %d %lf %lf %d %d %d %d", stf[i].ID, stf[i].name, stf[i].designation, stf[i].office_name,stf[i].add.inf.tow.house_no, stf[i].add.inf.tow.road_no, stf[i].add.inf.tow.street_name,stf[i].add.inf.vil.village, stf[i].add.inf.vil.upazilla, stf[i].age, stf[i].weight, stf[i].height, stf[i].salary, stf[i].date.day, stf[i].date.month, stf[i].date.year);
    }
}