#include <stdio.h>
int main() {
  char bytes[204800];
  size_t sizeOfArray = sizeof(bytes);

  int i;
  int j;
  
  for (size_t j = 0; j < 100; j++) {
    for(i = 4095; i < sizeOfArray; i += 4096) {
      bytes[i];
    }
  }

  return 0; 
}