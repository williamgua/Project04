//
//  Relations.c
//  p4
//
//  Created by jianpengyan on 2017/11/25.
//  Copyright © 2017年 jianpeng. All rights reserved.
//

#include "Relations.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define Lcourse 7
#define Lid
typedef char *String;

//course-studentid-grade
typedef struct CSG *CSGLIST;
struct CSG{
    char Course[10];
    char StudentId[10];
    char Grade[4];
    CSGLIST next;
};
typedef CSGLIST CSGH[1009];

//studentid-name-address-phone
typedef struct SNAP *SNAPLIST;
struct SNAP{
    char StudentId[10];
    char Name[30];
    char Address[50];
    char Phone[10];
    SNAPLIST next;
};
typedef SNAPLIST SNAPH[1009];

//course-prerequisite
typedef struct CP *CPLIST;
struct CP{
    char Course[10];
    char Prerequisite[10];
    CPLIST next;
};
typedef CPLIST CPH[1009];

//course-day-hour
typedef struct CDH *CDHLIST;
struct CDH{
    char Course[10];
    char Day[4];
    char Hour[6];
    CDHLIST next;
};
typedef CDHLIST CDHH[1009];

//course-room
typedef struct CR *CRLIST;
struct CR{
    char Course[10];
    char Room[30];
    CRLIST next;
};
typedef CRLIST CRH[1009];


int equal_CSG(CSG* c1, CSG* c2){
    if(!(c1==NULL && c2==NULL)){
        if((strcmp(c1->Course,c2->Course) == 0)&&(strcmp(c1->StudentId,c2->StudentId)== 0)&&(strcmp(c1->Grade,c2->Grade) == 0)) return 1;
        if((strcmp(c1->Course,c2->Course) == 0)&&(strcmp(c1->StudentId,c2->StudentId) == 0)&&(strcmp(c1->Grade,"*") == 0)) return 1;
        if((strcmp(c1->Course,c2->Course) == 0)&&(strcmp(c1->Grade,c2->Grade) == 0)&&(strcmp(c1->StudentId,"*") == 0)) return 1;
        if((strcmp(c1->StudentId,c2->StudentId) == 0)&&(strcmp(c1->Grade,c2->Grade) == 0)&&(strcmp(c1->Course,"*") == 0)) return 1;
        if((strcmp(c1->Course,c2->Course) == 0)&&(strcmp(c1->Grade,"*") == 0)&&(strcmp(c1->StudentId,"*") == 0)) return 1;
        if((strcmp(c1->Course,"*") == 0)&&(strcmp(c1->Grade,"*") == 0)&&(strcmp(c1->StudentId,c2->StudentId) == 0)) return 1;
        if((strcmp(c1->Course,c2->Course) == 0)&&(strcmp(c1->Grade,"*") == 0)&&(strcmp(c1->StudentId,"*") == 0)) return 1;
        if((strcmp(c1->Course,"*") == 0)&&(strcmp(c1->Grade,c2->Grade) == 0)&&(strcmp(c1->StudentId,"*") == 0)) return 1;
        if((strcmp(c1->Course,"*") == 0)&&(strcmp(c1->Grade,"*") == 0)&&(strcmp(c1->StudentId,"*") == 0)) return 1;
    }
    return 0;
}

int equal_SNAP(SNAP* s1, SNAP* s2){
    if (s1 == NULL || s2 == NULL) return 0;//TODO change studentID to string
    if (!(strcmp(s1->StudentId,s2->StudentId) == 0) && !((strcmp(s1->StudentId,"*") == 0) || (strcmp(s2->StudentId,"*") == 0))) return 0;
    if (!(strcmp(s1->Name,s2->Name) == 0) && !((strcmp(s1->Name,"*") == 0) || (strcmp(s2->Name,"*") == 0))) return 0;
    if (!(strcmp(s1->Address,s2->Address) == 0) && !((strcmp(s1->Address,"*") == 0) || (strcmp(s2->Address,"*") == 0))) return 0;
    if (!(strcmp(s1->Phone, s2->Phone) == 0) && !((strcmp(s1->Phone,"*") == 0) || (strcmp(s2->Phone,"*") == 0))) return 0;
    return 1;
}

