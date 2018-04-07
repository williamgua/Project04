#ifndef _relation_h
#define _relation_h

#include <stdio.h>
#include <stdlib.h>

typedef struct Course_StudentID_Grade {
	char course[5];
	int studentId;
	char grade[2];
} *CSG;

typedef struct StudentID_Name_Address_Phone {
	int studentId;
	char name[15];
	char address[15];
	char phone[9];
} *SNAP;

typedef struct Course_Prerequisite {
	char course[5];
	char prereq[5];
} *CP;

typedef struct Course_Room {
	char course[5];
	char room[15];
} *CR;

typedef struct Course_Day_Hour {
	char course[5];
	char day[2];
	char hour[4];
} *CDH;

extern CSG CSG_new(char* course, int studentId, char* grade[]);
extern SNAP SNAP_new(int studentId, char* name, char* address, char* phone);
extern CP CP_new(char* course, char* prereq);
extern CR CR_new(char* course, char* room);
extern CDH CDH_new(char* course, char* day, char* hour);

#endif