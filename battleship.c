#include <stdlib.h>

#include <stdio.h>

#include <time.h>

#include <conio.h> // for getch() func.

#include <string.h> // for strcpy() func.

#include <unistd.h> // for sleep() func.

#include <windows.h> // for COORD and gotoxy

COORD coord = {0,0};

void gotoxy(int x, int y) // for x y axis
{
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

char buildChart(char list[9][9]); // for create chart (A,B,...H 0-1-2,...7 etc. coordinate values)

void print(char list[9][9]); // decorating chart and interface of the game

typedef struct { // to keep the coordinates practically
  int sayi;
  int karakter;
}
koordinat;

void welcomeScreen();

void createShips(koordinat gecicidizi[20]); // ship creating part

void menu();
void level(); // level choosing interface
void play();
void howtoplay();
void credits();
void gameOver();
void victory();
void shipDestroyedInfo();
int quit();

//global variables
int i, j;
char ch;

int main() {

  srand(time(NULL));
  system("cls");
  welcomeScreen();
  menu();

}

void createShips(koordinat gecicidizi[20]) {

  while (1) { // we have already created the ships to be in the range of 0-7 a-h, the process will be done last.

    while (1) {

      // 1 unit ships

      for (i = 0; i < 2; i++) {
        int sayi = rand() % 8; // we took number
        char harf = rand() % 8 + 65; // we took number; and converted it letter through ascii
        gecicidizi[i].sayi = sayi; // coordinates are saving by that struct
        gecicidizi[i].karakter = harf;

      }

      // 2 unit ships

      for (i = 2; i < 3; i++) {
        int sayi = rand() % 8; // vertical ship part
        char harf = rand() % 8 + 65;
        gecicidizi[i].sayi = sayi;
        gecicidizi[i].karakter = harf;


        // consecutive numbers taking part by sensible randomly(like one more or less) , to create logical ships
        int a = sayi; // saving values for process
        int sayi2 = sayi;
        /* To search for a different value when both of them have the same number in the while, see:
        (If we have 2A coordinate, we took 1A 3A coordinates by that sensible randomly, and we avoid take same coordinate like 2A with that while loop.)*/
        while (sayi2 == sayi) {
          sayi2 = rand() % 3 + (a - 1);
        }
        gecicidizi[i + 1].sayi = sayi2;
        gecicidizi[i + 1].karakter = harf; // so that the letter is same because we are creating vertical ship.

        sayi = rand() % 8; // 2 unit horizontal ship part.
        harf = rand() % 8 + 65;
        gecicidizi[i + 2].sayi = sayi;
        gecicidizi[i + 2].karakter = harf;

        // consecutive characters receiving part
        int b = harf; // We equated a to the ascii value of the letter to use in rand
        int c = harf; // To search for different values in the while when both of them have the same letter in rand
        while (b == c) { // in case of same value as I mentioned before.
          c = rand() % 3 + (b - 1);
        }
        gecicidizi[i + 3].sayi = sayi;
        gecicidizi[i + 3].karakter = c;

        // 3 Unit Ships

        sayi = rand() % 8; // vertical ship part
        harf = rand() % 8 + 65;
        gecicidizi[i + 4].sayi = sayi;
        gecicidizi[i + 4].karakter = harf;

        a = sayi;
        sayi2 = sayi;
        while (sayi2 == sayi) {
          sayi2 = rand() % 3 + (a - 1);
        }
        gecicidizi[i + 5].sayi = sayi2;
        gecicidizi[i + 5].karakter = harf; // so far we did the same things with 2 unit ships.

        a = sayi2;
        int sayi3 = sayi;
        while (sayi3 == sayi || a == sayi2) { // same logic again, but there should not be 2 identical numbers
          sayi3 = rand() % 3 + (a - 1); // see if theres a ship at coordinates 2A 1A, the 3rd random number will be 0 1 or 2, so avoid that wont be 1 or 2.
          a = sayi3;
        }
        gecicidizi[i + 6].sayi = sayi3;
        gecicidizi[i + 6].karakter = harf;

        // horizontal ship part
        sayi = rand() % 8;
        harf = rand() % 8 + 65;
        gecicidizi[i + 7].sayi = sayi;
        gecicidizi[i + 7].karakter = harf;

        b = harf;
        c = harf;
        while (b == c) {
          c = rand() % 3 + (b - 1);
        }
        gecicidizi[i + 8].sayi = sayi;
        gecicidizi[i + 8].karakter = c;

        b = harf;
        int harf2 = c;
        while (harf2 == c || b == harf) {
          harf2 = rand() % 3 + (b - 1);
          b = harf2;
        }
        gecicidizi[i + 9].sayi = sayi;
        gecicidizi[i + 9].karakter = harf2;

        // 4 Unit Ships

        // Vertical ship part
        sayi = rand() % 8;
        harf = rand() % 8 + 65;
        gecicidizi[i + 10].sayi = sayi;
        gecicidizi[i + 10].karakter = harf;

        a = sayi;
        sayi2 = sayi;
        while (sayi2 == sayi) {
          sayi2 = rand() % 3 + (a - 1);
        }
        gecicidizi[i + 11].sayi = sayi2;
        gecicidizi[i + 11].karakter = harf;

        a = sayi2;
        sayi3 = sayi;
        while (sayi3 == sayi || a == sayi2) {
          sayi3 = rand() % 3 + (a - 1);
          a = sayi3;
        }
        gecicidizi[i + 12].sayi = sayi3;
        gecicidizi[i + 12].karakter = harf;

        a = sayi3;
        int sayi4 = sayi2;
        // for avoid overlap, again same logic, only longer version of 3 unit ship's logical.
        while (sayi4 == sayi2 || a == sayi3 || sayi4 == sayi) {
          sayi4 = rand() % 3 + (a - 1);
          a = sayi4;
        }
        gecicidizi[i + 13].sayi = sayi4;
        gecicidizi[i + 13].karakter = harf;

        // horizantal ships part
        sayi = rand() % 8;
        harf = rand() % 8 + 65;
        gecicidizi[i + 14].sayi = sayi;
        gecicidizi[i + 14].karakter = harf;

        b = harf;
        c = harf;
        while (b == c) {
          c = rand() % 3 + (b - 1);
        }
        gecicidizi[i + 15].sayi = sayi;
        gecicidizi[i + 15].karakter = c;

        b = harf;
        harf2 = c;
        while (harf2 == c || b == harf) {
          harf2 = rand() % 3 + (b - 1);
          b = harf2;
        }
        gecicidizi[i + 16].sayi = sayi;
        gecicidizi[i + 16].karakter = harf2;

        b = harf2;
        int harf3 = harf;
        // the same logic, but the long version has 3 identical letters so that they don't overlap.
        while (harf3 == harf || b == harf2 || harf3 == c) {
          harf3 = rand() % 3 + (b - 1);
          b = harf3;
        }
        gecicidizi[i + 17].sayi = sayi;
        gecicidizi[i + 17].karakter = harf3;

      }
      int sonuc = 0;
      for (i = 0; i < 19; i++) { // we check if randomly generated ships are overlapping
        for (j = i + 1; j < 20; j++) {
          if (gecicidizi[i].sayi == gecicidizi[j].sayi && gecicidizi[i].karakter == gecicidizi[j].karakter) { // If there is any overlap it goes into that if block
            // we get information that it overlaps
            sonuc = 1;
            break;
          }
        }
      }
      // if they overlap, the cycle starts over and the ships are rebuilt until they do not overlap
      if (sonuc) {
        continue;
      }
      // If they do not overlap, the ship creation exits the while loop
      else {
        break;
      }
    }
    int logical = 0; // If the ships don't overlap, we come here and we want the ships created here to be in the 0-7 a-h range.

    for (i = 0; i < 20; i++) {
      if (gecicidizi[i].sayi < 8 && gecicidizi[i].sayi >= 0 && gecicidizi[i].karakter >= 65 && gecicidizi[i].karakter < 73) { // If it is in the desired range, the logical value we create is 0.
        logical = 0;
      } else { // If it isn't in the desired range, the logical value is 1
        logical = 1;
        break;
      }
    }

    if (logical) { // If it is not in the desired range, the logical value was 1, we say continue and our loop starts from the beginning, the ships occur again and continue until they are in the desired range.
      continue;
    } else {
      /*  for(i=0;i<20;i++){  // created for testing purposes can optionally be activated for cheating / testing. In order to appear, the level function must be disabled.
			   printf("Gemi: %d %c\n",gecicidizi[i].sayi,gecicidizi[i].karakter);
      }   */
      break; // If it is in the desired range, it does not enter the if block above, and our cycle ends and our ships are created.
    }
  }
}

char buildChart(char list[9][9]) {

  // creating the table on which we will operate above that.

  list[0][0] = ' ';
  for (i = 0; i < 9; i++) {
    for (j = 0; j < 9; j++) {
      if (i == 0 && j != 0) {
        list[i][j] = 'A' + j - 1;
      }
      if (j == 0) {
        list[i + 1][j] = '0' + i;
      }
      if (i > 0 && j > 0) {
        list[i][j] = 177;
      }
    }
  }
  return list[9][9];
}

void print(char list[9][9]) {

  int y;

  // level info framework

  gotoxy(90, 2);
  printf("%c", 201);

  for (i = 0; i < 35; i++) {
    printf("%c", 205);
    if (i == 17) {
      gotoxy(91, 4);
    }
  }
  printf("%c", 188);
  gotoxy(90, 3);
  printf("%c Mode =          %c", 186, 186);
  gotoxy(108, 2);
  printf("%c", 187);
  gotoxy(90, 4);
  printf("%c", 200);

  gotoxy(72, 25);

  // frame of coordinate entries

  gotoxy(11, 22);
  printf("%c", 201);
  for (i = 0; i < 53; i++) {
    printf("%c", 205);
  }
  printf("%c", 187);
  gotoxy(65, 23);
  printf("%c", 186);
  gotoxy(65, 24);
  printf("%c", 185);
  gotoxy(11, 24);
  printf("%c", 204);
  for (i = 0; i < 53; i++) {
    printf("%c", 205);
  }
  gotoxy(65, 25);
  printf("%c", 186);
  gotoxy(11, 26);
  printf("%c", 200);
  for (i = 0; i < 53; i++) {
    printf("%c", 205);
  }
  printf("%c", 188);

  gotoxy(11, 23);
  printf("%c \xB2 Enter Letter Coordinate of shoot's place=", 186);
  gotoxy(11, 25);
  printf("%c \xB2 Enter Number Coordinate of shoot's place=", 186);

  // frame of the ship chart

  gotoxy(72, 7);
  printf("%c", 201);
  for (i = 0; i < 35; i++) {
    printf("%c", 205);
  }
  printf("%c", 187);
  gotoxy(73, 9);
  int a = 2;
  for (i = 0; i < 175; i++) {
    if (i % 35 == 0 && i != 0) {
      gotoxy(73, 9 + a);
      a += 2;
    }
    printf("%c", 205);
  }

  for (i = 0; i < 12; i++) {

    gotoxy(72, 8 + i);
    printf("%c", 186);
  }

  gotoxy(72, 9);
  printf("%c", 204);
  gotoxy(73, 10);
  printf("1 Unit --->");
  gotoxy(72, 11);
  printf("%c", 204);
  gotoxy(73, 12);
  printf("2 Unit --->");
  gotoxy(72, 13);
  printf("%c", 204);
  gotoxy(73, 14);
  printf("3 Unit --->");
  gotoxy(72, 15);
  printf("%c", 204);
  gotoxy(73, 16);
  printf("4 Unit --->");
  gotoxy(72, 17);
  printf("%c", 204);

  gotoxy(72, 20);
  printf("%c", 200);
  for (i = 0; i < 35; i++) {
    printf("%c", 205);
  }
  printf("%c", 188);
  for (i = 0; i < 12; i++) {
    gotoxy(108, 8 + i);
    printf("%c", 186);
  }

  gotoxy(96, 9);
  printf("%c", 203);
  for (i = 0; i < 8; i++) {
    gotoxy(96, 10 + i);
    printf("%c", 186);
    if (i % 2 != 0) {
      gotoxy(96, 10 + i);
      printf("%c", 206);
    }
  }
  gotoxy(96, 17);
  printf("%c", 202);
  gotoxy(108, 9);
  printf("%c", 185);
  gotoxy(108, 11);
  printf("%c", 185);
  gotoxy(108, 13);
  printf("%c", 185);
  gotoxy(108, 15);
  printf("%c", 185);
  gotoxy(108, 17);
  printf("%c", 185);

  gotoxy(73, 8);
  printf("Ship Length");
  gotoxy(91, 8);
  printf("Ship Titles");
  gotoxy(84, 7);
  printf("%c", 203);
  gotoxy(84, 8);
  printf("%c", 186);
  gotoxy(84, 9);
  printf("%c", 206);
  for (i = 0; i < 8; i++) {
    gotoxy(84, 10 + i);
    printf("%c", 186);
    if (i % 2 != 0) {
      gotoxy(84, 10 + i);
      printf("%c", 206);
    }
  }
  gotoxy(84, 17);
  printf("%c", 202);

  gotoxy(73, 18);
  for (i = 0; i < 35; i++) {
    if (i % 2 == 0) {
      printf("%c", 176);
    } else {
      printf("%c", 178);
    }

  }
  gotoxy(73, 19);
  for (i = 0; i < 35; i++) {
    if (i % 2 == 0) {
      printf("%c", 178);
    } else {
      printf("%c", 176);
    }
  }

  // ship info frame finished

  // some decorating operatings

  gotoxy(17, 2);
  printf("%c", 201);
  for (i = 0; i < 8; i++) {
    printf("%c%c%c%c%c%c", 205, 205, 205, 205, 205, 203);
  }
  printf("\n");

  gotoxy(17, 3);
  printf("%c", 186);
  gotoxy(18, 3);
  for (i = 1; i < 9; i++) {
    printf("  %c  %c", list[0][i], 186);
  }
  gotoxy(18, 4);
  for (i = 0; i < 8; i++) {
    printf("%c%c%c%c%c%c", 205, 205, 205, 205, 205, 206);
  }

  gotoxy(17, 4);
  printf("%c", 206);
  gotoxy(17, 5);
  printf("%c", 186);

  for (i = 1, y = 5; i < 9; i++, y++) {
    gotoxy(14, y);
    for (j = 0; j < 9; j++) {
      printf("%c  %c  ", list[i][j], 186);
    }

    ++y;

    gotoxy(12, y);
    if (i != 8)
    {
      for (j = 0; j < 9; j++) {
        printf("%c%c%c%c%c%c", 205, 205, 205, 205, 205, 206);
      }
    } else {
      gotoxy(12, y);
      for (j = 0; j < 9; j++) {
        if (j != 8) {
          printf("%c%c%c%c%c%c", 205, 205, 205, 205, 205, 202);
        } else {
          printf("%c%c%c%c%c%c", 205, 205, 205, 205, 205, 188);
        }
      }
    }
  }

  gotoxy(65, 2);
  printf("%c", 187);

  for (y = 4; y <= 18; y += 2) {
    gotoxy(65, y);
    printf("%c", 185);
  }

  gotoxy(11, 4);
  printf("%c", 201);
  for (i = 0; i < 5; i++) {
    printf("%c", 205);
  }

  for (i = 0, y = 5; i < 15; i++, y++) {
    gotoxy(11, y);
    if (y % 2 == 0) {
      printf("%c", 204);
    } else {
      printf("%c", 186);
    }
  }

  gotoxy(11, 20);
  printf("%c", 200);

  gotoxy(72, 2);
  printf("%c", 201);

  for (i = 0; i < 31; i++) {
    printf("%c", 205);
    if (i == 15) {
      gotoxy(73, 4);
    }
  }
  printf("%c", 187);
  gotoxy(72, 3);
  printf("%c CANNONS =     %c", 186, 186);
  gotoxy(88, 2);
  printf("%c", 187);
  gotoxy(72, 4);
  printf("%c", 200);
  gotoxy(88, 4);
  printf("%c", 188);

  gotoxy(72, 25);

}

void welcomeScreen() {

  // printing "battleship" with sleep function

  char bir[64] = "XXXXX   XXXX  XXXXXX XXXXXX XX     XXXXXX  XXXXX XX  XX XX XXXX";
  char iki[66] = "XX  XX XX  XX   XX     XX   XX     XX     XX     XX  XX XX XX  XX";
  char uc[64] = "XXXXX  XX  XX   XX     XX   XX     XXXX    XXXX  XXXXXX XX XXXX";
  char dort[62] = "XX  XX XXXXXX   XX     XX   XX     XX         XX XX  XX XX XX";
  char bes[62] = "XXXXX  XX  XX   XX     XX   XXXXXX XXXXXX XXXXX  XX  XX XX XX";
  int k = 0, l = 0, m = 0, n = 0, j = 0, x = 20;

  while (1) {
    if (91 - k > x) {
      gotoxy(x + 8, 5);
      printf("%c", bir[k]);
      Sleep(10);
      gotoxy(91 - k, 5);
      printf("%c", bir[63 - k]);
      Sleep(10);
    }
    if (92 - l > x) {
      gotoxy(x + 8, 6);
      printf("%c", iki[l]);
      gotoxy(93 - l, 6);
      printf("%c", iki[65 - l]);
    }
    if (91 - m > x) {
      gotoxy(x + 8, 7);
      printf("%c", uc[m]);
      gotoxy(91 - m, 7);
      printf("%c", uc[63 - m]);
      Sleep(10);
    }
    if (89 - n > x) {
      gotoxy(x + 8, 8);
      printf("%c", dort[n]);
      gotoxy(89 - n, 8);
      printf("%c", dort[61 - n]);
    }
    if (89 - j > x) {
      gotoxy(x + 8, 9);
      printf("%c", bes[j]);
      gotoxy(89 - j, 9);
      printf("%c", bes[61 - j]);
      Sleep(10);
    }

    k++, l++, m++, n++, j++, x++;

    if (x == 85) {
      break;
    }
  }

  gotoxy(0, 28);
  for (i = 0; i < 120; i++) {
    printf("%c", 205);
  }
  // some warnings
  gotoxy(79, 29);
  printf("\xB2 Please don't change the screen mode.");
  gotoxy(76, 29);
  printf("%c", 186);
  gotoxy(76, 28);
  printf("%c", 203);
  gotoxy(2, 29);
  printf("\xB2 While playing this game please don't click right mouse on the screen.");
  gotoxy(44, 19);
  printf("Press any key to continue . . .");
  getch();
  system("cls");
}

void menu() {

  int a;
  a:
    a = 0;

  // back font
  ch = 178;
  gotoxy(0, 0);
  for (i = 0; i < 3600; i++) {
    printf("%c", ch);
  }
  ch = 176;
  gotoxy(49, 2);
  for (i = 0; i < 17; i++) {
    printf("%c", ch);
  }
  gotoxy(49, 3);
  for (i = 0; i < 17; i++) {
    printf("%c", ch);
  }
  gotoxy(49, 4);
  for (i = 0; i < 17; i++) {
    printf("%c", ch);
  }
  // buttons
  gotoxy(54, 3);
  printf(" MENU ");
  gotoxy(50, 8);
  printf("    1) Play    ");
  gotoxy(50, 12);
  printf("2) How To Play?");
  gotoxy(50, 16);
  printf("  3) Credits   ");
  gotoxy(50, 20);
  printf("    0) Exit    ");

  for (i = 0; i < 4; i++) { // framework of buttons

    ch = 201;
    gotoxy(49, 7 + a);
    printf("%c", ch);
    ch = 200;
    gotoxy(49, 9 + a);
    printf("%c", ch);
    ch = 187;
    gotoxy(65, 7 + a);
    printf("%c", ch);
    ch = 188;
    gotoxy(65, 9 + a);
    printf("%c", ch);
    ch = 186;
    gotoxy(49, 8 + a);
    printf("%c", ch);
    gotoxy(65, 8 + a);
    printf("%c", ch);
    gotoxy(50, 7 + a);
    for (j = 0; j < 15; j++) {
      ch = 205;
      printf("%c", ch);
    }
    gotoxy(50, 9 + a);
    for (j = 0; j < 15; j++) {
      ch = 205;
      printf("%c", ch);
    }
    a += 4;
  }
  gotoxy(98, 28);
  printf("Patch Version 1.00");
  gotoxy(119, 29);

  // warning for entered wrong values
  switch (getch()) {
  case '1':
    play();
    break;
  case '2':
    howtoplay();
    goto a;
    break;
  case '3':
    credits();
    goto a;
    break;
  case '0':
    quit();
    break;
  default:
    system("cls");
    gotoxy(45, 12);
    printf("\aYou entered wrong type keyword!");
    Sleep(1500);
    goto a;
  }
}

void play() {

  int shootRight, totalHit;
  a:
  totalHit = 19;
  system("cls");
  char dizi[9][9];
  buildChart(dizi);
  koordinat sameCoordinate[100];
  koordinat ships[20];
  createShips(ships);
  char diff[8]; // to print the level on the right side of the table.

  char shipNames[8][11] = {"Shirakami","Veg","Cruiser","Submarine","Matthew","Minelayer","Nusrat","Titanic"};
  int control[8] = {0,0,0,0,0,0,0,0}; // to operate on the ship information section, ship sunk etc.

  b:
    level();

  // assignment of hit right based on level selection
  switch (getch()) {
  case '1':
    shootRight = 30;
    strcpy(diff, "Easy");
    break;
  case '2':
    shootRight = 20;
    strcpy(diff, "Medium");
    break;
  case '3':
    shootRight = 10;
    strcpy(diff, "Hard");
    break;
  case '4':
    shootRight = 5;
    strcpy(diff, "Expert");
    break;
  default:
    system("cls");
    gotoxy(45, 12);
    printf("\aYou entered wrong type keyword!");
    Sleep(1500);
    goto b;
  }

  system("cls");
  print(dizi);
  gotoxy(84, 3);
  printf("%d", shootRight);

  char letterCoordinate, numberCoordinate, letterSwitch[10];
  int correctRange, totalPlace = 0;
  int process;

  while (1) {

    fflush(stdin);

    while (1) { // In order for the coordinate values ​​received from the user to be in the range 0-7 and A-H

      gotoxy(100, 3);
      printf("%s", diff);

      gotoxy(86, 10); // place of suppression of ship names
      printf("%s", shipNames[0]);
      gotoxy(98, 10);
      printf("%s", shipNames[1]);
      gotoxy(86, 12);
      printf("%s", shipNames[2]);
      gotoxy(98, 12);
      printf("%s", shipNames[3]);
      gotoxy(86, 14);
      printf("%s", shipNames[4]);
      gotoxy(98, 14);
      printf("%s", shipNames[5]);
      gotoxy(86, 16);
      printf("%s", shipNames[6]);
      gotoxy(98, 16);
      printf("%s", shipNames[7]);

      for (i = 0; i < 8; i++) {
        if (!strcmp(shipNames[i], "DESTROYED")) {
          if (i == 0) gotoxy(86, 10);
          if (i == 1) gotoxy(98, 10);
          if (i == 2) gotoxy(86, 12);
          if (i == 3) gotoxy(98, 12);
          if (i == 4) gotoxy(86, 14);
          if (i == 5) gotoxy(98, 14);
          if (i == 6) gotoxy(86, 16);
          if (i == 7) gotoxy(98, 16);
          for (j = 0; j < 9; j++) {
            printf("%c", shipNames[i][j]);
            Sleep(50);
          }
          strcpy(shipNames[i], "    X");
        }
      }

      correctRange = 0;
      gotoxy(11, 23);
      fflush(stdin);
      printf("%c \xB2 Enter Letter Coordinate of shoot's place= ", 186);
      scanf("%s", letterSwitch);
      int length = strlen(letterSwitch);
      letterCoordinate = letterSwitch[0];
      fflush(stdin);
      gotoxy(11, 25);
      printf("%c \xB2 Enter Number Coordinate of shoot's place= ", 186);
      scanf("%c", & numberCoordinate);

      if (length > 1) {
        correctRange = 0;
      } else {

        if (numberCoordinate < 56 && numberCoordinate > 47 && ((letterCoordinate > 64 && letterCoordinate < 73) || (letterCoordinate < 105 && letterCoordinate > 96))) {

          correctRange = 1;

          if (correctRange) { // If user entered the same coordinates, it was written to request the coordinate again
            totalPlace++;
            for (i = 0; i < totalPlace; i++) {
              if (sameCoordinate[i].sayi == numberCoordinate - 48 && (sameCoordinate[i].karakter == letterCoordinate || sameCoordinate[i].karakter == letterCoordinate + 32)) {
                correctRange = 2;
                break;
              }
            }
            sameCoordinate[totalPlace].sayi = numberCoordinate - 48;
            sameCoordinate[totalPlace].karakter = letterCoordinate;
          }
        }
      }

      if (correctRange == 1) {
        break;
      } else if (correctRange == 2) {
        system("cls");
        print(dizi);
        gotoxy(84, 3);
        printf("%d", shootRight);
        gotoxy(11, 28);
        printf("----------> \aYou have entered a coordinate you have entered before, please enter a different coordinate!");

      } else {
        system("cls");
        print(dizi);
        gotoxy(84, 3);
        printf("%d", shootRight);
        gotoxy(11, 28);
        printf("----------> \aYou entered incorrect coordinates, please enter letter and number in order!");
      }
    } // kullanıcıdan alınan değerler 0-7 a-h arası oldu şimdi diğer işlemlere geçiyoruz

    int isHit = totalHit; // We created data to find out if it misses, if it misses, this value will not increase, we will act accordingly.

    for (i = 0; i < 20; i++) {

      if (numberCoordinate - 48 == ships[i].sayi && (letterCoordinate == ships[i].karakter || letterCoordinate == (ships[i].karakter + 32))) {
        // If this enters this if block, it means its shoot is hit

        isHit++; // to get the success info of the hit

        ships[i].sayi = -1; // so that it cannot hit if he enters the same coordinates again.
        ships[i].karakter = 'K';

        for (i = 1; i < 8; i++) { // It was written to get the coordinates of the place hit, to press the + where it was hit.

          if (dizi[i][0] == (numberCoordinate)) {
            break;
          }
        }
        for (j = 1; j < 8; j++) {
          if (dizi[0][j] == letterCoordinate || dizi[0][j] + 32 == letterCoordinate) { // so that lower and upper case doesn't matter.
            break;
          }
        }

        dizi[i][j] = '+';
      }

    } // If isHit does not increase in this for loop, we will decrease the hit right by 1, otherwise we will increase it by 1.

    if (isHit == totalHit) {

      for (i = 1; i < 8; i++) { // written to get the coordinates of the shooting location
        if (dizi[i][0] == (numberCoordinate)) {
          break;
        }
      }
      for (j = 1; j < 8; j++) {
        if (dizi[0][j] == letterCoordinate || dizi[0][j] + 32 == letterCoordinate) { // so that lower and upper case doesn't matter.
          break;
        }
      }

      dizi[i][j] = '-'; // The coordinates of the missed place were found above and there - printed

      shootRight--; // Right to hit reduced for missed
      system("cls");
      print(dizi);
      gotoxy(11, 28);
      printf("--------------------------------------------> You MISSED! <--------------------------------------------");
      gotoxy(84, 3);
      printf("%d", shootRight);

    } else {
      shootRight++; // The right to hit was increased as a result of an accurate shot
      totalHit++; // If user hits 20 times means all ships are finished, the user wins the game.
      system("cls");
      print(dizi);
      gotoxy(11, 28);
      printf("--------------------------------------------> You HIT! <--------------------------------------------");
      gotoxy(84, 3);
      printf("%d", shootRight);
    }

    // We operate in the control sequence according to the size of the ship, and according to the information there, we understand that the ship has sunk.

    for (i = 0; i < 20; i++) {

      if (i < 2) {
        if (ships[i].sayi == -1) {
          control[i] = 1;
          ships[i].sayi = -2;
        }
      } else if (i < 4) {
        if (ships[i].sayi == -1) {
          control[2] = control[2] + 1;
          ships[i].sayi = -2;
        }
      } else if (i < 6) {
        if (ships[i].sayi == -1) {
          control[3] = control[3] + 1;
          ships[i].sayi = -2;
        }
      } else if (i < 9) {
        if (ships[i].sayi == -1) {
          control[4] = control[4] + 1;
          ships[i].sayi = -2;
        }
      } else if (i < 12) {
        if (ships[i].sayi == -1) {
          control[5] = control[5] + 1;
          ships[i].sayi = -2;
        }
      } else if (i < 16) {
        if (ships[i].sayi == -1) {
          control[6] = control[6] + 1;
          ships[i].sayi = -2;
        }
      } else if (i < 20) {
        if (ships[i].sayi == -1) {
          control[7] = control[7] + 1;
          ships[i].sayi = -2;
        }
      }

    }
    //example of logic; 2 ships have 2 parts, if the 2nd and 3rd values of the control function will be 2, we understand that the 2 unit ship or ships sunk.
    int x;
    for (i = 0; i < 8; i++) {
      if (i < 2) {
        if (control[i] == 1) {
          gotoxy(108, 24);
          printf("%c", 186);
          shipDestroyedInfo();

          x = strlen(shipNames[i]);

          for (j = 0; j < x; j++) {
            printf("%c", shipNames[i][j]);
            Sleep(50);
          }
          printf(" SHIP!");
          strcpy(shipNames[i], "DESTROYED");
          control[i] = -1;
        }
      } else if (i < 4) {
        if (control[i] == 2) {
          gotoxy(108, 24);
          printf("%c", 186);
          shipDestroyedInfo();
          int x = strlen(shipNames[i]);
          for (j = 0; j < x; j++) {
            printf("%c", shipNames[i][j]);
            Sleep(50);
          }
          printf(" SHIP!");
          strcpy(shipNames[i], "DESTROYED");
          control[i] = -1;
        }
      } else if (i < 6) {
        if (control[i] == 3) {
          gotoxy(108, 24);
          printf("%c", 186);
          shipDestroyedInfo();
          int x = strlen(shipNames[i]);
          for (j = 0; j < x; j++) {
            printf("%c", shipNames[i][j]);
            Sleep(50);
          }
          printf(" SHIP!");
          strcpy(shipNames[i], "DESTROYED");
          control[i] = -1;
        }
      } else if (i < 8) {
        if (control[i] == 4) {
          gotoxy(108, 24);
          printf("%c", 186);
          shipDestroyedInfo();
          int x = strlen(shipNames[i]);
          for (j = 0; j < x; j++) {
            printf("%c", shipNames[i][j]);
            Sleep(50);
          }
          printf(" SHIP!");
          strcpy(shipNames[i], "DESTROYED");
          control[i] = -1;
        }
      }
    }
    // If the right to shoot is over, the game is over
    if (shootRight == 0) {
      Sleep(250);
      system("cls");
      gameOver();
      n:
        switch (getch()) {
        case '1':
          goto a;
          break;
        case '2':
          menu();
          break;
        case '3':
          quit();
          process = 1;
          break;
        default:
          printf("\a");
          goto n;
        }
    // If totalHit=20, it means, user found all the ships and won the game.
    } else if (totalHit == 20) {
      Sleep(250);
      system("cls");
      victory();
      // for avoid wrong entries
      m:
        switch (getch()) {
        case '1':
          goto a;
          break;
        case '2':
          menu();
          break;
        case '3':
          quit();
          process = 1;
          break;
        default:
          printf("\a");
          goto m;
        }
    } else {
      if (process == 1) {
        break;
      }
      continue;
    }

    if (process == 1) {
      break;
    }
  }
}

void howtoplay() {

  int y;
  ch = 219;
  system("cls");

  // white frame
  gotoxy(8, 1);
  for (i = 0; i < 105; i++) {
    printf("%c", ch);
  }

  // decorating of interface

  gotoxy(50, 1);
  printf("%c", ch - 41);
  printf(" Game Information ");
  printf("%c", ch - 41);

  gotoxy(8, 26);
  for (i = 0; i < 105; i++) {
    printf("%c", ch);
  }

  gotoxy(7, 1);
  for (i = 0; i < 26; i++) {
    gotoxy(7, 1 + i);
    printf("%c", 219);
  }
  gotoxy(112, 1);
  for (i = 0; i < 26; i++) {
    gotoxy(112, 1 + i);
    printf("%c", 219);
  }

  gotoxy(12, 4);
  printf("%c%c%c%c", ch, ch, ch, ch - 41);
  printf(" This is a single player game.");
  gotoxy(12, 6);
  printf("%c%c%c%c", ch, ch, ch, ch - 41);
  printf(" There are 8 ships in total.");
  gotoxy(12, 8);
  printf("%c%c%c%c", ch, ch, ch, ch - 41);
  printf(" Ships Information  ");
  ch = 186;
  printf("%c", ch);
  ch = 201;
  gotoxy(12, 9);
  printf("%c", ch);
  ch = 205;
  for (i = 0; i < 23; i++) {
    printf("%c", ch);
  }
  ch = 185;
  printf("%c", ch);
  ch = 186;
  for (i = 0; i < 7; i++) {
    gotoxy(12, 10 + i);
    printf("%c", ch);
  }
  gotoxy(12, 17);
  ch = 200;
  printf("%c", ch);
  ch = 205;
  for (i = 0; i < 23; i++) {
    gotoxy(13 + i, 17);
    printf("%c", ch);
  }
  ch = 188;
  printf("%c", ch);
  ch = 186;
  for (i = 0; i < 7; i++) {
    gotoxy(36, 10 + i);
    printf("%c", ch);
  }

  ch = 219;
  gotoxy(12, 19);
  printf("%c%c%c%c", ch, ch, ch, ch - 41);
  printf(" You will have the right to shoot according to game mode you will choose.");
  gotoxy(12, 21);
  printf("%c%c%c%c", ch, ch, ch, ch - 41);
  printf(" When the game is over, you will lose if you haven't found all the ships.");
  gotoxy(12, 23);
  printf("%c%c%c%c", ch, ch, ch, ch - 41);
  printf(" For each successful hit, you will earn one shoot..");

  char oneUnit[77] = "1 Unit --> 2 Piece\n2 Unit --> 2 Piece\n3 Unit --> 2 Piece\n4 Unit --> 2 Piece\n";

  gotoxy(15, 10);
  for (i = 0, y = 12; oneUnit[i] != '\0'; i++) {
    if (oneUnit[i] != '\n') {
      printf("%c", oneUnit[i]);
    } else {
      gotoxy(15, y);
      y += 2;
    }

    Sleep(15);
  }

  gotoxy(35, 28);
  printf("------> Press any key to return to the main menu.");
  getch();
  system("cls");

}

void credits() {

  int y;
  char title[148] = "XXXXX XXXXX  XXXX   XXXX  XXXX\nX       X   XX  XX  X     X   \nXXXX    X   XX  XX  XXX   XXX\n   XX   X   XXXXXX  X     X";
  system("cls");

  gotoxy(45, 2);
  for (i = 0, y = 3; title[i] != '\0'; i++) // staff logo is printing
  {
    if (title[i] == 'X') {
      printf("%c", 223);
    } else if (title[i] == ' ') {
      printf(" ");
    } else if (title[i] == '\n') {
      gotoxy(45, y++);
    }
  }
  // decorating interface
  gotoxy(44, y);
  printf("%c%c%c%c%c    %c   %c%c  %c%c  %c     %c", 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223);
  gotoxy(44, 3);
  printf("%c", 223);

  gotoxy(34, 8);
  printf("%c", 201);
  for (i = 0; i < 48; i++) {
    printf("%c", 205);
  }
  printf("%c", 187);

  gotoxy(34, 9);
  printf("%c", 186);
  printf("            PROGRAMMERS & DESIGNERS");
  gotoxy(34, 10);
  printf("%c", 200);
  gotoxy(83, 9);
  printf("%c", 186);
  gotoxy(35, 10);

  for (i = 0; i < 48; i++) {
    printf("%c", 205);
  }
  printf("%c", 188);

  char emir[100] = "  ERGUN EMIR GULER   ~   B1905.010009";
  char ozkan[100] = "  OZKAN TEL   ~   B1905.010050";
  // printing names with sleep function
  gotoxy(36, 13);
  printf("%c", 178);
  for (i = 0; emir[i] != '\0'; i++) {
    printf("%c", emir[i]);
    Sleep(25);
  }
  gotoxy(36, 15);
  printf("%c", 178);
  for (i = 0; ozkan[i] != '\0'; i++) {
    printf("%c", ozkan[i]);
    Sleep(25);
  }

  gotoxy(34, 18);
  printf("%c", 201);
  for (i = 0; i < 48; i++) {
    printf("%c", 205);
  }
  printf("%c", 187);

  gotoxy(34, 19);
  printf("%c", 186);
  gotoxy(50, 19);
  printf("HEAD OF DEPARTMENT");
  gotoxy(34, 20);
  printf("%c", 200);
  gotoxy(83, 19);
  printf("%c", 186);
  gotoxy(35, 20);
  gotoxy(35, 20);
  for (i = 0; i < 48; i++) {
    printf("%c", 205);
  }
  gotoxy(83, 20);
  printf("%c", 188);

  gotoxy(36, 22);
  printf("%c Prof. Dr. ALI GUNES", 178);

  gotoxy(57, 26);
  printf("%c ", 206);
  printf("ISTANBUL AYDIN UNIVERSITY");

  gotoxy(35, 28);
  printf("------> Press any key to return to the main menu.");
  getch();
  system("cls");
}

int quit() {

  int a = 0, b = 0, counter = 50, seconds = 5;

  system("cls");

  // The section of creating framed circular rotating string

  char exiting[33] = "Thank you for playing our game!";

  // framework
  ch = 205;
  gotoxy(25, 3);
  for (i = 0; i < 73; i++) {
    printf("%c", ch);
  }

  gotoxy(25, 25);
  for (i = 0; i < 73; i++) {
    printf("%c", ch);
  }
  ch = 186;

  for (i = 0; i < 21; i++) {
    gotoxy(24, 4 + i);
    printf("%c", ch);
  }
  for (i = 0; i < 21; i++) {
    gotoxy(98, 4 + i);
    printf("%c", ch);
  }
  ch = 201;
  gotoxy(24, 3);
  printf("%c", ch);
  ch = 187;
  gotoxy(98, 3);
  printf("%c", ch);
  ch = 200;
  gotoxy(24, 25);
  printf("%c", ch);
  ch = 188;
  gotoxy(98, 25);
  printf("%c", ch);
  // we created the circular rotation by increasing x,y values using gotoxy
  while (1) {
    for (j = 0; j < 40; j++) {

      if (j < 10) {
        gotoxy(45 + a, 4 + b);
        for (i = 0; i < 33; i++) {
          printf("%c", exiting[i]);
        }
        Sleep(100);
        gotoxy(45 + a, 4 + b);
        for (i = 0; i < 33; i++) {
          printf(" ");
        }
        a += 2;
        b += 1;
      } else if (j < 20) {
        gotoxy(45 + a, 4 + b);
        for (i = 0; i < 33; i++) {
          printf("%c", exiting[i]);
        }
        Sleep(100);
        gotoxy(45 + a, 4 + b);
        for (i = 0; i < 33; i++) {
          printf(" ");
        }
        a -= 2;
        b += 1;
      } else if (j < 30) {
        gotoxy(45 + a, 4 + b);
        for (i = 0; i < 33; i++) {
          printf("%c", exiting[i]);
        }
        Sleep(100);
        gotoxy(45 + a, 4 + b);
        for (i = 0; i < 33; i++) {
          printf(" ");
        }
        a -= 2;
        b -= 1;
      } else if (j < 40) {
        gotoxy(45 + a, 4 + b);
        for (i = 0; i < 33; i++) {
          printf("%c", exiting[i]);
        }
        Sleep(100);
        gotoxy(45 + a, 4 + b);
        for (i = 0; i < 33; i++) {
          printf(" ");
        }
        a += 2;
        b -= 1;
      }

      gotoxy(76, 27);
      // Information about exiting after 5 seconds
      if (counter % 10 == 0) {
        printf("Exiting in %d seconds...", seconds);
        seconds--;
      }
      counter--;

      if (counter == -1) {
        for (i = 4; i < 25; i++) {
          for (j = 25; j < 98; j++) {
            gotoxy(j, i);
            printf("%c", 219);
          }
        }

        for (i = 54, j = 6; i > 43; i--, j++) // printing first flag
        {
          gotoxy(i, j);
          printf(" ");
          gotoxy(54, j);
          printf(" ");
        }

        for (i = 44; i < 49; i++) {
          gotoxy(i, 16);
          printf("%c", 220);
        }
        for (i = 49; i < 55; i++) {
          gotoxy(i, 16);
          printf("%c", 223);
        }

        for (i = 16; i < 19; i++) // mast of ship flag
        {
          gotoxy(54, i);
          printf(" ");
        }

        for (i = 68, j = 5; i > 57; i--, j++) // 2. flag
        {
          gotoxy(i, j);
          printf(" ");
          gotoxy(68, j);
          printf(" ");
        }

        for (i = 57; i < 63; i++) {
          gotoxy(i, 16);
          printf("%c", 220);
        }
        for (i = 63; i < 69; i++) {
          gotoxy(i, 16);
          printf("%c", 223);
        }

        for (i = 16; i < 19; i++) // printing mast of ship flag
        {
          gotoxy(68, i);
          printf(" ");
        }

        for (i = 80, j = 5; i > 69; i--, j++) // pringting 3. flag
        {
          gotoxy(i, j);
          printf(" ");
          gotoxy(80, j);
          printf(" ");
        }

        for (i = 70; i < 75; i++) {
          gotoxy(i, 15);
          printf("%c", 220);
        }
        for (i = 75; i < 81; i++) {
          gotoxy(i, 15);
          printf("%c", 223);
        }

        // -| PRINTING BOTTOM PART OF THE SHIP |-

        gotoxy(70, 18);
        printf("%c", 223);

        for (i = 71; i < 86; i++) {
          printf(" ");
        }

        gotoxy(40, 19);
        printf("%c%c", 220, 220);

        for (i = 42; i < 86; i++) {
          printf(" ");
        }

        for (i = 78; i < 86; i++) {
          gotoxy(i, 17);
          printf("%c", 223);
        }

        for (i = 15; i < 18; i++) // Printing mast of the third flag
        {
          gotoxy(80, i);
          printf(" ");
        }

        gotoxy(44, 20);
        printf("%c%c", 220, 220);

        for (i = 46; i < 86; i++) {
          printf(" ");
        }

        gotoxy(47, 21);
        printf("%c", 220);

        for (i = 48; i < 85; i++) {
          printf(" ");

        }

        for (i = 48; i < 85; i++) {
          gotoxy(i, 22);
          printf(" ");

        }

        gotoxy(37, 18);
        printf("%c", 220);

        for (i = 38; i < 43; i++) {

          printf(" ");
        }

        printf("%c%c%c", 223, 223, 223);
        gotoxy(37, 17);
        printf("%c%c%c", 223, 223, 223);

        gotoxy(118, 27);
        return 0;
      }
    }
  }
}

void level() {

  int a = 0;

  // back font
  ch = 178;
  gotoxy(0, 0);
  for (i = 0; i < 3600; i++) {
    printf("%c", ch);
  }
  ch = 176;
  gotoxy(49, 2);
  for (i = 0; i < 17; i++) {
    printf("%c", ch);
  }
  gotoxy(49, 3);
  for (i = 0; i < 17; i++) {
    printf("%c", ch);
  }
  gotoxy(49, 4);
  for (i = 0; i < 17; i++) {
    printf("%c", ch);
  }
  // buttons
  gotoxy(52, 3);
  printf(" Difficulty ");
  gotoxy(50, 8);
  printf("1)    Easy     ");
  gotoxy(50, 12);
  printf("2)   Medium    ");
  gotoxy(50, 16);
  printf("3)    Hard     ");
  gotoxy(50, 20);
  printf("4)   Expert    ");

  for (i = 0; i < 4; i++) { // framework of buttons

    ch = 201;
    gotoxy(49, 7 + a);
    printf("%c", ch);
    ch = 200;
    gotoxy(49, 9 + a);
    printf("%c", ch);
    ch = 187;
    gotoxy(65, 7 + a);
    printf("%c", ch);
    ch = 188;
    gotoxy(65, 9 + a);
    printf("%c", ch);
    ch = 186;
    gotoxy(49, 8 + a);
    printf("%c", ch);
    gotoxy(65, 8 + a);
    printf("%c", ch);
    gotoxy(50, 7 + a);
    for (j = 0; j < 15; j++) {
      ch = 205;
      printf("%c", ch);
    }
    gotoxy(50, 9 + a);
    for (j = 0; j < 15; j++) {
      ch = 205;
      printf("%c", ch);
    }
    a += 4;
  }
  gotoxy(98, 28);
  printf("Patch Version 1.00");
  gotoxy(119, 29);

}

void shipDestroyedInfo() {
  // framework of ship infos
  int x;
  gotoxy(72, 23);
  printf("%c", 201);
  for (x = 0; x < 35; x++) {
    printf("%c", 205);
  }
  printf("%c", 187);

  gotoxy(72, 25);
  printf("%c", 200);
  for (x = 0; x < 35; x++) {
    printf("%c", 205);
  }
  printf("%c", 188);
  gotoxy(72, 24);
  printf("%c You DESTROYED the ", 186);

}

void gameOver() {
  int i, y = 4, length, ch1 = 219, ch2 = 176;

  //TEXTS OF THE GAME LOGO
  char bir[] = "XXXXXXXX        XXXX      XXXX      XXXX  XXXXXXXXXXXX";
  char iki[] = "XXXXAAAAXXXX    XXXXXXXX    XXXXXX  XXXXXXAAXXXXXXXXXXXXAA\nXXXXAA    AAAAXXXXXXXXXXXX  XXXXXXXXXXXXXXAAXXXXAAAAAAAAAA\n";
  char uc[] = "XXXXAAXXXXXX  XXXXAAAAXXXXAAXXXXAAXXAAXXXXAAXXXXXXXXXX\nXXXXAA  XXXXAAXXXXAA  XXXXAAXXXXAA  AAXXXXAAXXXXXXXXXXAA\n";
  char dort[] = "XXXXAA  XXXXAAXXXXXXXXXXXXAAXXXXAA    XXXXAAXXXXAAAAAAAA\nXXXXXXXXXXXXAAXXXXAAAAXXXXAAXXXXAA    XXXXAAXXXXXXXXXXXX\n";
  char bes[] = "XXXXXXXXAAAAXXXXAA  XXXXAAXXXXAA    XXXXAAXXXXXXXXXXXXAA";
  char alti[] = "AAAAAAAA    AAAA    AAAA  AAAA      AAAA  AAAAAAAAAAAA";

  //TEXTS OF THE OVER LOGO
  char yedi[] = "XXXXXXXX    XXXX    XXXX  XXXXXXXXXXXX  XXXXXXXXXX";
  char sekiz[] = "XXXXAAAAXXXX  XXXXAA  XXXXAAXXXXXXXXXXXXAAXXXXAAAAXXXX\nXXXXAA  XXXXAAXXXXAA  XXXXAAXXXXAAAAAAAAAAXXXXAA  XXXXAA\n";
  char dokuz[] = "XXXXAA  XXXXAAXXXXAA  XXXXAAXXXXXXXXXX    XXXXAA  XXXXAA\nXXXXAA  XXXXAAXXXXAA  XXXXAAXXXXXXXXXXAA  XXXXXXXXXXAAAA\n";
  char on[] = "XXXXAA  XXXXAAXXXXAA  XXXXAAXXXXAAAAAAAA  XXXXXXXXXXAA\nXXXXAA  XXXXAA  XXXXXXXXAAAAXXXXXXXXXXXX  XXXXAAXXXXXX\n";
  char onbir[] = "XXXXXXXXAAAA    XXXXAAAA  XXXXXXXXXXXXAAXXXXAA  XXXXAA";
  char oniki[] = "AAAAAAAA        AAAA      AAAAAAAAAAAA  AAAA    AAAA";

  // -| PRINTING GAME LOGO |-
  gotoxy(31, 2);
  length = strlen(bir);
  for (i = 0; i < length; i++) {
    if (bir[i] == 'X') {
      printf("%c", ch1);
    } else if (bir[i] == 'A') {
      printf("%c", ch2);
    } else {
      printf(" ");
    }
  }

  gotoxy(29, 3);
  length = strlen(iki);
  for (i = 0; i < length; i++) {
    if (iki[i] == '\n') {
      gotoxy(29, y);
      ++y;
    } else if (iki[i] == 'X') {
      printf("%c", ch1);
    } else if (iki[i] == 'A') {
      printf("%c", ch2);
    } else {
      printf(" ");
    }
  }

  length = strlen(uc);
  for (i = 0; i < length; i++) {
    if (uc[i] == '\n') {
      gotoxy(29, y);
      ++y;
    } else if (uc[i] == 'X') {
      printf("%c", ch1);
    } else if (uc[i] == 'A') {
      printf("%c", ch2);
    } else {
      printf(" ");
    }
  }

  length = strlen(dort);
  for (i = 0; i < length; i++) {
    if (dort[i] == '\n') {
      gotoxy(29, y);
      y++;
    } else if (dort[i] == 'X') {
      printf("%c", ch1);
    } else if (dort[i] == 'A') {
      printf("%c", ch2);
    } else {
      printf(" ");
    }
  }

  gotoxy(31, 9);
  length = strlen(bes);
  for (i = 0; i < length; i++) {
    if (bes[i] == 'X') {
      printf("%c", ch1);
    } else if (bes[i] == 'A') {
      printf("%c", ch2);
    } else {
      printf(" ");
    }
  }

  gotoxy(33, 10);
  length = strlen(alti);
  for (i = 0; i < length; i++) {
    if (alti[i] == 'X') {
      printf("%c", ch1);
    } else if (alti[i] == 'A') {
      printf("%c", ch2);
    } else {
      printf(" ");
    }
  }

  // -| PRINGTING OVER LOGO |-

  y = 12;
  gotoxy(31, y);
  length = strlen(yedi);
  for (i = 0; i < length; i++) {
    if (yedi[i] == 'X') {
      printf("%c", ch1);
    } else if (yedi[i] == 'A') {
      printf("%c", ch2);
    } else {
      printf(" ");
    }
  }

  y = 14;

  gotoxy(29, 13);
  length = strlen(sekiz);
  for (i = 0; i < length; i++) {
    if (sekiz[i] == '\n') {
      gotoxy(29, y);
      ++y;
    } else if (sekiz[i] == 'X') {
      printf("%c", ch1);
    } else if (sekiz[i] == 'A') {
      printf("%c", ch2);
    } else {
      printf(" ");
    }
  }

  gotoxy(29, y - 1);
  length = strlen(dokuz);
  for (i = 0; i < length; i++) {
    if (dokuz[i] == '\n') {
      gotoxy(29, y);
      ++y;
    } else if (dokuz[i] == 'X') {
      printf("%c", ch1);
    } else if (dokuz[i] == 'A') {
      printf("%c", ch2);
    } else {
      printf(" ");
    }
  }

  gotoxy(29, y - 1);
  length = strlen(on);
  for (i = 0; i < length; i++) {
    if (on[i] == '\n') {
      gotoxy(29, y);
      ++y;
    } else if (on[i] == 'X') {
      printf("%c", ch1);
    } else if (on[i] == 'A') {
      printf("%c", ch2);
    } else {
      printf(" ");
    }
  }

  gotoxy(31, y - 1);
  length = strlen(onbir);
  for (i = 0; i < length; i++) {
    if (onbir[i] == '\n') {
      gotoxy(29, y);
      ++y;
    } else if (onbir[i] == 'X') {
      printf("%c", ch1);
    } else if (onbir[i] == 'A') {
      printf("%c", ch2);
    } else {
      printf(" ");
    }
  }

  gotoxy(33, y);
  length = strlen(oniki);
  for (i = 0; i < length; i++) {
    if (oniki[i] == '\n') {
      gotoxy(29, y);
      ++y;
    } else if (oniki[i] == 'X') {
      printf("%c", ch1);
    } else if (oniki[i] == 'A') {
      printf("%c", ch2);
    } else {
      printf(" ");
    }
  }

  Sleep(500);
  char main[] = "1) PLAY AGAIN";
  char main2[] = "2) MAIN MENU";
  char exit[] = "EXIT";

  // printing play again
  gotoxy(45, 24);
  for (i = 0; i < 13; i++) {
    printf("%c ", main[i]);
    Sleep(75);
  }
  gotoxy(45, 26);
  // printing main menu
  for (i = 0; i < 12; i++) {
    printf("%c ", main2[i]);
    Sleep(75);
  }

  gotoxy(45, 28);
  printf("3 )        ");

  // printing exit
  for (i = 0; i < 4; i++) {
    printf("%c ", exit[i]);
    Sleep(75);
  }

  gotoxy(118, 28);
}

void victory() {

  int i, length, y = 2, x = 53;
  // text version of the CUP

  char bir[] = "AAAAAAAAAAAA\nAACCCCAAAAAA\n";
  char iki[] = "AAAAAACCAAAAAAAAAAAA\nAA  AAAAAAAAAAAA  AA\n";
  char uc[] = "AAAAAAAAAAAAAAAA\nAAAAAAAA\n";

// printing CUP logo
  gotoxy(x, y);
  length = strlen(bir);
  for (i = 0; i < length; i++) {
    if (bir[i] == 'A') {
      printf("%c", 219);
    } else if (bir[i] == 'C') {
      printf(" ");
    } else {
      ++y;
      gotoxy(x, y);
    }
  }

  x = 49;
  gotoxy(x, y);
  length = strlen(iki);
  for (i = 0; i < length; i++) {
    if (iki[i] == 'A') {
      printf("%c", 219);
    } else if (iki[i] == 'C') {
      printf(" ");
    } else if (iki[i] == '\n') {
      ++y;
      gotoxy(x, y);
    } else {
      printf(" ");
    }
  }

  x = 51;
  gotoxy(x, y);
  length = strlen(uc);
  for (i = 0; i < length; i++) {
    if (uc[i] == 'A') {
      printf("%c", 219);
    } else {
      y += 1;
      x += 4;
      gotoxy(x, y);
    }
  }

  gotoxy(57, 8);
  printf("%c%c%c%c", 219, 219, 219, 219);
  gotoxy(57, 9);
  printf("%c%c%c%c", 219, 219, 219, 219);
  gotoxy(55, 10);
  printf("%c%c%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219);

  // Printing YOU WIN! logo

  char dort[] = "XX      XXXX    XXXXXX    XX    XXXX      XX      XXXX  XXXX  XX      XXXX  XXXX\nXXAA    XXXXAAXX  AAXXXX  XXAA  XXXXAA    XXAA    XXXXAAXXXXAAXXXX    XXXXAAXXXXAA\nXXAA  XXXXXXAAXXAA  XXXXAAXXAA  XXXXAA    XXAA    XXXXAAXXXXAAXXAAXX  XXXXAAXXXXAA\n";
  char bes[] = "XXXXXXXXAAAAXXAA  XXXXAAXXAA  XXXXAA    XXAAXX  XXXXAAXXXXAAXXAA  XXXXXXAAXXXXAA\n";
  char alti[] = "XXXXAAAA  XXAA  XXXXAAXXAA  XXXXAA    XXAAXXAAXXXXAAXXXXAAXXAA    XXXXAAXXXXAA\nXXXXAA    XXAA  XXXXAAXXAA  XXXXAA    XXAAXXAAXXXXAAXXXXAAXXAA    XXXXAA  AAAA\nXXXXAA      XXXXXXAAAA  XXXXXXAAAA      XX  XXXXAAAAXXXXAAXXAA    XXXXAAXXXX\n";
  char yedi[] = "AAAA        AAAAAA      AAAAAA          AA  AAAA    AAAA  AA      AAAA  AAAA";
  x = 19, y = 13;
  gotoxy(x, y);
  length = strlen(dort);
  for (i = 0; i < length; i++) {
    if (dort[i] == 'X') {
      printf("%c", 219);
    } else if (dort[i] == 'A') {
      printf("%c", 176);
    } else if (dort[i] == ' ') {
      printf(" ");
    } else {
      ++y;
      gotoxy(x, y);
    }
  }

  gotoxy(21, y);
  length = strlen(bes);
  for (i = 0; i < length; i++) {
    if (bes[i] == 'X') {
      printf("%c", 219);
    } else if (bes[i] == 'A') {
      printf("%c", 176);
    } else if (bes[i] == ' ') {
      printf(" ");
    } else {
      ++y;
      gotoxy(x, y);
    }
  }

  x = 23;
  gotoxy(x, y);
  length = strlen(alti);
  for (i = 0; i < length; i++) {
    if (alti[i] == 'X') {
      printf("%c", 219);
    } else if (alti[i] == 'A') {
      printf("%c", 176);
    } else if (alti[i] == ' ') {
      printf(" ");
    } else {
      ++y;
      gotoxy(x, y);
    }
  }

  gotoxy(25, y);
  length = strlen(yedi);
  for (i = 0; i < length; i++) {
    if (yedi[i] == 'A') {
      printf("%c", 176);
    } else {
      printf(" ");
    }

  }

  //printing bottom menu side

  Sleep(500);
  char main[] = "1) PLAY AGAIN";
  char main2[] = "2) MAIN MENU";
  char exit[] = "EXIT";

  gotoxy(45, 24);
  for (i = 0; i < 13; i++) {
    printf("%c ", main[i]);
    Sleep(75);
  }

  gotoxy(45, 26);
  for (i = 0; i < 12; i++) {
    printf("%c ", main2[i]);
    Sleep(75);
  }

  gotoxy(45, 28);
  printf("3 )        ");

  for (i = 0; i < 4; i++) {
    printf("%c ", exit[i]);
    Sleep(75);
  }
  gotoxy(117, 29);
}
