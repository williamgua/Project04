#include "Database.h"

Database Database_new() {
    Database db = (Database)malloc(sizeof Database);
}

int hash(int in){
    return in % 1009;
}

int strToInt(char* str){
    int n = 0;
    for(int i = 0; i < 6; i++){
        n += (int)str[i];
    }
    return n;
}

void insert_CSG(CSG* toInsert,Database CSGTable){
    //Hashes on inserted CSG's StudentId
    int index = hash(strToInt(toInsert->StudentId));
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

void insert_SNAP(SNAP* toInsert,Database db){
    //Hashes on inserted SNAP's StudentId
    int index = hash(strToInt(toInsert->StudentId));
    
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

void insert_CP(CP* toInsert,Database db){
    //Hashes on inserted CP's StudentId
    int index = hash(strToInt(toInsert->Course));
    
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
    int index = hash(strToInt(toInsert->Course));
    
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
    int index = hash(strToInt(toInsert->Course));
    
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

void delete_CSG(CSG* toDelete,  Database tb){
    int index = hash(strToInt(toDelete->StudentId));
    
    if (db->CSGtb[index] == NULL){
        return; //Not found
    }
    //If it's the first in bucket before cycling through
    if (equal_CSG( toDelete , db->CSGtb[index])){
        CSG* toFree = db->CSGtb[index];
        db->CSGtb[index] = db->CSGtb[index]->next;
        free(toFree);
    } else {//Not in first bucket
        
        for (CSG* temp = db->CSGtb[index]; temp != NULL && temp->next != NULL; temp = temp->next){
            //If we've found the matching entry as temp's next
            if (equal_CSG(toDelete, temp->next)){
                CSG* toFree = temp->next;
                temp->next = temp->next->next;//passes the deleted node
                free(toFree);//Free the deleted data
            }
        }
    }
}

void delete_SNAP(SNAP* toDelete,  Database db){
    int index = hash(strToInt(toDelete->StudentId));
    
    if (db->SNAPtb[index] == NULL){
        return; //Not found
    }
    //If it's the first in bucket before cycling through
    if (equal_SNAP( toDelete, db->SNAPtb[index])){
        SNAP* toFree = db->SNAPtb[index];
        db->SNAPtb[index] = db->SNAPtb[index]->next;
        free(toFree);
    } else {//Not in first bucket
        for (SNAP* temp = db->SNAPtb[index]; temp != NULL && temp->next != NULL; temp = temp->next){
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
    int index = hash(strToInt(toDelete->Course));
    
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
    int index = hash(strToInt(toDelete->Course));
    
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
    int index = hash(strToInt(toDelete->Course));
    
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


CSG** lookup_CSG(CSG* toLookup, Database db)
{
    //  int index = hash(strToInt(toLookup->StudentId));
    CSG** List = (CSG**)calloc(1009,sizeof(CSG*));
    int i = 0;//index pointers in double pointer
    for(int j = 0;j<1009;j++){
        if(db->CSGtb[j]!=NULL){
            for (CSG* temp = db->CSGtb[j]; temp != NULL; temp = temp->next){
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

SNAP** lookup_SNAP(SNAP* toLookup, Database db)
{
    //int index = hash(strToInt(toLookup->StudentId));
    SNAP** List = (SNAP**)calloc(1009,sizeof(SNAP*));
    int i = 0;//index pointers in double pointer
    for(int j = 0;j<1009;j++){
        if(db->SNAPtb[j]!=NULL){
            
            for (SNAP* temp = db->SNAPtb[j]; temp != NULL; temp = temp->next){
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
    //int index = hash(strToInt(toLookup->Course));
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
