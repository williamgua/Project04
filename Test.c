#include "Relation.h"
#include "Database.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

printf("test");

    Database test = Database_new();

    insertCSG(CSG_new("CSC101", 12345, "B+"), test);
    insertCSG(CSG_new("CSC101", 12345, "F"), test);
    insertCSG(CSG_new("CSC101", 12346, "B-"), test);
    insertCSG(CSG_new("CSC103", 12347, "B"), test);

    print_CSG(test);
}
