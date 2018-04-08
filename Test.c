#include "Relation.h"
#include "Database.h"

int main() {
    Database test = Database_new();

    insertCSG(test, CSG_new("CSC101", "12345", "B+"));
    insertCSG(test, CSG_new("CSC101", "12345", "F"));
    insertCSG(test, CSG_new("CSC101", "12346", "B-"));
    insertCSG(test, CSG_new("CSC103", "12347", "B"));

    
}
