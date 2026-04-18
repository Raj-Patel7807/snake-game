#pragma once
#include "../../config/Config.h"

#if !defined(_WIN32) && !defined(_WIN64)
int _kbhit();
int _getch();
#endif
