#ifndef DCPMESSAGES_H
#define DCPMESSAGES_H

#include "include/String.h"

class DCPMessages {
	public:
		static const String welcomeMessage;
		static const String supportedDataTypesMessage;
		static const String columnAlreadyExistsMessage;
		static const String emptyTableMessage;
		static const String noRecordsFoundMessage;
		static const String typeMissmatchMessage;
		static const String innerJoinSuccessMessage;
		static const String emptyAggregateOperands;
};

#endif