#include <stdio.h>
#include <stdlib.h>
#include "backrooms-inc.h"
#include <sys/ioctl.h>
#include <unistd.h>
#include <threads.h>

struct winsize ws;

char* msg;

char* msgs[] = {
 "The backrooms is a place beyond reality...\n"
 "You may have been there in your dreams, or you saw a hallway that looked unnatural.\n"
 "If you venture too far into one of those hallways, you might end up in the real backrooms, if it exists.\n"
 "But who knows? Maybe one day you'll be here, the next you'll be lost in the backrooms.",

 // I will add more here, just not yet
};

int buzz_loop(void* arg) {
 (void)arg;

 for(int j = 0; j < 1; j++) {
  int i = system("ffplay -autoexit -v fatal hum1.wav");
  if(i /* != 0 */) {
   exit(i);
  }
  msg = msgs[j];
 }

 puts("\033[2JThat's all. Goodbye.");
 exit(0);
}

int main(int argc, char* * argv) {
 if(argc != 2) {
  printf("Error: no termsup location provided. Use: %s terminal.tsp\n", argv[0]);
  return -1;
 }
 fetch_term_sup(argv[1]);
 ESC_SEQ_SETUP_NP();

 ioctl(STDIN_FILENO, TIOCGWINSZ, &ws);

 thrd_t buz;
 int err;
 if((err = thrd_create(&buz,&buzz_loop,NULL)) != thrd_success) {
  puts("Error in thread creation");
  return err;
 }

 msg =
  "If you're not careful and no-clip out of reality in wrong areas, you'll end up in the Backrooms,\n"
  " where it's nothing but the stink of moist carpet, the madness of mono-yellow,\n"
  " and endless background noise of fluorescent lights at maximum hum-buzz,\n"
  " and approximately six hundred million square miles of randomly segmented empty rooms to be trapped in.\n"
  "God save you if you hear something wandering around nearby, because it sure as hell has heard you...";

 for(;;) {
  puts("\033[2J\033[1;1H\033[22;43m");

  usleep((rand() % 1000000) + 100000);

  for(int i = 0; i < ws.ws_col; i++) { putchar(' '); }

  for(int i = 0; i < 6; i++) {
   int m = 0;
   for(int k = 0; k < 3; k++) {
    for(int j = 0; j < (ws.ws_col / 7); j++) {
     putchar(' ');
     m++;
    }
    for(int j = 0; j < (ws.ws_col / 6); j++) {
     fputs("█", stdout);
     m++;
    }
   }
   for(;m < ws.ws_col; m++) {
    putchar(' ');
   }
   putchar('\n');
  }
  for(int i = 0; i < ws.ws_col; i++) { putchar(' '); }

  putchar('\n');

  draw_wallpaper();
  puts(msg);

  sleep((rand() % 12) + 2);
 }
}
