/*
 ============================================================================
 Name        : main.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "Student.h"

int main()
{
	int Choice;
	sstudent_buff FIFOStudent;

	creat_fifo(&FIFOStudent ,one , 50);



	DPRINTF("  Hello in student  System\n");
	while(1)
	{
		DPRINTF("\nChoose The Task that you want to perform\n");
		DPRINTF("1. Add the student Details Manually\n");
		DPRINTF("2. Add the student Details From Text File\n");
		DPRINTF("3. Find the Student Details by Roll Number\n");
		DPRINTF("4. Find the Student Details by First Name\n");
		DPRINTF("5. Find the Total number of Students\n");
		DPRINTF("6. Delete the Students Details by Roll Number\n");
		DPRINTF("7. Show all information\n");
		DPRINTF("7. To Exit\n");
		DPRINTF("Enter your choice to perform the task: ");

		scanf("%d",&Choice);
		switch(Choice)
		{
		case 1:
			DPRINTF("Add the student Details\n");
			DPRINTF("==============================\n");
			fullmanually(&FIFOStudent);
			break;
		case 2:
			fullfile(&FIFOStudent);
			break;
		case 3:
			DPRINTF("----------------------------\n");
			fu_roll(&FIFOStudent);
			break;
		case 4:
			DPRINTF("----------------------------\n");
			fu_name(&FIFOStudent);
		break;
		case 5:
			DPRINTF("----------------------------\n");
			numofstud(&FIFOStudent);
			break;
		case 6:
			DPRINTF("----------------------------\n");
			deletstu(&FIFOStudent);
			break;
		case 7:
			DPRINTF("----------------------------\n");
			show(&FIFOStudent);
			break;
		case 8:
			exit(1);
		}
	}
	return 0;
}
