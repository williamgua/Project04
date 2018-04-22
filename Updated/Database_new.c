#include "Database_new.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int hash(int input){
    return input % 1009;
}

int strToInt(char* in) {
    int index = 0;
    for(int i=0; i<6; i++) {
        index += (int)in[i];
    }
    return index;
}

void insert_CSG(CSG* tuple, CSGtb table) {
    int index = hash(strToInt(tuple->StudentId)); //hash on studentID (if no ID, hash on Course)
    if(table[index] == NULL) {
        table[index] = tuple; //if the bucket is empty, just insert
    }
    //if the bucket is not empty, and if the first tuple in it is not a duplicate
    else if(!(strcmp(table[index]->Course, tuple->Course)==0 && strcmp(table[index]->StudentId, tuple->StudentId)==0 && strcmp(table[index]->Grade, tuple->Grade)==0)) {
        CSG* current = table[index];
        int match = 0;
        while(current != NULL) {
            //if a duplicate is found, terminate
            if(strcmp(current->Course, tuple->Course)==0 && strcmp(current->StudentId, tuple->StudentId)==0 && strcmp(current->Grade, tuple->Grade)==0) {
                match = 1;
                break;
            } else {
                current = current->next; //until itself is null
            }
        }
        if(match == 0) {
            current = tuple; //insert the tuple as the next of the last tuple in the bucket
        }
    }
    
}

void insert_SNAP(SNAP* tuple, SNAPtb table) {
   int index = hash(strToInt(tuple->StudentId));
    if(table[index] == NULL) {
        table[index] = tuple;
    }
    else if(!(strcmp(table[index]->StudentId, tuple->StudentId)==0 && strcmp(table[index]->Name, tuple->Name)==0 && strcmp(table[index]->Address, tuple->Address)==0 && strcmp(table[index]->Phone, tuple->Phone)==0)) {
        SNAP* current = table[index];
        int match = 0;
        while(current != NULL) {
            if(strcmp(current->StudentId, tuple->StudentId)==0 && strcmp(current->Name, tuple->Name)==0 && strcmp(current->Address, tuple->Address)==0 && strcmp(current->Phone, tuple->Phone)==0) {
                match = 1;
                break;
            } else {
                current = current->next;
            }
        }
        if(match == 0) {
            current = tuple;
        }
    }

}

void insert_CP(CP* tuple, CPtb table) {
    int index = hash(strToInt(tuple->Course));
    if(table[index] == NULL) {
        table[index] = tuple;
    } 
    else if(!(strcmp(table[index]->Course, tuple->Course)==0 && strcmp(table[index]->Prerequisite, tuple->Prerequisite)==0)) {
        CP* current = table[index];
        int match = 0;
        while(current != NULL) {
            if(strcmp(current->Course, tuple->Course)==0 && strcmp(current->Prerequisite, tuple->Prerequisite)==0) {
                match = 1;
                break;
            } else{
                current = current->next;
            }
        }
        if(match == 0) {
            current = tuple;
        }
    }
}

void insert_CDH(CDH* tuple, CDHtb table) {
    int index = hash(strToInt(tuple->Course));
    if(table[index] == NULL) {
        table[index] = tuple;
    } 
    else if(!(strcmp(table[index]->Course, tuple->Course)==0 && strcmp(table[index]->Day, tuple->Day)==0 && strcmp(table[index]->Hour, tuple->Hour)==0)) {
        CDH* current = table[index];
        int match = 0;
        while(current != NULL) {
            if(strcmp(current->Course, tuple->Course)==0 && strcmp(current->Day, tuple->Day)==0 && strcmp(current->Hour, tuple->Hour)==0) {
                match = 1;
                break;
            } else {
                current = current->next;
            }
        }
        if(match == 0) {
            current = tuple;
        }
    }
}

void insert_CR(CR* tuple, CRtb table) {
    int index = hash(strToInt(tuple->Course));
    if(table[index] == NULL) {
        table[index] = tuple;
    } 
    else if(!(strcmp(table[index]->Course, tuple->Course)==0 && strcmp(table[index]->Room, tuple->Room)==0)) {
        CR* current = table[index];
        int match = 0;
        while(current != NULL) {
            if(strcmp(current->Course, tuple->Course)==0 && strcmp(current->Room, tuple->Room)==0) {
                match = 1;
                break;
            } else{
                current = current->next;
            }
        }
        if(match == 0) {
            current = tuple;
        }
    }
}

