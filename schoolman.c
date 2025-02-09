#include <stdio.h>
#include <string.h>

#define NAME_LENGTH 50

const char *FILE_NAME = "data.dat";

typedef struct
{
  int roll;
  int room_no;
  char class[NAME_LENGTH];
  char section;
} Class;

typedef struct
{
  char route[NAME_LENGTH];
  char bus_name[NAME_LENGTH];
  char driver[NAME_LENGTH];
} Transport;

typedef struct
{
  int day;
  int month;
  int year;
} Dob;

typedef struct
{
  char city[NAME_LENGTH];
  char dist[NAME_LENGTH];
  char pin_code[NAME_LENGTH];
} Address;

typedef struct
{
  char father_name[NAME_LENGTH];
  char mother_name[NAME_LENGTH];
  char phone_no[10];
  Address Addr_parents;

} Parent;

typedef struct
{
  char student_name[NAME_LENGTH];
  int age;
  char reg_no[NAME_LENGTH];
  int id;
  Dob Student_DOB;
  Parent Student_Parent;
  Address Student_Address;
  Transport Student_Transport;
  Class Student_Class;

} student;

typedef struct
{
  char name[NAME_LENGTH];
  Parent teacher_parent;
} Teacher;

FILE *open_file();
FILE *open_file_readM();
void clear_newlinechar();

void admsn();
void admsn_cancel();
void admsn_enq();
void fee_payment();
void detail();
void general();

void student_detail();
void parent_detail();

void fix_fgets_error(char *);

int main()
{

  int option;

  while (1)
  {

    printf("\n-------School management------------");
    printf("\nChoose options(1-9");
    printf("\n1.Admission");
    printf("\n2.Admission cancelation");
    printf("\n3.Addmission enquiry");
    printf("\n4.Detail");
    printf("\n5.Fee Payment");
    printf("\n6.General");
    printf("\n7.Exit");

    printf("\nChoose options: ");

    scanf("%d", &option);

    switch (option)
    {

    case 1:
      admsn();
      break;
    case 2:
      admsn_cancel();
      break;
    case 3:
      admsn_enq();
      break;
    case 4:
      detail();
      break;
    case 5:
      fee_payment();
      break;
    case 6:
     general();
      break;
    case 7:
      printf("\nExiting");
      return 0;
    default:
      printf("Invalid optioins");
      break;
    }
  }

  return 0;
}

void admsn()
{
  student s;
  FILE *file = open_file();
  printf("\n--------Admission----------");
  printf("\nEnter students Details");

  printf("\nEnter students name: ");

  // getchar();
  clear_newlinechar();
  fgets(s.student_name, NAME_LENGTH, stdin);
  fix_fgets_error(s.student_name);

  printf("\nEnter studetns age: ");
  scanf("%d", &s.age);

  printf("\nEnter student id: ");
  scanf("%d", &s.id);

  printf("\nEnter student registration number: ");
  getchar();
  fgets(s.reg_no, NAME_LENGTH, stdin);
  fix_fgets_error(s.reg_no);

  printf("\nEnter students DOB>>");
  printf("\nDAY : ");
  scanf("%d", &s.Student_DOB.day);
  printf("\nMonth: ");
  scanf("%d", &s.Student_DOB.month);
  printf("\nYear: ");
  scanf("%d", &s.Student_DOB.year);
  fwrite(&s, sizeof(s), 1, file);

  fclose(file);

  printf("\nAdmission done succesfully");
  return;
}

void admsn_cancel()
{
  // do something
}
void admsn_enq()
{
  // do something
}
void fee_payment()
{
  // do something
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

void general()
{
  // do something
}

void student_detail()
{

  printf("\n----- Student Detail --------\n");

  FILE *file = open_file_readM();
  char temp_student_reg_no[NAME_LENGTH];
  student s;

  if (file == NULL)
  {
    return;
  }

  printf("\nEnter student registration no: ");
  clear_newlinechar();
  fgets(temp_student_reg_no, NAME_LENGTH, stdin);
  fix_fgets_error(temp_student_reg_no);

  while (fread(&s, sizeof(s), 1, file))
  {
    if (strcmp(s.reg_no, temp_student_reg_no) == 0)
    {
      printf("\nDetail found ....");
      printf("\nName : %s", s.student_name);
      printf("\nID : %d", s.id);
      printf("\nAge : %d", s.age);
      printf("\nDOB: %d/%d/%d", s.Student_DOB.day, s.Student_DOB.month, s.Student_DOB.year);
      fclose(file);
      return;
    }
  }

  printf("\nDetailed not found ..........");
  fclose(file);
  return;
}
void parent_detail() {}

void fix_fgets_error(char *buffer)
{
  int index;
  index = strcspn(buffer, "\n");
  buffer[index] = '\0';
}

FILE *open_file()
{
  FILE *file = fopen(FILE_NAME, "ab+");

  if (file == NULL)
  {
    printf("\nFile couldn't open");
    return NULL;
  }
  return file;
}
// In read mode rb+
FILE *open_file_readM()
{
  FILE *file = fopen(FILE_NAME, "rb");

  if (file == NULL)
  {
    printf("\nFile couldn't open");
    return NULL;
  }
  return file;
}

void clear_newlinechar()
{
  char c;
  do
  {
    c = getchar();
  } while (c != '\n' && c != EOF);
}
