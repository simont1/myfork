#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>



int main(){
  srand(time(NULL));
  int num1 = rand()%5 + 5;
  int num2 = rand()%5 + 5;
  int status;

  printf("I am parent: %d\n", getpid());
  int child = fork();
  if(!child){
    printf("Hi my name is: %d\n", getpid());
    sleep(num1);
    printf("Child%d has slept for %d seconds!\n", getpid(), num1);
    return num1;
  }
  else{
    int child2 = fork();
    if(child2==0){
    printf("Hi my name is: %d\n", getpid());
    sleep(num2);
    printf("Child%d has slept for %d seconds!\n", getpid(), num2);
    return num2;
    }
    else{
      int cpid = wait(&status);
      printf("Parent waited %d seconds for child %d\n", WEXITSTATUS(status), cpid);
      return 0;
    }
  }
  sleep(5);
  printf("awake\n");
  return 0;
}
