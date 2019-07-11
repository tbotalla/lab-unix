#include <stdio.h>
#include <unistd.h>

int rm0(const char* filename) {
    int result = unlink(filename);
    if (result == -1) {
        fprintf(stderr, "rm0: No se pudo eliminar '%s': ", filename);
        perror(""); // Printea msg asociado al errno
    }
    return result;
}

int main(int argc, char *argv[]) {
    if (argc < 2) { 
        fprintf(stdout, "No se recibio el archivo a eliminar! \n");
        return -1; 
    }
    return rm0(argv[1]);
}