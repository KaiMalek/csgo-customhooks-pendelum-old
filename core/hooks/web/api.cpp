/*#include <iostream>
#include <curl/curl.h>
#include "../../../dependencies/utilities/csgo.hpp"
#include "../../features/features.hpp"

size_t WriteCallback(char* contents, size_t size, size_t nmemb, std::string* data)
{
    size_t totalSize = size * nmemb;
    data->append(contents, totalSize);
    return totalSize;
}
// coded this a few months ago 06 09
void api_ch()
{
    CURL* curl;
    CURLcode res;
    std::string apiResponse;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, "http://localhost:3000/api/data");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &apiResponse);

        res = curl_easy_perform(curl);

        if (res != CURLE_OK)
        {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();

    // Handle the API response
    if (res == CURLE_OK)
    {
        std::cout << "API response: " << apiResponse << std::endl;
    }
    // TODO: ???
     if (std::strstr(GetCommandLineA(), "-insecure")) {
         render::text(10, 10, render::fonts::watermark_font, "customhooks | [ALPHA] | Build: " __DATE__ " | -insecure | API test:" + apiResponse, false, color(255, 255, 255, 190));
     }
     else {
         render::text(10, 10, render::fonts::watermark_font, "customhooks | [ALPHA] | Build: " __DATE__ " | API test:" + apiResponse, false, color(255, 255, 255, 190));
     }
}


*/