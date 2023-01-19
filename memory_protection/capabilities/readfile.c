#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char **argv){

	FILE *fp = fopen(argv[1], "r");
	char buff[200];

	if(fp == NULL){
		printf("ERROR READING THE FILE!\n");
		return 1;
	}
	fgets(buff, 200, fp);
	printf("First line: %s\n", buff);

	return 0;
}

