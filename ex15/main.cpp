#include <iostream>
#include "Matrix.hpp"
#include "Vector.hpp"
#include "Complex.hpp"
#include <initializer_list>

using namespace ft;

void	test_ex00_add_sub_scl_vector()
{
	std::cout << "------ test_ex00_add_sub_scl_vector ------" << std::endl;

	ft::Vector<Complex> u = {Complex(1,1), Complex(3)};
	ft::Vector<Complex> v = {5., Complex(7,4)};

	std::cout << "------ VECTOR add ------" << std::endl;
	std::cout << "u = " << std::endl << u << std::endl;
	std::cout << "v = " << std::endl << v << std::endl;
	std::cout << "u.add(v) = " << std::endl << u.add(v) << std::endl;
	u = {Complex(1,1), Complex(3)};
	std::cout << "u + v = " << std::endl << (u + v) << std::endl;
	u += v;
	std::cout << "u += v" << std::endl << u << std::endl;

	std::cout << "------ VECTOR sub ------" << std::endl;
	u = {Complex(1,1), Complex(3)};
	std::cout << "u = " << std::endl << u << std::endl;
	std::cout << "v = " << std::endl << v << std::endl;
	std::cout << "u.sub(v) = " << std::endl << u.sub(v) << std::endl;
	u = {Complex(1,1), Complex(3)};
	std::cout << "u - v = " << std::endl << (u - v) << std::endl;
	u -= v;
	std::cout << "u -= v" << std::endl << u << std::endl;


	std::cout << "------ VECTOR scl ------" << std::endl;
	u = {Complex(1,1), Complex(3)};
	std::cout << "u = " << std::endl << u << std::endl;
	std::cout << "u.scl(2) = " << std::endl << u.scl(2) << std::endl;
	u = {Complex(1,1), Complex(3)};
	std::cout << "u * 2 = " << std::endl << (u * 2) << std::endl;
	std::cout << "Complex(2) * u = " << std::endl << (Complex(2) * u) << std::endl;
	u *= 2;
	std::cout << "u *= 2" << std::endl << u << std::endl;

}

void	test_ex00_add_sub_scl_matrix()
{
	std::cout << "------ test_ex00_add_sub_scl_matrix ------" << std::endl;

	ft::Matrix<Complex> u = {{Complex(1,1), Complex(3)}, {Complex(6), Complex(2, 2)}};
	ft::Matrix<Complex> v = {{Complex(5), Complex(7,4)}, {Complex(1, 21), Complex(2, 42)}};

	std::cout << "------ MATRIX add ------" << std::endl;
	std::cout << "u = " << std::endl << u << std::endl;
	std::cout << "v = " << std::endl << v << std::endl;
	std::cout << "u.add(v) = " << std::endl << u.add(v) << std::endl;
	u = {{Complex(1,1), Complex(3)}, {Complex(6), Complex(2, 2)}};
	std::cout << "u + v = " << std::endl << (u + v) << std::endl;
	u += v;
	std::cout << "u += v" << std::endl << u << std::endl;

	std::cout << "------ MATRIX sub ------" << std::endl;
	u = {{Complex(1,1), Complex(3)}, {Complex(6), Complex(2, 2)}};
	std::cout << "u = " << std::endl << u << std::endl;
	std::cout << "v = " << std::endl << v << std::endl;
	std::cout << "u.sub(v) = " << std::endl << u.sub(v) << std::endl;
	u = {{Complex(1,1), Complex(3)}, {Complex(6), Complex(2, 2)}};
	std::cout << "u - v = " << std::endl << (u - v) << std::endl;
	u -= v;
	std::cout << "u -= v" << std::endl << u << std::endl;

	std::cout << "------ MATRIX scl ------" << std::endl;
	u = {{Complex(1,1), Complex(3)}, {Complex(6), Complex(2, 2)}};
	std::cout << "u = " << std::endl << u << std::endl;
	std::cout << "u.scl(2) = " << std::endl << u.scl(2) << std::endl;
	u = {{Complex(1,1), Complex(3)}, {Complex(6), Complex(2, 2)}};
	std::cout << "u * Complex(2) = " << std::endl << (u * Complex(2)) << std::endl;
	std::cout << "Complex(2) * u = " << std::endl << (Complex(2) * u) << std::endl;
	u *= Complex(2);
	std::cout << "u *= Complex(2)" << std::endl << u << std::endl;
}

