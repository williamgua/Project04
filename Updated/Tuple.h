#ifndef _tuple_h
#define _tuple_h

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct CSG* CSGptr;
typedef struct CSG {
    char Course[5];
    char StudentId[5];
    char Grade[2];
    CSGptr next;
} CSG;
typedef CSGptr CSGht[1009];


//studentid-name-address-phone
typedef struct SNAP *SNAPptr;
typedef struct SNAP {
    char StudentId[5];
    char Name[15];
    char Address[15];
    char Phone[10];
    SNAPptr next;
} SNAP;
typedef SNAPptr SNAPht[1009];


//course-prerequisite
typedef struct CP *CPptr;
typedef struct CP {
    char Course[5];
    char Prerequisite[5];
    CPptr next;
} CP;
typedef CPptr CPht[1009];


//course-day-hour
typedef struct CDH *CDHptr;
typedef struct CDH {
    char Course[5];
    char Day[2];
    char Hour[4];
    CDHptr next;
} CDH;
typedef CDHptr CDHht[1009];


//course-room
typedef struct CR *CRptr;
typedef struct CR {
    char Course[5];
    char Room[15];
    CRptr next;
} CR;
typedef CRptr CRht[1009];


/* Equal functions */
extern int equal_SNAP(SNAP* s1, SNAP* s2);
extern int equal_CSG(CSG* c1, CSG* c2);
extern int equal_CP(CP* c1, CP* c2);
extern int equal_CDH(CDH* c1, CDH* c2);
extern int equal_CR(CR* c1,CR* c2);

/* New functions */
extern SNAP* SNAP_new(char* StudentId, char* Name, char* Address, char* Phone);
extern CSG* CSG_new(char* Course, char* StudentId, char* Grade);
extern CP* CP_new(char* Course, char* Prerequisite);
extern CDH* CDH_new(char* Course, char* Day, char* Hour);
extern CR* CR_new(char* Course, char* Room);

#endif