#ifndef STRING_CPP
#define STRING_CPP
#include<new>
#include<assert.h>
#include "String.h"

#define NO_FREE_MEM_ERR "Error: No free memory!"

unsigned int strLen(const char* str) {
	unsigned int res = 0;
	for (unsigned int i = 0; str[i]; i++)
	{
		res++;
	}

	return res;
}

unsigned int max(const int& first, const int& second) {
	return first >= second ? first : second;
}

unsigned int min(const int& first, const int& second) {
	return first >= second ? second : first;
}

short strCompare(const char* first, const char* second) {
	unsigned int firstLength = strLen(first);
	unsigned int secondLength = strLen(second);

	unsigned int minLength = min(firstLength, secondLength);
	for (unsigned int i = 0; i < minLength; i++)
	{
		if (first[i] < second[i]) {
			return -1;
		}
		else if (first[i] > second[i]) {
			return 1;
		}
	}

	if (firstLength == secondLength) {
		return 0;
	}

	return firstLength > secondLength ? 1 : -1;
}

void strCopy(const char* source, char* destination) {
	if (source == nullptr || destination == nullptr) {
		return;
	}

	unsigned int sourceLength = strLen(source);
	unsigned int destinationLength = strLen(destination);
	
	assert(destinationLength >= sourceLength);

	for (unsigned int i = 0; i < sourceLength; i++)
	{
		destination[i] = source[i];
	}

	destination[sourceLength] = '\0';
}

void strConcat(char* destination, const char* source) {
	unsigned int sourceLength = strLen(source);
	unsigned int destinationLength = strLen(destination);
	unsigned int sourceIndex = 0;

	for (unsigned int i = destinationLength; i < destinationLength + sourceLength; i++)
	{
		destination[i] = source[sourceIndex];
		sourceIndex++;
	}

	destination[destinationLength + sourceLength] = '\0';
}

const unsigned short String::defaultCapacity = 50; //This capacity will be doubled

String::String(const char* _str) : capacity(0), length(0), str(nullptr) {
	assert(_str != nullptr);

	this->length = strlen(_str);
	this->reserve(this->length);

	strCopy(_str, this->str);
}

String::String(const String& other) : capacity(0), length(0), str(nullptr) {
	if (this != &other) {
		this->copy(other);
	}
}

String::~String() {
	this->deleteInternals();
}

String& String::operator=(const String& other) {
	if (this != &other) {
		this->copy(other);
	}

	return *this;
}

String& String::operator+=(const String& other) {
	this->copy(*this + other);

	return *this;
}
String& String::operator+=(const char* str) {
	this->copy(*this + str);

	return *this;
}

String& String::operator+=(const char& character) {
	this->copy(*this + character);

	return *this;
}

String String::operator+(const String& other) {
	String result = *this;
	unsigned int strLength = strLen(other.str);

	if (strLength + result.length >= result.capacity) {
		result.reserve(max(strLength, result.length));
	}

	strConcat(result.str, other.str);
	result.length += strLength;

	return result;
}
String String::operator+(const char* str) {
	String result = *this;
	unsigned int strLength = strLen(str);

	if (strLength + result.length >= result.capacity) {
		result.reserve(max(strLength, result.length));
	}

	strConcat(result.str, str);
	result.length += strLength;

	return result;
}
String String::operator+(const char& character) {
	String result = *this;

	if (result.length + 1 >= result.capacity) {
		result.reserve(result.length);
	}

	result.str[result.length++] = character;
	result.str[result.length] = '\0';

	return result;
}

bool String::operator==(const String& other) const {
	return strCompare(this->str, other.str) == 0;
}
bool String::operator==(const char* str) const {
	return strCompare(this->str, str) == 0;
}

bool String::operator!=(const char* str) const {
	return !(*this == str);
}

bool String::operator!=(const String& other) const {
	return !(*this == other);
}

bool String::operator>(const String& other) const {
	return strCompare(this->str, other.str) == 1;
}
bool String::operator>(const char* str) const {
	return strCompare(this->str, str) == 1;
}

bool String::operator<(const String& other) const {
	return strCompare(this->str, other.str) == -1;
}

bool String::operator<(const char* str) const {
	return strCompare(this->str, str) == -1;
}

