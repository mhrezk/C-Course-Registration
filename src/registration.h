#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef REGISTRATION //if not define directive

//Register course
void registerCourse(int* studentID, int numberOfStudents, int numberOfCourses, char** courseCode, int** table) {
	int id;
	int indexID = 0;
	char course[8];
	int courseIndex = 0;
	int isFound = 0; //boolean for comparing student id and course code with registrar

	do {
		printf("Enter student ID: ");
		scanf("%d", &id);
		for(int i = 0; i < numberOfStudents; i++) {
			if(studentID[i] == id) {
				isFound = 1;
				indexID = i;
				break;
			}
		}
		if(isFound == 0) {
			printf("Student ID %d is not in the registrar! Please retry!\n", id);
		}
	} while(isFound == 0);

	isFound = 0;
	
	do {
		printf("Enter course code: ");
		scanf("%s", course);
		for(int i = 0; i < numberOfCourses; i++) {
			if(strcmp(course, courseCode[i]) == 0) {
				isFound = 1;
				courseIndex = i;
                printf("Student registered!\n");
				break;
			}
		}

		if(isFound == 0) {
			printf("Course code %s is not in the registrar! Please retry!\n", course);
		}
	} while(isFound == 0);

	table[indexID][courseIndex] = 1;
}

//Dropping course
void dropCourse(int* studentID, int numberOfStudents, int numberOfCourses, char** courseCode, int** table) {
	int id;
	int indexID = 0;
	char course[8];
	int courseIndex = 0;
	int isFound = 0; //boolean for comparing student id and course code with registrar


	do {
		printf("Enter student ID: ");
		scanf("%d", &id);
		for(int i = 0; i < numberOfStudents; i++) {
			if(studentID[i] == id)
			{
				isFound = 1;
				indexID = i;
				break;
			}
		}
		if(isFound == 0) {
			printf("Student ID %d is not in the registrar! Please retry!\n", id);
		}
	} while(isFound == 0);

	isFound = 0;

	do {
		printf("Enter course code: ");
		scanf("%s", course);
		for(int i = 0; i < numberOfCourses; i++) {
			if(strcmp(course, courseCode[i]) == 0) {
				isFound = 1;
				courseIndex = i;
                printf("Course dropped!\n");
				break;
			}
		}

		if(isFound == 0) {
			printf("Course code %s is not in the registrar! Please retry!\n", course);
		}
	} while(isFound == 0);

	table[indexID][courseIndex] = 0;
}

//Display registration table
void displayTable(int* studentID, int numberOfStudents, int numberOfCourses, char** courseCode, int** table) {
	for(int i = 0; i < numberOfStudents; i++) {
		printf("\nStudent ID: %d", studentID[i]);
		for(int j = 0; j < numberOfCourses; j++) {
			printf("\tCourses %s: [%d]", courseCode[j], table[i][j]);
		}
	}
	printf("\n");
}

//Function for free()
void freeMemory(int* studentID, char** courseCode, int** table) {
	free(studentID);
	free(courseCode);
	free(table);
}

int sameElements(int array[]) {
	int first = array[0];
	int arraySize = sizeof(array) / sizeof(array[0]);

       for (int i = 1; i < arraySize; i++) {
		   if (array[i] != first)
                return 0;
	   }
       return 1;
}

#define REGISTRATION
#endif //end ifndefine