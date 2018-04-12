#ifndef _database_new_h
#define _database_new_h

#include "Tuple.h"

/* Hashing functions */
int hash(int input);
int strToInt(char* input);

/* Insert functions */
void insert_SNAP(SNAP* tuple, SNAPtb table);
void insert_CSG(CSG* tuple, CSGtb table);
void insert_CP(CP* tuple, CPtb table);
void insert_CDH(CDH* tuple, CDHtb table);
void insert_CR(CR* tuple, CRtb table);

/* Delete functions */
void delete_SNAP(SNAP* tuple, SNAPtb table);
void delete_CSG(CSG* tuple, CSGtb table);
void delete_CP(CP* tuple, CPtb table);
void delete_CDH(CDH* tuple, CDHtb table);
void delete_CR(CR* tuple, CRtb table);

/* Lookup functions */
SNAP** lookup_SNAP(SNAP* tuple, SNAPtb table);
CSG** lookup_CSG(CSG* tuple, CSGtb table);
CP** lookup_CP(CP* tuple, CPtb table);
CDH** lookup_CDH(CDH* tuple, CDHtb table);
CR** lookup_CR(CR* tuple, CRtb table);

/* Print functions */
void print_CSG(CSGptr* list);
void print_SNAP(SNAPptr* list);
void print_CP(CPptr* list);
void print_CDH(CDHptr* list);
void print_CR(CRptr* list);
void print_CRDH(CRDHptr* list);

#endif
