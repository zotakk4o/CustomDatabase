#ifndef FCP_MESSAGES_CPP
#define FCP_MESSAGES_CPP
#include "../../String.h"

namespace FCPMessages {
	const String helpMessage = "The following commands are supported:\nopen <file>	opens <file>\nclose		closes currently opened file\nsave		saves the currently open file\nsaveas <file>	saves the currently open file in <file>\nhelp		prints this information\n";
	const String exitMessage = "Exiting the program...";
}

#endif