int equal_CP(CP* c1, CP* c2){
    if (c1 == NULL || c2 == NULL) return 0;
    if ((!(strcmp(c1->Course,c2->Course) == 0) && !(strcmp(c1->Course,"*") == 0))||(!(strcmp(c1->Prerequisite,c2->Prerequisite) == 0) && !(strcmp(c1->Prerequisite,"*") == 0))) return 0;
    return 1;
}

int equal_CDH(CDH* c1, CDH* c2){
    if(!(c1==NULL && c2==NULL)){
        if((strcmp(c1->Course,c2->Course) == 0)&&(strcmp(c1->Day,c2->Day)== 0)&&(strcmp(c1->Hour,c2->Hour) == 0)) return 1;
        if((strcmp(c1->Course,c2->Course) == 0)&&(strcmp(c1->Day,c2->Day) == 0)&&(strcmp(c1->Hour,"*") == 0)) return 1;
        if((strcmp(c1->Course,c2->Course) == 0)&&(strcmp(c1->Hour,c2->Hour) == 0)&&(strcmp(c1->Day,"*") == 0)) return 1;
        if((strcmp(c1->Day,c2->Day) == 0)&&(strcmp(c1->Hour,c2->Hour) == 0)&&(strcmp(c1->Course,"*") == 0)) return 1;
        if((strcmp(c1->Course,c2->Course) == 0)&&(strcmp(c1->Hour,"*") == 0)&&(strcmp(c1->Day,"*") == 0)) return 1;
        if((strcmp(c1->Course,"*") == 0)&&(strcmp(c1->Hour,"*") == 0)&&(strcmp(c1->Day,c2->Day) == 0)) return 1;
        if((strcmp(c1->Course,c2->Course) == 0)&&(strcmp(c1->Hour,"*") == 0)&&(strcmp(c1->Day,"*") == 0)) return 1;
        if((strcmp(c1->Course,"*") == 0)&&(strcmp(c1->Hour,c2->Hour) == 0)&&(strcmp(c1->Day,"*") == 0)) return 1;
        if((strcmp(c1->Course,"*") == 0)&&(strcmp(c1->Hour,"*") == 0)&&(strcmp(c1->Day,"*") == 0)) return 1;
    }
    return 0;
}

int equal_CR(CR* c1, CR* c2){
    if (c1 == NULL || c2 == NULL) return 0;
    if ((!(strcmp(c1->Course,c2->Course) == 0) && !(strcmp(c1->Course,"*") == 0)) || (!(strcmp(c1->Room,c2->Room) == 0) && !(strcmp(c1->Room,"*") == 0))) return 0;
    return 1;
}

int hash(int input){
    return input % 1009;
}

int stringToInt(char* string){
    int ind = 0;
    for(int i = 0; i < 6; i++){
        ind += (int)string[i];
    }
    return ind;
}

CSG* CSG_new(char* Course, char* StudentId, char* Grade){
    CSG* new = (CSG*)calloc(1,sizeof(CSG));
    strcpy(new->StudentId, StudentId);
    strcpy(new->Course, Course);
    strcpy(new->Grade, Grade);
    return new;
}

SNAP* SNAP_new(char* StudentId, char* Name, char* Address, char* Phone){
    SNAP* new = (SNAP*)calloc(1,sizeof(SNAP));
    strcpy(new->StudentId, StudentId);
    strcpy(new->Name, Name);
    strcpy(new->Address, Address);
    strcpy(new->Phone, Phone);
    return new;
}

CP* CP_new(char* Course, char* Prerequisite){
    CP* new = (CP*)calloc(1,sizeof(CP));
    strcpy(new->Course, Course);
    strcpy(new->Prerequisite, Prerequisite);
    return new;
}

CDH* CDH_new(char* Course, char* Day, char* Hour){
    CDH* new = (CDH*)calloc(1,sizeof(CDH));
    strcpy(new->Course, Course);
    strcpy(new->Day, Day);
    strcpy(new->Hour, Hour);
    return new;
}

CR* CR_new(char* Course, char* Room){
    CR* new = (CR*)calloc(1,sizeof(CR));
    strcpy(new->Course, Course);
    strcpy(new->Room, Room);
    return new;
}

