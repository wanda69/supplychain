#include <curl/curl.h>
#include <jansson.h>

//
// Created by Lenovo on 2/18/2025.
//

size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata);

const char * revenueGet = "https://www.alphavantage.co/query?function=INCOME_STATEMENT&symbol=GOOGL&apikey=1N63WH6QQ7HMDS4Z";

void GetRevenue(char * symbol, char * apiKey) {

    CURL *curl = curl_easy_init();
    if (!curl) {
        fprintf(stderr, "curl_easy_init failed\n");
        return;
    }

    char data[4096] = "";

    char url[256] = "";

    snprintf(url, sizeof(url), revenueGet);

    CURLcode response = get_req



    json_t *root;
    json_error_t error;
    root = json_loads()



}