void delete_CSG(CSG* toDelete,  CSGtb table){
    int index = hash(strToInt(toDelete->StudentId));

    if (table[index] == NULL){
        return; //Not found
    }
    if (equal_CSG( toDelete , table[index])){
        CSG* toFree = table[index];
        table[index] = table[index]->next;
        free(toFree);
    } else {//Not in first bucket

        for (CSG* temp = table[index]; temp != NULL && temp->next != NULL; temp = temp->next){
            if (equal_CSG(toDelete, temp->next)){
                CSG* toFree = temp->next;
                temp->next = temp->next->next;//deleted node
                free(toFree);
            }
        }
    }
}

void delete_SNAP(SNAP* toDelete,  SNAPtb table){
    int index = hash(strToInt(toDelete->StudentId));

    if (table[index] == NULL){
        return; //Not found
    }
    if (equal_SNAP( toDelete, table[index])){
        SNAP* toFree = table[index];
        table[index] = table[index]->next;
        free(toFree);
    } else {//Not in first bucket
        for (SNAP* temp = table[index]; temp != NULL && temp->next != NULL; temp = temp->next){
            if (equal_SNAP(toDelete, temp->next)){
                SNAP* toFree = temp->next;
                temp->next = temp->next->next;//passes the deleted node
                free(toFree);//Free the deleted data
            }
        }
    }
}

void delete_CP(CP* toDelete,  CPtb table){
    int index = hash(strToInt(toDelete->Course));

    if (table[index] == NULL){
        return; //Not found
    }
    if (equal_CP( toDelete, table[index])){
        CP* toFree = table[index];
        table[index] = table[index]->next;
        free(toFree);
    } else {//Not in first bucket
        for (CP* temp = table[index]; temp != NULL && temp->next != NULL; temp = temp->next){
            if (equal_CP(toDelete, temp->next)){
                CP* toFree = temp->next;
                temp->next = temp->next->next;//passes the deleted node
                free(toFree);
            }
        }
    }
}

void delete_CDH(CDH* toDelete, CDHtb table){
    int index = hash(strToInt(toDelete->Course));

    if (table[index] == NULL){
        return; //Not found
    }
    //If it's the first in bucket before cycling through
    if (equal_CDH( toDelete,table[index])){
        CDH* toFree = table[index];
        table[index] = table[index]->next;
        free(toFree);
    } else {//Not in first bucket
        for (CDH* temp = table[index]; temp != NULL && temp->next != NULL; temp = temp->next){
            //If we've found the matching entry as temp's next
            if (equal_CDH(toDelete, temp->next)){
                CDH* toFree = temp->next;
                temp->next = temp->next->next;//passes the deleted node
                free(toFree);//Free the deleted data
            }
        }
    }
}

void delete_CR(CR* toDelete,  CRtb table){
    int index = hash(strToInt(toDelete->Course));

    if (table[index] == NULL){
        return; //Not found
    }
    if (equal_CR(toDelete ,table[index])){
        CR* toFree = table[index];
        table[index] = table[index]->next;
        free(toFree);
    } else {//Not in first bucket
        for (CR* temp = table[index]; temp != NULL && temp->next != NULL; temp = temp->next){
            //If we've found the matching entry as temp's next
            if (equal_CR(toDelete, temp->next)){
                CR* toFree = temp->next;
                temp->next = temp->next->next;//passes the deleted node
                free(toFree);//Free the deleted data
            }
        }
    }
}


CSG** lookup_CSG(CSG* tuple, CSGtb table)
{
    //  int index = hash(strToInt(tuple->StudentId));
    CSG** List = (CSG**)calloc(1009,sizeof(CSG*));
    int i = 0;//index pointers in double pointer
    for(int j = 0;j<1009;j++){
        if(table[j]!=NULL){
            for (CSG* temp = table[j]; temp != NULL; temp = temp->next){
                if (equal_CSG(tuple, temp)) {//If we've found the matching entry as temp's next
                    List[i] = temp;
                    i++;
                }
            }
        }
    }
    if (List[0] == NULL) return NULL;
    return List;
}

