#ifndef FCP_ERRORS_CPP
#define FCP_ERRORS_CPP

#include "../../String.h"

namespace FCPErrors {
	const String wrongCommandError = "Error: Unrecognized command!";
	const String noFileOpened = "Error: no file has been loaded for processing!";
	const String noFilenameArgumentError = "Error: missing filename argument!";
}

#endif