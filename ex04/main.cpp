#include "../Matrix.hpp"
#include "../Vector.hpp"

using namespace ft;

void	test_in_task()
{
	std::cout << "------ norm in task ------" << std::endl;

	ft::Vector<double>   u = {0., 0., 0.};
	std::cout << "{0., 0., 0.}" << "\t" << u.norm_1() << "\t";
	std::cout << u.norm() << "\t" << u.norm_inf() << std::endl;
	
	u = {1., 2., 3.};
	std::cout << "{1., 2., 3.}" << "\t" << u.norm_1() << "\t";
	std::cout << u.norm() << "\t" << u.norm_inf() << std::endl;
	
	u = {-1., -2.};
	std::cout << "{-1., -2.}" << "\t" << u.norm_1() << "\t";
	std::cout << u.norm() << "\t" << u.norm_inf() << std::endl;
}

int	main()
{
	test_in_task();
}
