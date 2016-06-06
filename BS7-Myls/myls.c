/*
 * myls.c
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#define MAX_PATH 1024

char path[MAX_PATH];
void *readPath(char *path, int, int);
int main(int argc, char *argv[]){
	if(argc > 1){
		strcpy(path, argv[1]);
	} else {
		getcwd(path, MAX_PATH);

	}
	printf("input path: %s", path);
	int c;
	int aoption = 0;
	int loption = 0;
	 while ( (c = getopt(argc, argv, "al")) != -1) {
	        switch (c) {
	        case 'a':
	        	aoption = 1;
	        	break;
	        case 'l':
	        	loption = 1;
	        	break;
//eq
	        }
	    }


	readPath(path,aoption,loption);
	return 0;
}
void *readPath(char *path,int aoption, int loption){
	char resolved_path[MAX_PATH];
	DIR *dir = NULL;
	struct dirent *dptr = NULL;
	char *dot = ".";
	if(realpath(path, resolved_path)){
		printf("resolved_path: %s\n", resolved_path);
		if((dir = opendir(resolved_path))){
			while((dptr = readdir(dir))){
				if(!aoption){
				if(strncmp(dptr->d_name, dot,1) == 0  ){
					continue;
				}
				}
				printf("%s\n",dptr->d_name);

			}
			closedir(dir);
		}
	}
	return NULL;

}
