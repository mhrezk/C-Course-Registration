/*
    Name: Mohamed Rezk
    Course: C Programming Language 
    Assignment: Lab 03
    Description: Program that registers students and drops students from courses
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "registration.h" //importing user-defined library

//Global variables
int numberOfStudents = 0;
int numberOfCourses = 0;
int* studentID;
char** courseCode;
int** table;

int main() {

	printf("Enter number of students for registration: ");
	scanf("%d", &numberOfStudents);

	//Number of Students
	studentID = (int*) malloc(numberOfStudents * sizeof(int));
	sameStudents(studentID);
	for(int i = 0; i < numberOfStudents; i++) {
		printf("Enter ID for student %d: ", (i+1));
		scanf("%d", &studentID[i]);
		while(sameStudents(studentID) == 1) {
			printf("Duplicate ID!\n");
			printf("Enter ID for student %d: ", (i+1));
			scanf("%d", &studentID[i]);
		}
	}
	
		
	
	
		//if(scanf("%d", &numberOfStudents) == 1) { //user input verification
	
	
	

	//Number of courses
	printf("Enter number of courses offered: ");
	scanf("%d", &numberOfCourses);
	courseCode = malloc(numberOfCourses * sizeof(char*));
	for(int i = 0; i < numberOfCourses; i++) {

		// Clear standard input (stdin) for next input
		int c = getchar(); 
        while(c != '\n' && c != EOF) {//clearing input buffer through new line character and End Of File macro
            c = getchar();
        } 
		
		printf("Enter code for course %d: ", (i + 1));
		courseCode[i] = malloc(8 * sizeof(char));
		fgets(courseCode[i], 8, stdin);
		
		if(i >= 1 && strcmp(courseCode[0], courseCode[i]) == 0) {
			int isSame = 1;
			while(isSame == 1) {
				printf("Duplicate Code!\n");
				printf("Enter code for course %d: ", (i + 1));
				courseCode[i] = malloc(8 * sizeof(char));
				fgets(courseCode[i], 8, stdin);
				if(strcmp(courseCode[0], fgets(courseCode[i], 8, stdin)) != 0) {
					isSame = 0;
				}
			}
		}
		
		// int wordSize = sizeof(courseCode[0])/sizeof(courseCode[0][0]);
		// for(int j = 0; j < wordSize; j++) {
		// 	while (sameCourses(courseCode) == 0) {
		// 		printf("Duplicate Code!\n");
		// 		printf("Enter code for course %d: ", (i+1));
		// 		fgets(courseCode[i], 8, stdin);
		// 	}
		// }
	}

	//Registration table
	table = (int**) malloc(numberOfStudents * sizeof(int*));
	for(int i = 0; i < numberOfStudents; i++) {
        table[i] = (int*) calloc(numberOfCourses, sizeof(int));
    }
		

	//Menu display
	int option = 0;
	while(option!=4) {
		printf("\nWelcome!\n"
                "What would you like to do?\n"
			   "1- Register a student into a course\n"
			   "2- Drop a student from a course\n"
			   "3- Display Registration table\n"
			   "4- Exit\n"
			   "Choose an option: ");
		//clear input buffer	   
		int c = getchar(); 
        while(c!='\n' && c!=EOF) {
            c = getchar();
        } 
		scanf("%d", &option);

		//Switch statement
		switch(option) {
			case 1:
				registerCourse(studentID, numberOfStudents, numberOfCourses, courseCode, table);
				break;
			case 2:
				dropCourse(studentID, numberOfStudents, numberOfCourses, courseCode, table);
				break;
			case 3:
				displayTable(studentID, numberOfStudents, numberOfCourses, courseCode, table);
				break;
			case 4:
                printf("<<-- Terminating -->>\n");
				freeMemory(studentID, courseCode, table);//freeing memory from heap
				break;
			default:
				printf("Invalid input! Please retry!");
				break;
		}
	}
	return EXIT_SUCCESS;
}