SNAP** lookup_SNAP(SNAP* tuple, SNAPtb table)
{
    //int index = hash(strToInt(tuple->StudentId));
    SNAP** List = (SNAP**)calloc(1009,sizeof(SNAP*));
    int i = 0;//index pointers in double pointer
    for(int j = 0;j<1009;j++){
        if(table[j]!=NULL){

            for (SNAP* temp = table[j]; temp != NULL; temp = temp->next){
                if (equal_SNAP(tuple, temp)){//If we've found the matching entry as temp's next
                    List[i] = temp;
                    i++;
                }
            }
        }
    }
    if (List[0] == NULL)
        return NULL;
    return List;
}

CP** lookup_CP(CP* tuple, CPtb table)
{
    CP** List = (CP**)calloc(1009,sizeof(CP*));
    int i = 0;//index pointers in double pointer
    for(int j = 0;j<1009;j++){
        if(table[j]!=NULL){
            for (CP* temp = table[j]; temp != NULL; temp = temp->next){
                if (equal_CP(tuple, temp)) {//If we've found the matching entry as temp's next
                    List[i] = temp;
                    i++;
                }
            }
        }
    }
    if (List[0] == NULL)
        return NULL;
    return List;
}

CDH** lookup_CDH(CDH* tuple, CDHtb table)
{
    //int index = hash(strToInt(tuple->Course));
    CDH** List = (CDH**)calloc(1009,sizeof(CDH*));
    int i = 0;//index pointers in double pointer
    for(int j = 0;j<1009;j++){
        if(table[j]!=NULL){
            for (CDH* temp = table[j]; temp != NULL; temp = temp->next){
                if (equal_CDH(tuple, temp)){//If we've found the matching entry as temp's next
                    List[i] = temp;
                    i++;
                }
            }
        }
    }
    if (List[0] == NULL)
        return NULL;
    return List;
}

CR** lookup_CR(CR* tuple, CRtb table)
{
    int i = 0;//index pointers in double pointer
    CR** List = (CR**)calloc(1009,sizeof(CR*));
    for(int i = 0; i<1009;i++){
        List[i] = NULL;
    }
    for(int j = 0;j<1009;j++){
        if(table[j]!=NULL){
            for (CR* temp = table[j]; temp != NULL; temp = temp->next){
                if (equal_CR(tuple, temp)){//If we've found the matching entry as temp's next
                    // printf("%s\n",temp->Course);
                    List[i] = temp;
                    i++;
                }
            }
        }
    }
    if (List[0] == NULL)
        return NULL;
    return List;
}

void print_CSG(CSGptr* csglist){
    int i = 0;
    while (csglist[i] != NULL) {
        char* Course = csglist[i]->Course;
        char* StudentID= csglist[i]->StudentId;
        char* Grade = csglist[i]->Grade;
        printf("%s\n", Course);
        printf("%s\n",StudentID);
        printf("%s\n", Grade);
        i++;
    }
}
void print_SNAP(SNAPptr* snaplist){
    int i = 0;
    while (snaplist[i] != NULL) {
        char* Name = snaplist[i]->Name;
        char* StudentID= snaplist[i]->StudentId;
        char* Phone = snaplist[i]->Phone;
        char* Address = snaplist[i]->Address;
        printf("%s\n",StudentID);
        printf("%s\n", Name);
        printf("%s\n", Address);
        printf("%s\n", Phone);
        i++;
    }
}

void print_CP(CPptr* cplist){
    if (cplist){
        int i = 0;
        while (cplist[i] != NULL) {
            char* Course = cplist[i]->Course;
            char* Prerequisite = cplist[i]->Prerequisite;
            printf("%s\n", Course);
            printf("%s\n",Prerequisite);
            printf("\n");
            i++;
        }
    }
    else {
        printf("Empty CP\n");
    }
}