void insert_CSG(CSG* toInsert,CSGH CSGTable){
    //Hashes on inserted CSG's StudentId
    int index = hash(stringToInt(toInsert->StudentId));
    if (CSGTable[index] == NULL){
        //Fresh, empty Bucket
        CSGTable[index] = toInsert;
    } else if (strcmp(CSGTable[index]->Course, toInsert->Course)==0&&strcmp(CSGTable[index]->StudentId, toInsert->StudentId)==0&&strcmp(CSGTable[index]->Grade, toInsert->Grade)==0){
    } else{
        CSG* currentHead = CSGTable[index];
        int eq = 0;
        while(currentHead->next!=NULL){
            if (strcmp(CSGTable[index]->Course, toInsert->Course)==0&&strcmp(CSGTable[index]->StudentId, toInsert->StudentId)==0&&strcmp(CSGTable[index]->Grade, toInsert->Grade)==0){
                eq = 1;
                break;
            }else{
                currentHead = currentHead->next;
            }
        }
        if(eq==0){
            currentHead->next = toInsert;
        }
    }
}

void insert_SNAP(SNAP* toInsert,SNAPH SNAPTable){
    //Hashes on inserted SNAP's StudentId
    int index = hash(stringToInt(toInsert->StudentId));

    if (SNAPTable[index] == NULL){
        //Fresh, empty Bucket
        SNAPTable[index] = toInsert;
    } else{
        //Already a member in bucket
        SNAP* currentHead = SNAPTable[index];
        toInsert->next = currentHead;
        SNAPTable[index] = toInsert;
    }
}

void insert_CP(CP* toInsert,CPH CPTable){
    //Hashes on inserted CP's StudentId
    int index = hash(stringToInt(toInsert->Course));

    if (CPTable[index] == NULL){
        //Fresh, empty Bucket
        CPTable[index] = toInsert;
    } else if (strcmp(CPTable[index]->Course, toInsert->Course)==0&&strcmp(CPTable[index]->Prerequisite, toInsert->Prerequisite)==0){
    }else{
        CP* currentHead = CPTable[index];
        int eq = 0;
        while(currentHead->next!=NULL){
            //Already a member in bucket
            if (strcmp(currentHead->next->Course, toInsert->Course)==0&&strcmp(currentHead->next->Prerequisite, toInsert->Prerequisite)==0){
                eq = 1;
                break;
            }else{
                currentHead = currentHead->next;
            }
        }
        if(eq==0){
            currentHead->next = toInsert;
        }
    }
}

void insert_CDH(CDH* toInsert,CDHH CDHTable){
    //Hashes on inserted CD's StudentId
    int index = hash(stringToInt(toInsert->Course));

    if (CDHTable[index] == NULL){
        //Fresh, empty Bucket
        CDHTable[index] = toInsert;
    } else if (strcmp(CDHTable[index]->Course, toInsert->Course)==0&&strcmp(CDHTable[index]->Day, toInsert->Day)==0&&strcmp(CDHTable[index]->Hour, toInsert->Hour)==0){
    } else{
        //Already a member in bucket
        CDH* currentHead = CDHTable[index];
        int eq = 0;
        while(currentHead->next!=NULL){
            if (strcmp(CDHTable[index]->Course, toInsert->Course)==0&&strcmp(CDHTable[index]->Day, toInsert->Day)==0&&strcmp(CDHTable[index]->Hour, toInsert->Hour)==0){
                eq = 1;
                break;
            }else{
                currentHead = currentHead->next;
            }
        }
        if(eq==0){
            currentHead->next = toInsert;
        }
    }
}

void insert_CR(CR* toInsert,CRH CRTable){
    //Hashes on inserted CR's StudentId
    int index = hash(stringToInt(toInsert->Course));

    if (CRTable[index] == NULL){
        //Fresh, empty Bucket
        CRTable[index] = toInsert;
    }else if(strcmp(CRTable[index]->Course, toInsert->Course)==0&&strcmp(CRTable[index]->Room, toInsert->Room)==0){}
    else{
        //Already a member in bucket
        CR* currentHead = CRTable[index];
        int eq = 0;
        while(currentHead->next!=NULL){
            if (strcmp(CRTable[index]->Course, toInsert->Course)==0&&strcmp(CRTable[index]->Room, toInsert->Room)==0){
                eq = 1;
                break;
            }else{
                currentHead = currentHead->next;
            }
        }
        if(eq==0){
            currentHead->next = toInsert;
        }
    }
}

