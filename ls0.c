#include <stdio.h>
#include <dirent.h>

int ls0() {
    DIR* curr_dir = opendir(".");
    if (curr_dir == NULL) perror("");
    
    struct dirent* node;
    for (node = readdir(curr_dir); node != NULL; node = readdir(curr_dir)){
        if (strcmp(node->d_name, ".") == 0 || strcmp(node->d_name, "..") == 0) continue; 
        printf("%s \n", node->d_name);
    }
    
    int close_result = closedir(curr_dir);
    return close_result;
}

int main() {
    return ls0();
}
