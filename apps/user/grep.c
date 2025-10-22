#include "app.h"
#include <string.h>

int main(int argc, char** argv) {
    if (argc != 3) {
        INFO("usage: grep [PATTERN] [FILE]");
        return -1;
    }

     /* Get the inode number of the file. */
        int file_ino = dir_lookup(workdir_ino, argv[2]);
        if (file_ino < 0) {
            INFO("grep: file %s not found", argv[2]);
            return -1;
            }
        char buf[BLOCK_SIZE];
        file_read(file_ino, 0, buf);
        char* token = strtok(buf, "\n");
        while (token != NULL) {
            char* line = strstr(token,argv[1]);
            if (line != NULL){
                printf("%s\n\r",token);
            }
            token = strtok(NULL, "\n");
            }
    return 0;
}
