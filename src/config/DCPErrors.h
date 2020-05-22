#ifndef DCPERRORS_H
#define DCPERRORS_H

#include "include/String.h"

class DCPErrors {
	public:
		static const String wrongCommandError;
		static const String incorrectTableFormatError;
		static const String tableNotFoundError;
		static const String tableAlreadyExistsError;
		static const String incorrectTableDataFormatError;
		static const String insertFailedError;
		static const String updateFailedError;
		static const String innerJoinColumnMissmatchError;
		static const String innerJoinTypeMissmatchError;
		static const String expectedNumericTypeError;
		static const String columnNotFoundError;
		static const String wrongAggregateCommand;
};

#endif