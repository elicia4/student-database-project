#include "student.h"

// FUNCTION LIST: 
// void input_student(student* std);
// void print_student(student* std);
// void init_student(student* std);
// void edit_student(student* std);
// void find_fio_student(student *std[], int stud_num);

int main() {
  setlocale(LC_ALL, "Rus");

  student *std[20];
  int stud_num = 0;
  char choice = '0';
  printf("Открыть существующую базу данных(1)\nили создать свою?(2) \nВведите 1 или 2: ");
  scanf(" %c", &choice);
  if (choice == '2')
  {
    stud_num = 0;
    for (int i = 0; i < 20; i++){ // Ввод студентов в базу данных
      char answer = 'y';
      printf("Вы хотите ввести информацию о студенте #%d? \nВведите 'y' для да, 'n' для нет: ", i+1);
      scanf(" %c", &answer);
      if (answer == 'y'){
        std[i] = (struct student *)malloc(sizeof(struct student));
        input_student(std[i]);
        stud_num++;
      }
      else
      {
        break;
      }
    }
  }
  // if (!stud_num) return (0);
  // choice = '';
  // while (choice != 'q'){
  //   printf("Что бы вы хотели сделать?\n\tВвести студента в базу данных - 'e'\n\tИзменить информацию о студенте - 'c'\n\tУдалить информацию о студенте - 'd'\n\tНайти студента по ФИО - 'f'\n\tНайти студенту по возрасту - 'g'\n\tВывести на экран всю базу данных - 'a'\nВывести на печатающее устройство всей информации из базы данных - 'p'\nВыйти из программы - 'q'\n");
  // }

  // print_database(file_name);
  output_database(std, stud_num);

  return (0);
} 