#ifndef PAGINATIONCONFIG_H
#define PAGINATIONCONFIG_H

#include "include/String.h"
#include "include/Vector.cpp"
#include "../commands/BaseClasses/PaginationCommand.h"
#include <istream>

class PaginationConfig
{
	public:
		static const String paginationStopCommand;
		static std::istream& commandInputStream;
		static const Vector<PaginationCommand*> paginationCommands;
		~PaginationConfig();
};

#endif

