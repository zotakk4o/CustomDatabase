#ifndef COMMANDSPROCESSOR_H
#define COMMANDSPROCESSOR_H
#include "../../include/String.h"

class CommandsProcessor {
	private:
		static bool wasKeywordFound(const String&);
		static void parseInput();
	public:
		static void start();
};

#endif // !COMMANDSPROCESSOR_H
