#include "../include/school.h"

void admsn() {
    Student s;
    FILE *file = open_file();
    printf("\n-------- Admission ----------");
    printf("\nEnter Student's Details");

    printf("\nEnter Student's Name: ");
    clear_newlinechar();
    fgets(s.student_name, NAME_LENGTH, stdin);
    fix_fgets_error(s.student_name);

    printf("\nEnter Student's Age: ");
    scanf("%d", &s.age);

    printf("\nEnter Student ID: ");
    scanf("%d", &s.id);

    printf("\nEnter Student Registration Number: ");
    clear_newlinechar();
    fgets(s.reg_no, NAME_LENGTH, stdin);
    fix_fgets_error(s.reg_no);

    printf("\nEnter Student's DOB:");
    printf("\nDay: ");
    scanf("%d", &s.Student_DOB.day);
    printf("\nMonth: ");
    scanf("%d", &s.Student_DOB.month);
    printf("\nYear: ");
    scanf("%d", &s.Student_DOB.year);

    fwrite(&s, sizeof(s), 1, file);
    fclose(file);

    printf("\nAdmission Done Successfully!");
}

void admsn_cancel() {
    printf("\nAdmission Cancellation - Functionality Not Implemented Yet\n");
}

void admsn_enq() {
    printf("\nAdmission Enquiry - Functionality Not Implemented Yet\n");
}

