/*

Write a program in ‘C’ language, which accepts Enrolment number, Name
Aggregate marks secured in a Program by a student. Assign ranks to students
according to the marks secured. Rank-1 should be awarded to the students who
secured the highest marks and so on. The program should print the enrolment
number, name of the student and the rank secured in ascending order.

*/

#include <stdio.h>
#include <string.h>

// Define the maximum number of students
#define MAX_STUDENTS 10

int main()
{
    // Declare the student array
    struct student
    {
        int enrolment_number;
        char name[100];
        int marks;
        int rank;
    } students[MAX_STUDENTS];

    // Prompt the user to enter the details of the students
    printf("Enter the details of the students:\n");
    for (int i = 0; i < MAX_STUDENTS; i++)
    {
        printf("Student %d\n", i + 1);
        printf("Enrolment number: ");
        scanf("%d", &students[i].enrolment_number);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Marks: ");
        scanf("%d", &students[i].marks);
        printf("\n");
    }

    // Assign ranks to the students
    for (int i = 0; i < MAX_STUDENTS; i++)
    {
        int max_marks = 0;
        int max_index = 0;

        // Find the student with the highest marks
        for (int j = 0; j < MAX_STUDENTS; j++)
        {
            if (students[j].marks > max_marks)
            {
                max_marks = students[j].marks;
                max_index = j;
            }
        }

        // Assign the rank to the student
        students[max_index].rank = i + 1;

        // Set the marks of the student to 0 so that it is not considered in the next iteration
        students[max_index].marks = 0;
    }

    // Print the details of the students in ascending order of rank
    printf("Student details:\n");
    for (int i = 0; i < MAX_STUDENTS; i++)
    {
        for (int j = 0; j < MAX_STUDENTS; j++)
        {
            if (students[j].rank == i + 1)
            {
                printf("Enrolment number: %d\n", students[j].enrolment_number);
                printf("Name: %s\n", students[j].name);
                printf("Rank: %d\n", students[j].rank);
                printf("\n");
            }
        }
    }

    return 0;
}