//
//
// Created by S861321135 on 04/08/2026.
//
#include "terminal.h"

#ifdef _WIN32
#include <windows.h>
#endif

void terminal_initialize() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif
}
