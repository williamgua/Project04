#include "Tuples.h"


int equal_CSG(CSG* c1, CSG* c2){
    if(c1 == NULL || c2 == NULL) return 0; 
    if(!(strcmp(c1->StudentId, c2->StudentId) == 0) && !((strcmp(c1->StudentId, "*") == 0) || (strcmp(c2->StudentId, "*") == 0))) return 0;
    if(!(strcmp(c1->Course, c2->Course) == 0) && !((strcmp(c1->Course, "*") == 0) || (strcmp(c2->Course, "*") == 0))) return 0;
    if(!(strcmp(c1->Grade, c2->Grade) == 0) && !((strcmp(c1->Grade, "*") == 0) || (strcmp(c2->Grade, "*") == 0))) return 0;
    return 1;
}

int equal_SNAP(SNAP* s1, SNAP* s2){
    if (s1 == NULL || s2 == NULL) return 0;
    if(!(strcmp(s1->StudentId, s2->StudentId) == 0) && !((strcmp(s1->StudentId, "*") == 0) || (strcmp(s2->StudentId, "*") == 0))) return 0;
    if (!(strcmp(s1->Name,s2->Name) == 0) && !((strcmp(s1->Name,"*") == 0) || (strcmp(s2->Name,"*") == 0))) return 0;
    if (!(strcmp(s1->Address,s2->Address) == 0) && !((strcmp(s1->Address,"*") == 0) || (strcmp(s2->Address,"*") == 0))) return 0;
    if (!(strcmp(s1->Phone, s2->Phone) == 0) && !((strcmp(s1->Phone,"*") == 0) || (strcmp(s2->Phone,"*") == 0))) return 0;
    return 1;
}

int equal_CP(CP* c1, CP* c2){
    if(c1 == NULL || c2 == NULL) return 0; 
    if(!(strcmp(c1->Prerequisite, c2->Prerequisite) == 0) && !((strcmp(c1->Prerequisite, "*") == 0) || (strcmp(c2->Prerequisite, "*") == 0))) return 0;
    if(!(strcmp(c1->Course, c2->Course) == 0) && !((strcmp(c1->Course, "*") == 0) || (strcmp(c2->Course, "*") == 0))) return 0;
    return 1;
}

int equal_CDH(CDH* r1, CDH* r2){
    if(r1 == NULL || r2 == NULL) return 0;
    if(!(strcmp(r1->Day, r2->Day) == 0) && !((strcmp(r1->Day, "*") == 0) || (strcmp(r2->Day, "*") == 0))) return 0;
    if(!(strcmp(r1->Hour, r2->Hour) == 0) && !((strcmp(r1->Hour, "*") == 0) || (strcmp(r2->Hour, "*") == 0))) return 0;
    if(!(strcmp(r1->Course, r2->Course) == 0) && !((strcmp(r1->Course, "*") == 0) || (strcmp(r2->Course, "*") == 0))) return 0;
    return 1;
}

int equal_CR(CR* c1, CR* c2){
    if(c1 == NULL || c2 == NULL) return 0; 
    if(!(strcmp(c1->Room, c2->Room) == 0) && !((strcmp(c1->Room, "*") == 0) || (strcmp(c2->Room, "*") == 0))) return 0;
    if(!(strcmp(c1->Course, c2->Course) == 0) && !((strcmp(c1->Course, "*") == 0) || (strcmp(c2->Course, "*") == 0))) return 0;
    return 1;
}

CSG* CSG_new(char* Course, char* StudentId, char* Grade){
    CSG* new = (CSG*)malloc(sizeof(CSG));
    strcpy(new->StudentId, StudentId);
    strcpy(new->Course, Course);
    strcpy(new->Grade, Grade);
    new->next = NULL;
    return new;
}

SNAP* SNAP_new(char* StudentId, char* Name, char* Address, char* Phone){
    SNAP* new = (SNAP*)malloc(sizeof(SNAP));
    strcpy(new->StudentId, StudentId);
    strcpy(new->Name, Name);
    strcpy(new->Address, Address);
    strcpy(new->Phone, Phone);
    new->next = NULL;
    return new;
}

CP* CP_new(char* Course, char* Prerequisite){
    CP* new = (CP*)malloc(sizeof(CP));
    strcpy(new->Course, Course);
    strcpy(new->Prerequisite, Prerequisite);
    new->next = NULL;
    return new;
}

CDH* CDH_new(char* Course, char* Day, char* Hour){
    CDH* new = (CDH*)malloc(sizeof(CDH));
    strcpy(new->Course, Course);
    strcpy(new->Day, Day);
    strcpy(new->Hour, Hour);
    new->next = NULL;
    return new;
}

CR* CR_new(char* Course, char* Room){
    CR* new = (CR*)malloc(sizeof(CR));
    strcpy(new->Course, Course);
    strcpy(new->Room, Room);
    new->next = NULL;
    return new;
}


