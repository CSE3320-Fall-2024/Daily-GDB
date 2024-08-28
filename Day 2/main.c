#include <stdio.h>
#include <stdlib.h>


int main( int argc, char * argv[] )
{
    FILE * fd;

    // Buffer to store the read data
    char buffer[100];

    printf("Opening the file\n");
 
    fd = fopen("MISSING_FILE", "r");
   
    // Data is read from the file into the buffer
    // sizeof(buffer) specifies the size of each element to
    // be read 1 is the number of elements to read
    // fd is the file to read from
    while (!feof(fd)) 
    {
 
        // Read from the file into the buffer and then print
        fread(buffer, sizeof(buffer), 1, fd);
        printf("%s", buffer);
    }
 
    fclose(fd);
}
