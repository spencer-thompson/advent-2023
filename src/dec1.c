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

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        // printf("%s", buffer);
        for (int i = 0; buffer[i] != '\0'; i++) {
            int j = 0;
            int array[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
            if (buffer[i] >= '0' && buffer[i] <= '9') {
                // printf("%c", buffer[i]);

                array[j] = buffer[i] - '0';
                j++;
                // int first = 0;
                // if (first == 0) {
                    // printf("%c", buffer[i]);
                    // first = buffer[i] - '0';
                    // int last = first;
                // } else {
                    // int last = buffer[i] - '0';
                // }
            int length = 0;
            for (int i = 0; array[i] != '\0'; i++) {
                length++;
            }
            
            printf("%d", array[0]);
            printf("%d", array[length - 1]);
            // for (int i = 0; array[i] != '\0'; i++) {
            //     if (i == length - 1) {
            //         printf("%d", array[i]);
            //     }
            // }
            // printf("%d %d\n", first, last);
            }
        }
        printf("\n");
    }
    
    fclose(file);

    return 0;
}
