#include "DCPErrors.h"

const String DCPErrors::wrongCommandError = "Error: Unrecognized command!";
const String DCPErrors::incorrectTableFormatError = "Error: incorrect table data format. Expected <table name,file name>!";
const String DCPErrors::tableNotFoundError = "Error: no table was found with the name you entered!";
const String DCPErrors::tableAlreadyExistsError = "Error: table already exists!";
const String DCPErrors::incorrectTableDataFormatError = "Error: the table file you want to operate with is corrupted!";
const String DCPErrors::insertFailedError = "Error: insert failed, no data has been changed!";
const String DCPErrors::updateFailedError = "Error: update failed, no data has been updated!";
const String DCPErrors::innerJoinColumnMissmatchError = "Error: one of the tables you entered does not have such a column!";
const String DCPErrors::innerJoinTypeMissmatchError = "Error: cannot join column of different data types!";
const String DCPErrors::columnNotFoundError = "Error: column not found!";
const String DCPErrors::expectedNumericTypeError = "Error: could not execute the current operation, column type is not numeric!";
const String DCPErrors::wrongAggregateCommand = "Error: unrecognized aggregate command!";
const String DCPErrors::aggregateFailedError = "Error: aggregate command did not succeed!";
const String DCPErrors::incorrectLogicalOperatorError = "Error: incorrect logical operator. Allowed are: \"AND\" and \"OR\"!";
const String DCPErrors::couldNotRenameTableError = "Error: could not rename table!";