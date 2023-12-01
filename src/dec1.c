#include <stdio.h>
#include <stdlib.h>

int length(int array[]) {
    int length = 0;
    for (int i = 0; array[i] != 0; i++) {
        length++;
    }
    return length;
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

    int total = 0;
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        // printf("%s", buffer);
        int j = 0;
        int array[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        for (int i = 0; buffer[i] != '\0'; i++) {
            // Check if digit and append as int to array
            if (buffer[i] >= '0' && buffer[i] <= '9') {
                array[j] = buffer[i] - '0';
                j++;

            }
        }
        int length_a = length(array);
        total += (array[0] * 10) + array[length_a-1];
        printf("%d", array[0]);
        printf("%d", array[length_a-1]);
        printf("\n");
    }
    // answer yay
    printf("%d", total);
    fclose(file);

    return 0;
}
