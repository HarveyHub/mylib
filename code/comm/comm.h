#ifndef _COMM_H
#define _COMM_H

#include <iostream>
#include <sstream>
// #include <string>

template <typename T>
void str2val(const std::string &str, T &val)
{
	std::stringstream ss;
	ss << str;
	ss >> val;
}

template <typename T>
void val2str(const T &val, std::string &str)
{
	std::stringstream ss;
	ss << val;
	str += ss.str();
}
// red
#ifdef ERR
#undef ERR
#endif
#define ERR(x) do{std::cout <<__FILE__ << ":" << __LINE__ << " " <<__func__ << "() " <<  "\x1b[40;31m" << x << "\x1b[0;m" << std::endl;}while(0)
// green
#ifdef MSG
#undef MSG
#endif
#define MSG(x) do {std::cout <<__FILE__ << ":" << __LINE__ << " " <<__func__ << "() " << "\x1b[40;32m" << x << "\x1b[0;m" << std::endl;}while(0)
// yellow
#ifdef WARN
#undef WARN
#endif
#define WARN(x) do {std::cout <<__FILE__ << ":" << __LINE__ << " " <<__func__ << "() " << "\x1b[40;33m" << x << "\x1b[0;m" << std::endl;}while(0)

#include <stdio.h>
#include <stdlib.h>
#ifdef 	_WIN32
	#include <windows.h>
#else
	#include <unistd.h>
	#include <time.h>
#endif

extern double getCurrentTimeStamp();


#endif