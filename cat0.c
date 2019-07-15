#include <stdio.h>
#include <fcntl.h> // para O_RDONLY
#include <unistd.h>

int close_file(int file_descriptor) {
    int result_close = close(file_descriptor);
    if (result_close == -1) { 
        perror(""); 
        return -1;
    }
    return 0;
}

int cat0(const char* filename) {
    int file_descriptor = open(filename, O_RDONLY);
    if (file_descriptor == -1) {
        perror("");
        return file_descriptor;
    }

    int N_BYTES = 128;
    void* buffer[N_BYTES];
    ssize_t readed_bytes = -1;

    while (readed_bytes) {
        // returns 0 si termina o -1 si error
        readed_bytes = read(file_descriptor, buffer, N_BYTES); 
        if (readed_bytes < 0) {
            perror("");
            close_file(file_descriptor);
        }

        ssize_t written_bytes = 0;
        while (written_bytes < readed_bytes) {
            // write a stdout
            written_bytes = write(STDOUT_FILENO, buffer + written_bytes,
                                  (size_t) (readed_bytes - written_bytes));
            if (written_bytes < 0) {
                perror("");
                close_file(file_descriptor);
            }
        }
    }
    close_file(file_descriptor);
}

int main(int argc, char *argv[]) {
    if (argc != 2) { 
        fprintf(stderr, "No se recibio el archivo a leer! \n");
        return -1; 
    }
    return cat0(argv[1]);
}