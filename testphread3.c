#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#define N 5

void *maths(void *arg)
{
	srand(time(NULL));
	double *ps = (double*) malloc(sizeof(double));
	double *ds = (double*) malloc(sizeof(double));
	double a[] = { 1.0, 2.0, 3.0, 4.0 };
	double ar[] = { 1.0, 4.0, 9.0, 16.0 };
	double arr[4];
	double m = 0.0, d = 0.0, m_in_2 = 0.0, m_2_in = 0.0;
	for (int i = 0;i < 4;i++)
	{
		arr[i] = (rand() % 10) / 10.0;
	}
	for (int i = 0;i < 4;i++)
	{
		m = m + a[i] * arr[i];
	}
	m_2_in = m * m;
	for (int i = 0;i < 4;i++)
	{
		m_in_2 = m_in_2 + ar[i] * arr[i];
	}
	d = m_in_2 - m_2_in;
	*ps = m; //mathswait
	*ds = d;
	printf("maths wait=%f\n", *ps);
	printf("disperce=%f\n", *ds);
	pthread_exit(0);
}

int main(int argc, char * argv[]){
	int result;
	pthread_t threads[N];
	void *status[N];
	for (int i = 0;i < N;i++)
	{
		sleep(1);
		result = pthread_create(&threads[i], NULL, maths, NULL);
		if (result != 0){
			perror("Creating the first thread");
			return EXIT_FAILURE;
		}
	}
	for (int i = 0;i < N;i++){
		result = pthread_join(threads[i], &status[i]);
		if (result != 0){
			perror("Joining the first thread");
			return EXIT_FAILURE;
		}
		else{
			printf("maths wait[%d]=%f\n", i, *((double*)status[i]));
		}
		free(status[i]);
	}
	printf("Done..\n");
	return EXIT_SUCCESS;
}

