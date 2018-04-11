#include "Database.h"

Database* Database_new() {
    Database* db = (Database*)malloc(sizeof(Database));
    // memset(db->CSGtb, 0, sizeof(db->CSGtb));
    // memset(db->CDHtb, 0, sizeof(db->CDHtb));
    // memset(db->CPtb, 0, sizeof(db->CPtb));
    // memset(db->CRtb, 0, sizeof(db->CRtb));
    // memset(db->SNAPtb, 0, sizeof(db->SNAPtb));
    return db;
}

int hash(int input){
    return input % 1009;
}

int strToInt(char* input) {
    int ind = 0;
    for(int i = 0; i < 6; i++) {
        ind += (int) input[i];
    }
    return ind;
}

// void insert_CSG(Database* D, CSG* tuple) {
//     int index = hash(strToInt(tuple->StudentId));
//     if(D->CSGtb[index] == NULL) {
//         D->CSGtb[index] = tuple;
//         printf("123\n");
//     } 
//     else if(!(strcmp(D->CSGtb[index]->Course, tuple->Course)==0 && strcmp(D->CSGtb[index]->StudentId, tuple->StudentId)==0 && strcmp(D->CSGtb[index]->Grade, tuple->Grade)==0)) {
//         printf("234/n");
//         CSG* currentHead = D->CSGtb[index];
//         int match = 0;
//         while(currentHead->next != NULL) {
//             printf("345");
//             if(strcmp(D->CSGtb[index]->Course, tuple->Course)==0 && strcmp(D->CSGtb[index]->StudentId, tuple->StudentId)==0 && strcmp(D->CSGtb[index]->Grade, tuple->Grade)==0) {
//                 match = 1;
//                 break;
//             } else {
//                 currentHead = currentHead->next;
//                 printf("456");
//             }
//         }
//         if(match == 0) {
//             currentHead->next = tuple;
//         }
//     }
// }

void insert_CSG(Database* D, CSG* toInsert){
    int index = hash(strToInt(toInsert->StudentId));
    if (D->CSGtb[index] == NULL){
        //Fresh, empty Bucket
        D->CSGtb[index] = toInsert;
        printf("123\n");
    } else if (strcmp(D->CSGtb[index]->Course, toInsert->Course)==0&&strcmp(D->CSGtb[index]->StudentId, toInsert->StudentId)==0&&strcmp(D->CSGtb[index]->Grade, toInsert->Grade)==0){
    } else{
        printf("234\n");
        CSG* currentHead = D->CSGtb[index];
        int eq = 0;
        // printf("%s\n", currentHead->next->Course);
        while(currentHead!=NULL){ //currentHead should be NULL but it is not NULL??? CSG_new next NULL but doesn't work
           printf("345\n");
            if (strcmp(D->CSGtb[index]->Course, toInsert->Course)==0&&strcmp(D->CSGtb[index]->StudentId, toInsert->StudentId)==0&&strcmp(D->CSGtb[index]->Grade, toInsert->Grade)==0){
                eq = 1;
                break;
            }else{
                currentHead = currentHead->next;
                printf("456\n");
            }
        }
        if(eq==0){
            currentHead = toInsert;
            printf("567\n");
        }
    }
}


void insert_SNAP(Database* D, SNAP* tuple) {
    int index = hash(strToInt(tuple->StudentId));
    if(D->SNAPtb[index] == NULL) {
        D->SNAPtb[index] = tuple;
    } 
    else if(!(strcmp(D->SNAPtb[index]->StudentId, tuple->StudentId)==0 && strcmp(D->SNAPtb[index]->Name, tuple->Name)==0 && strcmp(D->SNAPtb[index]->Address, tuple->Address)==0 && strcmp(D->SNAPtb[index]->Phone, tuple->Phone)==0)) {
        SNAP* currentHead = D->SNAPtb[index];
        int match = 0;
        while(currentHead->next != NULL) {
            if(strcmp(currentHead->StudentId, tuple->StudentId)==0 && strcmp(currentHead->Name, tuple->Name)==0 && strcmp(currentHead->Address, tuple->Address)==0 && strcmp(currentHead->Phone, tuple->Phone)==0) {
                match = 1;
                break;
            } else {
                currentHead = currentHead->next;
            }
        }
        if(match == 0) {
            currentHead->next = tuple;
        }
    }
}

void insert_CP(Database* D, CP* tuple){
    int index = hash(strToInt(tuple->Course));
    if(D->CPtb[index] == NULL) {
        D->CPtb[index] = tuple;
    } 
    else if(!(strcmp(D->CPtb[index]->Course, tuple->Course)==0 && strcmp(D->CPtb[index]->Prerequisite, tuple->Prerequisite)==0)) {
        CP* currentHead = D->CPtb[index];
        int match = 0;
        while(currentHead->next != NULL) {
            if(strcmp(currentHead->Course, tuple->Course)==0 && strcmp(currentHead->Prerequisite, tuple->Prerequisite)==0) {
                match = 1;
                break;
            } else{
                currentHead = currentHead->next;
            }
        }
        if(match == 0) {
            currentHead->next = tuple;
        }
    }
}