void print_CDH(CDHptr* cdhlist){
    int i = 0;
    while (cdhlist[i] != NULL) {
        char* Course = cdhlist[i]->Course;
        char* Day= cdhlist[i]->Day;
        char* Hour = cdhlist[i]->Hour;
        printf("%s\n", Course);
        printf("%s\n",Day);
        printf("%s\n",Hour);
        i++;
    }
}
void print_CR(CRptr* crlist){
    if (crlist){
        int i = 0;
        while (crlist[i]) {
            char* Course = crlist[i]->Course;
            char* Room = crlist[i]->Room;
            printf("%s\n", Course);
            printf("%s\n", Room);
            printf("\n");
            i++;
        }
    }
    else {
        printf("Empty CR");
    }
}
void print_CRDH(CRDHptr* crdhlist){
    if (crdhlist){
        int i =0;
        while (crdhlist[i]){
            char* Course = crdhlist[i]->Course;
            char* Room = crdhlist[i]->Room;
            char* Day = crdhlist[i]->Day;
            char* Hour = crdhlist[i]->Hour;
            printf("%s\n", Course);
            printf("%s\n", Room);
            printf("%s\n", Day);
            printf("%s\n", Hour);
            printf("\n");
            i++;
        }
    }
    else {
        printf("Empty CRDH");
    }
}
void getGrade(char* name, char* course, CSGtb csgtable, SNAPtb snaptable){
    SNAPptr* snap = lookup_SNAP(SNAP_new("*", name, "*", "*"), snaptable);
    int i = 0;
    while(snap[i] != NULL && i <1009){
        char* id = snap[i]->StudentId;
        CSGptr* csg = lookup_CSG(CSG_new("*", id, "*"), csgtable);
        int j=0;
        while(csg[j] != NULL && j <1009) {
            if(strcmp(csg[j]->Course,course) == 0){
                printf("Grade: %s\n", csg[j]->Grade);
            }
            j++;
        }
        free(csg);
        i++;
    }
    free(snap);
}

void getRoom(char* name, char* hour, char* day, CSGtb csgtable, SNAPtb snaptable, CDHtb cdhtable, CRtb crtable){
    SNAPptr* snap = lookup_SNAP(SNAP_new("*", name, "*", "*"), snaptable);
    int i=0;
    while(snap[i] != NULL && i <1009){
        char* id = snap[i]->StudentId;
        CSGptr* csg = lookup_CSG(CSG_new("*", id, "*"), csgtable);
        int j=0;
        while(csg[j] != NULL && j <1009) {
            char* course = csg[j]->Course;
            CDHptr* cdh = lookup_CDH(CDH_new(course, day, hour), cdhtable);
            if(cdh == NULL){
                j++;
                continue;
            }
            int k=0;
            while(cdh[k] != NULL && k <1009) {
                CRptr* cr = lookup_CR(CR_new(course, "*"), crtable);
                int l=0;
                while(cdh[l] != NULL && l <1009){
                    if(cr==NULL){
                        l++;
                        continue;
                    }
                    printf("Room: %s\n", cr[l]->Room);
                    l++;
                }
                free(cr);
                k++;
            }
            free(cdh);
            j++;
        }
        free(id);
        free(csg);
        i++;
    }
    free(snap);
}


//Part3
CSG** select_CSG(CSGtb table, char* course){
    CSG** sCSG = (CSG**)calloc(1009, sizeof(CSG*));
    int CSGIndex = 0;
    for(int i = 0; i < 1009; i++){
        for (CSG* temp = table[i]; temp != NULL; temp = temp->next){
            if(strcmp(temp->Course,course)==0){
                sCSG[CSGIndex] = temp;
                CSGIndex++;
            }
        }
    }
    return sCSG;
}

CRDH** join_CR_CDH (CRtb table, CDHtb table1){
    int index = 0;
    CRDH** sCRDH = (CRDH**)calloc(1009,sizeof(CRDH*));
    for(int i = 0; i < 1009; i++){
        if(table[i] != NULL){
            for (int j = 0; j < 1009; j++){
                if (table1[j] != NULL){
                    if(strcmp(table[i]->Course, table1[j]->Course) == 0){
                        CRDH* add = CRDH_new(table[i]->Course,table[i]->Room,table1[j]->Day,table1[j]->Hour);
                        int found = 0;
                        for (int m = 0; m < 1009 && found == 0; m++ ){
                            if (sCRDH[m] != NULL && equal_CRDH(sCRDH[m],add)){
                                found = 1;
                            }
                        }
                        if (!found){
                            sCRDH[index] = add;
                            index ++;
                        }else free(add);
                    }
                }
            }
        }
    }
    if (sCRDH == NULL) {
        return NULL;
    }else return sCRDH;
}

void projection_CSG(CSG** csg) {
    int i = 0;
    while(csg[i] != NULL) {
        printf("%s\n", csg[i]->StudentId);
        i++;
    }
}

