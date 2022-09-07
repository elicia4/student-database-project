#include "student.h"

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

void input_student(student* std, int zach_num, int ex_num){ // std - указатель на конкретного студента, zach_num - количество уже сданных зачетов
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