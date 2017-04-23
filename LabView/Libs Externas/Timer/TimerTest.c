#include <analysis.h>
//Make sure your project is set for stdcall mode and not cdecl
double TickCount(void);
void Wait(double delay);

main()
{
	double stdDev;
	double mean;
	double start, end;
	double correction = -.007;
	int i=0;
	double times[1000]={0};
	
	for (i=0; i<1000; i++)
	{
	  	start =	TickCount();
		Wait(5.5 + correction); //waits 5.5 milliseconds +correction factor
		end = TickCount();		//I found the correction factor experimentally 
		end = end-start; 		//to give me about an error or +-.005ms with a std. Dev of .11
		
		times[i]=end;
	}
	StdDev (times, 1000, &mean, &stdDev);
	
		
}
