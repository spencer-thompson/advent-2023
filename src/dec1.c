#include <stdio.h>
#include <stdlib.h>

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
            // Check if digit and append as int to array
            if (buffer[i] >= '0' && buffer[i] <= '9') {
                array[j] = buffer[i] - '0';
                j++;
                int length = 0;
                for (int i = 0; array[i] != '\0'; i++) {
                    length++;
                }
            
            printf("%d", array[0]);
            printf("%d", array[length - 1]);
            }
        }
        printf("\n");
    }
    
    fclose(file);

    return 0;
}
