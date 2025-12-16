#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "backrooms-inc.h"

void draw_wallpaper(void) {
 int rows = ((ws.ws_row - 2 - 11) / 10) - 2;
 int cols = ((ws.ws_col - 2) / 19) - 2;

 fputs("\033[93;43m", stdout);
 // TODO = add improved colors for terminals that support it

 FILE* top_left = fopen("paper-top-left.txt", "r");
 FILE* top_middle = fopen("paper-top-middle.txt", "r");
 FILE* top_right = fopen("paper-top-right.txt", "r");

 char buffer[65]; // box drawing characters may take up multiple chars

 int t = ws.ws_col - 40 - (19 * cols);

 for(int i = 0; i < 11; i++) {
  fgets(buffer, sizeof(buffer), top_left);
  buffer[strlen(buffer)-1] = 0;
  fputs(buffer, stdout);

  fgets(buffer, sizeof(buffer), top_middle);
  buffer[strlen(buffer)-1] = 0;
  for(int j = 0; j < cols; j++) {
   fputs(buffer, stdout);
  }

  fgets(buffer, sizeof(buffer), top_right);
  buffer[strlen(buffer)-1] = 0;
  fputs(buffer, stdout);

  for(int tt = 0; tt < t; tt++) { putchar(' '); }
  putchar('\n');
 }

 fclose(top_left);
 fclose(top_middle);
 fclose(top_right);

 FILE* middle_left = fopen("paper-middle-left.txt", "r");
 FILE* middle_middle = fopen("paper-middle-middle.txt", "r");
 FILE* middle_right = fopen("paper-middle-right.txt", "r");

 for(int i = 0; i < rows; i++) {
  for(int j = 0; j < 10; j++) {
   fgets(buffer, sizeof(buffer), middle_left);
   buffer[strlen(buffer)-1] = 0;
   fputs(buffer, stdout);

   fgets(buffer, sizeof(buffer), middle_middle);
   buffer[strlen(buffer)-1] = 0;
   for(int k = 0; k < cols; k++) {
    fputs(buffer, stdout);
   }

   fgets(buffer, sizeof(buffer), middle_right);
   buffer[strlen(buffer)-1] = 0;
   fputs(buffer, stdout);

   for(int tt = 0; tt < t; tt++) { putchar(' '); }
   putchar('\n');
  }

  rewind(middle_left);
  rewind(middle_middle);
  rewind(middle_right);
 }

 fclose(middle_left);
 fclose(middle_middle);
 fclose(middle_right);

 FILE* bottom_left = fopen("paper-bottom-left.txt", "r");
 FILE* bottom_middle = fopen("paper-bottom-middle.txt", "r");
 FILE* bottom_right = fopen("paper-bottom-right.txt", "r");

 for(int i = 0; i < 11; i++) {
  fgets(buffer, sizeof(buffer), bottom_left);
  buffer[strlen(buffer)-1] = 0;
  fputs(buffer, stdout);

  fgets(buffer, sizeof(buffer), bottom_middle);
  buffer[strlen(buffer)-1] = 0;
  for(int j = 0; j < cols; j++) {
   fputs(buffer, stdout);
  }

  fgets(buffer, sizeof(buffer), bottom_right);
  buffer[strlen(buffer)-1] = 0;
  fputs(buffer, stdout);

  for(int tt = 0; tt < t; tt++) { putchar(' '); }
  putchar('\n');
 }

 fclose(bottom_left);
 fclose(bottom_middle);
 fclose(bottom_right);

 puts("\033[0m");
}
