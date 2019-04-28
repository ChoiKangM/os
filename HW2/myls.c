#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int myls()
{
    DIR *mydir;
    struct dirent *myfile;
    struct stat mystat;
    char *buffer;

   // Get the current working directory: 
   if( (buffer = getcwd( NULL, 0 )) == NULL )
      perror( "_getcwd error" );
   else
   {
      printf( "current directory : %s \n"
             "Number of internal elements : %d\n", buffer, strnlen(buffer)-1 );
       // strnlen include terminating null byte('\0')
   }
    
    mydir = opendir(buffer);
    while((myfile = readdir(mydir)) != NULL)
    {
        stat(myfile->d_name, &mystat);    
        printf("%d",mystat.st_size);
        printf(" %s\n", myfile->d_name);
    }
    closedir(mydir);
    free(buffer);
    return 0;
}