//void importDB(char* fileName) {
//    FILE *fp;
//    char buf[100];
//    fp = fopen(filename, "r");
//    if (fp == NULL) {
//        perror("Error: Cannot Open File");
//        return;
//    }
//    while(fgets(buf, 100, fp) != NULL) {
//        int length = strlen(buf);
//        char input[length];
//        strcpy(input, buf);
//        char* token = strtok(input, " ");
//        if (strcmp(token, "CSG") == 0) {
//            for(int i=5; i<length; i++) {
//                input[i-5] = input[i];
//            }
//            for(int i=length-1; i>length-5; i--) {
//                input[i] = " ";
//            }
//            length -= 5;
//            char *course = strtok(input, " ");
//            int len1 = strlen(course)+1;
//            for(int i=len1; i<length; i++) {
//                input[i-len1] = input[i];
//            }
//            for(int i=length-1; i>length-len1; i--) {
//                input[i] = " ";
//            }
//            length -= len1;
//            char *StudentId = strtok(input, " ");
//            int len2 = strlen(StudentId)+1;
//            for(int i=len2; i<length; i++) {
//                input[i-len2] = input[i];
//            }
//            for(int i=length-1; i>length-len2; i--) {
//                input[i] = " ";
//            }
//            length -= len2;
//            char *Grade = strtok(input, " ");
//            int len3 = strlen(Grade)+1;
//            for(int i=len3; i<length; i++) {
//                input[i-len3] = input[i];
//            }
//            for(int i=length-1; i>length-len3; i--) {
//                input[i] = " ";
//            }
//            length -= len3;
//            insert_CSG(CSG_new(Course, StudentId, Grade), csgtable);
//        } else if (strcmp(token, "SNAP") == 0) {
//            for(int i=6; i<length; i++) {
//                input[i-6] = input[i];
//            }
//            for(int i=length-1; i>length-6; i--) {
//                input[i] = " ";
//            }
//            length -= 6;
//            char* StudentId = strtok(input, " ");
//            int len2 = strlen(StudentId)+1;
//            for(int i=len2; i<length; i++) {
//                input[i-len2] = input[i];
//            }
//            for(int i=length-1; i>length-len2; i--) {
//                input[i] = " ";
//            }
//            length -= len2;
//            char* Name = strtok(input, " ");
//            int len1 = strlen(Name)+1;
//            for(int i=len1; i<length; i++) {
//                input[i-len1] = input[i];
//            }
//            for(int i=length-1; i>length-len1; i--) {
//                input[i] = " ";
//            }
//            length -= len1;
//            char* Address = strtok(input, " ");
//            int len3 = strlen(Address)+1;
//            for(int i=len3; i<length; i++) {
//                input[i-len3] = input[i];
//            }
//            for(int i=length-1; i>length-len3; i--) {
//                input[i] = " ";
//            }
//            length -= len3;
//            char* Phone = strtok(input, " ");
//            int len4 = strlen(Phone)+1;
//            for(int i=len4; i<length; i++) {
//                input[i-len4] = input[i];
//            }
//            for(int i=length-1; i>length-len4; i--) {
//                input[i] = " ";
//            }
//            length -= len4;
//            insert_SNAP(SNAP_new(StudentId, Name, Address, Phone), snaptable);
//        } else if (strcmp(token, "CP") == 0) {
//            for(int i=4; i<length; i++) {
//                input[i-4] = input[i];
//            }
//            for(int i=length-1; i>length-4; i--) {
//                input[i] = " ";
//            }
//            length -= 4;
//            char* Course = strtok(input, " ");
//            int len1 = strlen(Course)+1;
//            for(int i=len1; i<length; i++) {
//                input[i-len1] = input[i];
//            }
//            for(int i=length-1; i>length-len1; i--) {
//                input[i] = " ";
//            }
//            length -= len1;
//            char* Prerequisite = strtok(input, " ");
//            int len2 = strlen(Prerequisite)+1;
//            for(int i=len2; i<length; i++) {
//                input[i-len2] = input[i];
//            }
//            for(int i=length-1; i>length-len2; i--) {
//                input[i] = " ";
//            }
//            length -= len2;
//            insert_CP(CP_new(Course, Prerequisite), cptable);
//        } else if (strcmp(token, "CDH") == 0) {
//            for(int i=5; i<length; i++) {
//                input[i-5] = input[i];
//            }
//            for(int i=length-1; i>length-5; i--) {
//                input[i] = " ";
//            }
//            length -= 5;
//            char* Course = strtok(input, " ");
//            int len1 = strlen(Course)+1;
//            for(int i=len1; i<length; i++) {
//                input[i-len1] = input[i];
//            }
//            for(int i=length-1; i>length-len1; i--) {
//                input[i] = " ";
//            }
//            length -= len1;
//            char* Day = strtok(input, " ");
//            char* Hour = strtok(input, " ");
//            insert_CDH(CDH_new(Course, Day, Hour), cdhtable);
//        } else if (strcmp(token, "CR") == 0) {
//            for(int i=4; i<length; i++) {
//                input[i-4] = input[i];
//            }
//            for(int i=length-1; i>length-4; i--) {
//                input[i] = " ";
//            }
//            length -= 4;
//            char* Course = strtok(input, " ");
//            int len1 = strlen(Course)+1;
//            for(int i=len1; i<length; i++) {
//                input[i-len1] = input[i];
//            }
//            for(int i=length-1; i>length-len1; i--) {
//                input[i] = " ";
//            }
//            length -= len1;
//            char* Room = strtok(input, " ");
//            int len2 = strlen(Room)+1;
//            for(int i=len2; i<length; i++) {
//                input[i-len2] = input[i];
//            }
//            for(int i=length-1; i>length-len2; i--) {
//                input[i] = " ";
//            }
//            length -= len2;
//            insert_CR(CR_new(Course, Room), crtable);
//        } else {
//            perror("Error");
//        }
//    }
//    if(fclose(fp) != 0) {
//        perror("Error: Cannot Close File");
//    }
//    
//}

