#include "comm.h"

double getCurrentTimeStamp()
{
	double current;
	#ifdef _WIN32
	static LARGE_INTEGER fre = {};
	LARGE_INTEGER cur_clock;
	if(0 == fre.QuadPart)
		QueryPerformanceFrequency(&fre);
	QueryPerformanceCounter(&cur_clock);
	current = (double)cur_clock.QuadPart / (double)fre.QuadPart * 10e6;//us
	#else
		struct timespec ts;
		clock_gettime(CLOCK_MONOTONIC, &ts);
		current = (double)ts.tv_nsec * 10e-3 + (double)ts.tv_sec * 10e6;//us
	#endif
	return current;
}
