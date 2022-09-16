#include "student.h"

void edit_student(student* std){ // Редактирование студента
  char decision = 'y';
  do {
    char opt = 'a';
    printf("Что вы хотите отредактировать?\n\"f\" - фамилию, \"i\" - имя, \"o\" - отчество,\n\"d\" - дату рождения, \"z\" - зачет, \"e\" - экзамен.\n");
    scanf(" %c", &opt);
    if (opt == 'f')
    {
      printf("Введите фамилию студента: ");
      scanf("%s", std->name->last_name);
    }
    else if (opt == 'i')
    {
      printf("\nВведите имя студента: ");
      scanf("%s", std->name->first_name);
    }
    else if (opt == 'o')
    {
      printf("Введите отчество студента: ");
      scanf("%s", std->name->middle_name);
    }
    else if (opt == 'd')
    {
      printf("Введите дату рождения студента (например: \"30 01 2003\"): ");
      scanf("%d %d %d", &std->birthday.day, &std->birthday.month, &std->birthday.year);
    }
    else if (opt == 'z')
    {
      printf("Какой конкретно зачет Вы бы хотели отредактировать? Введите номер: ");
      int num = 0;
      scanf("%d", &num);
      printf("Введите дату сдачи зачета #%d:\n", num);
      num -= 1;
      scanf("%d %d %d", \
          &std->zacheti[num].zachet_date.day, \
          &std->zacheti[num].zachet_date.month, \
          &std->zacheti[num].zachet_date.year \
      );
    }
    else if (opt == 'e')
    {
      printf("Какой конкретно экзамен Вы бы хотели отредактировать? Введите номер: ");
      int num = 0;
      scanf("%d", &num);
      printf("Введите оценку и дату сдачи экзамена #%d:\n", num);
      num -= 1;
      scanf("%d %d %d %d", 
          &std->exams[num].grade, \
          &std->exams[num].exam_date.day, \
          &std->exams[num].exam_date.month, \
          &std->exams[num].exam_date.year \
      );
    }
    else
    {
      printf("Неверный формат ввода");
    }

    printf("'q' - выйти из редактора, 'y' - продолжить.\n");
    scanf(" %c", &decision);
  } while (decision != 'q');
}

void print_student(student* std){ // Вывод информации о конкретном студенте
  printf("\nФИО: %s %s %s\nДата рождения: %d/%d/%d\n", 
    std->name->first_name,
    std->name->middle_name,
    std->name->last_name,
    std->birthday.day, 
    std->birthday.month, 
    std->birthday.year
  );
  for (int i = 0; i < 10; i++) {
    if (std->zacheti[i].zachet_date.day && std->zacheti[i].zachet_date.month && std->zacheti[i].zachet_date.year)
      printf("Зачет #%d: %d/%d/%d\n",
        i+1, 
        std->zacheti[i].zachet_date.day,
        std->zacheti[i].zachet_date.month,
        std->zacheti[i].zachet_date.year
      );
  }
  for (int i = 0; i < 5; i++) {
    if (std->exams[i].grade && std->exams[i].exam_date.day && std->exams[i].exam_date.month && std->exams[i].exam_date.year)
      printf("Экзамен #%d: Оценка - %d, %d/%d/%d\n",
        i+1, 
        std->exams[i].grade,
        std->exams[i].exam_date.day,
        std->exams[i].exam_date.month,
        std->exams[i].exam_date.year
      );
  }
}

