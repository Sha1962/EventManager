#pragma once 
#include "PlatformDetection.h"
#include "LoggerCore.h"
#include <memory>

#ifdef PLATFORM_WINDOWS

	#ifdef BUILD_DLL
	#define DLL_PORTING __declspec(dllexport)
	#else
	#define DLL_PORTING __declspec(dllimport)
	#endif

#endif

class DLL_PORTING EventManager
{
public:
	EventManager() {};
	~EventManager() {};
	EventManager(const EventManager&) {};

	__event void SendEvent(int EventCode, int KeyCode, const char* message);

};


class DLL_PORTING EventHandler {
public:
	EventHandler(Logger* logger);
	EventHandler(const EventHandler&);
	~EventHandler();

	bool hookEvent();
	void unhookEvent();
	EventManager* eventManager;
	
private:
	void HandleEvent(int EventCode, int KeyCode, const char* message);
	Logger* logger;
	
};