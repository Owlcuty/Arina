#include <iostream>
#include <cmath>

double recurs_function(double x, ssize_t n, double last_val);
ssize_t calc_func(double *sum, double x, size_t max_iter, double (*func)(double x, ssize_t n, double last_val));

double Yfunc(double x);

int main()
{
	double x = 0;

	std::cout << "Функция суммы (-1)^n * (1 + x)^2n / n\n";
	std::cout << "Введите x: ";
	std::cin >> x;

	double sum = 0;
	ssize_t num = calc_func(&sum, x, 40, recurs_function);
	if (num == -1)
	{
		std::cout << "Error from calc_func\n";
		return -1;
	}

	std::cout << "Sum of " << num << " elemets = " << sum << "\n";

	std::cout << "Y = ln(1 / (" << x * x << " + " << 2 * x << " + 2)) = ";
	double res = Yfunc(x);
	std::cout << res << std::endl;

	return 0;
}

double recurs_function(double x, ssize_t n, double last_val)
{
	if (n == 1)
	{
		return -pow((1 + x), 2 * n) / n;
	}
	last_val *= (1 - n) / (double)n;	
	last_val *= pow((1 + x), n);
	return last_val;
}

double Yfunc(double x)
{
	return log(1 / (x * x + 2 * x + 2));
}

ssize_t calc_func(double *sum, double x, size_t max_iter, double (*func)(double x, ssize_t n, double last_val))
{
	if (sum == nullptr)
	{
		return 0;
	}

	*sum = 0;
	size_t n = 1;
	double cur = func(x, n++, 0);

	while (n <= max_iter)
	{
		(*sum) += cur;
		cur = func(x, n++, cur);
	}

	return n - 1;
}