void insert_CDH(Database* D, CDH* tuple){
    int index = hash(strToInt(tuple->Course));
    if(D->CDHtb[index] == NULL) {
        D->CDHtb[index] = tuple;
    } 
    else if(!(strcmp(D->CDHtb[index]->Course, tuple->Course)==0 && strcmp(D->CDHtb[index]->Day, tuple->Day)==0 && strcmp(D->CDHtb[index]->Hour, tuple->Hour)==0)) {
        CDH* currentHead = D->CDHtb[index];
        int match = 0;
        while(currentHead->next != NULL) {
            if(strcmp(currentHead->Course, tuple->Course)==0 && strcmp(currentHead->Day, tuple->Day)==0 && strcmp(currentHead->Hour, tuple->Hour)==0) {
                match = 1;
                break;
            } else {
                currentHead = currentHead->next;
            }
        }
        if(match == 0) {
            currentHead->next = tuple;
        }
    }
}

void insert_CR(Database* D, CR* tuple){
   int index = hash(strToInt(tuple->Course));
    if(D->CRtb[index] == NULL) {
        D->CRtb[index] = tuple;
    } 
    else if(!(strcmp(D->CRtb[index]->Course, tuple->Course)==0 && strcmp(D->CRtb[index]->Room, tuple->Room)==0)) {
        CR* currentHead = D->CRtb[index];
        int match = 0;
        while(currentHead->next != NULL) {
            if(strcmp(currentHead->Course, tuple->Course)==0 && strcmp(currentHead->Room, tuple->Room)==0) {
                match = 1;
                break;
            } else{
                currentHead = currentHead->next;
            }
        }
        if(match == 0) {
            currentHead->next = tuple;
        }
    }
}

void delete_CSG(Database* D, CSG* tuple){
    if(strcmp(tuple->Course, "*")!=0 && strcmp(tuple->StudentId, "*")!=0 && strcmp(tuple->Grade, "*")!=0) {
        int index = hash(strToInt(tuple->StudentId));
        if(D->CSGtb[index] == NULL) {
            return;
        }
        if(equal_CSG(tuple, D->CSGtb[index])) {
            CSG* toFree = D->CSGtb[index];
            D->CSGtb[index] = D->CSGtb[index]->next;
            free(toFree);
        }
        else {
            CSG* temp = D->CSGtb[index];
            while(temp != NULL) {
                if(equal_CSG(tuple, temp)) {
                    CSG* toFree = temp->next;
                    temp->next = temp->next->next;
                    free(toFree);
                    break;
                }
                temp = temp->next;
            }
        }
    }
    
}

void delete_SNAP(Database* D, SNAP* tuple){
    int index = hash(strToInt(tuple->StudentId));

    if (D->SNAPtb[index] == NULL){
        return; //Not found
    }
    //If it's the first in bucket before cycling through
    if (equal_SNAP( tuple, D->SNAPtb[index])){
        SNAP* toFree = D->SNAPtb[index];
        D->SNAPtb[index] = D->SNAPtb[index]->next;
        free(toFree);
    } else {//Not in first bucket
        for (SNAP* temp = D->SNAPtb[index]; temp != NULL && temp->next != NULL; temp = temp->next){
            //If we've found the matching entry as temp's next
            if (equal_SNAP(tuple, temp->next)){
                SNAP* toFree = temp->next;
                temp->next = temp->next->next;//passes the deleted node
                free(toFree);//Free the deleted data
            }
        }
    }
}

void delete_CP(Database* D, CP* tuple){
    int index = hash(strToInt(tuple->Course));

    if (D->CPtb[index] == NULL){
        return; //Not found
    }
    //If it's the first in bucket before cycling through
    if (equal_CP( tuple,D->CPtb[index])){
        CP* toFree = D->CPtb[index];
        D->CPtb[index] = D->CPtb[index]->next;
        free(toFree);
    } else {//Not in first bucket
        for (CP* temp = D->CPtb[index]; temp != NULL && temp->next != NULL; temp = temp->next){
            //If we've found the matching entry as temp's next
            if (equal_CP(tuple, temp->next)){
                CP* toFree = temp->next;
                temp->next = temp->next->next;//passes the deleted node
                free(toFree);//Free the deleted data
            }
        }
    }

}

