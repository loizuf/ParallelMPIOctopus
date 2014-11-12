#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define little = 2;
#define big = 2048;

int main(int argc, char const *argv[])
{
	int littleMessage[little], bigMessage[big], rank, zero, one, tag;
	double timeCheckOne, timeCheckTwo, durationOne, durationTwo, latency, bandwidth;
	MPI_Status status;

	tag = -1;

	zero = 0;
	one = 1;

	MPI_Init(&argc, &argv);

	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	// First attempt with little message
	if(rank = zero){
		timeCheckOne = MPI_Wtime();
		if(MPI_SUCCESS != MPI_Send(littleMessage, little, MPI_INT, two, ++tag, MPI_COMM_WORLD){
			MPI_Abort();
		};
		MPI_Recv(littleMessage, little, MPI_INT, two, tag, MPI_COMM_WORLD, *status);
	} else if(rank = one){
		MPI_Recv(littleMessage, little, MPI_INT, one, tag, MPI_COMM_WORLD, *status);
		if(MPI_SUCCESS != MPI_Send(littleMessage, little, MPI_INT, one, ++tag, MPI_COMM_WORLD){
			MPI_Abort();
		}
		timeCheckTwo = MPI_Wtime();
	}
	durationOne = timeCheckTwo - timeCheckOne;

	// Second attempt with big message
	if(rank = zero){
		timeCheckOne = MPI_Wtime();
		if(MPI_SUCCESS != MPI_Send(bigMessage, big, MPI_INT, two, ++tag, MPI_COMM_WORLD){
			MPI_Abort();
		};
		MPI_Recv(bigMessage, big, MPI_INT, two, tag, MPI_COMM_WORLD, *status);
	} else if(rank = one){
		MPI_Recv(bigMessage, big, MPI_INT, one, tag, MPI_COMM_WORLD, *status);
		if(MPI_SUCCESS != MPI_Send(bigMessage, big, MPI_INT, one, ++tag, MPI_COMM_WORLD){
			MPI_Abort();
		}
		timeCheckTwo = MPI_Wtime();
	}
	durationTwo = timeCheckTwo - timeCheckOne;

	MPI_Finalize();

	// Result of equationsystem
	latency = (durationTwo-big/little*durationOne)/-1023;
	bandwidth = (sizeOf(int)*little)/(t1-latency);

	printf("Latency is: %f\nBandwidth is: %f", Latency, bandwidth);

	free(littleMessage);
	free(bigMessage);

	/* code */
	return 0;
}