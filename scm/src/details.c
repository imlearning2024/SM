#include "../include/school.h"

void student_detail() {
    printf("\n----- Student Detail --------\n");

    FILE *file = open_file_readM();
    char temp_student_reg_no[NAME_LENGTH];
    Student s;

    if (file == NULL) return;

    printf("\nEnter Student Registration No: ");
    clear_newlinechar();
    fgets(temp_student_reg_no, NAME_LENGTH, stdin);
    fix_fgets_error(temp_student_reg_no);

    while (fread(&s, sizeof(s), 1, file)) {
        if (strcmp(s.reg_no, temp_student_reg_no) == 0) {
            printf("\nDetail Found!");
            printf("\nName: %s", s.student_name);
            printf("\nID: %d", s.id);
            printf("\nAge: %d", s.age);
            printf("\nDOB: %d/%d/%d", s.Student_DOB.day, s.Student_DOB.month, s.Student_DOB.year);
            fclose(file);
            return;
        }
    }

    printf("\nDetails Not Found.");
    fclose(file);
}

void parent_detail() {
    printf("\nParent Detail - Functionality Not Implemented Yet\n");
}

void detail()
{

  int opt;

  while (1)
  {

    printf("\n\n-----details-------\n");

    printf("\n1.Student Details");
    printf("\n2.Parent Details");
    printf("\n3.Exit");

    printf("\nChoose options: ");
    scanf("%d", &opt);

    switch (opt)
    {
    case 1:
      student_detail();
      break;
    case 2:
      parent_detail();
      break;
    case 3:
      printf("\nExiting .. Detial");
      return;
      break;
    default:
      printf("Invalid choice");
      break;
    }
  }
}


