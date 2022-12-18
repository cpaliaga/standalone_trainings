#include <sys/types.h> /* open() dependencies */
#include <sys/stat.h> /* open() dependencies */
#include <fcntl.h> /* open() dependencies */
#include <stdio.h> /* printf() dependencies */
 #include <unistd.h> /* read() and close() dependencies */
/* int open(const char *pathname, int flags, mode_t mode); */
/* The  argument flags must include one 
of the following access modes: O_RDONLY, O_WRONLY, or O_RDWR.  
These request opening the file read-only, write-only, or read/write, 
respectively. */
/* 00700 user (file owner) has read, write, and execute permission */
/* Create an empty file if not exist al same tiem to open 
int fd = open("file.txt", O_CREAT | O_RDWR, 0700); 
*/
int main(int argc, char argv[])
{
    //char *path_file;
    int fd;
    ssize_t bytes;
    int fd2;
    char buff[500];

    fd = open("quijote.txt", O_RDWR, 0700);
    if (fd == -1)
    {
        printf("Open was fail %d \n", fd);
        return (0);
    }
    else
    {
        printf("File is open %d \n", fd);
        bytes = read(fd, buff, 500);
        if (bytes == -1)
        {
            printf("Read was fail %d \n", bytes);
            return (NULL);
        }
        printf("Reading ... %s \n", buff); 
    }

    fd2 = open("quijote2.txt", O_CREAT | O_RDWR, 0700);
    if (fd2 == -1)
    {
        printf("Open was fail %d \n", fd2);
        return (0);
    }
    printf("File is created or open %d \n", fd);
    /// @brief Write 500 bytes of content from read on 'fd' to 'fd2'
    /// @param fd2 - Destinity
    /// @param buff - Source
    /// @return new file "quijote2.txt"
    write(fd2, buff, 500);

    close(fd);
    close(fd2);
    return (0);
}