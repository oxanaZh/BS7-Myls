/*
 * myls.c
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATH 1024

char path[MAX_PATH];

int main(int argc, char *argv[]){
	if(argc > 1){
		strcpy(path, argv[1]);
	} else {
		getcwd(path, MAX_PATH);

	}
	printf("input path: %s", path);
	return 0;
}
