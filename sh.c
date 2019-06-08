#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <string.h>
#include <sys/wait.h>


int main()
{
    char cmd[80];
    char entrada[100];
    int status;
    pid_t p;
    const char s[] = " ";
    char *split;
    char* args[100];
    int i=0;

    while(1){
      printf("Shell >");
      fflush(stdin);
      //scanf("%[^\n]%*c",entrada);
      fgets(entrada, 100, stdin);
      entrada[strlen(entrada)-1 ]='\0';
      split = strtok(entrada, s);
      i=0;
      while( split != NULL ) {
        args[i] = split;
        i++;
        split = strtok(NULL, s);
      }
      args[i] = NULL;
      if (strcmp(entrada,"exit")==0){
        execlp("./getty","getty",NULL );
      }


      if (strcmp(entrada,"shutdown")==0){
        //kill all
        execlp ("killall", "killall", "-9", "xterm","init", NULL);
      }

      if (strcmp(entrada,"\n")==0){
        continue;
      }


      p = fork();
      if(p==0){
          execvp(args[0], args);

      }else {
        wait(&status);
      }
    }//end while



      printf("Ending-----");

    return 0;
}
