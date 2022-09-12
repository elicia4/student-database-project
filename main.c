#include "student.h"

int main() {
  setlocale(LC_ALL, "Rus");

  student *std[20];
  int stud_num = 0;
  char choice;
  char file_name[50];
  printf("Открыть существующую базу данных(1) или создать свою(2)?\nВведите 1 или 2: ");
  scanf(" %c", &choice);
  if (choice == '1')
  {
    printf("Введите название нужной БД: \n");
    scanf("%s", file_name);
    get_database(file_name, std, &stud_num);
  }
  else if (choice == '2')
  {
    printf("Введите название Вашей БД: \n");
    scanf("%s", file_name);
    FILE *fp = NULL;
    fp = fopen(file_name, "a");
    if (!fp)
    {
      printf("Такого файла не существует, возможно, у вас проблемы с жестким диском.\n");
      exit(1);
    }
    stud_num = 0;
    for (int i = 0; i < 20; i++){ // Ввод студентов в базу данных
      char answer = 'y';
      printf("Вы хотите ввести информацию о еще одном студенте(#%d)? \nВведите 'y' для да, 'n' для нет: ", i+1);
      scanf(" %c", &answer);
      if (answer == 'y'){
        if (!(std[i] = (struct student *)malloc(sizeof(struct student))))
        {
          printf("Проблемы с памятью.\n");
          exit(1);
        }
        input_student(std[i]);
        stud_num++;
        print_db_to_file(file_name, std, stud_num);
      }
      else
      {
        break;
      }
    }
    fclose(fp);
  }

  if (stud_num == 0) 
  {
    exit(0);
  }
  choice = '\0';
  while (choice != 'q'){
    printf("Что бы вы хотели сделать?\n\
    \tВвести студента в базу данных - 'e'\n\
    \tИзменить информацию о студенте - 'c'\n\
    \tУдалить информацию о студенте - 'd'\n\
    \tНайти студента по ФИО - 'f'\n\
    \tНайти студенту по возрасту - 'g'\n\
    \tВывести на экран всю базу данных - 'a'\n\
    \tВывести на печатающее устройство всей информации из базы данных - 'p'\n\
    \tВыйти из программы - 'q'\n"); 
    scanf(" %c", &choice);
    if(choice == 'e') { // Ввести студента в базу данных
      if (stud_num < 20) {
        if(!(std[stud_num] = (struct student *)malloc(sizeof(struct student))))
        {
          printf("Проблемы с памятью.\n");
          exit(1);
        }
        printf("%d\n", stud_num);
        input_student(std[stud_num]);
        stud_num++;
      }
      else {
        printf("Лимит студентов достигнут.\n");
      }
    } else if (choice == 'c') { // Изменить информацию о студенте
      output_database(std, stud_num);
      printf("Сверху выведена информация о всех студентах\nИнформацию какого конкретно студента вы бы хотели отредактировать?\n");
      int std_id = 0;
      scanf("%d", &std_id);
      std_id--;
      edit_student(std[std_id]);
    } else if (choice == 'd') { // Удалить информацию о студенте
      output_database(std, stud_num);
      printf("Сверху выведена информация о всех студентах\nИнформацию какого конкретно студента Вы бы хотели удалить?\n");
      int std_id = 0;
      scanf("%d", &std_id);
      std_id--;
      del_student(std[std_id]);
    } else if (choice == 'f') { // Найти по ФИО
      find_fio_student(std, stud_num);
    } else if (choice == 'g') { // Найти по возрасту
      find_age_student(std, stud_num);
    } else if (choice == 'a') { // Вывести всех
      output_database(std, stud_num);
    } else if (choice == 'p') { // Распечатать всех
      print_database(file_name);
    }
    print_db_to_file(file_name, std, stud_num);
  }

  free_struct(std, stud_num);
  output_database(std, stud_num);
  return (0);
} 