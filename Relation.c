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