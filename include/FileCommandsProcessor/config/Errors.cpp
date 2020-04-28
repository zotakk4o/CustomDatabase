#ifndef CP_ERRORS_CPP
#define CP_ERRORS_CPP

#include "../../String.h"

namespace FCPErrors {
	const String wrongCommandError = "Error: Unrecognized command!";
	const String noFileOpened = "Error: no file has been loaded for processing!";
	const String noFilenameArgumentError = "Error: missing filename argument!";
	const String noHookFunctionError = "Error: no hook function was provided to the FileCommandsProcessor!";
}

#endif
