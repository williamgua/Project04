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
    while (fgets(buf, 100, fp))  {
	    int l = strlen(buf);
	    char c[l];
	    strcpy(c, buf);
	    // if (c[l-1] !='\0') 
	    // 	c[l-1] = '\0';
	    char* token = strtok(c, " ");
	    if (strcmp(token, "CSG") == 0) {
	    	char *course = strtok(NULL, " ");
	        char StudentId = strtok(NULL, " ");
	        char *Grade = strtok(NULL, " ")
	        insert_CSG(CSG_new(Course, StudentId, Grade), CSGtb);
	    } else if (strcmp(token, "SNAP") == 0) {
	        char StudentId = strtok(NULL, " ");
	        char* Name = strtok(NULL, " ");
	        char* Address = strtok(NULL, " ");
	        char* Phone = strtok(NULL, " ");
	        insert_SNAP(SNAP_new(StudentId, Name, Address, Phone),SNAPtb);
	    } else if (strcmp(token, "CP") == 0) {
	        char* Course = strtok(NULL, " ");
	        char*Prerequisite = strtok(NULL, " ");
	        insert_CP(CP_new(Course, Prerequisite),CPtb);
	    } else if (strcmp(token, "CDH") == 0) {
	        char* Course = strtok(NULL, " ");
	        char* Day = strtok(NULL, " ");
	        char* Hour = strtok(NULL, " ");
	        insert_CDH(CDH_new(Course, Day, Hour), CDHtb);
	    } else if (strcmp(token, "CR") == 0) {
	        char* Course = strtok(NULL, " ");
	        char* Room = strtok(NULL, " ");
	        insert_CR(createCR(Course, Room), CRtb);
	    } else {
	        perror("Error");
	    }
    }
        fclose(fp);
    
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
            while (current) {
                fprintf(fp, "CSG \n%s %d %s\n", current-> Course, current->StudentId, current->Grade);
                current = current->next;
            }
        }
        //SNAP
        for (i=0; i<1009; i++) {
            SNAP *current = SNAPtb[i];
            while (current) {
                fprintf(fp, "SNAP \n%d %s %s %d\n", current->StudentId, current->Name, current->Address, current->Phone);
                current = current->next;
            }
        }
        //CP
        for (i=0; i<1009; i++) {
            CP *current = CPtb[i];
            while (current) {
                fprintf(fp, "CP \n%s %s\n", current-> Course, current->Prerequisite);
                current = current->next;
            }
        }
        //CDH
        for (i=0; i<1009; i++) {
            CDH *current = CDHtb[i];
            while (current) {
                fprintf(fp, "CDH \n%s %s %s\n", current-> Course, current->Day, current->Hour);
                current = current->next;
            }
        }
        //CR
        for (i=0; i<1009; i++) {
            CR *current = CRtb[i];
            while (current) {
                fprintf(fp, "CR \n%s %s\n", current-> Course, current->Room);
                current = current->next;
            }
        }
        fclose(fp);
    }
}