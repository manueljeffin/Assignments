#include<stdio.h>
struct cperson
{
	char cpid[3],fname[15],lname[15],email[30];
};
struct cgroup
{
	char c_id[6],c_name[30],street[30],area[30],city[15];
	struct cperson persons[2];
};
