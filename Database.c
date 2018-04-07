#include "Database.h"

Database Database_new() {
    Database db = (Database)malloc(1*sizeof(Database));
    return db;
}

int hash(int n) {
    return n%101;
}

int charToInt(char* str) {
    int out = 0;
    for (int i=0; i<5; i++) {
        out = out + (int)str[i];
    }
}

void insertCSG(CSG *csg, Database *d){
	int index = hash(charToInt(csg->course));

	if (d->CSGtb[index] == NULL){
		d->CSGtb[index] = csg;
	}else{
		csg->next = d->CSGtb[index];
        d->CSGtb[index] = csg;
	}
}
void insertSNAP(SNAP *snap, Database *d);
void insertCP(CP *cp, Database *d );
void insertCR (CR *cr, Database *d);
void insertCDH (CDH *cdh, Database *d); 

void deleteCSG (CSG csg, Database d){
    int index = hash(charToInt(csg->course));
    if (d->CSGtb[index] == NULL){
        return;
    }else{

        if(CDH_equal(d->CSGtb[index],csg) == 1){
            d->CSGtb[index] = d->CSGtb[index]->next;
        }
        else{
            CSG csgPtr = d->CSGtb[index]->next;
            while (CDH_equal(csgPtr, csg) == 0 && csgPtr->next != NULL){
                csgPtr = csgPtr->next;
            }
        }
        }


    }

CSG* lookupCSG (CSG csg, Database d) {
    int index = hash(charToInt(csg->course));
    CSG* resultList = (CSG*)malloc(sizeof(CSG*));
    int i = 0;

    if(d->CSGtb[index] == NULL){
        return NULL;
    }
    else {
        for(CSG iter = d->CSGtb[index]; iter !=NULL; iter=iter->next){
            if (CSG_equal(csg,iter) ==1){
                resultList[i] = iter;
                i++;
            }
        }
    }
    return resultList;
}