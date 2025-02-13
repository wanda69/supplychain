#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
// components

void * safe_realloc(void * ptr, size_t nmem, size_t size) { // changes the size of a block (resizes)
    // check for multiplication overflow
    if (nmem > 0 && SIZE_MAX / nmem < size) {       // boolean expression
        fprintf(stderr, "memory allocation error");
        return NULL;
    }
    return realloc(ptr, nmem * size);
}

typedef struct Node {
    int data;
    struct Node * next; // The key is that each node stores the address (the pointer) of the next node, creating the chain.
} Node;

/*
    Every node is a simultaneous instance of data.
    if every node is a simultaneous instance of data, then ->

*/

// how to remove node from list?

    void remove_node(Node * head, int data) {
        Node * current = head;
        Node * previous = NULL;

        // step through the chain
        for (current; current != NULL; current = current->next) {
            // how do we assign previous?
            if (current->data != data) {
                previous = current;
            } else {
                previous->next = current->next;
                free(current);
                return;
            }
        }


    }

Node * new_node(Node * head, int data) { // Every time you call new_node, you are dynamically allocating memory for a single Node structure.
    struct Node * temp = (struct Node *)malloc(sizeof(struct Node));

    temp->data = data;
    temp->next = NULL;

    if (head == NULL) {
        return temp;
    } else {
        Node * current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = temp;
        return head;
    }


}

bool isSwapped() {

    }

Node * swap_node(Node * head) {
        bool sorted;
        Node * current = head;

        return current;

    }
void Print(Node * head) {
    for (Node * temp = head; temp != NULL; temp = temp->next) {
        printf("%d ", temp->data);
    }
}



struct memory {
        char * response;
        size_t size;
    };

size_t curl_callback(char *ptr, size_t size, size_t nmemb, void *userdata) {
    size_t multipliedSize = size * nmemb;   // newly arrived data...
    struct memory * mem = (struct memory *)userdata; // cast *userdata, why not use a safe-version?

    char *resp = safe_realloc(mem->response, mem->size + multipliedSize + 1, 1);


    if (!resp)
        return 0;

    mem->response = resp;
    memcpy(&(mem->response[mem->size]), ptr, multipliedSize);
    mem->size += multipliedSize;
    mem->response[mem->size] = 0;

    return multipliedSize;
}

int main(void) {
    CURL * curl;
    CURLcode res;

    FILE * fp;
    fp = fopen("text.txt", "w");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file\n");
    }


        curl_global_init(CURL_GLOBAL_WIN32);
        curl = curl_easy_init();

        const char * apiKey = "7832340f8d4e3c9cfa31dd0bdd95f20b";
        const char *url = "https://api.stlouisfed.org/fred/series/observations?series_id=GDP&api_key=";

        const char *totalproduction = "https://api.stlouisfed.org/fred/series/observations?series_id=INDPRO&api_key=7832340f8d4e3c9cfa31dd0bdd95f20b&file_type=json&observation_start=2025-01-01&observation_end=2025-01-31";



        const char * simpleUrl = "https://api.stlouisfed.org/fred/releases?api_key=7832340f8d4e3c9cfa31dd0bdd95f20b";

        struct memory chunk = {0};
        char * buffer;

        if (curl) {
            printf("Curl initialized\n\n");

            curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
            curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);


            curl_easy_setopt(curl, CURLOPT_URL, totalproduction);

            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, curl_callback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void*)&chunk);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)fp;


            res = curl_easy_perform(curl);

            if (res != CURLE_OK) {
                fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            }

            puts("opening GET in firefox...\n\n");
            char * command = "start firefox \"https://api.stlouisfed.org/fred/series/observations?series_id=INDPRO&api_key=7832340f8d4e3c9cfa31dd0bdd95f20b&file_type=json&observation_start=2025-01-01&observation_end=2025-01-31\"";

            int openBrowser = system(command);
            if (openBrowser == -1)
                puts("Browser not available.");

            puts(chunk.response);


            free(chunk.response);
            curl_easy_cleanup(curl);
        }
        curl_global_cleanup();

    printf("Supply Chain w/ components...\n");

    Node * head = new_node(NULL, 1);

    head = new_node(head, 10);
    head = new_node(head, 12);
    head = new_node(head, 13);

    Print(head);
    printf("\n");

    remove_node(head, 12);

    Print(head);
    printf("\n");


    return 0;
}