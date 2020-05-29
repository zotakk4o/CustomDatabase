#ifndef PAGINATION_H
#define PAGINATION_H

#include "include/Vector.cpp"
#include "include/String.h"
#include "include/Loggers/interfaces/ILogger.h"

class Pagination
{
	private:
		ILogger& logger;
		const Vector<String>& data;
		unsigned int firstItemIndex;
		const unsigned int itemsPerPage;
		unsigned int currentPage;
	public:
		Pagination(ILogger&, const Vector<String>&, const unsigned int&);
		void next();
		void prev();
		unsigned int getNumberOfPages() const;
};

#endif;
