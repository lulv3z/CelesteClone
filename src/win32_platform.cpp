
#define WIN32_LEAD_AND_MEAN
#define NOMINMAX
#include <windows.h>
#include "platform.h"
#include "pommes_lib.h"

// #############################################################################
//                           Windows Globals
// #############################################################################

static HWND window;

// #############################################################################
//                           Platform Implementations
// #############################################################################
LRESULT CALLBACK windows_window_callback(HWND window, UINT msg, WPARAM wParam, LPARAM lParam)
{
    LRESULT result = 0;

    switch(msg)
    {
        case WM_CLOSE:
        {
            running = false;
            break;
        }

        default:
        {
            // Let windows handle the default input forn now
            result = DefWindowProcA(window, msg, wParam, lParam);
        }
    }

    return result;
}

bool platform_create_window(int width, int height, char* title)
{
    HINSTANCE instance = GetModuleHandleA(0);

    WNDCLASSA wc = {};
    wc.hInstance = instance;
    wc.hIcon = LoadIcon(instance, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.lpszClassName = title;                       // this is NOT the title, just a unique identifier(10)
    wc.lpfnWndProc = windows_window_callback;       // Callbacl for Input into the window

    if(!RegisterClassA(&wc))
    {
        return false;
    }

    // WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX
    int dwStyle = WS_OVERLAPPEDWINDOW;

    window = CreateWindowExA(0, title, // This references lpszClassName from wc
                                    title,  // This is the actual title
                                    dwStyle,
                                    100,
                                    100,
                                    width,
                                    height,
                                    NULL,   // parent
                                    NULL,   // menu
                                    instance,
                                    NULL);  // lpParam
    
    if(window == NULL)
    {
        return false;
    }

    ShowWindow(window, SW_SHOW);

    return true;
}

void platform_update_window()
{
    MSG msg;

    while(PeekMessageA(&msg, window, 0, 0, PM_REMOVE))
    {
        TranslateMessage(&msg);
        DispatchMessageA(&msg); // Calls the callback specified when creating the window
    }
}