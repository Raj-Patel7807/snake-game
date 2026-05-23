#include "Color.h"

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#endif

void Color::enableVirtualTerminal() {
#if defined(_WIN32) || defined(_WIN64)
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if(hOut == INVALID_HANDLE_VALUE) return;

    DWORD dwMode = 0;
    if(!GetConsoleMode(hOut, &dwMode)) return;

    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
#endif
}

const char *Color::reset() { return "\x1b[0m"; }

const char *Color::red() { return "\x1b[31m"; }
const char *Color::green() { return "\x1b[32m"; }
const char *Color::yellow() { return "\x1b[33m"; }
const char *Color::blue() { return "\x1b[34m"; }
const char *Color::magenta() { return "\x1b[35m"; }
const char *Color::cyan() { return "\x1b[36m"; }
const char *Color::white() { return "\x1b[37m"; }

const char *Color::brightRed() { return "\x1b[91m"; }
const char *Color::brightGreen() { return "\x1b[92m"; }
const char *Color::brightYellow() { return "\x1b[93m"; }
const char *Color::brightBlue() { return "\x1b[94m"; }
const char *Color::brightMagenta() { return "\x1b[95m"; }
const char *Color::brightCyan() { return "\x1b[96m"; }
const char *Color::brightWhite() { return "\x1b[97m"; }
