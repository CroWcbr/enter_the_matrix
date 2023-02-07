#include <iostream>
#include "../Matrix.hpp"
#include "../Vector.hpp"
#include <initializer_list>

void	test_vector_in_task()
{
	std::cout << "------ VECTOR in task ------" << std::endl;
	
	ft::Vector<double> u = {2., 3.};
	ft::Vector<double> v = {5., 7.};

	u.add(v);
	std::cout << "u.add(v) = " << std::endl << u << std::endl;

	u = {2., 3.};
	u.sub(v);
	std::cout << "u.sub(v) = " << std::endl << u << std::endl;

	u = {2., 3.};
	u.scl(2.);
	std::cout << "u.sub(v) = " << std::endl << u << std::endl;
}

void	test_matrix_in_task()
{
	std::cout << "------ MATRIX in task ------" << std::endl;
	
	ft::Matrix<double> u = {{1., 2.}, {3., 4.}};
	ft::Matrix<double> v = {{7., 4.}, {-2., 2.}};

	u.add(v);
	std::cout << "u.add(v) = " << std::endl << u << std::endl;

	u = {{1., 2.}, {3., 4.}};
	u.sub(v);
	std::cout << "u.sub(v) = " << std::endl << u << std::endl;

	u = {{1., 2.}, {3., 4.}};
	u.scl(2.);
	std::cout << "u.sub(v) = " << std::endl << u << std::endl;
}

void	test_vector_additional()
{
	std::cout << "------ VECTOR additional ------" << std::endl;

	ft::Vector<double> u = {2., 3.};
	ft::Vector<double> v = {5., 7.};

	try
	{
		ft::Vector<double> m = {2., 3., 4.};
		u.add(m);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "u + v = " << std::endl << u + v << std::endl;
	std::cout << "u - v = " << std::endl << u - v << std::endl;
	std::cout << "u * 2 = " << std::endl << u * 2 << std::endl;
	std::cout << "2 * u = " << std::endl << 2. * u << std::endl;

	{
		ft::Vector<double> u2 = u;
		std::cout << "u2 = u" << std::endl << u2 << std::endl;
	}

	{
		ft::Vector<double> u2(u);
		std::cout << "u2(u)" << std::endl << u2 << std::endl;
	}

	{
		ft::Vector<double> u2({1., 2, 3., 4., 5., 6.,7,8,9});
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
}

void	test_matrix_additional(void)
{
	std::cout << "------ MATRIX additional------" << std::endl;

	ft::Matrix<double> u = {{1., 2.}, {3., 4.}};
	ft::Matrix<double> v = {{7., 4.}, {-2., 2.}};

	try
	{
		ft::Matrix<double> m = {{2., 3., 4.}};
		u.add(m);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "u + v = " << std::endl << u + v << std::endl;
	std::cout << "u - v = " << std::endl << u - v << std::endl;
	std::cout << "u * 2 = " << std::endl << u * 2 << std::endl;
	std::cout << "2 * u = " << std::endl << 2. * u << std::endl;

	{
		ft::Matrix<double> u2 = u;
		std::cout << "u2 = u" << std::endl << u2 << std::endl;
	}

	{
		ft::Matrix<double> u2(u);
		std::cout << "u2(u)" << std::endl << u2 << std::endl;
	}

	{
		ft::Matrix<double> u2({{1., 2, 3.}, {4., 5., 6.}, {7., 8., 9.}});
		std::cout << "u2" << std::endl << u2 << std::endl;
	
		std::cout << "reshape_matrix_to_vector" << std::endl << u2.reshape_matrix_to_vector() << std::endl;
		
		u2 = {{1., 2, 3.}, {4., 5., 6.}, {7., 8., 9.}};
		u2.delete_row(1);
		std::cout << "u2.delete_element(1)" << std::endl << u2 << std::endl;

		u2 = {{1., 2, 3.}, {4., 5., 6.}, {7., 8., 9.}};
		u2.delete_col(2);
		std::cout << "u2.delete_element(2)" << std::endl << u2 << std::endl;
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

int	main(void)
{
		test_vector_in_task();
		test_matrix_in_task();

		test_vector_additional();
		test_matrix_additional();
}
