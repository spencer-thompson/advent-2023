#include <stdio.h>
#include <stdlib.h>

int indexOf(char str[], char c) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c){
            return i;
        }
    }
    return -1;
}

int main() {
    FILE *file;
    char filename[] = "dec1.txt";
    char buffer[1000];
    
    file = fopen(filename, "r");
    

    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    while (fgets(buffer, sizeof(buffer), file) != NULL){
        // printf("%s", buffer);
        for (int i = 0; buffer[i] != '\0'; i++) {
            if (buffer[i] >= '0' && buffer[i] <= '9') {
                printf("%s", buffer[i]);
            }
        }
    }
    
    fclose(file);

    return 0;
}
