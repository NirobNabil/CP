#include<stdio.h>

struct vil_info{
	char village[20], upazilla[20], dummy[50];
};
struct city_info{
	int house_no[20], road_no[20], street_name[50];
};
typedef union {
	vil_info vill;
	city_info city;
} Info;
struct Address{
	Info info;
	char police_station[20], post_office[20], district[20], country[20];
};
struct Joining_date{
	int day,month,year;
};
struct student{
	int reg;
	char name[100], session[20];
	Address address;
	int age, weight, height, result;
	float cgpa;
};
struct teacher{
	int id;
	char name[100], designation[20], dept_name[20];
	Address address;
	int age, weight, height, salary;
	Joining_date joining_date;
};
struct officer{
	int id;
	char name[100], designation[20], office_name[20];
	Address address;
	int age, weight, height, salary;
	Joining_date joining_date;
};
struct staff{
	int id;
	char name[100], designation[20], office_name[20];
	Address address;
	int age, weight, height, salary;
	Joining_date joining_date;
};

int main(){
	struct student students[] = {
		{
			11910027, "Nabil", "2018-2019", 
			{ {"10", "3/7/1", "johnson road"} , "sutrapur", "sutrapur", "dhaka", "bangladesh"},
			19, 80, 72, 1, 3.20
		},
		{
			11910026, "Avijit", "2018-2019", 
			{{"Akhalia", "dummy_upazilla", "dummy"}, "sutrapur", "sutrapur", "dhaka", "bangladesh"},
			19, 80, 72, 1, 3.20
		}
	};
	struct teacher teachers[] = {
		{
			1, "tapan", "senior teacher", "Physics", 
			{{"10", "3/7/1", "johnson road"}, "sutrapur", "sutrapur", "dhaka", "bangladesh"},
			19, 80, 72, 40000,
			{ 1, 3, 2000 }
		},
		{
			2, "bashar", "senior teacher", "Biology", 
			{{"Akhalia", "dummy_upazilla", "dummy"}, "sutrapur", "sutrapur", "dhaka", "bangladesh"},
			19, 80, 72, 1,
			{ 1, 5, 2004 }
		}
	};
	struct officer officers[] = {
		{
			1, "tapan", "senior teacher", "Physics", 
			{{"10", "3/7/1", "johnson road"}, "sutrapur", "sutrapur", "dhaka", "bangladesh"},
			19, 80, 72, 40000,
			{ 1, 3, 2000 }
		},
		{
			2, "bashar", "senior teacher", "Biology", 
			{{"10", "3/7/1", "johnson road"}, "sutrapur", "sutrapur", "dhaka", "bangladesh"},
			19, 80, 72, 1,
			{ 1, 5, 2004 }
		}
	};
	struct staff staffs[] = {
		{
			1, "tapan", "senior teacher", "Physics", 
			{{"10", "3/7/1", "johnson road"}, "sutrapur", "sutrapur", "dhaka", "bangladesh"},
			19, 80, 72, 40000,
			{ 1, 3, 2000 }
		},
		{
			2, "bashar", "senior teacher", "Biology", 
			{{{"10", "3/7/1", "johnson road"}}, "sutrapur", "sutrapur", "dhaka", "bangladesh"},
			19, 80, 72, 1,
			{ 1, 5, 2004 }
		}
	};
	int m;
	scanf("%d", &m);
	while(m--){
		int x, y;
		scanf("%d %d", &x, &y);
		switch(x){
			case 1:
			for(int i=0; i<2; i++) if(students[i].reg == y){
				printf("Name: %s\n reg: %d\n session: %d\n address: %s %s, house-%s, P.O-%s, P.S-%s, District-%s, Coutnry-%s\nage: %d\nheight: %d\nweight: %d\nresult: %d\ncgpa: %f",
					students[i].name, students[i].session, students[i].address.info.city.road_no,
					students[i].address.info.city.street_name, students[i].address.info.city.house_no,
					students[i].address.post_office, students[i].address.police_station, students[i].address.district, students[i].address.country,
					students[i].age, students[i].height, students[i].weight, students[i].result, students[i].cgpa);
			}
			break;
		}
	}
}