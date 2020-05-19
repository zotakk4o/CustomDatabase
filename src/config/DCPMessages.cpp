#include "DCPMessages.h"

const String DCPMessages::welcomeMessage = "Welcome to CDB! The application is now ready to be used.\nHere is the list of supported commands, which you can use to operate with your databases.\n";
const String DCPMessages::helpMessage = "The following commands are supported:\nopen <file>	opens <file>\nclose		closes currently opened file\nsave		saves the currently open file\nsaveas <file>	saves the currently open file in <file>\nhelp		prints this information\n";
const String DCPMessages::exitMessage = "Exiting the program...";
const String DCPMessages::supportedDataTypesMessage = "The only supported data types are: ";
const String DCPMessages::columnAlreadyExistsMessage = "The column you wanted to add already exists.";
const String DCPMessages::emptyTableMessage = "Table is empty.";
const String DCPMessages::noRecordsFoundMessage = "No records match the criteria you entered.";
const String DCPMessages::typeMissmatchMessage = "Incorrect data type entered.";