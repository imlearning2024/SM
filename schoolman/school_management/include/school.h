#ifndef SCHOOL_H
#define SCHOOL_H

#include <stdio.h>
#include <string.h>

#define NAME_LENGTH 50

extern const char *FILE_NAME;

// Define structures
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
} Student;

typedef struct
{
    char name[NAME_LENGTH];
    Parent teacher_parent;
} Teacher;

// Function declarations
FILE *open_file();
FILE *open_file_readM();
void clear_newlinechar();
void fix_fgets_error(char *);

void admsn();
void admsn_cancel();
void admsn_enq();
void fee_payment();
void detail();
void general();
void student_detail();
void parent_detail();

#endif
