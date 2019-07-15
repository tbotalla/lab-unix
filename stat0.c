#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>

int stat0(const char* filename) {
    struct stat buf;
    int result_stat = stat(filename, &buf);
    if (result_stat == -1) {
        perror("");
        return result_stat;
    }
    int size = buf.st_size;
    // POSIX macro para verificar si es directorio
    printf("Size: %d \nFile: %s \nType: %s",
           size, filename, S_ISDIR(buf.st_mode) ? "directory\n" : "regular file\n");
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 2) { 
        fprintf(stderr, "No se recibio el archivo a analizar! \n");
        return -1; 
    }
    return stat0(argv[1]);
}
