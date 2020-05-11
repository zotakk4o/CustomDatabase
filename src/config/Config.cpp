#ifndef CONFIG_CPP
#define CONFIG_CPP

#include "../../include/String.h"
#include "../../include/Vector.cpp"
#include "../interfaces/IDBFileCommand.h"
#include "../interfaces/IDBFileCommandParameters.h"

namespace DCPConfig {
	const char commandDelimiter = ' ';

	const Vector<String> dbCommandsKeywords{
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
	};

	const Vector<IDBFileCommand*> dbCommands{
		
	};

	const Vector<IDBFileCommandParameters*> dbCommandsParameters{
		
	};
}

#endif // !CONFIG_CPP