void delete_CSG(CSG* toDelete,  CSGH CSGHTable){
    int index = hash(stringToInt(toDelete->StudentId));

    if (CSGHTable[index] == NULL){
        return; //Not found
    }
    //If it's the first in bucket before cycling through
    if (equal_CSG( toDelete , CSGHTable[index])){
        CSG* toFree = CSGHTable[index];
        CSGHTable[index] = CSGHTable[index]->next;
        free(toFree);
    } else {//Not in first bucket

        for (CSG* temp = CSGHTable[index]; temp != NULL && temp->next != NULL; temp = temp->next){
            //If we've found the matching entry as temp's next
            if (equal_CSG(toDelete, temp->next)){
                CSG* toFree = temp->next;
                temp->next = temp->next->next;//passes the deleted node
                free(toFree);//Free the deleted data
            }
        }
    }
}

void delete_SNAP(SNAP* toDelete,  SNAPH SNAPHTable){
    int index = hash(stringToInt(toDelete->StudentId));

    if (SNAPHTable[index] == NULL){
        return; //Not found
    }
    //If it's the first in bucket before cycling through
    if (equal_SNAP( toDelete, SNAPHTable[index])){
        SNAP* toFree = SNAPHTable[index];
        SNAPHTable[index] = SNAPHTable[index]->next;
        free(toFree);
    } else {//Not in first bucket
        for (SNAP* temp = SNAPHTable[index]; temp != NULL && temp->next != NULL; temp = temp->next){
            //If we've found the matching entry as temp's next
            if (equal_SNAP(toDelete, temp->next)){
                SNAP* toFree = temp->next;
                temp->next = temp->next->next;//passes the deleted node
                free(toFree);//Free the deleted data
            }
        }
    }
}

void delete_CP(CP* toDelete,  CPH CPHTable){
    int index = hash(stringToInt(toDelete->Course));

    if (CPHTable[index] == NULL){
        return; //Not found
    }
    //If it's the first in bucket before cycling through
    if (equal_CP( toDelete, CPHTable[index])){
        CP* toFree = CPHTable[index];
        CPHTable[index] = CPHTable[index]->next;
        free(toFree);
    } else {//Not in first bucket
        for (CP* temp = CPHTable[index]; temp != NULL && temp->next != NULL; temp = temp->next){
            //If we've found the matching entry as temp's next
            if (equal_CP(toDelete, temp->next)){
                CP* toFree = temp->next;
                temp->next = temp->next->next;//passes the deleted node
                free(toFree);//Free the deleted data
            }
        }
    }
}

void delete_CDH(CDH* toDelete,  CDHH CDHHTable){
    int index = hash(stringToInt(toDelete->Course));

    if (CDHHTable[index] == NULL){
        return; //Not found
    }
    //If it's the first in bucket before cycling through
    if (equal_CDH( toDelete,CDHHTable[index])){
        CDH* toFree = CDHHTable[index];
        CDHHTable[index] = CDHHTable[index]->next;
        free(toFree);
    } else {//Not in first bucket
        for (CDH* temp = CDHHTable[index]; temp != NULL && temp->next != NULL; temp = temp->next){
            //If we've found the matching entry as temp's next
            if (equal_CDH(toDelete, temp->next)){
                CDH* toFree = temp->next;
                temp->next = temp->next->next;//passes the deleted node
                free(toFree);//Free the deleted data
            }
        }
    }
}

void delete_CR(CR* toDelete,  CRH CRHTable){
    int index = hash(stringToInt(toDelete->Course));

    if (CRHTable[index] == NULL){
        return; //Not found
    }
    if (equal_CR(toDelete ,CRHTable[index])){
        CR* toFree = CRHTable[index];
        CRHTable[index] = CRHTable[index]->next;
        free(toFree);
    } else {//Not in first bucket
        for (CR* temp = CRHTable[index]; temp != NULL && temp->next != NULL; temp = temp->next){
            //If we've found the matching entry as temp's next
            if (equal_CR(toDelete, temp->next)){
                CR* toFree = temp->next;
                temp->next = temp->next->next;//passes the deleted node
                free(toFree);//Free the deleted data
            }
        }
    }
}


