#pragma once

class Color {
public:
    static void enableVirtualTerminal();

    static const char *reset();

    static const char *red();

    static const char *green();

    static const char *yellow();

    static const char *blue();

    static const char *magenta();

    static const char *cyan();

    static const char *white();

    static const char *brightRed();

    static const char *brightGreen();

    static const char *brightYellow();

    static const char *brightBlue();

    static const char *brightMagenta();

    static const char *brightCyan();

    static const char *brightWhite();
};
