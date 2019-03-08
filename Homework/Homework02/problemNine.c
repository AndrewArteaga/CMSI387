#include <unistd.h>
//gcc problemNine.c && ./a.out
int main(int argc, char **argv) {
   int i; for(i = 0; i < 3; i++) {
      /* loops 3 times */ fork();
      /* each time calling fork */
   } 
   sleep(30); /* then sleeps 30 seconds */
}