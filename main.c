#include "student.h"

int main() {
  setlocale(LC_ALL, "Rus");

  int stud_num = 5;
   
  student *std[20];
  *std[0] = student_def;
  printf(std[0]);
  Ввод студентов

  for (int i = stud_num; i < 20; i++){
    char answer = 'y';
    printf("Вы хотите ввести информацию о студенте #%d? \nВведите 'y' для да, 'n' для нет: ", i+1);
    scanf("%c", &answer);
    
    if (answer == 'y'){
      std[i] = (struct student *)malloc(sizeof(struct student));
      input_student(std[i], 0, 0);
    }
    else
    {
      break;
    }
  }


  return (0);
} 