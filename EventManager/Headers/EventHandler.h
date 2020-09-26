#pragma once 
#include "LoggerCore.h"

#define INFO		0
#define WARN		1
#define TRACE		2
#define EVENT		3

EventHandler::EventHandler(Logger* logger)
{
	this->logger = logger;
	eventManager = new EventManager;
	hookEvent();
}

EventHandler::EventHandler(const EventHandler&)
{
	this->logger = logger;
	eventManager = new EventManager;
	hookEvent();
}

EventHandler::~EventHandler()
{
	unhookEvent();
	delete eventManager;
	eventManager = 0;
	logger = 0;
}

void EventHandler::HandleEvent(int EventCode, int KeyCode, const char* message)
{
	switch (EventCode) {
		case INFO: {
		#ifdef _DEBUG
			logger->LogToFile(true, LOG_INFO, "EVENT MANAGER", message);
		#endif
			//
			break;
		}
		case WARN: {
		#ifdef _DEBUG
			logger->LogToFile(true, LOG_WARN, "EVENT MANAGER", message);
		#endif
			//
			break;
		}
		case TRACE: {
		#ifdef _DEBUG
			logger->LogToFile(true, LOG_TRACE, "EVENT MANAGER", message);
		#endif
			//				
			break;
		}
		case EVENT: {
			switch (KeyCode) {
				case 27: {
				#ifdef _DEBUG
					logger->LogToFile(true, LOG_EVENT, "EVENT MANAGER", "KEYDOWN EVENT : KEY = ESC (EXIT APPLICATION");
				#endif
					break;
				}
				case 32: {
				#ifdef _DEBUG
					logger->LogToFile(true, LOG_EVENT, "EVENT MANAGER", "KEYDOWN EVENT : KEY = SPACEBAR");
				#endif	
					break;
				}
				default:
				#ifdef _DEBUG
					logger->LogToFile(true, LOG_EVENT, "EVENT MANAGER", "KEYDOWN EVENT :  EVENT NOT MANAGED");
				#endif
				break;
			}
		}
	}
}

bool EventHandler::hookEvent()
{
	try
	{
		__hook(&EventManager::SendEvent, eventManager, &EventHandler::HandleEvent);
	}
	catch (...)
	{
		return false;
	}

	return true;
}

void EventHandler::unhookEvent()
{
	__unhook(&EventManager::SendEvent, eventManager, &EventHandler::HandleEvent);
}