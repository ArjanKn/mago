// mago-mi.cpp: entry point


#include <windows.h>
#include "cmdline.h"
#include "debugger.h"

int wmain(int argc, wchar_t* argv[])
{
	parseCommandLine(argc, argv);
#ifdef _DEBUG
	if (!CRLog::isLoggerSet()) {
		CRLog::setFileLogger("mago-mi-debug.log", true);
		CRLog::setLogLevel(CRLog::LL_TRACE);
	}
#endif

	//testEngine();

	Debugger debugger;
	int res = debugger.enterCommandLoop();

	params.clear();
	CRLog::trace("mago-mi leaving wmain(), exit code: %d", res);
	return res;
}