CSG** lookup_CSG(CSG* toLookup, CSGH CSGHTable)
{
    //  int index = hash(stringToInt(toLookup->StudentId));
    CSG** List = (CSG**)calloc(1009,sizeof(CSG*));
    int i = 0;//index pointers in double pointer
    for(int j = 0;j<1009;j++){
        if(CSGHTable[j]!=NULL){
            for (CSG* temp = CSGHTable[j]; temp != NULL; temp = temp->next){
                if (equal_CSG(toLookup, temp)) {//If we've found the matching entry as temp's next
                    List[i] = temp;
                    i++;
                }
            }
        }
    }
    if (List[0] == NULL) return NULL;
    return List;
}

SNAP** lookup_SNAP(SNAP* toLookup, SNAPH SNAPHTable)
{
    //int index = hash(stringToInt(toLookup->StudentId));
    SNAP** List = (SNAP**)calloc(1009,sizeof(SNAP*));
    int i = 0;//index pointers in double pointer
    for(int j = 0;j<1009;j++){
        if(SNAPHTable[j]!=NULL){

            for (SNAP* temp = SNAPHTable[j]; temp != NULL; temp = temp->next){
                if (equal_SNAP(toLookup, temp)){//If we've found the matching entry as temp's next
                    List[i] = temp;
                    i++;
                }
            }
        }
    }
    if (List[0] == NULL) return NULL;
    return List;
}

CP** lookup_CP(CP* toLookup, CPH CPHTable)
{
    CP** List = (CP**)calloc(1009,sizeof(CP*));
    int i = 0;//index pointers in double pointer
    for(int j = 0;j<1009;j++){
        if(CPHTable[j]!=NULL){
            for (CP* temp = CPHTable[j]; temp != NULL; temp = temp->next){
                if (equal_CP(toLookup, temp)) {//If we've found the matching entry as temp's next
                    List[i] = temp;
                    i++;
                }
            }
        }
    }
    if (List[0] == NULL) return NULL;
    return List;
}

CDH** lookup_CDH(CDH* toLookup, CDHH CDHHTable)
{
    //int index = hash(stringToInt(toLookup->Course));
    CDH** List = (CDH**)calloc(1009,sizeof(CDH*));
    int i = 0;//index pointers in double pointer
    for(int j = 0;j<1009;j++){
        if(CDHHTable[j]!=NULL){
            for (CDH* temp = CDHHTable[j]; temp != NULL; temp = temp->next){
                if (equal_CDH(toLookup, temp)){//If we've found the matching entry as temp's next
                    List[i] = temp;
                    i++;
                }
            }
        }
    }
    if (List[0] == NULL) return NULL;
    return List;
}

CR** lookup_CR(CR* toLookup, CRH CRHTable)
{
    int i = 0;//index pointers in double pointer
    CR** List = (CR**)calloc(1009,sizeof(CR*));
    for(int i = 0; i<1009;i++){
        List[i] = NULL;
    }
    for(int j = 0;j<1009;j++){
        if(CRHTable[j]!=NULL){
            for (CR* temp = CRHTable[j]; temp != NULL; temp = temp->next){
                if (equal_CR(toLookup, temp)){//If we've found the matching entry as temp's next
                    // printf("%s\n",temp->Course);
                    List[i] = temp;
                    i++;
                }
            }
        }
    }
    if (List[0] == NULL) return NULL;
    return List;
}

void print_CSG(CSGLIST* csglist){
    int i = 0;
    while (csglist[i] != NULL) {
        String Course = csglist[i]->Course;
        String StudentID= csglist[i]->StudentId;
        String Grade = csglist[i]->Grade;
        printf("%s\n", Course);
        printf("%s\n",StudentID);
        printf("%s\n", Grade);
        i++;
    }
}
void print_SNAP(SNAPLIST* snaplist){
    int i = 0;
    while (snaplist[i] != NULL) {
        String Name = snaplist[i]->Name;
        String StudentID= snaplist[i]->StudentId;
        String Phone = snaplist[i]->Phone;
        String Address = snaplist[i]->Address;
        printf("%s\n",StudentID);
        printf("%s\n", Name);
        printf("%s\n", Address);
        printf("%s\n", Phone);
        i++;
    }
}

