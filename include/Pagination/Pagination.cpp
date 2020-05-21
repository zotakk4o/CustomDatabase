#include "Pagination.h"
#include "config/PaginationConfig.h"
#include "config/PaginationErrors.h"
#include "config/PaginationMessages.h"

Pagination::Pagination(const ILogger& _logger, const Vector<String>& _data, const unsigned int& _itemsPerPage) :
	logger(_logger),
	data(_data),
	firstItemIndex(0),
	itemsPerPage(_itemsPerPage),
	currentPage(0) 
{
	this->next();

	String command;
	bool wasCommandExecuted = false;

	while (true) {
		
		String::getLine(PaginationConfig::commandInputStream, command);

		if (command == PaginationConfig::paginationStopCommand) {
			break;
		}

		unsigned int commandsSize = PaginationConfig::paginationCommands.getSize();
		for (unsigned short i = 0; i < commandsSize; i++)
		{
			if (PaginationConfig::paginationCommands[i]->isValid(command)) {
				PaginationConfig::paginationCommands[i]->execute(*this);
				wasCommandExecuted = true;
				break;
			}
		}

		if (!wasCommandExecuted) {
			this->logger.log(PaginationErrors::unrecognizedCommand);
			break;
		}
	}
}

void Pagination::next() {
	if (this->currentPage == this->getNumberOfPages()) {
		this->logger.log(PaginationMessages::noNextPageMessage);
		return;
	}

	unsigned int size = this->data.getSize();
	for (unsigned int i = this->firstItemIndex; i < size && i < this->firstItemIndex + this->itemsPerPage; i++)
	{
		this->logger.log(String::toString(i + 1) + ". " + this->data[i]);
	}

	if (++this->currentPage == this->getNumberOfPages()) {
		return;
	}

	this->firstItemIndex += this->itemsPerPage;
}

void Pagination::prev() {
	if (this->currentPage == 1) {
		this->logger.log(PaginationMessages::noPrevPageMessage);
		return;
	}

	this->firstItemIndex -= this->itemsPerPage;
	unsigned int size = this->data.getSize();
	for (unsigned int i = this->firstItemIndex; i < size && i < this->firstItemIndex + this->itemsPerPage; i++)
	{
		this->logger.log(String::toString(i + 1) + ". " + this->data[i]);
	}

	this->currentPage--;
}

unsigned int Pagination::getNumberOfPages() const {
	return (this->data.getSize() / this->itemsPerPage + 1);
}