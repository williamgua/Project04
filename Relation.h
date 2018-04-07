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
extern int CSG_equal(CSG r1, CSG r2);
extern int SNAP_equal(SNAP r1, SNAP r2);
extern int CP_equal(CP r1, CP r2);
extern int CR_equal(CR r1, CR r2);
extern int CDH_equal(CDH r1, CDH r2);

#endif