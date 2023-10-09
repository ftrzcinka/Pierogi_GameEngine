#pragma once

#if PR_DEBUG==2
	#define PR_ERROR(x) std::cout<<x<<std::endl;
	#define PR_LOG(x) std::cout<<x<<std::endl;
#elif PR_DEBUG==1
	#define PR_ERROR(x) std::cout<<x<<std::endl;
	#define PR_LOG(x)
#else
	#define PR_ERROR(x)
	#define PR_LOG(x)
#endif

#ifdef PIEROGI_MSCPP
	#ifdef PIEROGI_LIB
		#define PIEROGI_API __declspec(dllexport)
	#else
		#define PIEROGI_API __declspec(dllimport)
	#endif
#else
	#define PIEROGI_API
#endif

#define PIEROGI_APPLICATION_START(ClassName) \
int main() \
{\
	ClassName::Init(); \
	ClassName::RunInterface(); \
	return(0); \
}