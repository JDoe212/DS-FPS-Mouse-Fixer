/*
purpose: This file contains all UI elements of the script control. Creates a simple UI with drop down menu, start button and text box explaining functionality.

NOTE: COMPILE THIS FILE WHEN REBUILDING
*/

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Main_Loop.c"

int on = 1, paused = 0;

RECT windowRect;

int gameSelected = -1;



//========================UI=========================//

#define START_BUTTON_ID 1
#define WINDOW_WIDTH 400
#define WINDOW_HEIGHT 290

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // Register the window class
    const char CLASS_NAME[] = "Sample Window Class";

    WNDCLASS wc = {0};
    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    RegisterClass(&wc);

    // Create the window
    HWND hwnd = CreateWindowEx(
        0,                          // Optional window styles.
        CLASS_NAME,                 // Window class
        "DS Mouse Input Fix",           // Window text
        WS_OVERLAPPEDWINDOW,        // Window style

        // Position and size
        CW_USEDEFAULT, CW_USEDEFAULT, WINDOW_WIDTH, WINDOW_HEIGHT,

        NULL,       // Parent window
        NULL,       // Menu
        hInstance,  // Instance handle
        NULL        // Additional application data
    );

    HBRUSH brush = CreateSolidBrush(RGB(40, 49, 117));
    SetClassLongPtr(hwnd, GCLP_HBRBACKGROUND, (LONG_PTR)brush);

    // Create the button
    HWND button = CreateWindow(
        "BUTTON",                   // Button class
        "Start",                 // Button text
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Button style
        10,                         // Position x
        10,                         // Position y
        365,                        // Width
        30,                         // Height
        hwnd,                       // Parent window handle
        (HMENU)START_BUTTON_ID,           // Button identifier
        NULL,                       // Instance handle
        NULL                        // Additional application data
    );

    //Create the drop down box
    HWND hDropdown = CreateWindow(
        "combobox",
        "",
        CBS_DROPDOWNLIST | CBS_HASSTRINGS | WS_CHILD | WS_OVERLAPPED | WS_VISIBLE,
        10,
        50,
        365,
        500,
        hwnd,
        (HMENU)3,
        hInstance,
        NULL
    );

    //Create the text box
    HWND hStatic = CreateWindow(
        "STATIC",
        "Thank you for using my janky tool for DS FPS games. Please select a game from the menu above, and once selected, press 'Start' to begin. After starting you will have 2 seconds before this window turns red, indicating the script is active. Once active, click the bottom-left and top-right corners of your stylus play area, and then enjoy.\nREMINDER: Pressing RIGHT_SHIFT at any time will pause this program, and BACKSPACE will kill it.\nHave fun!",
        WS_CHILD | WS_VISIBLE,
        10,
        80,
        365,
        160,
        hwnd,
        (HMENU)3,
        hInstance,
        NULL
    );

    //populate the drop down
    SendMessage(hDropdown, CB_ADDSTRING, 0, (LPARAM) "1) COD World At War");
    SendMessage(hDropdown, CB_ADDSTRING, 0, (LPARAM) "2) COD 4 Modern Warfare");
    SendMessage(hDropdown, CB_ADDSTRING, 0, (LPARAM) "3) COD Modern Warfare Mobilized");
    SendMessage(hDropdown, CB_ADDSTRING, 0, (LPARAM) "4) COD Modern Warfare Defiance");
    SendMessage(hDropdown, CB_ADDSTRING, 0, (LPARAM) "5) COD Black Ops");
    SendMessage(hDropdown, CB_ADDSTRING, 0, (LPARAM) "6) Dementeum The Ward");
    SendMessage(hDropdown, CB_ADDSTRING, 0, (LPARAM) "7) Dementeum II");
    SendMessage(hDropdown, CB_ADDSTRING, 0, (LPARAM) "8) Metroid Prime Hunters");

    // Display the window
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);
    // Hide the console
    HWND consoleWindow = GetConsoleWindow();
    ShowWindow(consoleWindow, SW_HIDE);

    // Message loop
    MSG msg = {0};
    while (GetMessage(&msg, NULL, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
//React to msgs
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_COMMAND:
            //When the button is pressed, and a game is selected, wait 2.5 seconds, then change the screen to red, indicating the script active
            //Then Run the mainloop
            if (LOWORD(wParam) == START_BUTTON_ID) 
            {
              if (gameSelected!=-1)
              {
                Sleep(2500);
                HBRUSH brush = CreateSolidBrush(RGB(255, 0, 0));
                SetClassLongPtr(hwnd, GCLP_HBRBACKGROUND, (LONG_PTR)brush);
                RedrawWindow(hwnd, NULL, NULL, RDW_ERASE | RDW_INVALIDATE);
                SendMessage(hwnd,WM_PAINT,wParam,lParam);
                on = 1;
                paused = 0;
                Run();
                brush = CreateSolidBrush(RGB(40, 49, 117));
                SetClassLongPtr(hwnd, GCLP_HBRBACKGROUND, (LONG_PTR)brush);
                SendMessage(hwnd,WM_PAINT,wParam,lParam);
                RedrawWindow(hwnd, NULL, NULL, RDW_ERASE | RDW_INVALIDATE);
              }

              
            }
            else if(HIWORD(wParam) == CBN_SELCHANGE)
            {
              int ItemIndex = SendMessage((HWND) lParam, (UINT) CB_GETCURSEL, 
                (WPARAM) 0, (LPARAM) 0);
                TCHAR  ListItem[256];
                (TCHAR) SendMessage((HWND) lParam, (UINT) CB_GETLBTEXT, 
                (WPARAM) ItemIndex, (LPARAM) ListItem);
              
              //printf("%c",ListItem[0]);
              char choice = ListItem[0];
              
              gameSelected = choice - '0';
              gameSelected-=1; 
            //MessageBox(hwnd, (LPCWSTR) ListItem, TEXT("Item Selected"), MB_OK);                        
        
            }
            break;
        //if the user tries to resize the window, dont let them
        case WM_SIZE:
            GetWindowRect(hwnd, &windowRect);
            SetWindowPos(hwnd, NULL, windowRect.left, windowRect.top, WINDOW_WIDTH, WINDOW_HEIGHT, SWP_SHOWWINDOW);
            return 0;
        //destroy window
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
    }

    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

//========================UI=========================//