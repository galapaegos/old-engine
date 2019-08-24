#include <gsutil/gscpu.h>

#ifdef WIN32
#include <windows.h>
#endif

namespace gsutil
{
	gscpu::gscpu ()
	{
	}

	gscpu::~gscpu ()
	{
	}

	void gscpu::detectCPU ()
	{
		unsigned long A = 0, B = 0, C = 0, D = 0;

		//check to see if cpuid works
		__asm
		{
			mov eax, 0
			cpuid
			mov dword ptr A, eax
		};

		if (A == 1)
		{
			// I *believe* this means its not found, so return from the function
			return;
		}

		// Get general information on chip
		__asm
		{
			mov eax, 0
			cpuid
			mov dword ptr A, eax
			mov dword ptr B, ebx
			mov dword ptr C, ecx
			mov dword ptr D, edx
		};

		// Full chip name
		char name[49] = {0};
		__asm
		{
			mov eax, 80000002h
			cpuid
			mov dword ptr name, eax
			mov dword ptr name + 4, ebx
			mov dword ptr name + 8, ecx
			mov dword ptr name + 12, edx
			mov eax, 80000003h
			cpuid
			mov dword ptr name + 16, eax
			mov dword ptr name + 20, ebx
			mov dword ptr name + 24, ecx
			mov dword ptr name + 28, edx
			mov eax, 80000004h
			cpuid
			mov dword ptr name + 32, eax
			mov dword ptr name + 36, ebx
			mov dword ptr name + 40, ecx
			mov dword ptr name + 44, edx
		};
		name[48] = '\0';

		m_currentCpu.m_strCpuName.add (name);

		// This gets the features of the chip
		__asm
		{
			mov eax, 1
			cpuid
			mov dword ptr A, eax
			mov dword ptr B, ebx
			mov dword ptr C, ecx
			mov dword ptr D, edx
		};

		// Parse out features of the chip

#ifdef WIN32
		SYSTEM_INFO info;
		GetSystemInfo (&info);

		m_currentCpu.m_iCpus = info.dwNumberOfProcessors;

		MEMORYSTATUSEX ms;
		ms.dwLength = sizeof (MEMORYSTATUSEX);
		GlobalMemoryStatusEx (&ms);

		m_currentCpu.m_lTotalVirtual = ms.ullTotalVirtual;
		m_currentCpu.m_lTotalPage = ms.ullTotalPageFile;
		m_currentCpu.m_lTotalRam = ms.ullTotalPhys;
		m_currentCpu.m_iLoad = ms.dwMemoryLoad;
#endif
	}
};
