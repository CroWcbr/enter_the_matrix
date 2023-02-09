#include "../Matrix.hpp"
#include "../Vector.hpp"

using namespace ft;

void	test_in_task()
{
	std::cout << "------ cosine in task ------" << std::endl;

	ft::Vector<double>	u = {1., 0.};
	ft::Vector<double>	v = {1., 0.};
	std::cout << "{1., 0.} & {1., 0.}" << "\t" << angle_cos(u, v) << std::endl;
	
	u = {1., 0.};
	v = {0., 1.};
	std::cout << "{1., 0.} & {0., 1.}" << "\t" << angle_cos(u, v) << std::endl;
	
	u = {-1., 1.};
	v = {1., -1.};
	std::cout << "{-1., 1.} & {1., -1.}" << "\t" << angle_cos(u, v) << std::endl;

	u = {2., 1.};
	v = {4., 2.};
	std::cout << "{2., 1.} & {4., 2.}" << "\t" << angle_cos(u, v) << std::endl;

	u = {1., 2., 3.};
	v = {4., 5., 6.};
	std::cout << "{1., 2., 3.} & {4., 5., 6.}" << "\t" << angle_cos(u, v) << std::endl;
}

void	test_additional()
{
	std::cout << "------ cosine additional ------" << std::endl;

	ft::Vector<double>	u = {1., 0.};
	ft::Vector<double>	v = {1., 0., 3.};
	try
	{
		std::cout << "{1., 0.} & {1., 0., 3.}" << "\t" << angle_cos(u, v) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	u = {1., 0.};
	v = {0., 1.};
	std::cout << "{1., 0.} & {0., 1.}" << "\t" << angle_cos({1., 0.}, {0., 1.}) << std::endl;
}

int	main()
{
	test_in_task();
	test_additional();
}
