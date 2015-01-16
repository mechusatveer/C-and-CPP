// timer.h

class Timer
{
public:
        explicit Timer(double);
        ~Timer();

private:
        class Implementation;
        Implementation *pImpl;
};


// timer.cpp

#include "timer.h"
#include <iostream>
#ifdef WIN32
#include <Windows.h>
#else
#include <sys/time.h>
#endif

class Timer::Implementation
{
public:
        double elapsedTime()
        {
#ifdef WIN32
                return (GetTickCount() - mStartTime)/1000 ;
#else
                struct timeval endTime;
                gettimeofday(&endTime,NULL);
                return endTime.tv_sec+(endTime.tv_usec/1000000.0)-
                       (mStartTime.tv_sec+(mStartTime.tv_usec/1000000.0)) ;
#endif
        }
#ifdef WIN32
        DWORD mStartTime;
#else
        struct timeval mStartTime;
#endif
        double mDuration;
};

Timer::Timer(double d):pImpl(new Timer::Implementation())
{
        pImpl->mDuration = d;
#ifdef WIN32
        pImpl->mStartTime = GetTickCount();
#else
        gettimeofday(&(pImpl->mStartTime), NULL);
#endif
}

Timer::~Timer()
{
        while(pImpl->elapsedTime() < pImpl->mDuration) ;
        std::cout << pImpl->mDuration << " sec elapsed" << std::endl;
        delete pImpl;
        pImpl = NULL;
}


// main.cpp

#include "timer.h"
int main()
{
	double wait = 5;
	Timer *pTimer = new Timer(wait);
        delete pTimer;
	return 0;
}


if we forget to delete pImpl its memory leak
scoped ptr solve this

// timer.h

#include <boost/smart_ptr/scoped_ptr.hpp>
class Timer
{
public:
        explicit Timer(double);
        ~Timer();

private:
        class Implementation;
        //Implementation *pImpl;
        boost::scoped_ptr<Implementation> pImpl;

};


// timer.cpp

#include "timer.h"
#include <iostream>
#ifdef WIN32
#include <Windows.h>
#else
#include <sys/time.h>
#endif

class Timer::Implementation
{
public:
        double elapsedTime()
        {
#ifdef WIN32
                return (GetTickCount() - mStartTime)/1000 ;
#else
                struct timeval endTime;
                gettimeofday(&endTime,NULL);
                return endTime.tv_sec+(endTime.tv_usec/1000000.0)-
                       (mStartTime.tv_sec+(mStartTime.tv_usec/1000000.0)) ;
#endif
        }
#ifdef WIN32
        DWORD mStartTime;
#else
        struct timeval mStartTime;
#endif
        double mDuration;
};

Timer::Timer(double d):pImpl(new Timer::Implementation())
{
        pImpl->mDuration = d;
#ifdef WIN32
        pImpl->mStartTime = GetTickCount();
#else
        gettimeofday(&(pImpl->mStartTime), NULL);
#endif
}

Timer::~Timer()
{
        while(pImpl->elapsedTime() < pImpl->mDuration) ;
        std::cout << pImpl->mDuration << " sec elapsed" << std::endl;
        // delete pImpl;
        // pImpl = NULL;
}


// main.cpp

#include "timer.h"
int main()
{
	double wait = 5;
	Timer *pTimer = new Timer(wait);
        delete pTimer;
	return 0;
}
