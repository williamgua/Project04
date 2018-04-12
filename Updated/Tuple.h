#ifndef _tuple_h
#define _tuple_h

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//CSG
typedef struct CSG* CSGptr;
typedef struct CSG {
    char Course[5];
    char StudentId[5];
    char Grade[2];
    CSGptr next;
} CSG;
typedef CSGptr CSGtb[1009];

//SNAP
typedef struct SNAP *SNAPptr;
typedef struct SNAP {
    char StudentId[5];
    char Name[15];
    char Address[15];
    char Phone[10];
    SNAPptr next;
} SNAP;
typedef SNAPptr SNAPtb[1009];

//CP
typedef struct CP *CPptr;
typedef struct CP {
    char Course[5];
    char Prerequisite[5];
    CPptr next;
} CP;
typedef CPptr CPtb[1009];

//CDH
typedef struct CDH *CDHptr;
typedef struct CDH {
    char Course[5];
    char Day[2];
    char Hour[4];
    CDHptr next;
} CDH;
typedef CDHptr CDHtb[1009];

//CR
typedef struct CR *CRptr;
typedef struct CR {
    char Course[5];
    char Room[15];
    CRptr next;
} CR;
typedef CRptr CRtb[1009];

//CRDH
typedef struct CRDH *CRDHptr;
typedef struct CRDH{
    char Course[10];
    char Room[30];
    char Day[4];
    char Hour[6];
    CRDHptr next;
} CRDH;
typedef CRDHptr CRDHtb[1009];


extern int equal_SNAP(SNAP* s1, SNAP* s2);
extern int equal_CSG(CSG* c1, CSG* c2);
extern int equal_CP(CP* c1, CP* c2);
extern int equal_CDH(CDH* c1, CDH* c2);
extern int equal_CR(CR* c1, CR* c2);
extern int equal_CRDH(CRDH* c1, CRDH* c2);

//INIT
extern SNAP* SNAP_new(char* StudentId, char* Name, char* Address, char* Phone);
extern CSG* CSG_new(char* Course, char* StudentId, char* Grade);
extern CP* CP_new(char* Course, char* Prerequisite);
extern CDH* CDH_new(char* Course, char* Day, char* Hour);
extern CR* CR_new(char* Course, char* Room);
extern CRDH* CRDH_new(char* Course, char* Room, char* Day, char* Hour);

#endif
