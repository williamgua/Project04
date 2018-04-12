#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Database.h"
#include "Saver.h"

void importDB(char* fileName) {
	FILE *fp;
	char buf[100];
    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error: Cannot Open File");
        return;
    } 
    while(fgets(buf, 100, fp) != NULL) {
	    int length = strlen(buf);
	    char input[length];
	    strcpy(input, buf);
	    char* token = strtok(input, " ");
	    if (strcmp(token, "CSG") == 0) {
	    	for(int i=5; i<length; i++) {
                input[i-5] = input[i];
            }
            for(int i=length-1; i>length-5; i--) {
                input[i] = " ";
            }
            length -= 5;
            char *course = strtok(input, " ");
            int len1 = strlen(course)+1;
            for(int i=len1; i<length; i++) {
                input[i-len1] = input[i];
            }
            for(int i=length-1; i>length-len1; i--) {
                input[i] = " ";
            }
            length -= len1;
	        char *StudentId = strtok(input, " ");
            int len2 = strlen(StudentId)+1;
            for(int i=len2; i<length; i++) {
                input[i-len2] = input[i];
            }
            for(int i=length-1; i>length-len2; i--) {
                input[i] = " ";
            }
            length -= len2;
	        char *Grade = strtok(input, " ");
            int len3 = strlen(Grade)+1;
            for(int i=len3; i<length; i++) {
                input[i-len3] = input[i];
            }
            for(int i=length-1; i>length-len3; i--) {
                input[i] = " ";
            }
            length -= len3;
	        insert_CSG(CSG_new(Course, StudentId, Grade), csgtable);
	    } else if (strcmp(token, "SNAP") == 0) {
	        for(int i=6; i<length; i++) {
                input[i-6] = input[i];
            }
            for(int i=length-1; i>length-6; i--) {
                input[i] = " ";
            }
            length -= 6;
            char* StudentId = strtok(input, " ");
            int len2 = strlen(StudentId)+1;
            for(int i=len2; i<length; i++) {
                input[i-len2] = input[i];
            }
            for(int i=length-1; i>length-len2; i--) {
                input[i] = " ";
            }
            length -= len2;
	        char* Name = strtok(input, " ");
            int len1 = strlen(Name)+1;
            for(int i=len1; i<length; i++) {
                input[i-len1] = input[i];
            }
            for(int i=length-1; i>length-len1; i--) {
                input[i] = " ";
            }
            length -= len1;
	        char* Address = strtok(input, " ");
            int len3 = strlen(Address)+1;
            for(int i=len3; i<length; i++) {
                input[i-len3] = input[i];
            }
            for(int i=length-1; i>length-len3; i--) {
                input[i] = " ";
            }
            length -= len3;
	        char* Phone = strtok(input, " ");
            int len4 = strlen(Phone)+1;
            for(int i=len4; i<length; i++) {
                input[i-len4] = input[i];
            }
            for(int i=length-1; i>length-len4; i--) {
                input[i] = " ";
            }
            length -= len4;
	        insert_SNAP(SNAP_new(StudentId, Name, Address, Phone), snaptable);
	    } else if (strcmp(token, "CP") == 0) {
	        for(int i=4; i<length; i++) {
                input[i-4] = input[i];
            }
            for(int i=length-1; i>length-4; i--) {
                input[i] = " ";
            }
            length -= 4;
            char* Course = strtok(input, " ");
            int len1 = strlen(Course)+1;
            for(int i=len1; i<length; i++) {
                input[i-len1] = input[i];
            }
            for(int i=length-1; i>length-len1; i--) {
                input[i] = " ";
            }
            length -= len1;
	        char* Prerequisite = strtok(input, " ");
            int len2 = strlen(Prerequisite)+1;
            for(int i=len2; i<length; i++) {
                input[i-len2] = input[i];
            }
            for(int i=length-1; i>length-len2; i--) {
                input[i] = " ";
            }
            length -= len2;
	        insert_CP(CP_new(Course, Prerequisite), cptable);
	    } else if (strcmp(token, "CDH") == 0) {
	        for(int i=5; i<length; i++) {
                input[i-5] = input[i];
            }
            for(int i=length-1; i>length-5; i--) {
                input[i] = " ";
            }
            length -= 5;
            char* Course = strtok(input, " ");
            int len1 = strlen(Course)+1;
            for(int i=len1; i<length; i++) {
                input[i-len1] = input[i];
            }
            for(int i=length-1; i>length-len1; i--) {
                input[i] = " ";
            }
            length -= len1;
	        char* Day = strtok(input, " ");
	        char* Hour = strtok(input, " ");
	        insert_CDH(CDH_new(Course, Day, Hour), cdhtable);
	    } else if (strcmp(token, "CR") == 0) {
	       for(int i=4; i<length; i++) {
                input[i-4] = input[i];
            }
            for(int i=length-1; i>length-4; i--) {
                input[i] = " ";
            }
            length -= 4;
            char* Course = strtok(input, " ");
            int len1 = strlen(Course)+1;
            for(int i=len1; i<length; i++) {
                input[i-len1] = input[i];
            }
            for(int i=length-1; i>length-len1; i--) {
                input[i] = " ";
            }
            length -= len1;
	        char* Room = strtok(input, " ");
            int len2 = strlen(Room)+1;
            for(int i=len2; i<length; i++) {
                input[i-len2] = input[i];
            }
            for(int i=length-1; i>length-len2; i--) {
                input[i] = " ";
            }
            length -= len2;
	        insert_CR(CR_new(Course, Room), crtable);
	    } else {
	        perror("Error");
	    }
    }
        if(fclose(fp) != 0) {
            perror("Error: Cannot Close File");
        }
    
}

void exportDB(char *fileName) {
    FILE *fp;
    fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("Error: Cannot Open File");
    } else {
        int i;
        //CSG
        for (i=0; i<1009; i++) {
            CSG *current = CSGtb[i];
            while (current != NULL) {
                fprintf(fp, "CSG \n%s %d %s\n", current->Course, current->StudentId, current->Grade);
                current = current->next;
            }
        }
        //SNAP
        for (i=0; i<1009; i++) {
            SNAP *current = SNAPtb[i];
            while(current != NULL) {
                fprintf(fp, "SNAP \n%d %s %s %d\n", current->StudentId, current->Name, current->Address, current->Phone);
                current = current->next;
            }
        }
        //CP
        for (i=0; i<1009; i++) {
            CP *current = CPtb[i];
            while(current != NULL) {
                fprintf(fp, "CP \n%s %s\n", current->Course, current->Prerequisite);
                current = current->next;
            }
        }
        //CDH
        for (i=0; i<1009; i++) {
            CDH *current = CDHtb[i];
            while(current != NULL) {
                fprintf(fp, "CDH \n%s %s %s\n", current->Course, current->Day, current->Hour);
                current = current->next;
            }
        }
        //CR
        for (i=0; i<1009; i++) {
            CR *current = CRtb[i];
            while(current != NULL) {
                fprintf(fp, "CR \n%s %s\n", current->Course, current->Room);
                current = current->next;
            }
        }
        if(fclose(fp) != 0) {
            perror("Error: Cannot Close File");
        }
    }
}