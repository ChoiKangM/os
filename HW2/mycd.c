#include <stdio.h>
#include <unistd.h>
#include "instructions.h"

/*
int cd(int argc, char *argv[]) {
	int pid, status;
	char* argv[] = { "cd", 0 }; //arg1은 관례적으로 프로그램명을 사용합니다
	pid = fork(); //프로세스 생성

	switch (pid) {
	case -1:
		printf("fork error \n");
		exit(1);

	case 0:
		execv("/bin/pwd", argv); //프로세스를 해당 경로의 프로그램으로 교체하고 argv를 넘겨줍니다
		printf("exec error \n");
		exit(1);

	default:
		wait(&status);
	}

	return 0;
}
*/
int mycd( int argc, char* argv[] ){ //cd : change directory
    if( argc == 1 )
        chdir( getenv( "HOME" ) );
    else if( argc == 2 ){
        if( chdir( argv[1] ) )
            printf( "No directory\n" );
    }
    else
        printf( "USAGE: cd [dir]\n" );
    
    return 1;
}