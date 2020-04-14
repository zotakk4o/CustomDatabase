#include "../../include/String.h"
#include "../../include/Vector.cpp"

namespace Config {
	const Vector<String> commandsKeywords{
		"import",
		"showtables",
		"describe",
		"print",
		"export",
		"select",
		"addcolumn",
		"update",
		"delete",
		"insert",
		"innerjoin",
		"rename",
		"count",
		"aggregate",
		"open",
		"close",
		"save",
		"saveas",
		"help",
		"exit"
	};

	const String welcomeMessage = "Welcome to CDB! The application is now ready to be used.\nHere is the list of supported commands, which you can use to operate with your databases.\n";
	const String helpMessage = "The following commands are supported:\nopen <file>	opens <file>\nclose		closes currently opened file\nsave		saves the currently open file\nsaveas <file>	saves the currently open file in <file>\nhelp		prints this information\n";
}