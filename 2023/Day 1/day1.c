#include <stdio.h>
#include <stdlib.h>
#include "../Support_files/Linked_list/linked_list.h"

int parse_line_number(List *l);

int main() {

    FILE *file;
    List *textLine = NULL;
    int calibrationValues = 0;

    file = fopen("input.txt", "r");

    if(file == NULL) {
        printf("Error reading file!\n");
        return -1;
    }

    while(!feof(file)) {
        char c;
        fscanf(file, "%c", &c);
        if(c >= '0' && c <= '9') {
            textLine = insert_back(textLine, c);
        }
        if(c == '\n') {
            calibrationValues += parse_line_number(textLine);
            destroy(textLine);
            textLine = NULL;
        }
    }

    // Getting the input from the last line
    if(textLine != NULL) {
        calibrationValues += parse_line_number(textLine);
        destroy(textLine);
        textLine = NULL;
    }

    printf("The sum of the calibration values is: %d\n", calibrationValues);

    fclose(file);
    return 0;
}

int parse_line_number(List *l) {
    int tens = 0;
    int unit = 0;
    List *temp = l;

    while(temp->next != NULL) 
        temp = temp->next;

    tens = (l->data - '0') * 10;
    unit = temp->data - '0';

    return tens + unit;
}