void	test_ex00_reshape()
{
	std::cout << "------ VECTOR reshape ------" << std::endl;
	{
		ft::Vector<Complex> u2({1., 2, 3., 4., 5., 6., 7, 8, 9});
		std::cout << "reshape_vector_to_matrix" << std::endl << u2.reshape_vector_to_matrix(3, 3) << std::endl;
		u2.delete_element(0);
		std::cout << "u2.delete_element(0)" << std::endl << u2 << std::endl;
		u2.delete_element(5);
		std::cout << "u2.delete_element(5)" << std::endl << u2 << std::endl;
		try
		{
			std::cout << "u2.delete_element(10)" << std::endl;
			u2.delete_element(10);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << "------ MATRIX reshape------" << std::endl;
	{
		ft::Matrix<Complex> u2({{Complex(1,1), Complex(2,2), Complex(3,3)}, \
								{Complex(4,4), Complex(5,5), Complex(6,6)}, \
								{Complex(7,7), Complex(8,8), Complex(9,9)}});
		std::cout << "u2" << std::endl << u2 << std::endl;
	
		std::cout << "reshape_matrix_to_vector" << std::endl << u2.reshape_matrix_to_vector() << std::endl;
		u2.delete_row(1);
		std::cout << "u2.delete_row(1)" << std::endl << u2 << std::endl;
		u2.delete_col(2);
		std::cout << "u2.delete_col(2)" << std::endl << u2 << std::endl;
		try
		{
			std::cout << "u2.delete_row(10)" << std::endl;
			u2.delete_row(10);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

}

void	test_ex01_linear_combination()
{
	std::cout << "------ linear_combination ------" << std::endl;

	ft::Matrix<Complex>	u({{Complex(1), Complex(2), Complex(3)}, {Complex(0), Complex(10), Complex(-100)}});
	ft::Vector<Complex>	v({Complex(10), Complex(-2)});
	std::cout << "u = " << std::endl << u << std::endl;
	std::cout << "v = " << std::endl << v << std::endl;

	std::cout << "linear_combination(u, v)" << std::endl;
	std::cout << ft::linear_combination(u, v) << std::endl;

	std::cout << "linear_combination(u, {10., -2.})" << std::endl;
	std::cout << ft::linear_combination(u, {10., -2.}) << std::endl;
}

void	test_ex02_lerp()
{
	std::cout << "------ lerp ------" << std::endl;

	std::cout << "lerp(0., 1., 0.)" << std::endl << ft::lerp(Complex(0), Complex(1), 0) << std::endl;
	std::cout << "lerp(0., 1., 1.)" << std::endl << ft::lerp(Complex(0), Complex(1), 1.) << std::endl;
	std::cout << "lerp(0., 1., 0.5)" << std::endl << ft::lerp(Complex(0), Complex(1), 0.5) << std::endl;
	std::cout << "lerp(21., 42., 0.3)" << std::endl << ft::lerp(Complex(21), Complex(42), 0.3) << std::endl;

	ft::Vector<Complex>	v1({2., 1.});
	ft::Vector<Complex>	v2({4., 2.});
	std::cout << "lerp(v1, v2, 0.3)" << std::endl << ft::lerp(v1, v2, 0.3) << std::endl;

	ft::Matrix<Complex>	u1({{Complex(2), Complex(1)}, {Complex(3), Complex(4)}});
	ft::Matrix<Complex>	u2({{Complex(20), Complex(10)}, {Complex(30), Complex(40)}});
	std::cout << "lerp(u1, u2, 0.5)" << std::endl << ft::lerp(u1, u2, 0.5) << std::endl;
}

void	test_ex03_dot()
{
	std::cout << "------ dot ------" << std::endl;

	Vector<Complex>	u({0., 0.});
	Vector<Complex>	v({1., 1.});
	std::cout << "u = " << u << std::endl;
	std::cout << "v = " << v << std::endl;
	std::cout << "u.dot(v) = " << u.dot(v) << std::endl;

	u = {1., 1.};
	v = {1., 1.};
	std::cout << "u = " << u << std::endl;
	std::cout << "v = " << v << std::endl;
	std::cout << "u.dot(v) = " << u.dot(v) << std::endl;

	u = {-1., 6.};
	v = {3., 2.};
	std::cout << "u = " << u << std::endl;
	std::cout << "v = " << v << std::endl;
	std::cout << "u.dot(v) = " << u.dot(v) << std::endl;
}

void	test_ex04_norm()
{
	std::cout << "------ norm in task ------" << std::endl;

	ft::Vector<Complex>	u = {Complex(1,2), Complex(0,-3), Complex(4,-5)};
	std::cout << "{0., 0., 0.}" << "\t" << u.norm_1() << "\t";
	std::cout << u.norm() ;//<< "\t" << u.norm_inf() << std::endl;
	
	// u = {1., 2., 3.};
	// std::cout << "{1., 2., 3.}" << "\t" << u.norm_1() << "\t";
	// std::cout << u.norm() << "\t" << u.norm_inf() << std::endl;
	
	// u = {-1., -2.};
	// std::cout << "{-1., -2.}" << "\t" << u.norm_1() << "\t";
	// std::cout << u.norm() << "\t" << u.norm_inf() << std::endl;
}

int	main(void)
{
		// test_ex00_add_sub_scl_vector();
		// test_ex00_add_sub_scl_matrix();
		// test_ex00_reshape();
		// test_ex01_linear_combination();
		// test_ex02_lerp();
		// test_ex03_dot();

		test_ex04_norm();

}
