#include "../Matrix.hpp"
#include "../Vector.hpp"

void	test_in_task_one()
{
	std::cout << "------ linear_combination in task one------" << std::endl;

	ft::Matrix<double>	u({{1., 2, 3.}, {0., 10., -100}});
	ft::Vector<double>	v({10., -2.});
	std::cout << "u = " << std::endl << u << std::endl;
	std::cout << "v = " << std::endl << v << std::endl;

	std::cout << "linear_combination(u, {10., -2.})" << std::endl;
	std::cout << ft::linear_combination(u, {10., -2.}) << std::endl;

	std::cout << "linear_combination(u, v)" << std::endl;
	std::cout << ft::linear_combination(u, v) << std::endl;

	std::cout << "linear_combination({{1., 2, 3.}, {0., 10., -100}}, {10., -2.})" << std::endl;
	std::cout << ft::linear_combination({{1., 2, 3.}, {0., 10., -100}}, {10., -2.}) << std::endl;

	std::cout << "linear_combination({{1., 2, 3.}, {0., 10., -100}}, v)" << std::endl;
	std::cout << ft::linear_combination({{1., 2, 3.}, {0., 10., -100}}, v) << std::endl;
}

void	test_in_task_two()
{
	std::cout << "------ linear_combination in task two ------" << std::endl;

	{
		ft::Matrix<double>	u({{1., 2, 3.}, {0., 10., -100}});
		ft::Vector<double>	v1({1., 0., 0.});
		ft::Vector<double>	v2({0., 1., 0.});
		ft::Vector<double>	v3({0., 0., 1.});

		std::cout << "linear_combination({v1, v2, v3}, {10., -2., 0.5})" << std::endl;
		std::cout << ft::linear_combination({v1, v2, v3}, {10., -2., 0.5}) << std::endl;
	}

	{
		ft::Vector<double>	v1({1., 2., 3.});
		ft::Vector<double>	v2({0., 10., -100.});

		std::cout << "linear_combination({v1, v2}, {10., -2.})" << std::endl;
		std::cout << ft::linear_combination({v1, v2}, {10., -2.}) << std::endl;
	}

	{
		ft::Vector<double>	v1({1., 2., 3.});
		ft::Vector<double>	v2({0., 10., -100.});
		ft::Vector<double>	v3({10., -2});

		std::cout << "linear_combination({v1, v2}, v3)" << std::endl;
		std::cout << ft::linear_combination({v1, v2}, v3) << std::endl;
	}
}

void	test_additional()
{
	std::cout << "------ linear_combination in additional test ------" << std::endl;

	try
	{	
		ft::Matrix<double>	u({{1., 2, 3.}, {0., 10., -100}});
		ft::Vector<double>	v({10., -2., -3.});
		std::cout << "linear_combination({{1., 2, 3.}, {0., 10., -100}}, {10., -2., 3})" << std::endl;
		std::cout << ft::linear_combination(u, v) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

int	main()
{
	test_in_task_one();
	test_in_task_two();
	test_additional();
}
