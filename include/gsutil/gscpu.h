#ifndef _gscpu_h_
#define _gscpu_h_

#include <gsutil/gsqueue.h>
#include <gsutil/gsstring.h>

namespace gsutil
{
	//determine current cpu
	class GS gscpu
	{
	public:
		gscpu ();
		~gscpu ();

		void detectCPU ();

		enum CPU_FEATURE
		{
			CPU_MMX		= 0x0001,
			CPU_SSE		= 0x0002,
			CPU_SSE2	= 0x0004,
			CPU_SSE3	= 0x0008,
			CPU_SSE4	= 0x0010,
			CPU_3DNOW	= 0x0020,
		};
	private:
		typedef struct
		{
			//cpu
			unsigned int m_iCpus;
			gsutil::gsqueue <gsutil::gsstring> m_strCpuName;
			unsigned long m_iFeatures;

			//memory
			unsigned long long m_lTotalVirtual;
			unsigned long long m_lTotalPage;
			unsigned long long m_lTotalRam;
			unsigned int m_iLoad;
		} gsCpuInfo;

		gsCpuInfo m_currentCpu;
	};

	//check available options with the cpu!

	//for SSE/2/3, etc
	//when calls are first made, overload everything using these to use a function pointer, so they use the specific version on the latter calls
};

#endif
