#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int sum;
void *runner(void *param);

int main(int argc, char *argv[])
{
	pthread_t tid;
	//pthread_attr_t attr;

	if(argc != 2){
		fprintf(stderr, "usage: a.out <integer value>\n");
		return -1;
	}
	if(atoi(argv[1]) < 0){
		fprintf(stderr, "%d should be >= 0\n", atoi(argv[1]));
		return -1;
	}

	//initialize attribute to default values
	//pthread_attr_init(&attr);
	//create thread
	pthread_create(&tid,NULL,runner,argv[1]);
	//wait for the thread number <tid> to complete
	pthread_join(tid,NULL);

	printf("sum = %d\n", sum);

	return 0;
}

void *runner(void *param)
{
	int i, upper = atoi(param);
	sum = 0;

	for(i = 1; i<= upper; i++)
		sum += i;

	pthread_exit(0);
}
