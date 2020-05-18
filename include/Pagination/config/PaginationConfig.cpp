#include "PaginationConfig.h"
#include "../commands/NextCommand.h"
#include "../commands/PrevCommand.h"
#include<iostream>

const String PaginationConfig::paginationStopCommand = "cancel";

std::istream& PaginationConfig::commandInputStream = std::cin;

const Vector<PaginationCommand*> PaginationConfig::paginationCommands{
	new NextCommand(),
	new PrevCommand()
};