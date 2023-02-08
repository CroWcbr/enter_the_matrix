#include "../Matrix.hpp"
#include "../Vector.hpp"

using namespace ft;

void	test_in_task()
{
	std::cout << "------ dot in task ------" << std::endl;

	Vector<float> u({0., 0.});
	Vector<float> v({1., 1.});
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

void	test_additional()
{
	std::cout << "------ dot additional ------" << std::endl;

	Vector<float> u({0., 0.});
	Vector<float> v({1., 1.});
	std::cout << "dot(u, v) = " << dot(u, v) << std::endl;

	u = {1., 1.};
	v = {1., 1.};
	std::cout << "dot(u, v) = " << dot(u, v) << std::endl;

	std::cout << "dot({-1., 6.}, {3., 2.}) = " << dot<double>({-1., 6.}, {3., 2.}) << std::endl;

	try
	{
		std::cout << "dot<int>({1, 2}, {1}) = " << dot<int>({1, 2}, {3}) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

int	main()
{
	test_in_task();
	test_additional();
}
