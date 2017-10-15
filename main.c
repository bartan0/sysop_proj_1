#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

int counter = 0;

void *start_thread(void *arg)
{
	printf("Thread #%d\n", *(int*)arg);

	for (int i = 0; i < 100000; i++)
		counter++;

	return NULL;
}

int main()
{
	int n_threads = 10;

	pthread_t *threads = malloc(n_threads*sizeof(pthread_t));
	int *ids = malloc(n_threads*sizeof(int));
	for (int i = 0; i < n_threads; i++)
		ids[i] = i;

	printf("Starting %d threads...\n", n_threads);

	for (int i_thread = 0; i_thread < n_threads; i_thread++)
		pthread_create(threads + i_thread, NULL, start_thread, ids + i_thread);

	for (int i_thread = 0; i_thread < n_threads; i_thread++)
		pthread_join(threads[i_thread], NULL);

	printf("All threads finished.\n\ncounter = %d\n", counter);

	free(threads);
	free(ids);

	return 0;
}
