**Problems 1-6** <br> By: Simon, Andrew, Riley
=================================================
### 1)
#### Answer/Explanation:
 Although middleware and operating systems are similar in the way they are both software built to run other software, there are some distinctions. The difference is that an operating system uses features supported in the hardware to provide the services in its API while middleware, aptly named, acts as a middleman between the operating system and application and provides more functionality in comparison.
### 2)
#### Answer/Explanation:
Essentially, threads and processes can accomplish the same thing, which is any sequence of computational steps. The main difference is the work each is used for. A process can contain multiple threads, so threads are used for smaller tasks whereas processes are usually (used for)? the execution of applications.
### 3)
#### Answer/Explanation:
 As a group, we are most looking forward to learning both about and how to execute multiple computations on one computer. We found this to be the most interesting topic because when you sit down to think about how many different processes a computer is easily capable of performing it can be quite mind boggling, especially when we have trouble being able to perform simple daily tasks like focusing on OS without thinking about sleep.
### 4)
#### Answers/Explanation:
 - a) 2.101 seconds
 - b) 1.301 seconds
 - c) In our opinion, the method used in part B is more efficient because it saves about 800 milliseconds of overall elapsed time by minimizing the amount of dead time where the processor would be idle when it could be working on a thread.
### 5)
```c++
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
//gcc thread.c && ./a.out
static void *infinite(void *ignored){
    while (1) {    
        sleep(5);
        printf("It's been 5 seconds.\n");
    } 
}
int main(int argc, char *argv[]){
    char input[100];
    pthread_t infinite_thread;
    int code;
    code = pthread_create(&infinite_thread, NULL, infinite, NULL);
    fgets(input,sizeof(input),stdin);
    if (input[0]=='\n') { 
        pthread_cancel(infinite_thread);  
        printf("Thread has been terminated good day\n");
        pthread_exit(NULL);   
    } 
    return 0;
}
```
#### Answer/Explanation:
Yes, the sleeping thread can print out its periodic messages while the main thread is waiting for keyboard input. Yes, the main thread can read input, kill the sleeping thread, and print a message while the sleeping thread is in the early part of one of its five-second sleeps.
### 6)

#### Answer/Explanation:
 - a) raw array :
   - void shuffle(int array[], int arrlength)
 - b) std::array :
   - void shuffle(std::array<int, arrlength>&, array)
