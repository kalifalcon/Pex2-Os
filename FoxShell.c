#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "list.h"

node* list = NULL;
void breakItDown(char*, char**);
void execute(char* cmdArray[]);
void addToList(char* currentCMDArray);
int main(){
	char input[64];
	char cwd[512];
	char *currentCMD;
	char* currentCMDArray[8];

	while(strcmp(input, "exit") != 0)
	{
		getcwd(cwd, sizeof(cwd));
        	printf ("%s:# ", cwd);
		fgets(input, sizeof(input), stdin);
		if(strlen(input)>0)
		{
			currentCMD = strtok(input, "\n");
			breakItDown(currentCMD, currentCMDArray);
			if(!strcmp(currentCMDArray[0], "recall"))
			{
				breakItDown(list_get(list, atoi(currentCMDArray[1])),currentCMDArray);
				
			}
			if(strcmp(currentCMDArray[0], "cd") == 0)
			{	
				chdir(currentCMDArray[1]);
				addToList(currentCMD);
			}

			else if(!strcmp(currentCMDArray[0], "history")){

				if(currentCMDArray[1] == NULL)
				{
					list_print(list);
				}
				else
				{
					if(atoi(currentCMDArray[1])>list_length(list)|| atoi(currentCMDArray[1]) == 0)
					{
						printf("Nothing there\n");
					}
					else
					{
						list_printn(list, atoi(currentCMDArray[1]));
					}
				}
			}
			else
			{
				execute(currentCMDArray);
				addToList(currentCMD);
			}
			fflush (stdout);
		}
	}
	list_destroy(list);
	return 1;
}

void addToList(char* currentCMD)
{
	list = list_remove(list, currentCMD);
	list = list_insert_tail(list, currentCMD);
	if(list_length(list)>10)
	{
		list_removen(list, 1);

	}
}
	
void breakItDown(char* string, char* currentCMDArray[]){ 
    
  char* pch = strtok (string," ");
  int i = 0;
  while (pch != NULL)
  {
    currentCMDArray[i] = malloc(strlen(pch) + 1);
    strcpy(currentCMDArray[i], pch);
    pch = strtok (NULL, " ");
    i++;
  }
  currentCMDArray[i] = NULL; //Fixes an error above
}

void execute(char* cmdArray[]){
    pid_t pid;
    int status;
    
    pid = fork();
    if(pid == 0){
        if(execvp(*cmdArray, cmdArray) < 0){
            exit(0);
        }
    }
    else{
        while(wait(&status)!=pid);
    }
}

