/*
 * student.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: 3abed
 */

#ifndef __student__
#define __student__
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"
#define DPRINTF(...)      {fflush(stdout);\
		fflush(stdin);\
		printf(__VA_ARGS__);\
		fflush(stdout);\
		fflush(stdin);}

typedef struct{
	char fname[15];
	char lname[15];
	int roll;
	float gpa;
	int course_id[10];

}Sstudent;

Sstudent one[50];

typedef struct{
	int length;
	int count;
	Sstudent* base;
	Sstudent *head;
	Sstudent *tail;

}sstudent_buff;
typedef enum{
	FIFO_NO_ERROR,
	FIFO_FULL,
	FIFO_NOT_FULL,
	FIFO_EMPTY,
	FIFO_NOT_EMPTY,
	FIFO_NULL
}FIFO_Buf_s;

FIFO_Buf_s creat_fifo(sstudent_buff *fifo,Sstudent* sbuffer,int length);
FIFO_Buf_s iffull(sstudent_buff *fifo);
FIFO_Buf_s ifempety(sstudent_buff *fifo);
int firstused(sstudent_buff *fifo_buff,int num);
void fullfile(sstudent_buff *fifo_buff);
void fullmanually(sstudent_buff *fifo_buff);
void fu_roll(sstudent_buff *fifo_buff);
void fu_name(sstudent_buff *fifo_buff);
void numofstud(sstudent_buff *fifo_buff);
void deletstu(sstudent_buff *fifo_buff);
void show(sstudent_buff *fifo_buff);

#endif
