#include "Database.h"

Database Database_new() {
    Database db = (Database)malloc(sizeof(Database));
    db->CSGtb = (CSG*)calloc(SIZE, sizeof(CSG));
    db->SNAPtb = (SNAP*)calloc(SIZE, sizeof(SNAP));
    db->CPtb = (CP*)calloc(SIZE, sizeof(CP));
    db->CRtb = (CR*)calloc(SIZE, sizeof(CR));
    db->CDHtb = (CDH*)calloc(SIZE, sizeof(CDH));
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
    return out;
}

void insertCSG(CSG csg, Database d){
	int index = hash(charToInt(csg->course));

	if (d->CSGtb[index] == NULL){
		d->CSGtb[index] = csg;
	}else{
		csg->next = d->CSGtb[index];
        d->CSGtb[index] = csg;
	}
}
void insertSNAP(SNAP snap, Database d);
void insertCP(CP cp, Database d);
void insertCR (CR cr, Database d);
void insertCDH (CDH cdh, Database d); 

//void deleteCSG (CSG csg, Database d){
//    int index = hash(charToInt(csg->course));
//    if (d->CSGtb[index] == NULL){
//        return;
//    }else{
//
//        if(CDH_equal(d->CSGtb[index],csg) == 1){
//            d->CSGtb[index] = d->CSGtb[index]->next;
//        }
//        else{
//            CSG csgPtr = d->CSGtb[index]->next;
//            while (CDH_equal(csgPtr, csg) == 0 && csgPtr->next != NULL){
//                csgPtr = csgPtr->next;
//            }
//        }
//        }
//
//
//    }

//CSG* lookupCSG(CSG csg, Database d) {
//    int index = hash(charToInt(csg->course));
//    CSG* resultList = (CSG*)calloc(5, sizeof(CSG));
//    int i = 0;
//
//    if(d->CSGtb[index] == NULL){
//        return NULL;
//    }
//    else {
//        for(CSG it = d->CSGtb[index]; it !=NULL; it=it->next){
//            if (CSG_equal(csg,it) ==1){
//                resultList[i] = it;
//                i++;
//            }
//        }
//    }
//    return resultList;
//}

void print_CSG_DB(Database d) {
	for(int i=0; i<SIZE; i++) {
        CSG temp = d->CSGtb[i];
        while(temp != NULL) {
            printf("%s %d %s", temp->course, temp->studentId, temp->grade);
            temp = temp->next;
        }
	}
}
