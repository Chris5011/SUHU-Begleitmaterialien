#include <stdio.h>
#include <unistd.h>

int main(){
	
	gid_t callingGID = getgid();
	gid_t executingGID = getegid();

	printf("Calling GID: %d\n", callingGID);
	printf("Executing GID: %d\n", executingGID);

	return 0;

}