bool String::operator>=(const char* str) const {
	return strCompare(this->str, str) >= 0;
}
bool String::operator<=(const char* str) const {
	return strCompare(this->str, str) <= 0;
}
bool String::operator>=(const String& other) const {
	return strCompare(this->str, other.str) >= 0;
}
bool String::operator<=(const String& other) const {
	return strCompare(this->str, other.str) <= 0;
}

std::istream& operator>>(std::istream& stream, String& string) {
	return string.readFromStream(stream);
}

std::istream& String::getLine(std::istream& stream, String& string) {
	return string.readFromStream(stream, true);
}

std::ostream& operator<<(std::ostream& stream, const String& string) {
	stream.write(string.str, string.length);

	return stream;
}

char& String::operator[](const unsigned int& index) {
	assert(index >= 0 && index < this->length);

	return this->str[index];
}

const char& String::operator[](const unsigned int& index) const {
	assert(index >= 0 && index < this->length);

	return this->str[index];
}

int String::indexOf(const char* str) const{
	unsigned int strLength = strLen(str);

	for (unsigned int i = 0; i < this->length; i++)
	{
		if (i + strLength - 1 >= this->length) {
			return -1;
		}

		if (this->str[i] == str[0]) {
			for (unsigned int j = 1; j < strLength; j++)
			{
				if (this->str[i + j] != str[j]) {
					return -1;
				}
			}

			return i;
		}

	}

	return -1;
}

int String::indexOf(const char& character) const{
	for (unsigned int i = 0; i < this->length; i++)
	{
		if (this->str[i] == character) {
			return i;
		}
	}

	return -1;
}

int String::indexOf(const String& other) const{
	return this->indexOf(other.str);
}

String String::reverse() const {
	String res;

	for (int i = this->length - 1; i >= 0; i--)
	{
		res += this->str[i];
	}

	return res;
}

String String::substring(const unsigned int& first, const unsigned int& length) const {
	assert(length >= 0 && first >= 0 && length < this->length && first + length <= length);

	String res;

	for (unsigned int i = first; i < first + length; i++)
	{
		res += this->str[i];
	}

	return res;
}

Vector<String> String::split(const char& delimiter) const {
	Vector<String> res;
	String currWord;

	for (unsigned int i = 0; i < this->length; i++)
	{
		if (this->str[i] == delimiter) {
			res.pushBack(currWord);
			currWord = "";
		}
		else {
			currWord += this->str[i];
		}
	}

	res.pushBack(currWord);

	return res;
}

unsigned int String::getLength() const {
	return this->length;
}
unsigned int String::getCapacity() const {
	return this->capacity;
}

const char* const String::getConstChar() const{
	return this->str;
}

void String::reserve(unsigned int capacity) {
	capacity = max(capacity, this->defaultCapacity);

	this->capacity += capacity * 2;

	this->copy(*this);
}

void String::copy(const String& other) {
	this->capacity = other.capacity;
	this->length = other.length;

	char* newStr = new (std::nothrow) char[this->capacity];

	if (newStr == nullptr) {
		throw NO_FREE_MEM_ERR;
	}

	strCopy(other.str, newStr);

	this->deleteInternals();
	this->str = newStr;
}

void String::deleteInternals() {
	delete[] this->str;
}

std::istream& String::readFromStream(std::istream& stream, bool whileNewLine) {
	char currSymbol;
	unsigned int index = 0;
	unsigned int currSize = 100;
	char* tempStr = new (std::nothrow) char[currSize];

	if (tempStr == nullptr) {
		throw NO_FREE_MEM_ERR;
	}

	do {
		stream.get(currSymbol);

		if (index % 100 == 0 && index != 0) {
			currSize += 100;
			char* extendedStr = new (std::nothrow) char[currSize];

			if (extendedStr == nullptr) {
				throw NO_FREE_MEM_ERR;
			}

			strcpy_s(extendedStr, currSize - 100, tempStr);
			delete[] tempStr;
			tempStr = extendedStr;
		}

		tempStr[index++] = currSymbol;

	} while (whileNewLine ? currSymbol != '\n' : currSymbol != ' ' && currSymbol != '\n');

	tempStr[index - 1] = '\0';
	*this = tempStr;
	delete[] tempStr;

	return stream;
}
#endif // !STRING_CPP
