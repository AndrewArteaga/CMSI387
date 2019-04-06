## **Problems 1-5** <br> By: Simon, Andrew, Riley

### 1)

```c
//https://www.thecrazyprogrammer.com/2017/06/dining-philosophers-problem-c-c.html used as reference
#include<stdio.h>
#define n 4

int compltedPhilo = 0,i;

struct fork{
    int taken;
}ForkAvil[n];

struct philosp{
    int left;
    int right;
}Philostatus[n];

void goForDinner(int philID){ //same like threads concept here cases implemented
    if(Philostatus[philID].left==10 && Philostatus[philID].right==10)
        printf("Philosopher %d completed his dinner\n",philID+1);
    //if already completed dinner
    else if(Philostatus[philID].left==1 && Philostatus[philID].right==1){
            //if just taken two forks
            printf("Philosopher %d completed his dinner\n",philID+1);

            Philostatus[philID].left = Philostatus[philID].right = 10; //remembering that he completed dinner by assigning value 10
            int otherFork = philID-1;

            if(otherFork== -1)
                otherFork=(n-1);

            ForkAvil[philID].taken = ForkAvil[otherFork].taken = 0; //releasing forks
            printf("Philosopher %d released fork %d and fork %d\n",philID+1,philID+1,otherFork+1);
            compltedPhilo++;
        }
        else if(Philostatus[philID].left==1 && Philostatus[philID].right==0){ //left already taken, trying for right fork
                if(philID==(n-1)){
                    if(ForkAvil[philID].taken==0){ //KEY POINT OF THIS PROBLEM, THAT LAST PHILOSOPHER TRYING IN reverse DIRECTION
                        ForkAvil[philID].taken = Philostatus[philID].right = 1;
                        printf("Fork %d taken by philosopher %d\n",philID+1,philID+1);
                    }else{
                        printf("Philosopher %d is waiting for fork %d\n",philID+1,philID+1);
                    }
                }else{ //except last philosopher case
                    int dupphilID = philID;
                    philID-=1;

                    if(philID== -1)
                        philID=(n-1);

                    if(ForkAvil[philID].taken == 0){
                        ForkAvil[philID].taken = Philostatus[dupphilID].right = 1;
                        printf("Fork %d taken by Philosopher %d\n",philID+1,dupphilID+1);
                    }else{
                        printf("Philosopher %d is waiting for Fork %d\n",dupphilID+1,philID+1);
                    }
                }
            }
            else if(Philostatus[philID].left==0){ //nothing taken yet
                    if(philID==(n-1)){
                        if(ForkAvil[philID-1].taken==0){ //KEY POINT OF THIS PROBLEM, THAT LAST PHILOSOPHER TRYING IN reverse DIRECTION
                            ForkAvil[philID-1].taken = Philostatus[philID].left = 1;
                            printf("Fork %d taken by philosopher %d\n",philID,philID+1);
                        }else{
                            printf("Philosopher %d is waiting for fork %d\n",philID+1,philID);
                        }
                    }else{ //except last philosopher case
                        if(ForkAvil[philID].taken == 0){
                            ForkAvil[philID].taken = Philostatus[philID].left = 1;
                            printf("Fork %d taken by Philosopher %d\n",philID+1,philID+1);
                        }else{
                            printf("Philosopher %d is waiting for Fork %d\n",philID+1,philID+1);
                        }
                    }
        }else{}
}

int main(){
    for(i=0;i<n;i++)
        ForkAvil[i].taken=Philostatus[i].left=Philostatus[i].right=0;

    while(compltedPhilo<n){
        /* Observe here carefully, while loop will run until all philosophers complete dinner
           Actually problem of deadlock occur only thy try to take at same time
           This for loop will say that they are trying at same time. And remaining status will print by go for dinner function
        */
    for(i=0;i<n;i++)
        goForDinner(i);
    printf("\nTill now num of philosophers completed dinner are %d\n\n",compltedPhilo);
    }

    return 0;
}
```

#### Answer/Explanation

A version of the Dining Philosophers program in C.

### 2)

#### Answer/Explanation

Deadlock is the state in a system where no progress is possible. The program in problem one avoids the deadlock through maintaining convention that all resources will be requested in order, and that gaurantees no two resources independant of eachother with respect to order will ever be used by a single unit of work at the same time. This is an example of an implementation of the resource hierarchy solution.

### 3)

```c
//https://www.lemoda.net/c/mmap-example/index.html as a reference
#include <sys/stat.h>
#include <sys/mman.h>
#include <errno.h>
#include <string.h>
#include <stdarg.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
static void
//cc file-processes.c && ./a.out
check (int test, const char * message, ...) {
    if (test) {
        va_list args;
        va_start (args, message);
        vfprintf (stderr, message, args);
        va_end (args);
        fprintf (stderr, "\n");
        exit (EXIT_FAILURE);
    }
}

int main () {
    int fd;
    struct stat s;
    int status;
    size_t size;
    const char * file_name = "file-ProcessTester.txt";
    const char * mapped;
    int i;
    fd = open ("file-ProcessTester.txt", O_RDONLY);
    check (fd < 0, "open %s failed: %s", file_name, strerror (errno));
    status = fstat (fd, & s);
    check (status < 0, "stat %s failed: %s", file_name, strerror (errno));
    size = s.st_size;
    mapped = mmap (0, size, PROT_READ, MAP_PRIVATE, fd, 0);
    check (mapped == MAP_FAILED, "mmap %s failed: %s",
           file_name, strerror (errno));
    for (i = 0; i < size; i++) {
        char c;
        c = mapped[i];
        if (! isupper(c)) {
            putchar (toupper(c));
        }
    }
    return 0;
}
```

#### Answer/Explanation

It capitlizes every char.

### 4)

```c
#include <sys/stat.h>
#include <sys/mman.h>
#include <errno.h>
#include <string.h>
#include <stdarg.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
static void
//cc mmap.c && ./a.out
check (int test, const char * message, ...) {
    if (test) {
        va_list args;
        va_start (args, message);
        vfprintf (stderr, message, args);
        va_end (args);
        fprintf (stderr, "\n");
        exit (EXIT_FAILURE);
    }
}

int main () {
    int fd;
    struct stat s;
    int status;
    size_t size;
    const char * file_name = "mmapTester.txt";
    const char * mapped;
    int i;
    fd = open ("mmapTester.txt", O_RDONLY);
    check (fd < 0, "open %s failed: %s", file_name, strerror (errno));
    status = fstat (fd, & s);
    check (status < 0, "stat %s failed: %s", file_name, strerror (errno));
    size = s.st_size;
    mapped = mmap (0, size, PROT_READ, MAP_PRIVATE, fd, 0);
    check (mapped == MAP_FAILED, "mmap %s failed: %s",
           file_name, strerror (errno));
    for (i = 0; i < size; i++) {
        char c;
        c = mapped[i];
        if (c == 'x') {
            printf("success\n");
            break;
        }
        if (i == size - 1) {
            printf("failure\n");
        }
    }
    return 0;
}
```

#### Answer/Explanation

Apparently the lyrics for All-Star by Smash Mouth doesn't contain the character x, therefore it is a failure.

### 5)

#### Answer/Explanation

The java class from chapter 4 that would be appropriate to use for the holding area would be the Bounded Buffer class. Since we want the alternate version of TopicServer to have the receive method place the message into temporary, the Bounded Buffer will do the following. "Every time the producer has a new value ready, the producer will store the value into an intermediate storage area, called a buffer. Every time the consumer is ready for the next value, it will retrieve the value from the buffer."