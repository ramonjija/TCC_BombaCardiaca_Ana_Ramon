//---------------------------------------------------------------------------

#ifndef TimeH
#define TimeH
//---------------------------------------------------------------------------

#ifdef __cplusplus
extern "C"
{                 
#endif

int Time_Init (void);
int Time_Get (double * Time);
int Time_Start (unsigned char id);
int Time_Stop (unsigned char id,double * Time,int Restart = 0);
double __declspec(dllexport) _stdcall TickCount(void);
void __declspec(dllexport) _stdcall Wait(double delay);

#ifdef __cplusplus
};	//	extern "C"
#endif

//---------------------------------------------------------------------------
#endif
