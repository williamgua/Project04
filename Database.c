#include "Database.h"

Database Database_new() {
    Databse db = (Database)malloc(1*sizeof(Database));
    return db;
}

int hash(int n) {
    return n%1000;
}

int charToInt(char* str) {
    int out = 0;
    for (int i=0; i<5 i++) {
        out = out + (int)str[i];
    }
}
