#include "threads.h"

void *print_thread(void *arg)
{
	printf("in thread\n");
	(void) arg;
	pthread_exit(0);
}

int main (int argc, char** argv)
{
	pthread_t thread_print;
	printf("creating thread\n");
	if (pthread_create(&thread_print, NULL, print_thread, NULL) == -1)
	{
		perror("failed to create thread");
		return -1;
	}

	if (pthread_join(thread_print, NULL))
	{
		perror("failed to join thread");
		return -1;
	}

	printf("done");
	return 0;
}
