#pragma once
#include<string>
#include<iostream>


class BigInteger {

public:
	BigInteger();
	BigInteger(std::string s);

	BigInteger(const BigInteger& N);
	~BigInteger();

	void display();

	BigInteger& operator=(const BigInteger& N);

	/*friend bool operator==(const BigInteger& A, const BigInteger& B);
	friend bool operator<(const BigInteger& A, const BigInteger& B);
	friend bool operator<=(const BigInteger& A, const BigInteger& B);
	friend bool operator>(const BigInteger& A, const BigInteger& B);
	friend bool operator>=(const BigInteger& A, const BigInteger& B);

	friend BigInteger operator+(const BigInteger& A, const BigInteger& B);
	BigInteger& operator+=(const BigInteger& N);

	friend BigInteger operator-(const BigInteger& A, const BigInteger& B);
	BigInteger& operator-=(const BigInteger& N);*/

	int sgn()const;
	void negate();

	BigInteger& operator++();
	BigInteger operator++(int t);

	std::string to_string();
	friend std::ostream& operator<<(std::ostream& out, BigInteger N);

protected:
	int* digits;
	int num_digits;
	int sign;

	/*BigInteger add(const BigInteger& N)const;
	BigInteger sub(const BigInteger& N)const;

	int compare(const BigInteger& N)const;*/
};