void print_CP(CPLIST* cplist){
    if (cplist){
        int i = 0;
        while (cplist[i] != NULL) {
            String Course = cplist[i]->Course;
            String Prerequisite = cplist[i]->Prerequisite;
            printf("%s\n", Course);
            printf("%s\n",Prerequisite);
            printf("\n");
            i++;
        }
    }
    else {
        printf("FALSE: CPEMPTY\n");
    }
}

void print_CDH(CDHLIST* cdhlist){
    int i = 0;
    while (cdhlist[i] != NULL) {
        String Course = cdhlist[i]->Course;
        String Day= cdhlist[i]->Day;
        String Hour = cdhlist[i]->Hour;
        printf("%s\n", Course);
        printf("%s\n",Day);
        printf("%s\n",Hour);
        i++;
    }
}
void print_CR(CRLIST* crlist){
    if (crlist){
        int i = 0;
        while (crlist[i]) {
            String Course = crlist[i]->Course;
            String Room = crlist[i]->Room;
            printf("%s\n", Course);
            printf("%s\n", Room);
            printf("\n");
            i++;
        }
    }
    else {
        printf("CREMPTY");
    }
}

//find grade for part 2
void findGrade(String Name, String Course, SNAPH snaptable, CSGH csgtable){
    SNAPLIST* list1 = lookup_SNAP(SNAP_new("*", Name, "*", "*"), snaptable);
    int i = 0 ;
    while(list1[i] != NULL && i <1009){

        String id = list1[i]->StudentId;
        CSGLIST* list2 = lookup_CSG(CSG_new("*", id, "*"), csgtable);
        int j = 0;
        while(list2[j] != NULL && j <1009) {
            if(strcmp(list2[j]->Course,Course) == 0){
                printf("Grade :");
                printf("%s\n", list2[j]->Grade);
            }
            j++;
        }
//        free(id);
        free(list2);
        i++;
    }
    free(list1);
}

//find location for part 2
void findRoom(String Name, String Hour, String Day, SNAPH snaptable, CSGH csgtable, CDHH cdhtable, CRH crtable){
    SNAPLIST* list1 = lookup_SNAP(SNAP_new("*", Name, "*", "*"), snaptable);
    int i = 0 ;
    while(list1[i] != NULL && i <1009){
        String id = list1[i]->StudentId;
        // printf("%s\n", id);
        CSGLIST* list2 = lookup_CSG(CSG_new("*", id, "*"), csgtable);
        int j = 0;
        while(list2[j] != NULL && j <1009) {
            String course = list2[j]->Course;
            CDHLIST* list3 = lookup_CDH(CDH_new(course, Day, Hour), cdhtable);
            int k = 0;
            if(list3==NULL){j++; continue;}
            while(list3[k] != NULL && k <1009) {
                // printf("%s\n", course);
                CRLIST* list4 = lookup_CR(CR_new(course, "*"), crtable);
                int l = 0;
                while(list3[l] != NULL && l <1009){
                    if(list4==NULL){l++; continue;}
                    printf("Room :");
                    printf("%s\n", list4[l]->Room);
                    //  printf("%d\n",l);
                    l++;
                }
                free(list4);
                k++;
            }
            free(list3);
            j++;
        }
        free(id);
        free(list2);
        i++;
    }
    free(list1);
}


//part 3 : Select function for CORSE on CSG structs
CSG** select_CSG(CSGH CSGHTable, char* course){
    CSG** sCSG = (CSG**)calloc(1009, sizeof(CSG*));
    int CSGIndex = 0;
    for(int i = 0; i < 1009; i++){
        for (CSG* temp = CSGHTable[i]; temp != NULL; temp = temp->next){
            if(strcmp(temp->Course,course)==0){
                sCSG[CSGIndex] = temp;
                CSGIndex++;
            }
        }
    }
    return sCSG;
}



