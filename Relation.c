#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Relations.h"

CSG CSG_new(char course[5], int studentId, char grade[2]) {
	CSG csg = (CSG)malloc(sizeof(CSG));
  	strcpy(csg->course, course);
  	strcpy(csg->grade, grade);
  	csg->studentId = studentId;
  	return csg;
}

SNAP SNAP_new(int studentId, char name[15], char address[15], char phone[9]) {
	SNAP snap = (SNAP)malloc(sizeof(SNAP));
	snap->studentId = studentId;
	strcpy(snap->name, name);
	strcpy(snap->address, address);
	strcpy(snap->phone, phone);
	return snap;
}

CP CP_new(char course[5], char prereq[5]) {
	CP cp = (CP)malloc(sizeof(CP));
	strcpy(cp->course, course);
	strcpy(cp->prereq, prereq);
	return cp;
}

CR CR_new(char course[5], char room[15]) {
	CR cr = (CR)malloc(sizeof(CR));
 	strcpy(cr->course, course);
	strcpy(cr->room, room);
	return cr;
}

CDH CDH_new(char course[5], char day[2], char hour[4]) {
	CDH cdh = (CDH)malloc(sizeof(CDH));
  	strcpy(cdh->course,course);
	strcpy(cdh->day,day);
	strcpy(cdh->hour,hour);
  	return cdh;
}

int CSG_equal(CSG r1, CSG r2) {
	if(r1 == NULL || r2 == NULL) return 0; 
	if(r1->studentId != r2->studentId) return 0; //need to be string and deal with * ??
	if(!(strcmp(r1->course, r2->course) == 0) && !((strcmp(r1->course, "*") == 0) || (strcmp(r2->course, "*") == 0))) return 0;
	if(!(strcmp(r1->grade, r2->grade) == 0) && !((strcmp(r1->grade, "*") == 0) || (strcmp(r2->grade, "*") == 0))) return 0;
	return 1;
}

int SNAP_equal(SNAP r1, SNAP r2) {
	if(r1 == NULL || r2 == NULL) return 0; 
	if(r1->studentId != r2->studentId) return 0; //need to be string and deal with * ??
	if(!(strcmp(r1->name, r2->name) == 0) && !((strcmp(r1->name, "*") == 0) || (strcmp(r2->name, "*") == 0))) return 0;
	if(!(strcmp(r1->address, r2->address) == 0) && !((strcmp(r1->address, "*") == 0) || (strcmp(r2->address, "*") == 0))) return 0;
	if(!(strcmp(r1->phone, r2->phone) == 0) && !((strcmp(r1->phone, "*") == 0) || (strcmp(r2->phone, "*") == 0))) return 0;
	return 1;
}

int CP_equal(CP r1, CP r2) {
	if(r1 == NULL || r2 == NULL) return 0; 
	if(!(strcmp(r1->prereq, r2->prereq) == 0) && !((strcmp(r1->prereq, "*") == 0) || (strcmp(r2->prereq, "*") == 0))) return 0;
	if(!(strcmp(r1->course, r2->course) == 0) && !((strcmp(r1->course, "*") == 0) || (strcmp(r2->course, "*") == 0))) return 0;
	return 1;
}

int CR_equal(CR r1, CR r2) {
	if(r1 == NULL || r2 == NULL) return 0; 
	if(!(strcmp(r1->room, r2->room) == 0) && !((strcmp(r1->room, "*") == 0) || (strcmp(r2->room, "*") == 0))) return 0;
	if(!(strcmp(r1->course, r2->course) == 0) && !((strcmp(r1->course, "*") == 0) || (strcmp(r2->course, "*") == 0))) return 0;
	return 1;
}

int CDH_equal(CDH r1, CDH r2) {
	if(r1 == NULL || r2 == NULL) return 0;
	if(!(strcmp(r1->day, r2->day) == 0) && !((strcmp(r1->day, "*") == 0) || (strcmp(r2->day, "*") == 0))) return 0;
	if(!(strcmp(r1->hour, r2->hour) == 0) && !((strcmp(r1->hour, "*") == 0) || (strcmp(r2->hour, "*") == 0))) return 0;
	return 1;
}