#include "threads.h"
#define NB_THREAD 4

int i;
int count;

void print_if_prime(int a)
{
	if (a == 2)
	{
		printf("%d\n", a);
		count++;
		return;
	}
	for(int k = 2; k < a; k++)
		if (a % k == 0) return;
	printf("%d\n", a);
	count++;
}

void *print_primes(void *arg)
{
	int a = 0;
	int max = (int) arg;
	while (count <= max)
	{
		a = ++i;
		print_if_prime(a);
	}
	pthread_exit(NULL);
}

int main(int argc, char** argv)
{
	int			max = 100;
	pthread_t	threads[NB_THREAD];
	if (argc == 2) max = atoi(argv[1]);
	i = 1;
	count = 0;
	for (int k = 0; k < NB_THREAD; k++)
		pthread_create (&threads[k], NULL, print_primes, (void*) max);
	for (int k = 0; k < NB_THREAD; k++)
		pthread_join(threads[k], NULL);
	return 0;
}
