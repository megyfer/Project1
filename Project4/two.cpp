#include "two.h"



two::two()
{
}


two::~two()
{
}
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sysexits.h>
#include <io.h>
#include <fcntl.h>

char * getinput(char *buffer, size_t buflen) {
	printf("$$ ");
	return fgets(buffer, buflen, stdin);
}
int main(int argc, char **argv)
{
	char buf[1024];
	int pid, status;
	int fdout;	               /* file descriptor for output */
		char cmd1[sizeof(buf)];
		char cmd2[sizeof(buf)];
		char cmd3[sizeof(buf)];
		char red[sizeof(buf)];
		char red2[sizeof(buf)];
	while (getinput(buf, sizeof(buf))) {
		
		for (size_t k = 0; k < strlen(buf); k++) {
			int c = 0;
			if (buf[k] == ' ' || k == sizeof(buf) - 1) {
				size_t m;
				if (c == 0) {
					for (size_t m = 0; m < k;m++) {
					
						cmd1[m]  << buf[m];
						c = 1;
					}
					m = k;
				} //command 1
				
				if (c == 1) {
					for (size_t n = m; m < k; n++) {
						char poo[sizeof(buf)];
						poo[n] << buf[n];
						if (strchr(poo, '>') || strchr(poo, '<')) {
							strcpy(red, poo);
							c = 2;
						}
						else {
							strcpy(cmd2, poo);
						}
						
					}
					m = k;
				} //gonna be file redirect
				if(c==2) {
					for (size_t l = m; m < k; l++) {
						char poo[sizeof(buf)];
						poo[l] << buf[l];
						if (strchr(poo, '>') || strchr(poo, '<')) {
							strcpy(red2, poo);
							c = 3;
						}
						else {
							strcpy(red2, poo);
						}
					}
					
				}
			}  //end of >> and <<s

		}
	}
	

	if ((fdout = open(red, O_CREAT | O_TRUNC | O_WRONLY, 0644)) < 0) {
		perror(red);	/* open failed */
		exit(1);
	}

	printf("writing output of the command %s to \"%s\"\n", cmd1, red);

	dup2(fdout, 1);
	execlp(cmd1, cmd1, cmd2, (char *)0);

	perror(cmd1);		/* execvp failed */
	exit(1);

}
