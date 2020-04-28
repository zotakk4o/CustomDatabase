#ifndef ERRORS_CPP
#define ERRORS_CPP
#include "../../include/String.h"

namespace Errors {
	const String wrongCommandError = "Error: Unrecognized command!";
	const String noSelectedDBError = "Error: no database has been loaded!";
	const String noFilenameArgumentError = "Error: missing filename argument!";
}

#endif // !ERRORS_CPP
