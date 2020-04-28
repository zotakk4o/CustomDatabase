#ifndef CONFIG_CPP
#define CONFIG_CPP

#include "../../include/String.h"
#include "../../include/Vector.cpp"

namespace Config {
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
}

#endif // !CONFIG_CPP
