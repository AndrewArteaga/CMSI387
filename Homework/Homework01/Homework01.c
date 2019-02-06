//#7 for Homework01
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
//gcc Homework01.c && ./a.out
int main(int argc, char *argv[]){
    char name[100];
    char age[8];
    char classYear[16];
    char ssNumber[36];
    char dignity[5];
    char fight[4];
    printf("What's your name?\n");
    fgets(name,20,stdin);
    printf("What's your age?\n");
    fgets(age,8,stdin);
    printf("What's your class year?\n");
    fgets(classYear,16,stdin);
    printf("What's your Social Security Number?\n");
    fgets(ssNumber,36,stdin);
    printf("Do you have any dignity?\n");
    fgets(dignity,5,stdin);
    printf("Can I fight you?\n");
    fgets(fight,4,stdin);
    printf("Name: %s \nAge: %s \nYear: %s \nSSN: %s \nDignity: %s \nReady To Fight: %s \n", name, age, classYear, ssNumber, dignity, fight);
    return 0;
}