#ifndef THREADS_H
#define THREADS_H
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

typedef struct atomic_s
{
int				var;
	pthread_mutex_t	mutex;
	pthread_cond_t	cond;
} atomic_t;

#endif
