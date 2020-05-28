#ifndef TABLEFILE_H
#define TABLEFILE_H

#include "include/File.h"
#include "include/String.h"

class TableFile : public File {
	private:
		String tableName;
		bool joined;

		String getColumnType(const unsigned int&) const;
		int getColumnIndex(const String&) const;
		bool doesMatchColumnType(const unsigned int&, const String&) const;
		Vector<unsigned int> getRowsIndexesByCriteria(const Vector<String>&, const String& = "AND", bool = false) const;
		String concatData(const Vector<String>&);
	public:
		TableFile(ILogger* = nullptr, const String& = "", const String& = "", bool = false);

		virtual bool open(const String& = "");

		void describe();
		void print();
		void exportData(const String&);
		void rename(const String&);
		void addColumn(const String&, const String&);
		void insert(const Vector<String>&);
		Vector<String> select(const Vector<String>&, const String& = "AND", bool = false);
		void update(const Vector<String>&);
		void count(const String&, const String&);
		void deleteRows(const String&, const String&);
		double aggregate(const Vector<String>&);

		static TableFile innerJoin(const TableFile&, const TableFile&, const String&, const String&);
		bool isJoined() const;
		void setTableName(const String&);
		const Vector<String> getColumnNames(bool = false) const;
		const Vector<String> getTableData(const Vector<unsigned int>& = {}) const;
		String getTableName() const;
};

#endif