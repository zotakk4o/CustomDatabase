#ifndef DCPERRORS_H
#define DCPERRORS_H

#include "../../include/String.h"

class DCPErrors {
	public:
		static const String wrongCommandError;
		static const String noSelectedDBError;
		static const String noFilenameArgumentError;
		static const String incorrectTableFormatError;
		static const String tableNotFoundError;
		static const String tableAlreadyExistsError;
		static const String incorrectTableDataFormatError;
};

#endif