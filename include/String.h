#ifndef STRING_H
#define STRING_H
#include<ostream>
#include "Vector.cpp"


class String {
	private:
		char* str;
		unsigned int length;
		unsigned int capacity;
		static const unsigned short defaultCapacity;

		void reserve(unsigned int);
		void copy(const String& other);
		void deleteInternals();
		std::istream& readFromStream(std::istream&, bool = false);
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

		static std::istream& getLine(std::istream&, String&);
		friend std::istream& operator>>(std::istream&, String&);
		friend std::ostream& operator<<(std::ostream&, const String&);

		int indexOf(const char*) const;
		int indexOf(const char&) const;
		int indexOf(const String&) const;

		String substring(const unsigned int&, const unsigned int& = 0) const;
		Vector<String> split(const char& = ',') const;

		unsigned int getLength() const;
		unsigned int getCapacity() const;
		const char* const getConstChar() const;
};

#endif // !STRING_H
