#pragma once

#include "glcorearb.h"
#include "pommes_lib.h"

// #############################################################################
//                           OpenGL Function Pointers
// #############################################################################  
static PFNGLCREATEPROGRAMPROC glCreateProgramm_ptr;

void* platform_load_gl_function(char* funName)
{
    PROC proc = wglGetProcAddress("glCreateProgramm");
    if(!proc)
    {
        static HMODULE openglDLL = LoadLibraryA("opengl32.dll");
        proc = GetProcAddress(openglDLL, funName);

        if(!proc)
        {
            SM_ASSERT(false, "Failed to load gl function %s", "glCreateProgramm")
            return nullptr;
        }
    }

    return (void*)proc;
}