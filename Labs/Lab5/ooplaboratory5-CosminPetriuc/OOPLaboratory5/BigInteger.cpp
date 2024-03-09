#include "BigInteger.h"

#include <cctype> // for isdigit
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>

BigInteger::BigInteger()
{
	this->digits = nullptr;
	this->num_digits = 0;
	this->sign = 0;
}

BigInteger::BigInteger(std::string s)
{
	this->num_digits = s.size();

	switch (s[0])
	{
	case '0':
		this->digits = new int[num_digits]();
		this->sign = 0;
		break;
	case '-':
		this->digits = new int[num_digits - 1]();
		s.erase(0, 1);
		this->num_digits--;
		this->sign = -1;
		break;
	case'+':
		this->digits = new int[num_digits - 1]();
		s.erase(0, 1);
		this->num_digits--;
		this->sign = 1;
		break;
	default:
		this->digits = new int[num_digits]();
		this->sign = 1;
		break;
	}

	int t = 0;

	for (int i = 0; i < this->num_digits; i++)
	{
		if (!isdigit(s[i])) throw("error");
		*(this->digits + t) = (int)(s[i] - '0');
		t++;
	}
}

BigInteger::BigInteger(const BigInteger& N)
{
	this->digits = new int[N.num_digits] { 0 };
	this->num_digits = N.num_digits;
	this->sign = N.sign;

	for (int i = 0; i < N.num_digits; i++)
		this->digits[i] = N.digits[i];
}

BigInteger::~BigInteger()
{
	delete[] digits;
}

void BigInteger::display()
{
	for (int i = 0; i < this->num_digits; i++)
		std::cout << this->digits[i] << " ";
}

BigInteger& BigInteger::operator=(const BigInteger& N)
{
	if (this == &N)
		return *this;

	delete[] this->digits;

	this->digits = new int[N.num_digits] { 0 };
	this->num_digits = N.num_digits;
	this->sign = N.sign;

	for (int i = 0; i < N.num_digits; i++)
		this->digits[i] = N.digits[i];

	return *this;
}

int BigInteger::sgn() const
{
	return this->sign;
}

void BigInteger::negate()
{
	this->sign *= -1;
}
//BigInteger& BigInteger::operator++()	//pre-increment
//{
//	BigInteger a = BigInteger("1");
//	if (this->sign > -1)
//		*this = this->add(a);
//
//	else
//		*this = this->sub(a);
//	return *this;
//}
//
//BigInteger BigInteger::operator++(int t)	//post-increment
//{
//	BigInteger a = BigInteger("1");
//	BigInteger copy = *this;
//	*this = this->add(a);
//	return copy;
//}
//
//BigInteger BigInteger::add(const BigInteger& N) const {
//	
//}
//
//BigInteger BigInteger::sub(const BigInteger& N) const {
//	
//}
//
//int BigInteger::compare(const BigInteger& N) const {
//	
//}
//bool operator==(const BigInteger& A, const BigInteger& B) {
//	
//}
//bool operator<(const BigInteger& A, const BigInteger& B)
//{
//	
//}
//
//bool operator<=(const BigInteger& A, const BigInteger& B)
//{
//	
//}
//
//bool operator>(const BigInteger& A, const BigInteger& B)
//{
//	
//}
//
//bool operator>=(const BigInteger& A, const BigInteger& B)
//{
//	
//}
//BigInteger& BigInteger::operator+=(const BigInteger& N)
//{
//	
//}
//
//BigInteger& BigInteger::operator-=(const BigInteger& N)
//{
//	
//}
//BigInteger operator+(const BigInteger& A, const BigInteger& B)
//{
//	
//}
//
//BigInteger operator-(const BigInteger& A, const BigInteger& B)
//{
//	
//}