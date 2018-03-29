#include "three.h"



three::three()
{
}


three::~three()
{
}
/* implementing  "/bin/ps -ef | /bin/more" */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <iostream>
using namespace std;
char * getinput(char *buffer, size_t buflen) {
	printf("$$ ");
	return fgets(buffer, buflen, stdin);
}

int main(int argc, char **argv)
{
	char buf[1024];
	int fds[3];
	int child[3];
	char *argv[3];
	char cmd[sizeof(buf)];
	char opt[sizeof(buf)];
	char poo2[sizeof(buf)];
	char cmd2[sizeof(buf)];
	char opt2[sizeof(buf)];
	char cmd3[sizeof(buf)];
	char opt3[sizeof(buf)];
	char arg1[sizeof(buf)];
	char arg2[sizeof(buf)];
	char arg3[sizeof(buf)];
	
	pipe(fds);
	while (getinput(buf, sizeof(buf))) {
		while (buf != NULL) {
			for (size_t i = 0; i < strlen(buf);i++) {
				
				poo2[i] = buf[i];
				if (buf[i] == '|' || i == sizeof(buf) - 1) {
					
					if (strchr(poo2, ';')) {
						for (size_t k = 0; k < strlen(buf); k++) {
							int c = 0;
							if (buf[k] == ' ' || k == sizeof(buf) - 1) {
								size_t m;
								if (c == 0) {
									char poo[sizeof(buf)];
									for (size_t m = 0; m < k;m++) {

										poo[m] << buf[m];
										c = 1;
									}
									if (cmd == NULL) { strcpy(cmd, poo); }
									else if (cmd2 == NULL) { strcpy(cmd2, poo); }
									else {strcpy(cmd3, poo);
								}
									m = k;
									cout << '\n';
								}
								if (c == 1) {char poo[sizeof(buf)];
									for (size_t n = m; m < k; n++) {
										
										poo[n] << buf[n];
										

									}if (strchr(poo, ';')) {
										if (opt == NULL) {
											strcpy(opt, poo);
										}
										else if (opt2 == NULL) {
											strcpy(opt2, poo);
										}
										else { strcpy(opt3, poo); }

									}
										else {
											if (cmd == NULL) { strcpy(cmd, poo); }
											else if (cmd2 == NULL) { strcpy(cmd2, poo); }
											else {
												strcpy(cmd3, poo);
										}
									m = k;
									cout << '\n';
								}
								for (size_t g = 0; g < i;g++) {
									poo2[g] = NULL;
								} //clear poo

							} //semicolon done
							if (strchr(poo2, '-')) {
								for (size_t k = 0; k < strlen(buf); k++) {
									int c = 0;
									if (buf[k] == ' ' || k == sizeof(buf) - 1) {
										size_t m;
										if (c == 0) {
											char p[sizeof(buf)];
											for (size_t m = 0; m < k;m++) {
												
													p[m] << buf[m];
													
												c = 1;
											}
											if (cmd == NULL) { strcpy(cmd, p); }
											else if (cmd2 == NULL) { strcpy(cmd2, p); }
											else {
												strcpy(cmd3, p);
											}
											m = k;
											cout << '\n';
										}
										if (c == 1) {
											char p[sizeof(buf)];
											for (size_t n = m; m < k; n++) {
												
												p[n] << buf[n];

												
												c = 2;



											}


										
											if (opt == NULL) {
												strcpy(opt, p);
											}
											else if (opt2 == NULL) {
												strcpy(opt2, p);
											}
											else { strcpy(opt3, p); }
											m = k;
											cout << '\n';
										}
										else {char poo[sizeof(buf)];
											for (size_t l = m; m < k; l++) {
												
												poo[l] << buf[l];


											}if (arg1 == NULL) {
												strcpy(arg1, poo);
											}
											else if (arg2 == NULL) {
												strcpy(arg2, poo);
											}
											else { strcpy(arg3, poo); }
											m = k;
											cout << '\n';
										}
											cout << '\n';
										}
										for (size_t g = 0; g < i;g++) {
											poo2[g] = NULL;
										} //clear poo

									} //done with arugmenut
									if (strchr(poo2, '>') || strchr(poo2, '<')) {
										for (size_t k = 0; k < strlen(buf); k++) {
											int c = 0;
											if (buf[k] == ' ' || k == sizeof(buf) - 1) {
												size_t m;
												if (c == 0) {
													char p[sizeof(buf)];
													for (size_t m = 0; m < k;m++) {

														p[m]<< buf[m];
														c = 1;
													}
													if (cmd == NULL) { strcpy(cmd, p); }
													else if (cmd2 == NULL) { strcpy(cmd2, p); }
													else {
														strcpy(cmd3, p);
													}
													m = k;
													cout << '\n';
												}
												if (c == 1) {char poo[sizeof(buf)];
													for (size_t n = m; m < k; n++) {
														
														poo[n] << buf[n];
														if (strchr(poo, '>') || strchr(poo, '<')) {
															if (arg1 == NULL) {
																strcpy(arg1, poo);
															}
															else if (arg2 == NULL) {
																strcpy(arg2, poo);
															}
															else { strcpy(arg3, poo); }
															c = 2;
														}
														else {
															if (opt == NULL) {
																strcpy(opt, poo);
															}
															else if (opt2 == NULL) {
																strcpy(opt2, poo);
															}
															else { strcpy(opt3, poo); }
														}

													}
													m = k;
													cout << '\n';
												}
												else {
													for (size_t l = m; m < k; l++) {
														char poo[sizeof(buf)];
														poo[l] << buf[l];
														if (strchr(poo, '>') || strchr(poo, '<')) {
															if (arg1 == NULL) {
																strcpy(arg1, poo);
															}
															else if (arg2 == NULL) {
																strcpy(arg2, poo);
															}
															else { strcpy(arg3, poo); }
															c = 3;
														}
														else {
															if (opt == NULL) {
																strcpy(opt, poo);
															}
															else if (opt2 == NULL) {
																strcpy(opt2, poo);
															}
															else { strcpy(opt3, poo); }
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


									else { //for lines not including the redirects
										for (size_t k = 0; k < strlen(buf); k++) {
											if (buf[k] == ' ' || k == sizeof(buf) - 1) {
												size_t m;
												char poo[sizeof(buf)];
												for (size_t m = 0; m < k;m++) {

													poo[m] << buf[m];
												}
												if (cmd == NULL) { strcpy(cmd, poo); }
												else if (cmd2 == NULL) { strcpy(cmd2, poo); }
												else {
													strcpy(cmd3, poo);
													cout << '\n'; char p[sizeof(buf)];
												for (size_t l = m; l < i;l++) {
													p[l]<< buf[l];
													k = l + 1;
												}
												if (cmd == NULL) { strcpy(opt, p); }
												else if (cmd2 == NULL) { strcpy(opt2, p); }
												else {
													strcpy(opt3, p);
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
				}
			}
		}
	}

	if (fork() == 0)
	{
		close(fds[2]);
		close(STDIN_FILENO); dup(fds[1]);
		/* redirect standard input to fds[0] */

		execv(cmd3, opt3, arg3);
		exit(-1);
	}

	if (fork() == 0)
	{	
		close(fds[1]);
		close(STDIN_FILENO); dup(fds[0]);
		/* redirect standard input to fds[0] */
		
		execv(cmd2, opt2, arg2);
		exit(-2);
	}

	if (fork() == 0)
	{
		close(fds[0]);
		close(STDOUT_FILENO); dup(fds[2]);
		argv[0] = "/bin/ps";
		argv[1] = "-ef"; argv[2] = NULL;
		execv(cmd,opt, arg1);
		exit(-3);
	}

	close(fds[0]); close(fds[1]); close(fds[2]);
	wait(child);
	wait(child + 1);
	wait(child + 2);

	return 0;
}
