#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/prctl.h>
#include <linux/seccomp.h>

int main(){
	
	FILE *f1 = fopen("f1", "w");
	fprintf(f1, "TEST1\n");

	prctl(PR_SET_SECCOMP, SECCOMP_MODE_STRICT);

	fprintf(f1, "TEST2\n");
	fflush(f1);

	FILE *f2 = fopen("f2", "w");
	fprintf(f2, "TEST1\n");
	
	return 0;
}
