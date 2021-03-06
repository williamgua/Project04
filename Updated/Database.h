#include "Tuples.h"
#include <stdlib.h>

typedef struct Database{
    CSG* CSGtb[1009];
    SNAP* SNAPtb[1009];
    CP* CPtb[1009];
    CDH* CDHtb[1009];
    CR* CRtb[1009];
} Database;

/* New database function */
Database* Database_new();

/* Hashing functions */
int hash(int input);
int strToInt (char* input);

/* Insert functions */
void insert_SNAP(Database* D, SNAP* tuple);
void insert_CSG(Database* D, CSG* tuple);
void insert_CP(Database* D, CP* tuple);
void insert_CDH(Database* D, CDH* tuple);
void insert_CR(Database* D, CR* tuple);

/* Delete functions */
void delete_SNAP(Database* D, SNAP* toDelete);
void delete_CSG(Database* D, CSG* toDelete);
void delete_CP(Database* D, CP* toDelete);
void delete_CDH(Database* D, CDH* toDelete);
void delete_CR(Database* D, CR* toDelete);

/* Lookup functions */
SNAP** lookup_SNAP(Database* D, SNAP* toLookup);
CSG** lookup_CSG(Database* D, CSG* toLookup);
CP** lookup_CP(Database* D, CP* toLookup);
CDH** lookup_CDH(Database* D, CDH* toLookup);
CR** lookup_CR(Database* D, CR* toLookup);

/* Print functions */
void print_CSG(CSGLIST* csglist);
void print_SNAP(SNAPLIST* snaplist);
void print_CP(CPLIST* cplist);
void print_CDH(CDHLIST* cdhlist);
void print_CR(CRLIST* crlist);
