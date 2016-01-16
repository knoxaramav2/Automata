#define PLATFORM_WINDOWS 	1
#define PLATFORM_LINUX		2

#if defined _WIN32 | __CYGWIN__ | __CYGWIN32__
	#define PLATFORM PLATFORM_WINDOWS
	#if defined _WIN64 | WIN64 | __WIN64 | __WIN64__
		#define BITMODE 64
	#else 
		#define BITMODE 32
	#endif
#endif
#ifdef __linux
	#define PLATFORM PLATFORM_LINUX
	#ifdef __x86_64__
		#define BITMODE 64
	#else
		#define BITMODE 32
	#endif
#endif

#define DEBUG	false

#ifndef DEFINITION_H
#define DEFINITION_H

/*
Defines macros and variable sizes for 
*/

/*
Determine system specs
*/

#endif