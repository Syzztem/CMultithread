#include "threads.h"
#define NB_THREAD 4

atomic_t i;
atomic_t count;

void print_if_prime(int a)
{
	if (a == 2)
	{
		printf("%d\n", a);
		pthread_mutex_lock(&count.mutex);
		count.var++;
		pthread_mutex_unlock(&count.mutex);
		return;
	}
	for(int k = 2; k < a; k++)
		if (a % k == 0) return;
	printf("%d\n", a);
	count.var++;
}

void *print_primes(void *arg)
{
	int a = 0;
	int max = (int) arg;
	while (count.var < max)
	{
		pthread_mutex_lock(&i.mutex);
		a = ++i.var;
		pthread_mutex_unlock(&i.mutex);
		print_if_prime(a);
	}
	pthread_exit(NULL);
}

int main(int argc, char** argv)
{
	int			max = 100;
	pthread_t	threads[NB_THREAD];
	if (argc == 2) max = atoi(argv[1]);
	i.var = 1;
	count.var = 0;
	pthread_mutex_init(&i.mutex, NULL);
	pthread_mutex_init(&count.mutex, NULL);
	for (int k = 0; k < NB_THREAD; k++)
		pthread_create (&threads[k], NULL, print_primes, (void*) max);
	for (int k = 0; k < NB_THREAD; k++)
		pthread_join(threads[k], NULL);
	printf("printed %d primes\n", count.var);
	return 0;
}