void delete_CDH(Database* D, CDH* tuple){
    int index = hash(strToInt(tuple->Course));

    if (D->CDHtb[index] == NULL){
        return; //Not found
    }
    //If it's the first in bucket before cycling through
    if (equal_CDH( tuple,D->CDHtb[index])){
        CDH* toFree = D->CDHtb[index];
         D->CDHtb[index] = D->CDHtb[index]->next;
        free(toFree);
    } else {//Not in first bucket
        for (CDH* temp = D->CDHtb[index]; temp != NULL && temp->next != NULL; temp = temp->next){
            //If we've found the matching entry as temp's next
            if (equal_CDH(tuple, temp->next)){
                CDH* toFree = temp->next;
                temp->next = temp->next->next;//passes the deleted node
                free(toFree);//Free the deleted data
            }
        }
    }
};
void delete_CR(Database* D, CR* tuple){
    int index = hash(strToInt(tuple->Course));

    if (D->CRtb[index] == NULL){
        return; //Not found
    }
    if (equal_CR(tuple ,D->CRtb[index])){
        CR* toFree = D->CRtb[index];
        D->CRtb[index] = D->CRtb[index]->next;
        free(toFree);
    } else {//Not in first bucket
        for (CR* temp = D->CRtb[index]; temp != NULL && temp->next != NULL; temp = temp->next){
            //If we've found the matching entry as temp's next
            if (equal_CR(tuple, temp->next)){
                CR* toFree = temp->next;
                temp->next = temp->next->next;//passes the deleted node
                free(toFree);//Free the deleted data
            }
        }
    }
}

/* Lookup functions */
CSG** lookup_CSG(Database* D, CSG* toLookup){
    //  int index = hash(stringToInt(toLookup->StudentId));
    CSG** List = (CSG**)calloc(1009,sizeof(CSG*));
    int i = 0;//index pointers in double pointer
    for(int j = 0;j<1009;j++){
        if(D->CSGtb[j]!=NULL){
            for (CSG* temp =D->CSGtb[j]; temp != NULL; temp = temp->next){
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

SNAP** lookup_SNAP(Database* D, SNAP* toLookup){
    //int index = hash(stringToInt(toLookup->StudentId));
    SNAP** List = (SNAP**)calloc(1009,sizeof(SNAP*));
    int i = 0;//index pointers in double pointer
    for(int j = 0;j<1009;j++){
        if(D->SNAPtb[j]!=NULL){

            for (SNAP* temp = D->SNAPtb[j]; temp != NULL; temp = temp->next){
                if (equal_SNAP(toLookup, temp)){//found matching entry as temp's next
                    List[i] = temp;
                    i++;
                }
            }
        }
    }
    if (List[0] == NULL) return NULL;
    return List;
}

CP** lookup_CP(Database* D, CP* toLookup){
    CP** List = (CP**)calloc(1009,sizeof(CP*));
    int i = 0;//index pointers in double pointer
    for(int j = 0;j<1009;j++){
        if(D->CPtb[j]!=NULL){
            for (CP* temp = D->CPtb[j]; temp != NULL; temp = temp->next){
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

CDH** lookup_CDH(Database* D, CDH* toLookup){
    //int index = hash(stringToInt(toLookup->Course));
    CDH** List = (CDH**)calloc(1009,sizeof(CDH*));
    int i = 0;//index pointers in double pointer
    for(int j = 0;j<1009;j++){
        if(D->CDHtb[j]!=NULL){
            for (CDH* temp =D->CDHtb[j]; temp != NULL; temp = temp->next){
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

CR** lookup_CR(Database* D, CR* toLookup){
    int i = 0;//index pointers in double pointer
    CR** List = (CR**)calloc(1009,sizeof(CR*));
    for(i = 0; i<1009;i++){
        List[i] = NULL;
    }
    for(int j = 0;j<1009;j++){
        if(D->CRtb[j]!=NULL){
            for (CR* temp = D->CRtb[j]; temp != NULL; temp = temp->next){
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
        char* Course = csglist[i]->Course;
        char* StudentID= csglist[i]->StudentId;
        char* Grade = csglist[i]->Grade;
        printf("%s\n", Course);
        printf("%s\n",StudentID);
        printf("%s\n", Grade);
        i++;
    }
}
void print_SNAP(SNAPLIST* snaplist){
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

void print_CP(CPLIST* cplist){
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
        printf("FALSE: CPEMPTY\n");
    }
}

void print_CDH(CDHLIST* cdhlist){
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
void print_CR(CRLIST* crlist){
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
        printf("CREMPTY");
    }
}

int main() {
    Database* new = Database_new();
    for(int i=0; i<1009; i++) {
        new->CSGtb[i] = NULL;
    }
    insert_CSG(new,CSG_new("CS101", "12345", "A"));
    // insert_CSG(new,CSG_new("CS101", "67890", "B"));
    insert_CSG(new,CSG_new("EE200", "12345", "C"));
    // insert_CSG(new,CSG_new("EE200", "22222", "B+"));
    // insert_CSG(new,CSG_new("CS101", "33333", "A-"));
    // insert_CSG(new,CSG_new("PH100", "67890", "C+"));

    // print_CSG(lookup_CSG(new, CSG_new("CSC101", "*", "*")));
    // return 1;
}
