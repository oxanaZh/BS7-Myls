/*
 * myls.c
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#define MAX_PATH 1024

char path[MAX_PATH];
void *readPath(char *path);
int main(int argc, char *argv[]){
	if(argc > 1){
		strcpy(path, argv[1]);
	} else {
		getcwd(path, MAX_PATH);

	}
	printf("input path: %s", path);
	readPath(path);
	return 0;
}
void *readPath(char *path){
	char resolved_path[MAX_PATH];
	DIR *dir = NULL;
	struct dirent *dptr = NULL;
	char *dot = ".";
	if(realpath(path, resolved_path)){
		printf("resolved_path: %s\n", resolved_path);
		if((dir = opendir(resolved_path))){
			while((dptr = readdir(dir))){
				if(strncmp(dptr->d_name, dot,1) == 0  ){
					continue;
				}
				printf("%s\n",dptr->d_name);

			}
			closedir(dir);
		}
	}
	return NULL;

}
