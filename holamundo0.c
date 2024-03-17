#include <stdio.h>
#include <omp.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int speedPowerUp = 100;

struct Player {
    char name[50];
	int speed;
	int coveredDistance;
};

int main(void) {

	srand(time(NULL));	

	struct Player players[4];

	strcpy(players[0].name,"Mario");
	strcpy(players[1].name,"Peach");
	strcpy(players[2].name,"Bowser");
	strcpy(players[3].name,"Yoshi");

	#pragma omp parallel num_threads(4) 
	{			
		int position = omp_get_thread_num();
		int randomSpeed = (rand() % 21) + 80;
	 	players[position].speed = randomSpeed;
		players[position].coveredDistance = 0;
		usleep(500000);

		#pragma omp critical
		{
			printf("Name: %s\n", players[position].name);
			printf("Speed: %d\n", players[position].speed);
			printf("Covered Distance: %d\n", players[omp_get_thread_num()].coveredDistance);
		}	
	}
	

	return 0;
}
