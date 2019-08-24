#ifndef _gsconsole_h_
#define _gsconsole_h_

#include <gs/gskernel.h>

#include <gsutil/gsqueue.h>
#include <gsutil/gssingleton.h>

#include <gsgeom/gscamera.h>

namespace gs
{
	class gsconsoleVariable
	{
	public:
		gsconsoleVariable () 
		{
			m_fValue = 0.f;
			m_iValue = 0;
		}
		gsconsoleVariable (const char *pvar, const float &val);
		gsconsoleVariable (const char *pvar, const int &val);
		gsconsoleVariable (const char *pvar, const char *val);
		~gsconsoleVariable ();
		
	private:
		char 	m_strVarName[256];
		float 	m_fValue;
		int 	m_iValue;
		char	m_strValue[256];
	};
	
	class gsconsole : public gssingleton<gsconsole>
	{
	public:
		gsconsole ();
		~gsconsole ();
		
		void addInput (const char *pstr);
		void execute ();
		
		char *getVariable (const char *pvarname);
		void setVariable (const char *pvar, const int &value);
		void setVariable (const char *pvar, const float &value);
		void setVariable (const char *pvar, const char *value);

	private:
		//gsgeom::gsscene *m_pConsole;
		//gsvector <gsconsoleVariable*> m_strVariables;
	};
};

#endif

