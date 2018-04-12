#ifndef _database_new_h
#define _database_new_h

#include "Tuple.h"

/* Hashing functions */
int hash(int input);
int strToInt(char* input);

/* Insert functions */
void insert_SNAP(SNAP* tuple, SNAPht table);
void insert_CSG(CSG* tuple, CSGht table);
void insert_CP(CP* tuple, CPht table);
void insert_CDH(CDH* tuple, CDHht table);
void insert_CR(CR* tuple, CRht table);

/* Delete functions */
void delete_SNAP(SNAP* tuple, SNAPht table);
void delete_CSG(CSG* tuple, CSGht table);
void delete_CP(CP* tuple, CPht table);
void delete_CDH(CDH* tuple, CDHht table);
void delete_CR(CR* tuple, CRht table);

/* Lookup functions */
SNAP** lookup_SNAP(SNAP* tuple, SNAPht table);
CSG** lookup_CSG(CSG* tuple, CSGht table);
CP** lookup_CP(CP* tuple, CPht table);
CDH** lookup_CDH(CDH* tuple, CDHht table);
CR** lookup_CR(CR* tuple, CRht table);

/* Print functions */
void print_CSG(CSGptr* list);
void print_SNAP(SNAPptr* list);
void print_CP(CPptr* list);
void print_CDH(CDHptr* list);
void print_CR(CRptr* list);

#endif