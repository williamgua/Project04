#include "Database_new.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int hash(int input){
    return input % 1009;
}

int stringToInt(char* input) {
    int index = 0;
    for(int i=0; i<6; i++) {
        index += (int)input[i];
    }
    return index;
}

void insert_CSG(CSG* tuple, CSGht table) {
    int index = hash(strToInt(tuple->StudentId)); //hash on studentID (if no ID, hash on Course)
    if(table[index] == NULL) {
        table[index] = tuple; //if the bucket is empty, just insert
    } 
    //if the bucket is not empty, and if the first tuple in it is not a duplicate
    else if(!(strcmp(table[index]->Course, tuple->Course)==0 && strcmp(table[index]->StudentId, tuple->StudentId)==0 && strcmp(table[index]->Grade, tuple->Grade)==0)) {
        CSG* currentHead = table[index];
        int match = 0;
        while(currentHead != NULL) {
            //if a duplicate is found, terminate
            if(strcmp(currentHead->Course, tuple->Course)==0 && strcmp(currentHead->StudentId, tuple->StudentId)==0 && strcmp(currentHead->Grade, tuple->Grade)==0) {
                match = 1;
                break;
            } else {
                currentHead = currentHead->next; //until itself is null
            }
        }
        if(match == 0) {
            currentHead = tuple; //insert the tuple as the next of the last tuple in the bucket
        }
    }
}

void insert_SNAP(SNAP* tuple, SNAPht table) {
   int index = hash(strToInt(tuple->StudentId));
    if(table[index] == NULL) {
        table[index] = tuple;
    } 
    else if(!(strcmp(table[index]->StudentId, tuple->StudentId)==0 && strcmp(table[index]->Name, tuple->Name)==0 && strcmp(table[index]->Address, tuple->Address)==0 && strcmp(table[index]->Phone, tuple->Phone)==0)) {
        SNAP* currentHead = table[index];
        int match = 0;
        while(currentHead != NULL) {
            if(strcmp(currentHead->StudentId, tuple->StudentId)==0 && strcmp(currentHead->Name, tuple->Name)==0 && strcmp(currentHead->Address, tuple->Address)==0 && strcmp(currentHead->Phone, tuple->Phone)==0) {
                match = 1;
                break;
            } else {
                currentHead = currentHead->next;
            }
        }
        if(match == 0) {
            currentHead = tuple;
        }
    }
}

void insert_CP(CP* tuple, CPht table) {
    int index = hash(strToInt(tuple->Course));
    if(table[index] == NULL) {
        table[index] = tuple;
    } 
    else if(!(strcmp(table[index]->Course, tuple->Course)==0 && strcmp(table[index]->Prerequisite, tuple->Prerequisite)==0)) {
        CP* currentHead = table[index];
        int match = 0;
        while(currentHead != NULL) {
            if(strcmp(currentHead->Course, tuple->Course)==0 && strcmp(currentHead->Prerequisite, tuple->Prerequisite)==0) {
                match = 1;
                break;
            } else{
                currentHead = currentHead->next;
            }
        }
        if(match == 0) {
            currentHead = tuple;
        }
    }
}

void insert_CDH(CDH* tuple, CDHht table) {
    int index = hash(strToInt(tuple->Course));
    if(table[index] == NULL) {
        table[index] = tuple;
    } 
    else if(!(strcmp(table[index]->Course, tuple->Course)==0 && strcmp(table[index]->Day, tuple->Day)==0 && strcmp(table[index]->Hour, tuple->Hour)==0)) {
        CDH* currentHead = table[index];
        int match = 0;
        while(currentHead != NULL) {
            if(strcmp(currentHead->Course, tuple->Course)==0 && strcmp(currentHead->Day, tuple->Day)==0 && strcmp(currentHead->Hour, tuple->Hour)==0) {
                match = 1;
                break;
            } else {
                currentHead = currentHead->next;
            }
        }
        if(match == 0) {
            currentHead = tuple;
        }
    }
}

void insert_CR(CR* tuple, CRht table) {
    int index = hash(strToInt(tuple->Course));
    if(table[index] == NULL) {
        table[index] = tuple;
    } 
    else if(!(strcmp(table[index]->Course, tuple->Course)==0 && strcmp(table[index]->Room, tuple->Room)==0)) {
        CR* currentHead = table[index];
        int match = 0;
        while(currentHead != NULL) {
            if(strcmp(currentHead->Course, tuple->Course)==0 && strcmp(currentHead->Room, tuple->Room)==0) {
                match = 1;
                break;
            } else{
                currentHead = currentHead->next;
            }
        }
        if(match == 0) {
            currentHead = tuple;
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