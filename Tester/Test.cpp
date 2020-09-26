
#include "Imports.h"

#define SEND_EVENT  __raise events->eventManager->SendEvent

int main() {
	Logger* logger;
	logger = new Logger;

	logger->LogToFile(true, LOG_INFO, "EVENT MANAGER", "EVENT TEST MESSAGE");

	EventHandler* events;
	events = new EventHandler(logger);

	SEND_EVENT(LOG_EVENT, 0, "TRIGGER TEST");

	system("pause");

	delete events;
	events = 0;

	delete logger;
	logger = 0;
	return 0;
}





