#pragma one;
#ifndef INCLUDE_H
#define INCLUDE_H

#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <istream>
#include <ostream>
#include <fstream>
#include <iomanip>
#include "Function.h"
// using std
using namespace std;

#if defined(_WIN32)
#include <conio.h>
#define PLATFORM_NAME "windows" // Windows
#elif defined(_WIN64)
#include <conio.h>
#define PLATFORM_NAME "windows" // Windows
#elif defined(__CYGWIN__) && !defined(_WIN32)
#include <conio.h>
#define PLATFORM_NAME "windows"               // Windows (Cygwin POSIX under Microsoft Window)
#elif defined(__APPLE__) && defined(__MACH__) // Apple OSX and iOS (Darwin)
#include "__getch.h"
#if TARGET_IPHONE_SIMULATOR == 1
#define PLATFORM_NAME "ios" // Apple iOS
#elif TARGET_OS_IPHONE == 1
#define PLATFORM_NAME "ios" // Apple iOS
#elif TARGET_OS_MAC == 1
#define PLATFORM_NAME "osx" // Apple OSX
#endif
#elif defined(__linux__)
#include "__getch.h"
#define PLATFORM_NAME "linux" // Debian, Ubuntu, Gentoo, Fedora, openSUSE, RedHat, Centos and other
#elif defined(__unix__) || !defined(__APPLE__) && defined(__MACH__)
#include "getch.h"
#if defined(BSD)
#define PLATFORM_NAME "bsd" // FreeBSD, NetBSD, OpenBSD, DragonFly BSD
#endif

// #elif defined(__ANDROID__)
//     #include "__getch.h"
//     #define PLATFORM_NAME "android" // Android (implies Linux, so it must come first)
// #elif defined(__hpux)
//     #define PLATFORM_NAME "hp-ux" // HP-UX
// #elif defined(_AIX)
//     #define PLATFORM_NAME "aix" // IBM AIX
// #elif defined(__sun) && defined(__SVR4)
//     #define PLATFORM_NAME "solaris" // Oracle Solaris, Open Indiana
#else
#define PLATFORM_NAME NULL
#endif

#endif
