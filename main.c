#include "student.h"

int main() {
  setlocale(LC_ALL, "Rus");

  student *std[20];
  int stud_num = 20;
  std[0] = (struct student *)malloc(sizeof(struct student));
  input_student(std[0], 0, 0);
  edit_student(std[0]);
  print_student(std[0]);
  // for (int i = 0; i < stud_num; i++){
  //   char answer = 'y';
  //   printf("Вы хотите ввести информацию о студенте #%d? \nВведите 'y' для да, 'n' для нет: ", i+1);
  //   scanf("%c", &answer);
    
  //   if (answer == 'y'){
  //     std[i] = (struct student *)malloc(sizeof(struct student));
  //     input_student(std[i], 0, 0);
  //   }
  //   else
  //   {
  //     break;
  //   }
  // }


  return (0);
} 