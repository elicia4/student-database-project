#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

typedef struct { // Структура даты
  int day;
  int month;
  int year;
} date;

typedef struct { // Структура имени (имя-отчество-фамилия)
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

typedef struct student{ // Структура студента: имя, день рождения, 10 зачетов, 5 экзаменов, ссылка на следующего студента
  full_name name[50];
  date birthday;
  zachet zacheti[10];
  exam exams[5];
  struct student* next;
} student;

void input_student(student* std, int zach_num, int ex_num);
void print_student(student* std);