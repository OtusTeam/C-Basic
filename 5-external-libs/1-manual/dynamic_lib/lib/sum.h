#pragma once

#if defined(_WIN32)
// On Windows we have to export each required API method manually.
#	ifdef BUILD_SUM_DLL
#		define SUM_DLL_API __declspec(dllexport)
#	else
#		define SUM_DLL_API __declspec(dllimport)
#	endif
#else
// On Linux, we don't need to do anything special.
#		define SUM_DLL_API
#endif


namespace library
{

	SUM_DLL_API int sum(int a, int b);
	
	SUM_DLL_API double sum(double a, double b);

} // namespace library