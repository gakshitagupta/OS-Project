#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
 
int main( int argc, char* argv[] ) {
    int a[2];
    pid_t childid;
 
    char b[50];
    char c[50];
    int readCounter;
 
    pipe( a);
 
    if( argc < 3 ) {
        printf( "Atleast need 2 params " );
        exit(1);
    }
 
    int fileOpen = open( argv[1], 0 );
    int targetFile = open( argv[2], 0666 );
     
    if ( fileOpen == -1 || targetFile == -1 ) {
        printf( "Opening file failed " );
        exit(1);
    }
    childid = fork();
 
    if( childid == 0 ) {
        // inside the child prcocess
        close( a[1] );
 
        read( a[0], b, sizeof( b ) );
        printf( "The recived string is : %s", b );
 
        //Writing to the target fileOpen
        write( targetFile,b, strlen( b ) + 1 );
    } else {
        // inside the parent process
        close( a[0] );
        // code to read from a text file
 
        while( (readCounter = read( fileOpen, b, sizeof( b ) ) > 0 ) )  {
        write( a[1], b, sizeof( b ) );
        }
        close( a[1] );
    }
}
