#include <iostream>
#include <cmath>

double function(double x, size_t n);
ssize_t calc_func(double *sum, double x, double eps, double (*func)(double x, size_t n));

double Yfunc(double x);

int main()
{
	double x = 0;
	double eps = 0;

	std::cout << "Функция суммы cos(nx) / n\n";
	std::cout << "Введите x: ";
	std::cin >> x;

	std::cout << "Введите точность eps: ";
	std::cin >> eps;

	double sum = 0;
	ssize_t num = calc_func(&sum, x, eps, function);
	if (num == -1)
	{
		std::cout << "Error from calc_func\n";
		return -1;
	}

	std::cout << "Sum of " << num << " elemets = " << sum << "\n";

	std::cout << "Y = -ln|2 * sin(" << x << " / 2)| = ";
	double res = Yfunc(x);
	std::cout << res << std::endl;

	return 0;
}

double function(double x, size_t n)
{
	return cos(n * x) / n;
}

double Yfunc(double x)
{
	return -log(fabs(2 * sin(x / 2)));
}

ssize_t calc_func(double *sum, double x, double eps, double (*func)(double x, size_t n))
{
	if (sum == nullptr)
	{
		return 0;
	}

	*sum = 0;
	size_t n = 1;
	double prev_a = func(x, n++);
	double cur_a = func(x, n++);
	std::cout << prev_a << " " << *sum << "\n";
	std::cout << cur_a << " " << *sum << "\n";
	(*sum) += prev_a + cur_a;

	while (fabs(cur_a - prev_a) > eps)
	{
		prev_a = cur_a;
		cur_a = func(x, n++);
		(*sum) += cur_a;
		
//		std::cout << cur_a << " " << *sum << "\n";
	}

	return n;
}
