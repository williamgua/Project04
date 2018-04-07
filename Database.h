#include <stdlib.h>
#include "Relations.h"

#define SIZE 100

typedef struct _Database
{
	CSG* CSGtb[SIZE];
	SNAP* SNAPtb[SIZE];
	CP* CPtb[SIZE];
	CR* CRtb[SIZE];
	CDH* CDHtb[SIZE];
}Database;