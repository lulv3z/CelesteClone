#pragma once

#include "glcorearb.h"
#include "pommes_lib.h"

// #############################################################################
//                           OpenGL Function Pointers
// #############################################################################  
static PFNGLCREATEPROGRAMPROC glCreateProgramm_ptr;

void gl_load_functions()
{
    glCreateProgramm_ptr = (PFNGLCREATEPROGRAMPROC)platform_load_gl_function("glCreateProgramm");
}

GLAPI GLuint APIENTRY glCreateProgramm(void)
{
    return glCreateProgramm_ptr();
}