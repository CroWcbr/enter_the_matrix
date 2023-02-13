#include "../Matrix.hpp"

using namespace ft;

Matrix<double> projection(double fov, double ratio, double near, double far) 
{
	Matrix<double> tmp(4, 4);

	for (size_t r = 0; r < 4; r++)
		for (size_t c = 0; c < 4; c++)
			tmp[r * 4 + c] = 0;
	
	double rad = fov * 0.5;
	double deltaZ = far - near;
	double cotangent = 1.0 / tan(rad);

	tmp[0 * 4 + 0] = cotangent / ratio;
	tmp[1 * 4 + 1] = cotangent;
	tmp[2 * 4 + 2] = -(far + near) / deltaZ;
	tmp[2 * 4 + 3] = -1;
	tmp[3 * 4 + 2] = -2.0 * near * far / deltaZ;
	return tmp;
}

int main()
{
	ft::Matrix<double> tmp = projection(90, 0.8, 0.1, 100);
	std::cout << tmp << std::endl;
	// for (size_t r = 0; r < 4; r++) 
	// {
	// 	for (size_t c = 0; c < 4; c++)
	// 	{
	// 		if (c != 0)
	// 			std::cout << ", ";
	// 		std::cout << tmp[r * 4 + c];
	// 	}
	// 	std::cout << std::endl;
	// }
}
