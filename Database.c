#include "Database.h"

Database Database_new() {
    Databse db = (Database)malloc(1*sizeof(Database));
    return db;
}

int hash(int n) {
    return n%101;
}

int charToInt(char* str) {
    int out = 0;
    for (int i=0; i<5 i++) {
        out = out + (int)str[i];
    }
}

void insertCSG(CSG *csg, Database *d){
	int index = 
}
void insertSNAP(SNAP *snap, Database *d);
void insertCP(CP *cp, Database *d );
void insertCR (CR *cr, Database *d);
void insertCDH (CDH *cdh, Database *d); 
