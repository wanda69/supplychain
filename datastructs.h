//
// Created by Lenovo on 2/17/2025.
//

#ifndef DATASTRUCTS_H
#define DATASTRUCTS_H
#include <sec_api/stdio_s.h>

#endif //DATASTRUCTS_H

typedef struct {

} Revenue;

typedef struct UnemploymentRate {
    char date[11];
    float rate;
} UnemploymentRate;

int read_csv(char * filename, UnemploymentRate ** data) {



    FILE * file;
    errno_t fileError = fopen_s(&file, filename, "r");
    if (fileError != 0) {
        fprintf(stderr, "File could not be opened\n");
    }


    char buffer[1024];

    int lineCnt = 0;
    while (fgets(buffer, 1024, file)) {
        lineCnt++;
    }

    *data = malloc(lineCnt * sizeof(UnemploymentRate));
    if (*data == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        fclose(file);
        return 0;
    }

    printf("number of lines %d", lineCnt);
    printf("\n");

    rewind(file);

    // skip one line
    fgets(buffer, 1024, file);

    memset(buffer, 0, 1024);



    int i = 0;
    while (fgets(buffer, 1024, file)) {
        char * token = strtok(buffer, ",");
        if (token) {
            strncpy((*data)[i].date, token, 11);
            token = strtok(NULL, ",");
            if (token) {
                size_t len = strlen(token);
                token[len - 1] = '\0';
                (*data)[i].rate = atof(token);
            }
        }
        memset(buffer, 0, 1024);
        i++;
    }




    fclose(file);
    return lineCnt;
}
void EmbedDataStruct() {

}typedef struct UnemploymentRate {
    char date[11]; // Store the date in YYYY-MM-DD format
    float rate;    // Unemployment rate as a percentage
} UnemploymentRate;
