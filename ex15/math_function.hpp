#pragma once

template<class T> 
T	ft_abs(const T &tmp) { return tmp < (T)0 ? -1 * tmp : tmp; }

template<class T> 
T	ft_max(const T &a, const T &b) { return a < b ? b : a; }

template<class T> 
T	ft_sqrt(const T &x)
{
	T	approx = x;
	T	prev = 0;

	while (ft_abs(approx - prev) > 0.000000001)
	{
		prev = approx;
		approx = (approx + x / approx) / 2;
	}
	return approx;
}
