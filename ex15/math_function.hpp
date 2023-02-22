#pragma once

#include "Complex.hpp"

template<class T> 
T		ft_abs(const T &tmp) { return tmp < (T)0 ? -1 * tmp : tmp; }

template<class T> 
T		ft_max(const T &a, const T &b) { return a < b ? b : a; }

template<class T> 
double	ft_sqrt(const T &x)
{
	double	approx = x;
	double	prev = 0;

	while (ft_abs(approx - prev) > 0.000000001)
	{
		prev = approx;
		approx = (approx + x / approx) / 2;
	}
	return approx;
}

template<class T> 
T		ft_real(const T &tmp) {return tmp; }

template<class T> 
T		ft_conj(const T &tmp) {return tmp; }

double	ft_abs(const ft::Complex &tmp) { return ft_sqrt(tmp.getReal() * tmp.getReal() + tmp.getImage() * tmp.getImage()); }

double	ft_real(const ft::Complex &tmp) {return tmp.getReal(); }

ft::Complex ft_conj(const ft::Complex &tmp) { return ft::Complex(tmp.getReal(), -tmp.getImage()); }
