#include <stdio.h>
#include <unistd.h>

int main(){
	
	uid_t callingUID = getuid();
	uid_t executingUID = geteuid();

	printf("Calling UID: %d\n", callingUID);
	printf("Executing UID: %d\n", executingUID);

	return 0;

}
