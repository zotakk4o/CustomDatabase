#ifndef PAGINATION_H
#define PAGINATION_H

#include "../Vector.cpp"
#include "../String.h"
#include "../Loggers/interfaces/ILogger.h"

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
