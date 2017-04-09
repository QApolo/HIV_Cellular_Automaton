#include "VIH_automata.h"

//functions used
void start()
{
	Cell **lattice = createLattice();
	printLattice(lattice);
}

Cell **createLattice()
{
	srand(time(NULL));
	Cell **lattice = (Cell**)malloc(WIDTH*sizeof(Cell*));
	int i, j;
	for(i = 0; i < WIDTH; i++)
		lattice[i] = (Cell*)malloc(sizeof(Cell)*HEIGHT);

	int number_infected = 5*WIDTH/HEIGHT;
	int infectedY, infectedX;

	printf("%d\n",number_infected );

	for(i = 0; i < WIDTH; i++)
	{
		for(j = 0; j < HEIGHT; j++)
		{
			infectedY = rand()%((WIDTH));
			infectedX = rand()%((HEIGHT));
			//printf("%d %d\n",infectedY,infectedX );

			if(lattice[i][j].state != '+') lattice[i][j].state = '.';
			if(number_infected)		
				if(lattice[infectedY][infectedX].state != '+')
				{
					lattice[infectedY][infectedX].state = '+';
					number_infected --;	
				}
		}
	}

return lattice;
}

void printLattice(Cell **lattice)
{
	int i, j;
	for(i = 0; i < WIDTH; i++)
	{
		for(j = 0; j < HEIGHT; j++)
		{
			printf("%c",lattice[i][j].state );
		}
		printf("\n");
	}
}