//void exportDB(char *fileName) {
//    FILE *fp;
//    fp = fopen(filename, "w");
//    if (fp == NULL) {
//        perror("Error: Cannot Open File");
//    } else {
//        int i;
//        //CSG
//        for (i=0; i<1009; i++) {
//            CSG *current = CSGtb[i];
//            while (current != NULL) {
//                fprintf(fp, "CSG \n%s %d %s\n", current->Course, current->StudentId, current->Grade);
//                current = current->next;
//            }
//        }
//        //SNAP
//        for (i=0; i<1009; i++) {
//            SNAP *current = SNAPtb[i];
//            while(current != NULL) {
//                fprintf(fp, "SNAP \n%d %s %s %d\n", current->StudentId, current->Name, current->Address, current->Phone);
//                current = current->next;
//            }
//        }
//        //CP
//        for (i=0; i<1009; i++) {
//            CP *current = CPtb[i];
//            while(current != NULL) {
//                fprintf(fp, "CP \n%s %s\n", current->Course, current->Prerequisite);
//                current = current->next;
//            }
//        }
//        //CDH
//        for (i=0; i<1009; i++) {
//            CDH *current = CDHtb[i];
//            while(current != NULL) {
//                fprintf(fp, "CDH \n%s %s %s\n", current->Course, current->Day, current->Hour);
//                current = current->next;
//            }
//        }
//        //CR
//        for (i=0; i<1009; i++) {
//            CR *current = CRtb[i];
//            while(current != NULL) {
//                fprintf(fp, "CR \n%s %s\n", current->Course, current->Room);
//                current = current->next;
//            }
//        }
//        if(fclose(fp) != 0) {
//            perror("Error: Cannot Close File");
//        }
//    }
//}

