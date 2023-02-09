#include "../Matrix.hpp"
#include "../Vector.hpp"

using namespace ft;

void	test_in_task()
{
	std::cout << "------ Cross product in task ------" << std::endl;

	ft::Vector<double> u = {0., 0., 1.};
	ft::Vector<double> v = {1., 0., 0.};
	std::cout   << "{0., 0., 1.} & {1., 0., 0.}\t" << std::endl << cross_product(u, v) << std::endl;

    u = {1., 2., 3.};
    v = {4., 5., 6.};
	std::cout   << "{1., 2., 3.} & {4., 5., 6.}\t" << std::endl << cross_product(u, v) << std::endl;

    u = {4., 2., -3.};
    v = {-2., -5., 16.};
    std::cout   << "{4., 2., -3.} & {-2., -5., 16.}\t" << std::endl << cross_product(u, v) << std::endl;
}

void	test_additional()
{
	std::cout << "------ Cross product additional ------" << std::endl;

}

int	main()
{
	test_in_task();
	// test_additional();
}
