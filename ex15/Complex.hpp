#pragma once

#include <iostream>
#include <memory>

namespace ft
{
	class Complex
	{
		private:
			typedef	double	value_type;

		private:
			value_type		_real;
			value_type		_imag;

		public:
//constructor
			Complex() : _real(0), _imag(0) {}
			Complex(const value_type& real) : _real(real), _imag(0) {}
			Complex(value_type r, value_type i) : _real(r), _imag(i) {}
			Complex(const Complex &copy) : _real(copy._real), _imag(copy._imag) {}
			~Complex() {}
			Complex	&operator=(const Complex &copy)
			{
				if (this == &copy)
					return *this;
				_real = copy._real;
				_imag = copy._imag;
				return *this;
			}
			Complex	&operator=(const value_type& real) 
			{
				_real = real;
				_imag = 0;
				return *this;
			}

			value_type const	&getReal() const { return _real; }
			value_type const	&getImage() const { return _imag; }

//overload
			Complex		&operator+=(const Complex &cmplx)
			{
				_real += cmplx.getReal();
				_imag += cmplx.getImage();
				return *this;
			}

			Complex		operator+(const Complex &cmplx) const
			{
				return Complex(_real + cmplx.getReal(), _imag + cmplx.getImage());
			}

			Complex		&operator-=(const Complex &cmplx)
			{
				_real -= cmplx.getReal();
				_imag -= cmplx.getImage();
				return *this;
			}

			Complex		operator-(const Complex &cmplx) const
			{
				return Complex(_real - cmplx.getReal(), _imag - cmplx.getImage());
			}

			Complex		&operator*=(const Complex &cmplx)
			{
				value_type	tmp;
				tmp = _real * cmplx.getImage() + _imag * cmplx.getReal();
				_real = _real * cmplx.getReal() - _imag * cmplx.getImage();
				_imag = tmp;
				return *this;
			}

			Complex		operator*(const Complex &cmplx) const
			{
				return Complex(_real * cmplx.getReal() - _imag * cmplx.getImage(), \
								_real * cmplx.getImage() + _imag * cmplx.getReal());
			}


	};

	std::ostream& operator << (std::ostream& os, const Complex &cmplx)
	{
		os << cmplx.getReal();
		if (cmplx.getImage() < 0 )
			os << " - ";
		else
			os << " + ";
		os << cmplx.getImage() << "i";
		return os;
	}

// overload
	double		ft_abs(const Complex &tmp) { return ft_sqrt(tmp.getReal() * tmp.getReal() + tmp.getImage() * tmp.getImage()); }

//ex01 overload
	Complex		operator*(const double a, const Complex &b) { return b * a; }

//ex02 overload
	Complex		lerp(const Complex &u, const Complex &v, double t) { return (((1 - t) * u) + (t * v)); }
}
