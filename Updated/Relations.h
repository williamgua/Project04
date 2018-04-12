//
//  Relations.h
//  p4
//
//  Created by jianpengyan on 2017/11/25.
//  Copyright © 2017年 jianpeng. All rights reserved.
//

#ifndef Relations_h
#define Relations_h

#include <stdio.h>
#include <stdlib.h>

typedef struct CSG CSG;
typedef struct SNAP SNAP;
typedef struct CP CP;
typedef struct CDH CDH;
typedef struct CR CR;

int equal_SNAP(SNAP* s1, SNAP* s2);

int equal_CSG(CSG* c1, CSG* c2);

int equal_CP(CP* c1, CP* c2);

int equal_CDH(CDH* c1, CDH* c2);

int equal_CR(CR* c1, CR* c2);

SNAP* SNAP_new(char* StudentId, char* Name, char* Address, char* Phone);

CSG* CSG_new(char* Course, char* StudentId, char* Grade);

CP* CP_new(char* Course, char* Prerequisite);

CDH* CDH_new(char* Course, char* Day, char* Hour);

CR* CR_new(char* Course, char* Room);

#endif /* Relations_h */
