#ifndef _tuples_h
#define _tuples_h

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct CSG *CSGLIST;
typedef struct CSG {
    char Course[5];
    char StudentId[10];
    char Grade[2];
    CSGLIST next;
} CSG;


//studentid-name-address-phone
typedef struct SNAP *SNAPLIST;
typedef struct SNAP {
    char StudentId[10];
    char Name[15];
    char Address[15];
    char Phone[10];
    SNAPLIST next;
} SNAP;


//course-prerequisite
typedef struct CP *CPLIST;
typedef struct CP {
    char Course[5];
    char Prerequisite[5];
    CPLIST next;
} CP;


//course-day-hour
typedef struct CDH *CDHLIST;
typedef struct CDH {
    char Course[5];
    char Day[2];
    char Hour[4];
    CDHLIST next;
} CDH;

//course-room
typedef struct CR *CRLIST;
typedef struct CR {
    char Course[5];
    char Room[15];
    CRLIST next;
} CR;


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