void input_student(student* std){ // Ввод информации о студенте
  printf("\nВведите имя студента: ");
  scanf("%s", std->name->first_name);
  printf("Введите отчество студента: ");
  scanf("%s", std->name->middle_name);
  printf("Введите фамилию студента: ");
  scanf("%s", std->name->last_name);
  printf("Введите дату рождения студента (например: \"30 01 2003\"): ");
  scanf("%d %d %d", &std->birthday.day, &std->birthday.month, &std->birthday.year);
  // Ввод дат зачетов с клавиатуры
  printf("\nВведите по очереди даты сданных зачетов;\nПример - \"05 03 2015\", '0 0 0' чтобы завершить\n");
  for (int i = 0; i < 10; i++)
  {
    int day, month, year;
    printf("Введите дату сдачи зачета #%d:\n", i+1);
    scanf("%d %d %d", &day, &month, &year);
    if (day && month && year)
    {
      std->zacheti[i].zachet_date.day = day;
      std->zacheti[i].zachet_date.month = month;
      std->zacheti[i].zachet_date.year = year;
    }
    else
    {
      break;
    }
  }
  // Дальше - ввод оценок и дат экзаменов с клавиатуры
  printf("\nВведите по очереди оценки и даты сданных экзаменов;\nПример - \"5 05 03 2015\", '0 0 0 0' чтобы завершить");
  for (int i = 0; i < 5; i++)
  {
    int day, month, year, grade;
    printf("\nВведите оценку и дату сдачи экзамена #%d:\n", i+1);
    scanf("%d %d %d %d", &grade, &day, &month, &year);
    if (day && month && year && grade)
    {
      std->exams[i].grade = grade;
      std->exams[i].exam_date.day = day;
      std->exams[i].exam_date.month = month;
      std->exams[i].exam_date.year = year;
    }
    else
      break;
  }

}

int is_student(student *std, full_name name){ // Проверяет, тот ли конкретно это человек по ФИО
  int res = 0;
  if (!strcmp(std->name->first_name, name.first_name) && !strcmp(std->name->middle_name, name.middle_name) && !strcmp(std->name->last_name, name.last_name))
  {
    printf("\nСтудент найден!\n");
    print_student(std);
    res = 1;
  }
  return(res);
}

void find_fio_student(student *std[], int stud_num){ // Проверка по ФИО всех студентов
  full_name std_name;
  printf("\nВведите имя студента: ");
  scanf("%s", std_name.first_name);
  printf("Введите отчество студента: ");
  scanf("%s", std_name.middle_name);
  printf("Введите фамилию студента: ");
  scanf("%s", std_name.last_name);
  int res = 0;
  for (int i = 0; i < stud_num; i++)
  {
    if ((res = is_student(std[i], std_name)) == 1)
    {
      printf("\nНомер студента - %d\n", i+1);
      break;
    }
  }
  if (res == 0)
  printf("Студента с таким ФИО нет в базе данных.\n");
}

void find_age_student(student *std[], int stud_num){ // Поиск по возрасту всех студентов
  int stud_age = 0;
  time_t s, val = 1;
  struct tm* current_time;
    
  s = time(NULL);
  current_time = localtime(&s);
  int current_day = current_time->tm_mday; // так работает
  int current_month = current_time->tm_mon + 1; // так работает
  int current_year = current_time->tm_year + 1900; // так работает
  int year_diff = 0;
  int month_diff = 0;
  int day_diff = 0;
  printf("Введите возраст студента: \n"); 
  scanf("%d", &stud_age);
  int res = 0;
  for (int i = 0; i < stud_num; i++)
  {
    year_diff = current_year - std[i]->birthday.year;
    month_diff = current_month - std[i]->birthday.month;
    day_diff = current_day - std[i]->birthday.day;
    if (year_diff > stud_age)
    {
      printf("Студент #%d подходит!!!\n", i + 1);
      print_student(std[i]);
      res++;
    } else if (year_diff == stud_age) {
      if (month_diff > 0) {
        printf("Студент #%d подходит!!!\n", i + 1);
        print_student(std[i]);
        res++;
      } else if (month_diff == 0) {
        if (day_diff >= 0){
          printf("Студент #%d подходит!!!\n", i + 1);
          print_student(std[i]);
          res++;
        }
      }
    } 
  }
  if (res == 0)
  printf("Студента с таким возрастом нет в базе данных.\n");
}

void output_database(student *std[], int stud_num){ // Вывод всей базы данных
  for (int i = 0; i < stud_num; i++)
  {
    printf("\nНомер студента - %d", i+1);
    print_student(std[i]);
  }
}

void print_database(char* file_name){ // Печать (на принтере) всей базы данных
  char print_command[150] = "notepad /p ";

  size_t file_name_size = strlen(file_name);
  size_t command_size = file_name_size + strlen(print_command);

  strcat(print_command, file_name);
  //system(print_command); - эта команда печатает, убрать коммент когда печатать
  printf("%s\n", print_command); // демонстрация команды
}

