#include "one.h"



one::one()
{
}


one::~one()
{
}
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>
#include <sysexits.h>
#include <sys/wait.h>
#include <iostream>
using namespace std;


char * getinput(char *buffer, size_t buflen) {
	printf("$$ ");
	return fgets(buffer, buflen, stdin);
}
char * find(char t[]) {
	while (t != NULL) {
		for (size_t i = 0; i < strlen(t);i++) {
			char poo2[sizeof(t)];
			poo2[i] = t[i];
			if (t[i] == '|' || i == sizeof(t) - 1) {
				if (t[i] == '|') { cout << "pipe";
				cout << '\n';
				} //to print out pipe
				if (strchr(poo2, ';')) {
					for (size_t k = 0; k < strlen(t); k++) {
						int c = 0;
						if (t[k] == ' ' || k == sizeof(t) - 1) {
							size_t m;
							if (c == 0) {
								for (size_t m = 0; m < k;m++) {

									cout << "command: " << t[m];
									c = 1;
								}
								m = k;
								cout << '\n';
							}
							if (c == 1) {
								for (size_t n = m; m < k; n++) {
									char poo[sizeof(t)];
									poo[n] << t[n];
									if (strchr(poo, ';')) {
										cout << "semicolon " << poo;
										
									}
									else {
										cout << "Command: " << poo;
									}

								}
								m = k;
								cout << '\n';
							}
							for (size_t g = 0; g < i;g++) {
								poo2[g] = NULL;
							} //clear poo
				
				} //semicolon done
						if (strchr(poo2, '-')) {
							for (size_t k = 0; k < strlen(t); k++) {
								int c = 0;
								if (t[k] == ' ' || k == sizeof(t) - 1) {
									size_t m;
									if (c == 0) {
										for (size_t m = 0; m < k;m++) {

											cout << "command: " << t[m];
											c = 1;
										}
										m = k;
										cout << '\n';
									}
									if (c == 1) {
										for (size_t n = m; m < k; n++){
											char poo[sizeof(t)];
											poo[n] << t[n];
											
												cout << "Options: " << poo;
												c = 2;
											
											

										}
										m = k;
										cout << '\n';
									}
									else {
										for (size_t l = m; m < k; l++) {
											char poo[sizeof(t)];
											poo[l] << t[l];
											
											
												cout << "Arguments: " << poo;
											
										}
										cout << '\n';
									}
									for (size_t g = 0; g < i;g++) {
										poo2[g] = NULL;
									} //clear poo
						
						} //done with arugmenut
				if (strchr(poo2, '>') || strchr(poo2, '<')) {
					for (size_t k = 0; k < strlen(t); k++) {
						int c = 0;
						if (t[k] == ' ' || k == sizeof(t) - 1) {
							size_t m;
							if (c == 0) {
								for (size_t m = 0; m < k;m++) {

									cout << "command: " << t[m];
									c = 1;
								}
								m = k;
								cout << '\n';
							}
							if (c == 1) {
								for (size_t n = m; m < k; n++) {
									char poo[sizeof(t)];
									poo[n] << t[n];
									if (strchr(poo, '>') || strchr(poo, '<')) {
										cout << "File Redirection: " << poo;
										c = 2;
									}
									else {
										cout << "options: " << poo;
									}

								}
								m = k;
								cout << '\n';
							}
							else {
								for (size_t l = m; m < k; l++) {
									char poo[sizeof(t)];
									poo[l] << t[l];
									if (strchr(poo, '>') || strchr(poo, '<')) {
										cout << "File Redirection: " <<poo; 
										c = 3;
									}
									else {
										cout << "File: " << poo;
									}
								}
								cout << '\n';
							}
							for (size_t g = 0; g < i;g++) {
								poo2[g] = NULL;
							} //clear poo
						}  //end of >> and <<s

					}
				} //real end of >> and <<s


				else{ //for lines not including the redirects
					for (size_t k = 0; k < strlen(t); k++) {
						if (t[k] == ' ' || k == sizeof(t) - 1) {
							size_t m;
							for (size_t m = 0; m < k;m++) {

								cout << "command: " << t[m];
							}
							cout << '\n';
							for (size_t l = m; l < i;l++) {
								cout << "argument: " << t[l];
								k = l + 1;
							}
						}
						cout << '\n';
					}
					for (size_t g = 0; g < i;g++) {
						poo2[g] = NULL;
					} //clear poo
				} //end of lines normal
			}
		}
		
	
	} //now t is empty
}



int
main(int argc, char **argv) {
	char buf[1024];
	pid_t pid;
	int status;

	while (getinput(buf, sizeof(buf))) {
		buf[strlen(buf) - 1] = '\0';

		if ((pid = fork()) == -1) {
			fprintf(stderr, "shell: can't fork: %s\n",
				strerror(errno));
			continue;
		}
		else if (pid == 0) {
			/* child to run the command */
			find(buf);
				
			/* your code to parse the command & set any file redirection as needed */
			execlp(buf, buf, (char *)0);
			fprintf(stderr, "shell: couldn't exec %s: %s\n", buf,
				strerror(errno));
			exit(EX_DATAERR);
		}

		// parent is waiting
		if ((pid = waitpid(pid, &status, 0)) < 0)
			fprintf(stderr, "shell: waitpid error: %s\n",
				strerror(errno));
	}
	exit(EX_OK);
}