int main() {
    CSGH csgtable ;
    for(int i=0; i<1009; i++){
        csgtable[i]=NULL;
    }
    insert_CSG( CSG_new("CS101", "12345", "A") , csgtable);
    insert_CSG( CSG_new("CS101", "67890", "B") , csgtable);
    insert_CSG( CSG_new("EE200", "12345", "C") , csgtable);
    insert_CSG( CSG_new("EE200", "22222", "B+") , csgtable);
    insert_CSG( CSG_new("CS101", "33333", "A-") , csgtable);
    insert_CSG( CSG_new("PH100", "67890", "C+") , csgtable);

    SNAPH snaptable;
    for(int i=0; i<1009; i++){
        snaptable[i]=NULL;
    }
    insert_SNAP( SNAP_new("12345", "C.Brown", "12 Apple St.","555-1234"),  snaptable);
    insert_SNAP( SNAP_new("67890", "L.Van Pelt", "34 Pear Ave.","555-5678"),  snaptable);
    insert_SNAP( SNAP_new("22222", "P.Patty", "56 Grape Blvd.","555-9999"),  snaptable);

    CPH cptable;
    for(int i=0; i<1009; i++){
        cptable[i]=NULL;
    }
    insert_CP( CP_new("CS101", "CS100"), cptable);
    insert_CP( CP_new("EE200", "EE005"), cptable);
    insert_CP( CP_new("EE200", "CS100"), cptable);
    insert_CP( CP_new("CS120", "CS101"), cptable);
    insert_CP( CP_new("CS121", "CS120"), cptable);
    insert_CP( CP_new("CS205", "CS101"), cptable);
    insert_CP( CP_new("CS206", "CS121"), cptable);
    insert_CP( CP_new("CS206", "CS205"), cptable);

    CDHH cdhtable;
    for(int i=0; i<1009; i++){
        cdhtable[i]=NULL;
    }
    insert_CDH( CDH_new("CS101", "M", "9AM"),  cdhtable);
    insert_CDH( CDH_new("CS101", "W", "9AM"),  cdhtable);
    insert_CDH( CDH_new("CS101", "F", "9AM"),  cdhtable);
    insert_CDH( CDH_new("EE200", "Tu", "10AM"),  cdhtable);
    insert_CDH( CDH_new("EE200", "W", "1PM"),  cdhtable);
    insert_CDH( CDH_new("EE200", "Th", "10AM"),  cdhtable);

    CRH crtable;
    for(int i=0; i<1009; i++){
        crtable[i]=NULL;
    }
    insert_CR( CR_new("CS101", "Turing Aud."), crtable);
    insert_CR( CR_new("EE200", "25 Ohm Hall"), crtable);
    insert_CR( CR_new("PH100", "Newton Lab."), crtable);



    //example 8.2
    CSGLIST* csglist = lookup_CSG(CSG_new("CS101", "12345", "*"), csgtable);//a
    CPLIST* cplist = lookup_CP(CP_new("CSC205", "CS120"), cptable);//b
    delete_CR(CR_new("CS101", "*"), crtable);//c
    CRLIST* crlist = lookup_CR(CR_new("*", "*"), crtable);
    insert_CP(CP_new("CS205", "CS120"), cptable);//d
    insert_CP(CP_new("CS205", "CS101"), cptable);//e
    CPLIST* cplist2 = lookup_CP(CP_new("CS205", "*"), cptable);
    insert_CR( CR_new("CS101", "Turing Aud."), crtable);

    CSGLIST* csglist2 = select_CSG(csgtable, "CS101");


    printf("Part I \n");
    printf("Find the tuple that shows the grade of the student with ID 12345 in CS101: \n");
    print_CSG(csglist);
    printf("\n");
    printf("Whether CS120 is a prerequisite of CS205: \n");
    print_CP(cplist);
    printf("\n");
    printf("Drop the first tuple(CS101,*) of CR, show the remaining tuples: \n");
    print_CR(crlist);
    printf("\n");
    printf("Make CS120 a prerequisite of CS205 and insert tuple (CS205,CS101) which already exists in CP, show the tuples starts with CS205 afterwards: \n");
    print_CP(cplist2);
    //printf("%d\n",equal_CDH(CDH_new("CS101", "*", "*"), CDH_new("CS101", "M", "9PM")));

    printf("Part II \n");
    printf("What grade did StudentName=P.Patty get in CourseName=EE200 ?: \n");
    findGrade("P.Patty", "EE200", snaptable, csgtable);
    printf("\n");
    printf("Where is StudentName=L.Van Pelt at Time=9AM on Day=W ?: \n");
    findRoom("L.Van Pelt", "9AM", "W", snaptable, csgtable, cdhtable, crtable);
    printf("\n");
    printf("Part III \n");
    printf("Select CourseName= CS101 From CSG: \n");
    print_CSG(csglist2);
}

















