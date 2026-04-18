#pragma once

#if defined(_WIN32) || defined(_WIN64)
    #include <conio.h>
    #define WIN32_LEAN_AND_MEAN
    #include <windows.h>
    #define CLEAR "cls"
#else
    #include <termios.h>
    #include <unistd.h>
    #include <fcntl.h>
    #define CLEAR "clear"
#endif
