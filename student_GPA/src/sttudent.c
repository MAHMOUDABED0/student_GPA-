/*
 * sttudent.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: 3abed
 */
#include"student.h"
FIFO_Buf_s creat_fifo(sstudent_buff *fifo,Sstudent* buffer,int length){
	if (buffer==NULL)
		return FIFO_NOT_FULL;
	fifo->base=buffer;
	fifo->head=buffer;
	fifo->tail=buffer;
	fifo->length=length;
	fifo->count=0;
	return FIFO_NO_ERROR;
}
FIFO_Buf_s iffull(sstudent_buff *fifo){
	if(fifo->base==NULL||fifo->head==NULL||fifo->tail==NULL)
		return FIFO_NULL;
	if  (fifo->count==fifo->length)
		return FIFO_FULL;
	else
	return FIFO_NOT_EMPTY;

}
FIFO_Buf_s ifempety(sstudent_buff *fifo)
{
	if(fifo->base==NULL||fifo->head==NULL||fifo->tail==NULL)
		return FIFO_NULL;
	if(fifo->count==0)
		return FIFO_EMPTY;
	else
	return FIFO_NOT_EMPTY;
}
int firstused(sstudent_buff *fifo_buff,int numb)
{
	int flag=1;
	Sstudent *ptr=fifo_buff->base;
	for(int i=0;i<fifo_buff->count;i++){
		if (ptr->roll==numb)
		{
			flag=0;
		}
		ptr++;
	}
	return flag;
}
void fullfile(sstudent_buff *fifo_buff){
	FILE* fp= fopen("add student","r");
	int rec=0, student_count=0,field_on=0;
	char lines[50];
	const char *token;
	while(fgets(lines,sizeof lines,fp)!=NULL){
		rec++;
		token=strtok(lines,",");
		field_on=0;
		while(token!=NULL)
			field_on++;
		if(field_on==1){
			if(firstused(fifo_buff,atoi(token))==0){
				DPRINTF("error this roll number %d is used",atoi(token));
				student_count++;
				break;
			}
			else{
				fifo_buff->head->roll=atoi(token);
				DPRINTF("Roll Number %d is saved successfully\n",atoi(token));
			}

		}
		else if(field_on == 2){
			strcpy(fifo_buff->head->fname,token);
		}
		else if(field_on == 3){
			strcpy(fifo_buff->head->lname,token);
		}
		else if(field_on == 4){
			fifo_buff->head->gpa=atoi(token);

		}
		else if(field_on == 5){
			fifo_buff->head->course_id[0]=atoi(token);
		}
		else if(field_on == 6){
			fifo_buff->head->course_id[1]=atoi(token);

		}
		else if(field_on == 7){
			fifo_buff->head->course_id[2]=atoi(token);

		}
		else if(field_on == 8){
			fifo_buff->head->course_id[3]=atoi(token);

		}
		else if(field_on == 9){
			fifo_buff->head->course_id[4]=atoi(token);

		}
		token = strtok(NULL,",\n");
		if(firstused(fifo_buff, atoi(token)) == 0){
			continue;
		}
		fifo_buff->count++;
		if(fifo_buff->head==(sstudent_buff*)(fifo_buff->length* sizeof(sstudent_buff))){
			fifo_buff->head=fifo_buff->base;
		}
		else{
			fifo_buff->head++;
		}
	}
	fclose(fp);
	DPRINTF("\n[INFO] students Details is added successfully");
	DPRINTF("\n--------------------------------");
	DPRINTF("\n[INFO] The total number of students is %d ",rec - student_count);
	DPRINTF("\n[INFO] You can add up to 50 students");
	DPRINTF("\n[INFO] You can add %d more students\n",50-(rec-student_count));

}
void fullmanually(sstudent_buff *fifo_buff){
	char temp[50];
	int rollnum=0;
	if(fifo_buff->base==NULL||fifo_buff->head==NULL||fifo_buff->tail==NULL)
		DPRINTF("FIFO_NULL");
	if(fifo_buff->count==fifo_buff->length)
		DPRINTF("FIFO_full");
	DPRINTF("enter roll number");
	gets(temp);
	rollnum= atoi (temp);
	if (firstused( fifo_buff, rollnum)==0){
		DPRINTF("Roll Number is taken before\n");
		DPRINTF("Enter the Roll Number: ");
		gets(temp);
	}
	fifo_buff->head->roll = atoi(temp);

	DPRINTF("Enter the first Name of Student:");
	gets(fifo_buff->head->fname);

	DPRINTF("Enter the Last Name of Student:");
	gets(fifo_buff->head->lname);
	DPRINTF("Enter the GPA you obtained:");
	gets(temp);
	fifo_buff->head->gpa = atof(temp);

	DPRINTF("Enter the Course ID of each course:\n");
	for(int i=0; i<5; ++i){
		DPRINTF("Course %d ID: ",i+1);
		gets(temp);
		fifo_buff->head->course_id[i] = atoi(temp);
	}
	fifo_buff->count++;
	if(fifo_buff->head==(sstudent_buff*)(fifo_buff->length* sizeof(sstudent_buff))){
		fifo_buff->head=fifo_buff->base;
	}
	else{
		fifo_buff->head++;
	}
	DPRINTF("\n[INFO] students Details is added successfully");
	DPRINTF("\n The total number of students is %d ",fifo_buff->count);
	DPRINTF("\n You can add 50 students");
	DPRINTF("\n You can add %d more students\n",50-fifo_buff->count);
}
void fu_roll(sstudent_buff *fifo_buff){
	int roll_num=0,flag=0;
	Sstudent *ptr=fifo_buff->base;
	DPRINTF("enter roll number");
	scanf("%d",&roll_num);
	for (int i=0;i<fifo_buff->count;i++){
		if(ptr->roll==roll_num){
			DPRINTF("The students Details are\n");
			DPRINTF(" First name is   :%s\n",ptr->fname);
			DPRINTF(" last  name  : %s\n",ptr->lname);
			DPRINTF(" roll  number: %d\n",ptr->roll);
			DPRINTF(" GPA        : %0.2f\n",ptr->gpa);
			DPRINTF("Enter the course ID of each course\n");
			for(int j=0;j<5;j++){
				DPRINTF("The course ID are: %d\n",ptr->course_id[j]);

			}
			flag=0;
			break;
		}
		else{
			flag=1;
		}
		ptr++;
		}
	if(flag == 1){
			DPRINTF("[ERROR] Roll Number %d not found\n",roll_num);
		}
	}


