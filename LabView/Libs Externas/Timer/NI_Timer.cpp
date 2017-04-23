#include "NI_Timer.h"
#include <windows.h>

int __stdcall DllMain (HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
	double time;

	switch (fdwReason)
		{
		case DLL_PROCESS_ATTACH:
			Time_Init ();
			Time_Start(0);
			break;
		case DLL_PROCESS_DETACH:
			Time_Get(&time);
			Time_Stop(0, &time, 0);
			break;
		}
	
	return 1;
}

static __int64 __Frequency = -1i64;
static
	struct
	{
		__int64 Counter;
		int Started;
	} __Timer[256];

//---------------------------------------------------------------------------
double __declspec(dllexport) _stdcall TickCount(void)
{
	double time;

	Time_Get(&time);

	return time;
}

void __declspec(dllexport) _stdcall Wait(double delay)
{
	double start, current;

	Time_Get(&start);
	Time_Get(&current);
	while ((current-start)< delay)
		Time_Get(&current);
}

int Time_Init ()
{
	if (__Frequency == -1i64)
	{
		if (!::QueryPerformanceFrequency ((LARGE_INTEGER *)&__Frequency))
			__Frequency = -1i64;
		::ZeroMemory ((void *)&__Timer,sizeof (__Timer));
	}

	return ((__Frequency > 0) ? 1 : 0);
}

int Time_Get (double * Time)
{
	__int64 Counter;

	if (__Frequency > 0)
	if (::QueryPerformanceCounter ((LARGE_INTEGER *)&Counter))
	{
		*Time = ((double)Counter / __Frequency) * 1000;
		return (1);
	}
	return (0);
}

//---------------------------------------------------------------------------

int Time_Start (unsigned char id)
{
	__int64 Counter;

	if (__Frequency > 0)
	if (::QueryPerformanceCounter ((LARGE_INTEGER *)&Counter))
	{
		__Timer[id].Counter = Counter;
		__Timer[id].Started = 1;

		return (1);
	}
	return (0);
}

int Time_Stop (unsigned char id,double * Time,int Restart)
{
	__int64 Counter;

	if (__Frequency > 0)
	if (::QueryPerformanceCounter ((LARGE_INTEGER *)&Counter))
	{
		if (__Timer[id].Started)
		{
			*Time = ((double)(Counter - __Timer[id].Counter) / __Frequency) * 1000;
		}
		__Timer[id].Counter = Counter;
		__Timer[id].Started = Restart;
		
		return (1);
	}
	return (0);
}

//---------------------------------------------------------------------------

