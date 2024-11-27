#include <iostream>

#ifdef _WIN32
#	include <windows.h>
#endif

#ifdef __linux__
#	include <dlfcn.h>
#endif

typedef int (*f_ptr)(int, int);

////////////////////////////////////////////////////////////////////////////////
// Windows:

#ifdef _WIN32

void windows_example() {
	
	// Here I'm using, for ex, 10 Mb.
	
	HINSTANCE hDLL = ::LoadLibrary("sumLib.dll"); // Lib costs - 300 Mb.
	if (!hDLL) {
		std::cout << "Could not load the dynamic library" << std::endl;
		return;
	}
	
	// Here I'm using, already 310 Mb (me + sumLib.dll) !!!
	//
	// We're going to use only one function from the library, but OS has already
	// loaded the FULL library - it doesn't know how many and what functions
	// we will use.

	f_ptr sumPtr = (f_ptr)::GetProcAddress(hDLL, "?sum@library@@YAHHH@Z");
	if (!sumPtr) {
		std::cout << "Could not locate the function." << std::endl;
		return;
	}

	int result = sumPtr(1, 2);
	std::cout << "result = " << result << std::endl;

	::FreeLibrary(hDLL);
	
	// Here I'm using 10 Mb again.
}

#else

void windows_example() {}

#endif

////////////////////////////////////////////////////////////////////////////////
// Linux:

#ifdef __linux__

void linux_example() {
	void *hLibrary = NULL;
	hLibrary = dlopen("./lib/libsum.so", RTLD_LAZY);
        if (!hLibrary) {
            std::cout << "Error at dynamic lubrary loading!\n";
            return;
        }

	f_ptr sumPtr = (f_ptr)dlsym(hLibrary, "_ZN7library3sumEii");

	int result = sumPtr(1, 2);
	std::cout << "result = " << result << std::endl;

	dlclose(hLibrary);

}

#else

void linux_example() {}

#endif

////////////////////////////////////////////////////////////////////////////////
// Main:

int main() {

	windows_example();
	linux_example();

	return 0;
}

////////////////////////////////////////////////////////////////////////////////