void fu_name(sstudent_buff *fifo_buff){

		int CID , Count = 0;
		Sstudent* Ptr = fifo_buff->base;

		DPRINTF("Enter the course ID: ");
		scanf("%d",&CID);

		for(int i=0; i<fifo_buff->count; ++i){

			for(int j=0; j<5; ++j){
				if(Ptr->course_id[j] == CID){
					Count++;
					DPRINTF("The students Details are\n");
					DPRINTF("The First name is   : %s\n",Ptr->fname);
					DPRINTF("Student last  name  : %s\n",Ptr->lname);
					DPRINTF("Student roll  number: %d\n",Ptr->roll);
					DPRINTF("Student GPA         : %0.2f\n",Ptr->gpa);
				}
			}
			Ptr++;
		}
		if(Count == 0){
			DPRINTF(" Course id %d not found\n",CID);
		}
		DPRINTF("[ Total Number of Students Enrolled: %d\n",Count);
}
void numofstud(sstudent_buff *fifo_buff){
	DPRINTF("[INFO] The total number of student is %d\n",fifo_buff->count);
		DPRINTF("[INFO] You can add up to 50 students\n");
		DPRINTF("[INFO] You can add %d more students\n",50-fifo_buff->count);
}
void deletstu(sstudent_buff *fifo_buff){
	int Num , flag = 0;
Sstudent* Ptr = fifo_buff->base;

DPRINTF("Enter the Roll Number which you want to delete: ");
scanf("%d",&Num);

for(int i=0; i<fifo_buff->count; ++i){
	if(Ptr->roll == Num){
		*Ptr = *(fifo_buff->tail);
		fifo_buff->count--;
		/* For circular Queue */
		if(fifo_buff->tail == (Sstudent*)(fifo_buff->length * sizeof(Sstudent))){
			fifo_buff->tail = fifo_buff->base;
		}
		else{
			fifo_buff->tail++;
		}
		flag = 0;
		break;
	}
	else{
		flag = 1;
	}
	Ptr++;
}
if(flag == 0){
	DPRINTF(" Number is removed successfully\n");
}
else{
	DPRINTF(" Roll Number %d not found\n",Num);
}
}


void show(sstudent_buff *fifo_buff){
	Sstudent* Ptr;

		if(ifempety(fifo_buff) == FIFO_EMPTY){
			DPRINTF("FIFO is Empty\n");
		}
		else{
			Ptr = fifo_buff->tail;
		}

		for(int i=0; i<fifo_buff->count; ++i){
			DPRINTF("Student first name  : %s\n",Ptr->fname);
			DPRINTF("Student last  name  : %s\n",Ptr->lname);
			DPRINTF("Student roll  number: %d\n",Ptr->roll);
			DPRINTF("Student GPA         : %0.2f\n",Ptr->gpa);
			for(int j=0 ;j < 5; ++j){
				DPRINTF("The course ID are: %d\n",Ptr->course_id[j]);
			}
			Ptr++;
			DPRINTF("-------------------------\n");
		}

}









