#include "DCPErrors.h"

const String DCPErrors::wrongCommandError = "Error: Unrecognized command!";
const String DCPErrors::noSelectedDBError = "Error: no database has been loaded!";
const String DCPErrors::noFilenameArgumentError = "Error: missing filename argument!";
const String DCPErrors::incorrectTableFormatError = "Error: incorrect table data format. Expected <table name, file name>!";
const String DCPErrors::tableNotFoundError = "Error: no table was found with the name you entered";
const String DCPErrors::tableAlreadyExistsError = "Error: the table you wanted to import already exists.";
const String DCPErrors::incorrectTableDataFormatError = "Error: the table file you want to operate with is corrupted.";