#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Answers:
Physics: 1-B, 2-D, 3-B, 4-A, 5-C.
Math: 1-A, 2-B, 3-D, 4-A, 5-D.
Mixed: 1-A, 2-B, 3-B, 4-C, 5-C.
*/

#define UZBEK 1
#define RUSSIAN 2
#define ENGLISH 3

#define PHYSICS 1
#define MATHEMATICS 2
#define MIXED 3
#define GO_BACK 4

typedef struct
{
  char name[50];
  char surname[50];
  int language;
  int score;
} User;

User user = {0};

const char *welcome_messages[3] = {
    "==========================================================\n\t\t\tHUSH KELIBSIZ!!!\n==========================================================",
    "==========================================================\n\t\t\tДобро пожаловать!!!\n==========================================================",
    "===========================================================\n\t\t\tWELCOME!!!\n==========================================================="};

const char *menu_messages[3] = {
    "\t\t\tViktorina Savollari\n\t\t\tIndekslarda ifodalang:\n============================================================\n| 1-Fizika;\n| 2-Matematika;\n| 3-Aralash qiziqarli savollar;\n| 4-Ortga qaytish;\n============================================================\n==>>",
    "\t\t\tТестовые вопросы\n\t\t\tУкажите в индексах:\n============================================================\n| 1-Физика;\n| 2-Математика;\n| 3-Интересные вопросы;\n| 4-Вернуться назад\n============================================================\n==>>",
    "\t\t\tTest Questions\n\t\t\tExpress in indexes:\n============================================================\n| 1-Physics;\n| 2-Mathematics;\n| 3-Interesting questions;\n| 4-Go back;\n============================================================\n==>>"};

const char *subject_headers[3][3] = {
    {"Fizika fanidan savollar:", "Matematika fanidan savollar:", "Aralash qiziqarli savollar:"},
    {"Вопросы по физике:", "Вопросы по математике:", "Интересные вопросы:"},
    {"Questions in physics:", "Questions in Mathematics:", "Interesting questions:"}};

const char *input_prompts[3][3] = {
    {"Ismingiz: ", "Familyangiz: ", "Javob: "},
    {"Имя: ", "Фамилия: ", "Ответ: "},
    {"First name: ", "Last name: ", "Answer: "}};

const char *question_labels[3] = {
    "Savol", "Вопрос", "Question"};

const char *correct_answers[3] = {
    "Javob to'g'ri", "Ответ правильный", "The answer is correct."};

const char *wrong_answers[3] = {
    "Javob noto'g'ri", "Неправильный ответ", "Wrong answer"};

const char *score_messages[3] = {
    "%s %s siz %d ball yig'diz\n", "%s %s вы набрали %d очков\n", "%s %s you scored %d points\n"};

const char *file_names[3][3] = {
    {"Fizika_uz.txt", "Matematika_uz.txt", "Aralash_uz.txt"},
    {"Fizika_ru.txt", "Matematika_ru.txt", "Aralash_ru.txt"},
    {"Fizika_eng.txt", "Matematika_eng.txt", "Aralash_eng.txt"}};

const char correct_answer_keys[3][5] = {
    {'B', 'D', 'B', 'A', 'C'}, // Physics
    {'A', 'B', 'D', 'A', 'D'}, // Mathematics
    {'A', 'B', 'B', 'C', 'C'}  // Mixed
};

int select_language(void);
void display_welcome(void);
void get_user_info(void);
int display_menu(void);
void display_subject_header(int subject);
int run_quiz(int subject);
void check_answer(char user_answer, char correct_answer);
void display_final_score(void);
void process_question_file(const char *filename, int subject);

int main()
{
  int choice;

  while (1)
  {
    user.language = select_language();

    display_welcome();
    get_user_info();

    choice = display_menu();

    if (choice == GO_BACK)
    {
      continue;
    }
    else if (choice >= PHYSICS && choice <= MIXED)
    {
      display_subject_header(choice);
      run_quiz(choice);
      display_final_score();
      break;
    }
    else
    {
      break;
    }
  }
  return 0;
}

int select_language(void)
{
  int lang;
  printf("O'zbek tili uchun 1 ni bosing\n");
  printf("Нажмите 2 для русского языка\n");
  printf("Press 3 for English\n");
  printf("==>> ");
  scanf("%d", &lang);

  if (lang < UZBEK || lang > ENGLISH)
  {
    lang = UZBEK;
  }

  return lang;
}

void display_welcome(void)
{
  printf("%s\n", welcome_messages[user.language - 1]);
}

void get_user_info(void)
{
  printf("%s", input_prompts[user.language - 1][0]);
  scanf("%s", user.name);
  printf("%s", input_prompts[user.language - 1][1]);
  scanf("%s", user.surname);
  printf("\n\n");
}

int display_menu(void)
{
  int choice;
  printf("%s", menu_messages[user.language - 1]);
  scanf("%d", &choice);
  return choice;
}

void display_subject_header(int subject)
{
  printf("\n\n\t\t\t%s\n", subject_headers[user.language - 1][subject - 1]);
  printf("-----------------------------------------------------------\n");
}

int run_quiz(int subject)
{
  const char *filename = file_names[user.language - 1][subject - 1];
  user.score = 0;

  process_question_file(filename, subject - 1);
  return 0;
}

void process_question_file(const char *filename, int subject)
{
  FILE *fp = fopen(filename, "r");
  if (!fp)
  {
    printf("Error opening file: %s\n", filename);
    return;
  }

  char line[400];
  int question_num = 1;
  int question_index = 0;

  while (fgets(line, sizeof(line), fp) != NULL && question_index < 5)
  {
    printf("\n%d-%s:\n", question_num, question_labels[user.language - 1]);
    printf("-----------------------------------------------------------\n");
    question_num++;

    int len = strlen(line);
    for (int i = 0; i < len; i++)
    {
      if (line[i] == '\\' && i + 1 < len && line[i + 1] == 'n')
      {
        printf("\n");
        i++;
      }
      else
      {
        printf("%c", line[i]);
      }
    }

    char user_answer;
    printf("\n%s", input_prompts[user.language - 1][2]);
    scanf(" %c", &user_answer);

    check_answer(user_answer, correct_answer_keys[subject][question_index]);

    question_index++;
  }

  fclose(fp);
}

void check_answer(char user_answer, char correct_answer)
{
  if (user_answer >= 'a' && user_answer <= 'z')
  {
    user_answer = user_answer - 'a' + 'A';
  }

  if (user_answer == correct_answer)
  {
    printf("%s\n\n", correct_answers[user.language - 1]);
    user.score += 20;
  }
  else
  {
    printf("%s\n\n", wrong_answers[user.language - 1]);
  }
}

void display_final_score(void)
{
  printf(score_messages[user.language - 1], user.name, user.surname, user.score);
}
