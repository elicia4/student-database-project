#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <time.h>

typedef struct { // Структура даты
  int day;
  int month;
  int year;
} date;

typedef struct full_name{ // Структура имени (имя-отчество-фамилия)
  char first_name[50];
  char middle_name[50];
  char last_name[50];
} full_name;

typedef struct { // Структура зачета, дата
  date zachet_date;
} zachet;

typedef struct { // Структура экзамена, дата + оценка
  date exam_date;
  int grade;
} exam;

typedef struct student{ // Структура студента: имя, день рождения, 10 зачетов, 5 экзаменов
  full_name name[50]; // ???
  date birthday;
  zachet zacheti[10];
  exam exams[5];
  // int id;
} student;

void input_student(student* std);
void print_student(student* std);
void edit_student(student* std);
int is_student(student *std, full_name name);
void find_fio_student(student *std[], int stud_num);
void print_database(char* file_name);
void output_database(student *std[], int stud_num);
void get_database(char* file_name, student *std[], int *stud_num);
void print_db_to_file(char *file_name, student *std[], int stud_num);
void free_struct(student *std[], int stud_num); 
void del_student(student *std);
void find_age_student(student *std[], int stud_num);