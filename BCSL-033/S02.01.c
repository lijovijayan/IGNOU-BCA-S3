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

    int i = 0, j = 0;

    // Prompt the user to enter the details of the students
    printf("Enter the details of the students:\n");
    for (i = 0; i < MAX_STUDENTS; i++)
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
    for (i = 0; i < MAX_STUDENTS; i++)
    {
        int max_marks = 0;
        int max_index = 0;

        // Find the student with the highest marks
        for (j = 0; j < MAX_STUDENTS; j++)
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
    for (i = 0; i < MAX_STUDENTS; i++)
    {
        for (j = 0; j < MAX_STUDENTS; j++)
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

// Output:

// Enter the details of the students:
// Student 1
// Enrolment number: 1001
// Name: Student_1
// Marks: 97

// Student 2
// Enrolment number: 1002
// Name: Student_2
// Marks: 84

// Student 3
// Enrolment number: 1003
// Name: Student_3
// Marks: 34

// Student 4
// Enrolment number: 1004
// Name: Student_4
// Marks: 75

// Student 5
// Enrolment number: 1005
// Name: Student_5
// Marks: 45

// Student 6
// Enrolment number: 1006
// Name: Student_6
// Marks: 34

// Student 7
// Enrolment number: 1007
// Name: Student_7
// Marks: 99

// Student 8
// Enrolment number: 1008
// Name: Student_8
// Marks: 34

// Student 9
// Enrolment number: 1009
// Name: Student_9
// Marks: 78

// Student 10
// Enrolment number: 1010
// Name: Student_10
// Marks: 92

// Student details:
// Enrolment number: 1007
// Name: Student_7
// Rank: 1

// Enrolment number: 1001
// Name: Student_1
// Rank: 2

// Enrolment number: 1010
// Name: Student_10
// Rank: 3

// Enrolment number: 1002
// Name: Student_2
// Rank: 4

// Enrolment number: 1009
// Name: Student_9
// Rank: 5

// Enrolment number: 1004
// Name: Student_4
// Rank: 6

// Enrolment number: 1005
// Name: Student_5
// Rank: 7

// Enrolment number: 1003
// Name: Student_3
// Rank: 8

// Enrolment number: 1006
// Name: Student_6
// Rank: 9

// Enrolment number: 1008
// Name: Student_8
// Rank: 10