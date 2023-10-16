#include "pommes_lib.h"

#include "platform.h"

#ifdef _WIN32
#include "win32_platform.cpp"
#endif

int main()
{
    platform_create_window(1200, 720, "Schnitzel Motor");
    while(running)
    {
        // Update
        platform_update_window();
    }
    
    return 0;
}