void get_database(char* file_name, student *std[], int *stud_num){ // Перенос всей базы данных из файла в массив
  FILE *db;
  db = fopen(file_name, "r");

  if (!db){
      printf("Проблема с чтением файла.\n");
      exit(0);
  }

  int num = 0;
  fscanf(db, "%d", &num);
  *stud_num = num;

  for (int i = 0; i < num; i++)
  {
    std[i] = (struct student *)malloc(sizeof(struct student));
    fscanf(db, "%s %s %s\n", std[i]->name->first_name, std[i]->name->middle_name, std[i]->name->last_name); // this is working

    fscanf(db, "%d %d %d\n", &std[i]->birthday.day, &std[i]->birthday.month, &std[i]->birthday.year); // this is working

    char text_zachet[50]; // bullshit
    fscanf(db, "%s\n", text_zachet); // bullshit

    for (int j = 0; j < 10; j++)
    {
      fscanf(db, "%d %d %d\n", &std[i]->zacheti[j].zachet_date.day, &std[i]->zacheti[j].zachet_date.month, &std[i]->zacheti[j].zachet_date.year);
    }

    char text_exam[50]; // bullshit
    fscanf(db, "%s\n", text_exam); // bullshit
    for (int j = 0; j < 5; j++)
    {
      fscanf(db, "%d %d %d %d\n",  &std[i]->exams[j].grade, &std[i]->exams[j].exam_date.day, &std[i]->exams[j].exam_date.month, &std[i]->exams[j].exam_date.year);
    }
  }

  fclose(db);
}

void print_db_to_file(char *file_name, student *std[], int stud_num){ // Перенос всей базы данных из массива в файл
  FILE *db;
  // Очистка файла
  db = fopen(file_name, "w");
  if (!db){
      printf("Проблема с чтением файла.\n");
      exit(0);
  }
  fclose(db);
  //Открываем очищенный файл
  db = fopen(file_name, "a");
  if (!db){
      printf("Проблема с чтением файла.\n");
      exit(0);
  }
  fprintf(db, "%d\n", stud_num);
  for (int i = 0; i < stud_num; i++)
  {
    fprintf(db, "%s %s %s\n", std[i]->name->first_name, std[i]->name->middle_name, std[i]->name->last_name);
    fprintf(db, "%d %d %d\n", std[i]->birthday.day, std[i]->birthday.month, std[i]->birthday.year);
    fprintf(db, "Зачеты:\n");
    for (int j = 0; j < 10; j++) {
      if (std[i]->zacheti[j].zachet_date.day != 0)
      fprintf(db, "%d %d %d\n", std[i]->zacheti[j].zachet_date.day, std[i]->zacheti[j].zachet_date.month, std[i]->zacheti[j].zachet_date.year);
    }
    fprintf(db, "Экзамены:\n");
    for (int j = 0; j < 5; j++) {
      if (std[i]->exams[j].exam_date.day != 0)
      fprintf(db, "%d %d %d %d\n", std[i]->exams[j].grade, std[i]->exams[j].exam_date.day, std[i]->exams[j].exam_date.month, std[i]->exams[j].exam_date.year);
    }
  }
  fclose(db);
}

void del_student(student *std){ // Удалить информацию о студенте
  strncpy(std->name->first_name, "", sizeof(std->name->first_name));
  strncpy(std->name->middle_name, "", sizeof(std->name->middle_name));
  strncpy(std->name->last_name, "", sizeof(std->name->last_name));
  std->birthday.day = 0;
  std->birthday.month = 0;
  std->birthday.year = 0;

  for (int i = 0; i < 10; i++)
  {
    std->zacheti[i].zachet_date.day = 0;
    std->zacheti[i].zachet_date.month = 0;
    std->zacheti[i].zachet_date.year = 0;
  }

  for (int i = 0; i < 5; i++)
  {
    std->exams[i].grade = 0;
    std->exams[i].exam_date.day = 0;
    std->exams[i].exam_date.month = 0;
    std->exams[i].exam_date.year = 0;
  }
}

void free_struct(student *std[], int stud_num){ // Освобождение всей памяти
  for (int i = 0; i < stud_num; i++){
    if (std[i] != NULL)
    {
      printf("ran %d\n", i);
      free(std[i]);
    }
  }
}