int main() {
    CSGtb csgtable ;
    for(int i=0; i<1009; i++){
        csgtable[i]=NULL;
    }
    
    SNAPtb snaptable;
    for(int i=0; i<1009; i++){
        snaptable[i]=NULL;
    }
    
    CPtb cptable;
    for(int i=0; i<1009; i++){
        cptable[i]=NULL;
    }
    
    CDHtb cdhtable;
    for(int i=0; i<1009; i++){
        cdhtable[i]=NULL;
    }
    
    CRtb crtable;
    for(int i=0; i<1009; i++){
        crtable[i]=NULL;
    }
    
    insert_CSG( CSG_new("CS101", "12345", "A") , csgtable);
    insert_CSG( CSG_new("CS101", "67890", "B") , csgtable);
    insert_CSG( CSG_new("EE200", "12345", "C") , csgtable);
    insert_CSG( CSG_new("EE200", "22222", "B+") , csgtable);
    insert_CSG( CSG_new("CS101", "33333", "A-") , csgtable);
    insert_CSG( CSG_new("PH100", "67890", "C+") , csgtable);

    insert_SNAP( SNAP_new("12345", "C.Brown", "12 Apple St.","555-1234"),  snaptable);
    insert_SNAP( SNAP_new("67890", "L.Van Pelt", "34 Pear Ave.","555-5678"),  snaptable);
    insert_SNAP( SNAP_new("22222", "P.Patty", "56 Grape Blvd.","555-9999"),  snaptable);

    insert_CP( CP_new("CS101", "CS100"), cptable);
    insert_CP( CP_new("EE200", "EE005"), cptable);
    insert_CP( CP_new("EE200", "CS100"), cptable);
    insert_CP( CP_new("CS120", "CS101"), cptable);
    insert_CP( CP_new("CS121", "CS120"), cptable);
    insert_CP( CP_new("CS205", "CS101"), cptable);
    insert_CP( CP_new("CS206", "CS121"), cptable);
    insert_CP( CP_new("CS206", "CS205"), cptable);

    insert_CDH( CDH_new("CS101", "M", "9AM"),  cdhtable);
    insert_CDH( CDH_new("CS101", "W", "9AM"),  cdhtable);
    insert_CDH( CDH_new("CS101", "F", "9AM"),  cdhtable);
    insert_CDH( CDH_new("EE200", "Tu", "10AM"),  cdhtable);
    insert_CDH( CDH_new("EE200", "W", "1PM"),  cdhtable);
    insert_CDH( CDH_new("EE200", "Th", "10AM"),  cdhtable);

    insert_CR( CR_new("CS101", "Turing Aud."), crtable);
    insert_CR( CR_new("EE200", "25 Ohm Hall"), crtable);
    insert_CR( CR_new("PH100", "Newton Lab."), crtable);

    //Import and Export
//    exportDB("database.txt");
//    importDB("database.txt");
    
    //eg 8.2
    CSGptr* csglist = lookup_CSG(CSG_new("CS101", "12345", "*"), csgtable);
    CPptr* cplist = lookup_CP(CP_new("CSC205", "CS120"), cptable);
    delete_CR(CR_new("CS101", "*"), crtable);
    CRptr* crlist = lookup_CR(CR_new("*", "*"), crtable);
    insert_CP(CP_new("CS205", "CS120"), cptable);
    insert_CP(CP_new("CS205", "CS101"), cptable);
    CPptr* cplist1 = lookup_CP(CP_new("CS205", "*"), cptable);
    insert_CR( CR_new("CS101", "Turing Aud."), crtable);


    printf("********************Part I********************\n");
    printf("1) Find the grade of the student with ID 12345 in CS101: \n");
    print_CSG(csglist);
    printf("\n");
    printf("2) Whether CS120 is a prerequisite of CS205: \n");
    print_CP(cplist);
    printf("\n");
    printf("3) Drop the first tuple(CS101,*) from 8.2(d), show the remaining tuples: \n");
    print_CR(crlist);
    printf("\n");
    printf("4) Make CS120 a prerequisite of CS205 and insert tuple (CS205,CS101) in CP, and then show the tuples starts with CS205: \n");
    print_CP(cplist1);
    
    printf("********************Part II******************** \n");
    printf("What grade did P.Patty get in EE200?\n");
//    getGrade("P.Patty", "EE200", csgtable, snaptable);
    printf("\n");
    printf("Where is L.Van Pelt at 9AM on W?\n");
//    getRoom("L.Van Pelt", "9AM", "W", csgtable, snaptable, cdhtable, crtable);
    printf("\n");

    //example 8.12
    CSGptr* csglist2 = select_CSG(csgtable, "CS101");
    
    //example 8.14
    CRDHptr* crdhlist = join_CR_CDH(crtable, cdhtable);

    printf("********************Part III******************** \n");
    printf("Example 8.12: Select 'CS101' from CSG: \n");
    print_CSG(csglist2);
    printf("Examplep 8.13: Project only StudentId for those taking CSC101 \n");
    projection_CSG(csglist2);
    printf("Example 8.14: Join CR and CDH on Course = Course \n");
    print_CRDH(crdhlist);
}
