#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int length(int array[]) {
    int length = 0;
    for (int i = 0; array[i] != 0; i++) {
        length++;
    }
    return length;
}


typedef struct {
    char word[10];
    int val;
} numWord;


int check_word(char arr[], numWord allWords[]) {

}

int main() {
    FILE *file;
    char filename[] = "dec1.txt";
    char buffer[1000];
    
    file = fopen(filename, "r");
    
    // File stuff
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    numWord words[9];
    char *numbers[] = {"one!", "two!", "three!", "four!", "five!", "six!", "seven!", "eight!", "nine!"};
    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    for (int i = 0; i < 9; i++) {
        strcpy(words[i].word, numbers[i]);
        words[i].val = nums[i];
    }

    int total = 0;
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        // printf("%s", buffer);
        int j = 0;
        int k = 0;
        int array[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        

        //check if word is digit
        //TODO
        

        for (int i = 0; buffer[i + k] != '\0'; i++) {
            // Check if digit and append as int to array
            k = 0;
            if (buffer[i] >= '0' && buffer[i] <= '9') {
                array[j] = buffer[i] - '0';
                j++;

            } else {
                switch (buffer[i + k]) {
                    case 'o':
                        if (buffer[i + k + 1] == 'n' && buffer[i + k + 2] == 'e') {
                            array[j] = 1;
                            j++;
                        }
                        break;
                    case 't':
                        if (buffer[i + k + 1] == 'w' && buffer[i + k + 2] == 'o') {
                            array[j] = 2;
                            j++;
                        } else if (buffer[i + k + 1] == 'h' && buffer[i + k + 2] == 'r' && buffer[i + k + 3] == 'e' && buffer[i + k + 4] == 'e') {
                            array[j] = 3;
                            j++;
                        }
                        break;
                    case 'f':
                        if (buffer[i + k + 1] == 'o' && buffer[i + k + 2] == 'u' && buffer[i + k + 3] == 'r') {
                            array[j] = 4;
                            j++;
                        } else if (buffer[i + k + 1] == 'i' && buffer[i + k + 2] == 'v' && buffer[i + k + 3] == 'e') {
                            array[j] = 5;
                            j++;
                        }
                        break;
                    case 's':
                        if (buffer[i + k + 1] == 'i' && buffer[i + k + 2] == 'x') {
                            array[j] = 6;
                            j++;
                        } else if (buffer[i + k + 1] == 'e' && buffer[i + k + 2] == 'v' && buffer[i + k + 3] == 'e' && buffer[i + k + 4] == 'n') {
                            array[j] = 7;
                            j++;
                        }
                        break;
                    case 'e':
                        if (buffer[i + k + 1] == 'i' && buffer[i + k + 2] == 'g' && buffer[i + k + 3] == 'h' && buffer[i + k + 4] == 't') {
                            array[j] = 8;
                            j++;
                        }
                        break;
                    case 'n':
                        if (buffer[i + k + 1] == 'i' && buffer[i + k + 2] == 'n' && buffer[i + k + 3] == 'e') {
                            array[j] = 9;
                            j++;
                        }
                        break;
                    default:
                        k = 0;
                }
                // int flag = 0;

                // for (int m = 0; m < 9 && !flag; m++) {
                //     k = 0;
                //     while (buffer[i + k] != '\0') {
                //         if (buffer[i + k] == '\0' && words[m].word[k] == '\0') {
                //             array[j] = words[m].val;
                //             flag = 1;
                //             break;
                //         } else if (buffer[i + k] == words[m].word[k]) {
                //             k++;
                //         } else if (words[m].word[k] == '!') {
                //             array[j] = words[m].val;
                //             flag = 1;
                //             break;
                //         } else {
                //             k = 0;
                //             break;
                //         }
                //     }
                // }
                // check if next set of chars is a "digit" then append that digit
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
