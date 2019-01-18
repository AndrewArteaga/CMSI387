#include <stdio.h>
#include <stdlib.h>
//gcc SayHello.c && ./a.out
int main( int argc, char * argv[] ) {
  char* input[100];
  printf( "" );
  char* nameInput = gets( input );
  printf("Hello,", nameInput, "\n");
  return 0;
}
