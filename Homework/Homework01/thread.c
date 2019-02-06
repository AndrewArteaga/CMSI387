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