#include <stdlib.h>
#include "Relation.h"

#define SIZE 100

typedef struct _Database
{
	CSG CSGtb[SIZE];
	SNAP SNAPtb[SIZE];
	CP CPtb[SIZE];
	CR CRtb[SIZE];
	CDH CDHtb[SIZE];
} *Database;

Database Database_new();

int hash(int n);
int charToInt(char* str);

void insertCSG(CSG csg, Database d);
void insertSNAP(SNAP snap, Database d);
void insertCP(CP cp, Database d);
void insertCR (CR cr, Database d);
void insertCDH (CDH cdh, Database d);

void deleteCSG(CSG csg, Database d);
void deleteSNAP(SNAP snap, Database d);
void deleteCP(CP cp, Database d);
void deleteCR (CR cr, Database d);
void deleteCDH (CDH cdh, Database d);

CSG lookupCSG(CSG csg, Database d);
SNAP lookupSNAP(SNAP snap, Database d);
CP lookupCP(CP cp, Database d);
CR lookupCR (CR cr, Database d);
CDH lookupCDH (CDH cdh, Database d);
