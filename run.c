#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//Mirxoliqov Sayfulla
/*Test javoblari
Fizikaniki: 1-B, 2-D, 3-B, 4-A, 5-C.
Matematikaniki: 1-A, 2-B, 3-D, 4-A, 5-D.
Aralashniki: 1-A, 2-B, 3-B, 4-C, 5-C.
*/
char tx[200][200][400]={{"                      Viktorina Savollari   \n                     Indekslarda ifodalang:\n============================================================\n| 1-Fizika;\n| 2-Matematika;\n| 3-Aralash qiziqarli savollar;\n| 4-Ortga qaytish;\n============================================================\n==>>"},{"                      Тестовые вопросы   \n                     Укажите в индексах:\n============================================================\n| 1-Физика;\n| 2-Математика;\n| 3-Интересные вопросы;\n| 4-Вернуться назад\n============================================================\n==>>"},{"                      Test Questions   \n                     Express in indexes:\n============================================================\n| 1-Physics;\n| 2-Mathematics;\n| 3-Interesting questions;\n| 4-Go back;\n============================================================\n==>>"}};
char sh[3][3][200]={{"==========================================================\n                       HUSH KELIBSIZ!!!                   \n=========================================================="},{"==========================================================\n                       Добро пожаловать!!!                  \n=========================================================="},{"===========================================================\n                       WELCOME!!!                  \n==========================================================="}};
char ara_uz_ru[9][60]={{"Aralash qiziqarli savollar:\n"},{"Интересные вопросы:"},{"Fizika fanidan savollar:\n"},{"Вопросы по физике:\n"},{"Matematika fanidan savollar:\n"},{"Вопросы по математике:\n"},{"Questions in physics:"},{"Questions in Mathematics:\n"},{"Interesting questions:"}};
char chiziq[60]={"-----------------------------------------------------------\n"};
char ism[20],familya[20];
int til=0,ball=0,tanladim=0;
int i, u = 1, h = 0;
char javob[4];
void Modul_A(){
  if(til==1){
    if(javob[h] == 'A' || javob[h]=='a'){
    printf("Javob to'g'ri\n\n");
    ball=ball+20;
    }else{
      printf("Javob noto'g'ri\n\n");
    }
  }else if(til==2){
    if(javob[h] == 'A' || javob[h]=='a'){
    printf("Ответ правильный\n\n");
    ball=ball+20;
    }else{
      printf("Неправильный ответ\n\n");
    }
  }else if(til==3){
    if(javob[h] == 'A' || javob[h]=='a'){
    printf("The answer is correct.\n\n");
    ball=ball+20;
    }else{
      printf("Wrong answer\n\n");
    }
  }
}
void Modul_B(){
  if(til==1){
    if(javob[h]=='B' || javob[h]=='b'){
        printf("Javob to'g'ri\n\n");
        ball=ball+20;
    }else{
        printf("Javob noto'g'ri\n\n");
    }
  }else if(til==2){
    if(javob[h] == 'B' || javob[h]=='b'){
    printf("Ответ правильный\n\n");
    ball=ball+20;
    }else{
      printf("Неправильный ответ\n\n");
    }
  }else if(til==3){
    if(javob[h] == 'B' || javob[h]=='b'){
    printf("The answer is correct.\n\n");
    ball=ball+20;
    }else{
      printf("Wrong answer\n\n");
    }
  }
}
void Modul_C(){
  if(til==1){
    if(javob[h]=='C' || javob[h]=='c'){
        printf("Javob to'g'ri\n\n");
        ball=ball+20;
    }else{
        printf("Javob noto'g'ri\n\n");
    }
  }else if(til==2){
    if(javob[h] == 'C' || javob[h]=='c'){
    printf("Ответ правильный\n\n");
    ball=ball+20;
    }else{
      printf("Неправильный ответ\n\n");
    }
  }else if(til==3){
    if(javob[h] == 'C' || javob[h]=='c'){
    printf("The answer is correct.\n\n");
    ball=ball+20;
    }else{
      printf("Wrong answer\n\n");
    }
  }
}
void Modul_D(){
  if(til==1){
    if(javob[h]=='D' || javob[h]=='d'){
        printf("Javob to'g'ri\n\n");
        ball=ball+20;
    }else{
        printf("Javob noto'g'ri\n\n");
    }
  }else if(til==2){
    if(javob[h] == 'D' || javob[h]=='d'){
    printf("Ответ правильный\n\n");
    ball=ball+20;
    }else{
      printf("Неправильный ответ\n\n");
    }
  }else if(til==3){
    if(javob[h] == 'D' || javob[h]=='d'){
    printf("The answer is correct.\n\n");
    ball=ball+20;
    }else{
      printf("Wrong answer\n\n");
    }
  }
}
int name(){
  if(til==1){
    printf("Ismingiz: ");
    scanf("%s",ism);
    printf("Familyangiz: ");
    scanf("%s",familya);
    printf("\n\n");
  }else if (til==2){
    printf("Имя: ");
    scanf("%s",ism);
    printf("Фамилия: ");
    scanf("%s",familya);
    printf("\n\n");
  }else if(til==3){
    printf("First name: ");
    scanf("%s",ism);
    printf("Last name: ");
    scanf("%s",familya);
    printf("\n\n");
  }
  return 0;
}
int Aralash_uz_ru(){
  FILE *fp;
  if (til == 1){
    fp = fopen("Aralash_uz.txt", "r");
    char ch[256];
    while (fgets(ch, 256, fp) != NULL){
      printf("%d-Savol: \n", u);
      u++;
      int len = strlen(ch);
      for (i = 0; i < len; i++){
        if (ch[i] == '\\'){
          i++;
          if (ch[i] == 'n'){
            printf("\n");
            continue;
          }
        }
        printf("%c", ch[i]);
      }
      printf("Javob: ");
      scanf("%s", &javob[h]);
      if(h==0){
          Modul_A();
      }else if(h==1){
          Modul_B();
      }else if(h==2){
          Modul_B();
      }else if(h==3){
          Modul_C();
      }else if(h==4){
          Modul_C();
      }
      h++;
    }
    fclose(fp);
  }
  else if (til == 2){
    fp = fopen("Aralash_ru.txt", "r");
    char ch[350];
    while (fgets(ch, 350, fp) != NULL){
      printf("%d-Вопрос: \n", u);
      u++;
      int len = strlen(ch);
      for (i = 0; i < len; i++){
        if (ch[i] == '\\'){
          i++;
          if (ch[i] == 'n'){
            printf("\n");
            continue;
          }
        }
        printf("%c", ch[i]);
      }
      printf("Ответ: ");
      scanf("%s", &javob[h]);
      if(h==0){
          Modul_A();
      }else if(h==1){
          Modul_B();
      }else if(h==2){
          Modul_B();
      }else if(h==3){
          Modul_C();
      }else if(h==4){
          Modul_C();
      }
      h++;
    }
    fclose(fp);
  }else if(til==3){
    fp = fopen("Aralash_eng.txt", "r");
    char ch[350];
    while (fgets(ch, 350, fp) != NULL){
      printf("%d-Question: \n", u);
      u++;
      int len = strlen(ch);
      for (i = 0; i < len; i++){
        if (ch[i] == '\\'){
          i++;
          if (ch[i] == 'n'){
            printf("\n");
            continue;
          }
        }
        printf("%c", ch[i]);
      }
      printf("Answer: ");
      scanf("%s", &javob[h]);
      if(h==0){
          Modul_A();
      }else if(h==1){
          Modul_B();
      }else if(h==2){
          Modul_B();
      }else if(h==3){
          Modul_C();
      }else if(h==4){
          Modul_C();
      }
      h++;
    }
    fclose(fp);
  }
  else{
    return 0;
  }
  return 0;
}
int Fizika_uz_ru(){
  FILE *fp;
  if (til == 1){
    fp = fopen("Fizika_uz.txt", "r");
    char ch[256];
    while (fgets(ch, 256, fp) != NULL){
      printf("%d-Savol: \n", u);
      u++;
      int len = strlen(ch);
      for (i = 0; i < len; i++){
        if (ch[i] == '\\'){
          i++;
          if (ch[i] == 'n'){
            printf("\n");
            continue;
          }
        }
        printf("%c", ch[i]);
      }
      printf("Javob: ");
      scanf("%s", &javob[h]);
      if(h==0){
          Modul_B();
      }else if(h==1){
          Modul_D();
      }else if(h==2){
          Modul_B();
      }else if(h==3){
          Modul_A();
      }else if(h==4){
          Modul_C();
      }
      h++;
    }
    fclose(fp);
  }
  else if (til == 2){
    fp = fopen("Fizika_ru.txt", "r");
    char ch[350];
    while (fgets(ch, 350, fp) != NULL){
      printf("%d-Вопрос: \n", u);
      u++;
      int len = strlen(ch);
      for (i = 0; i < len; i++){
        if (ch[i] == '\\'){
          i++;
          if (ch[i] == 'n'){
            printf("\n");
            continue;
          }
        }
        printf("%c", ch[i]);
      }
      printf("Ответ: ");
      scanf("%s", &javob[h]);
      if(h==0){
          Modul_B();
      }else if(h==1){
          Modul_D();
      }else if(h==2){
          Modul_B();
      }else if(h==3){
          Modul_A();
      }else if(h==4){
          Modul_C();
      }
      h++;
    }
    fclose(fp);
  }else if (til==3){
    fp = fopen("Fizika_eng.txt", "r");
    char ch[350];
    while (fgets(ch, 350, fp) != NULL){
      printf("%d-Question: \n", u);
      u++;
      int len = strlen(ch);
      for (i = 0; i < len; i++){
        if (ch[i] == '\\'){
          i++;
          if (ch[i] == 'n'){
            printf("\n");
            continue;
          }
        }
        printf("%c", ch[i]);
      }
      printf("Answer: ");
      scanf("%s", &javob[h]);
      if(h==0){
          Modul_B();
      }else if(h==1){
          Modul_D();
      }else if(h==2){
          Modul_B();
      }else if(h==3){
          Modul_A();
      }else if(h==4){
          Modul_C();
      }
      h++;
    }
    fclose(fp);
  }
  else{
    return 0;
  }
  return 0;
}
int Matematika_uz_ru(){
  FILE *fp;
  if (til == 1){
    fp = fopen("Matematika_uz.txt", "r");
    char ch[256];
    while (fgets(ch, 256, fp) != NULL){
      printf("%d-Savol: \n", u);
      u++;
      int len = strlen(ch);
      for (i = 0; i < len; i++){
        if (ch[i] == '\\'){
          i++;
          if (ch[i] == 'n'){
            printf("\n");
            continue;
          }
        }
        printf("%c", ch[i]);
      }
      printf("Javob: ");
      scanf("%s", &javob[h]);
      if(h==0){
          Modul_A();
      }else if(h==1){
          Modul_B();
      }else if(h==2){
          Modul_D();
      }else if(h==3){
          Modul_A();
      }else if(h==4){
          Modul_D();
      }
      h++;
    }
    fclose(fp);
  }else if (til == 2){
    fp = fopen("Matematika_ru.txt", "r");
    char ch[350];
    while (fgets(ch, 350, fp) != NULL){
      printf("%d-Вопрос: \n", u);
      u++;
      int len = strlen(ch);
      for (i = 0; i < len; i++){
        if (ch[i] == '\\'){
          i++;
          if (ch[i] == 'n'){
            printf("\n");
            continue;
          }
        }
        printf("%c", ch[i]);
      }
      printf("Ответ: ");
      scanf("%s", &javob[h]);
      if(h==0){
          Modul_A();
      }else if(h==1){
          Modul_B();
      }else if(h==2){
          Modul_D();
      }else if(h==3){
          Modul_A();
      }else if(h==4){
          Modul_D();
      }
      h++;
    }
    fclose(fp);
  }else if(til==3){
    fp = fopen("Matematika_eng.txt", "r");
    char ch[350];
    while (fgets(ch, 350, fp) != NULL){
      printf("%d-Question: \n", u);
      u++;
      int len = strlen(ch);
      for (i = 0; i < len; i++){
        if (ch[i] == '\\'){
          i++;
          if (ch[i] == 'n'){
            printf("\n");
            continue;
          }
        }
        printf("%c", ch[i]);
      }
      printf("Answer: ");
      scanf("%s", &javob[h]);
      if(h==0){
          Modul_A();
      }else if(h==1){
          Modul_B();
      }else if(h==2){
          Modul_D();
      }else if(h==3){
          Modul_A();
      }else if(h==4){
          Modul_D();
      }
      h++;
    }
    fclose(fp);
  }
  else{
    return 0;
  }
  return 0;
}
int main(void){
  qaytdi:
  printf("O'zbek tili uchun 1 ni bosing\nНажмите 2 для русского языка\nPress 3 for English\n==>> ");
  scanf("%d", &til);
  if(til==1){
  printf("%s\n",sh[0][0]);
  }else if(til==2){
    printf("%s\n",sh[1][0]);
  }else if(til==3){
    printf("%s\n",sh[2][0]);
  }
  if(til==1 || til==2 || til==3){
  name();
  }
  if(til==1){
      printf("%s",tx[0][0]);
      scanf("%d",&tanladim);
  }else if(til==2){
      printf("%s",tx[1][0]);
      scanf("%d",&tanladim);
  }else if(til==3){
    printf("%s",tx[2][0]);
    scanf("%d",&tanladim);
  }
  if(tanladim==1){
      if(til==1){
          printf("\n\n                  %s",ara_uz_ru[2]);
      }else if(til==2){
          printf("\n\n                 %s\n",ara_uz_ru[3]);
      }else if (til==3){
        printf("\n\n                   %s\n",ara_uz_ru[6]);
      }
      printf("%s",chiziq);
      Fizika_uz_ru();
  }else if(tanladim==2){
    if(til==1){
      printf("\n\n                  %s",ara_uz_ru[4]);
    }else if(til==2){
      printf("\n\n                  %s",ara_uz_ru[5]);
    }else if (til==3){
      printf("\n\n                  %s",ara_uz_ru[7]);
    }
    printf("%s",chiziq);
    Matematika_uz_ru();
  }else if(tanladim==3){
    if(til==1){
      printf("\n\n                  %s",ara_uz_ru[0]);
    }else if(til==2){
      printf("\n\n                  %s\n",ara_uz_ru[1]);
    }else if(til==3){
      printf("\n\n                  %s\n",ara_uz_ru[8]);
    }
    printf("%s",chiziq);
    Aralash_uz_ru();
  }else if (tanladim==4){
    printf("\n\n");
    goto qaytdi;
  }else{
    return 0;
  }
  if(til==1){
        printf("%s %s siz %d ball yig'diz\n",ism,familya,ball);
    }else if(til==2){
        printf("%s %s вы набрали %d очков\n",ism,familya,ball);
    }else if(til==3){
      printf("%s %s you scored %d points\n",ism,familya,ball);
    }
  return 0;
}
