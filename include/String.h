#ifndef STRING_H
#define STRING_H
#include "Vector.cpp"
#include<ostream>

class String {
	private:
		char* str;
		unsigned int length;
		unsigned int capacity;

		void reserve(const unsigned int& = 0);
		void copy(const String& other);
		void deleteInternals();
	public:
		String(const char* = "");
		String(const String&);
		~String();

		String& operator=(const String&);
		String& operator+=(const String&);
		String& operator+=(const char*);
		String& operator+=(const char&);
		String operator+(const String&);
		String operator+(const char*);
		String operator+(const char&);

		bool operator==(const String&);
		bool operator==(const char*);
		bool operator!=(const char*);
		bool operator!=(const String&);
		bool operator>(const String&);
		bool operator>(const char*);
		bool operator<(const char*);
		bool operator<(const String&);
		bool operator>=(const char*);
		bool operator<=(const char*);
		bool operator>=(const String&);
		bool operator<=(const String&);

		char& operator[](const unsigned int&);
		const char& operator[](const unsigned int&) const;

		friend std::ostream& operator<<(std::ostream&, const String&);

		int indexOf(const char*);
		int indexOf(const char&);
		int indexOf(const String&);

		String substring(const unsigned int&, const unsigned int& = 0);
		Vector<String> split(const char& = ',');

		unsigned int getLength() const;
		unsigned int getCapacity() const;
		const char* const getConstChar() const;
};

#endif // !STRING_H
