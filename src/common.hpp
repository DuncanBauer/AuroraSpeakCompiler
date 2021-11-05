#ifndef COMMON_H
#define COMMON_H

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
	#define RESET   	 "<ESC>[0m"
	#define BLACK   	 "<ESC>[30m"      /* Black */
	#define RED     	 "<ESC>[31m"      /* Red */
	#define GREEN   	 "<ESC>[32m"      /* Green */
	#define YELLOW  	 "<ESC>[33m"      /* Yellow */
	#define BLUE    	 "<ESC>[34m"      /* Blue */
	#define MAGENTA 	 "<ESC>[35m"      /* Magenta */
	#define CYAN    	 "<ESC>[36m"      /* Cyan */
	#define LIGHTGRAY    "<ESC>[37m"      /* Light Gray */
	#define DARKGRAY     "<ESC>[90m"      /* Dark Gray */
	#define LIGHTRED     "<ESC>[91m"      /* Light Red */
	#define LIGHTGREEN   "<ESC>[92m"      /* Light Green */
	#define LIGHTYELLOW  "<ESC>[93m"      /* Light Yellow */
	#define LIGHTBLUE    "<ESC>[94m"      /* Light Blue */
	#define LIGHTMAGENTA "<ESC>[95m"      /* Light Magenta */
	#define LIGHTCYAN    "<ESC>[96m"      /* Light Cyan */
	#define WHITE   	 "<ESC>[97m"      /* White */
	#define BOLD 	
  #ifdef _WIN64
    //define something for Windows (64-bit only)
  #else
    //define something for Windows (32-bit only)
  #endif
#elif __APPLE__
	#define RESET   "\033[0m"
	#define BLACK   "\033[30m"      /* Black */
	#define RED     "\033[31m"      /* Red */
	#define GREEN   "\033[32m"      /* Green */
	#define YELLOW  "\033[33m"      /* Yellow */
	#define BLUE    "\033[34m"      /* Blue */
	#define MAGENTA "\033[35m"      /* Magenta */
	#define CYAN    "\033[36m"      /* Cyan */
	#define WHITE   "\033[37m"      /* White */
	#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
	#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
	#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
	#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
	#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
	#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
	#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
	#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */
  #if TARGET_IPHONE_SIMULATOR
        // iOS Simulator
		#if TARGET_OS_MACCATALYST
					// Mac's Catalyst (ports iOS API into Mac, like UIKit).
		#elif TARGET_OS_IPHONE
				// iOS device
		#elif TARGET_OS_MAC
				// Other kinds of Mac OS
		#else
		#   error "Unknown Apple platform"
		#endif
	#endif
#elif __linux__
	#define RESET   "\033[0m"
	#define BLACK   "\033[30m"      /* Black */
	#define RED     "\033[31m"      /* Red */
	#define GREEN   "\033[32m"      /* Green */
	#define YELLOW  "\033[33m"      /* Yellow */
	#define BLUE    "\033[34m"      /* Blue */
	#define MAGENTA "\033[35m"      /* Magenta */
	#define CYAN    "\033[36m"      /* Cyan */
	#define WHITE   "\033[37m"      /* White */
	#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
	#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
	#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
	#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
	#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
	#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
	#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
	#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */
#elif __unix__ // all unices not caught above
    // Unix
#elif defined(_POSIX_VERSION)
    // POSIX
#else
#   error "Unknown compiler"
#endif
#endif