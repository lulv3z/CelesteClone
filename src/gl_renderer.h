#pragma once

#include "glcorearb.h"
#include "pommes_lib.h"

// #############################################################################
//                           OpenGL Function Pointers
// #############################################################################  
static PFNGLCREATEPROGRAMPROC glCreateProgramm_ptr;

void gl_load_functions()
{
    PROC proc = wglGetProcAddress("glCreateProgramm");
    if(!proc)
    {
        SM_ASSERT(false, "Failed to load gl function %s", "glCreateProgramm")
    }

    glCreateProgramm_ptr = (PFNGLCREATEPROGRAMPROC)proc;
}

GLAPI GLuint APIENTRY glCreateProgramm(void)
{
    return glCreateProgramm_ptr();
}