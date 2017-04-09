#include "VIH_automata.h"

//functions used

int countNeighbours(Cell **lattice, int y, int x)
{
	int count = 0,i;
	int movs[8][2] = 
	{
		{1,0},
		{0,1},
		{-1,0},
		{0,-1},
		{1,1},
		{-1,1},
		{1,-1},
		{-1,-1}
	};
	for(i = 0; i < 8; i++)
	{
		int auxY = y+movs[i][0], auxX = x+movs[i][1];
		if(validMov(auxY,auxX))
		{
			if(lattice[auxY][auxX].state == '+')
				count ++;
		}
	}
return count;
}

int validMov(int y, int x)
{
	if(y < 0 || y >= WIDTH || x < 0 || x >= HEIGHT)	return 0;
return 1;
}
void runProcess(Cell **lattice,int time)
{
	Cell **aux_lattice = createLattice();
	int i,j;

	while(time--)
	{
		printLattice(lattice);
		usleep(100000);
		
		system(CLEAR);

		for(i = 0; i < WIDTH; i++)
		{

			for(j = 0; j < HEIGHT; j++)
			{
				if( lattice[i][j].state == '.')
				{
					if ( countNeighbours(lattice,i,j) >= RA)
					{
						aux_lattice[i][j].state = '*';
						aux_lattice[i][j].lt = T;
					}
					else 
					{
						aux_lattice[i][j] = lattice[i][j];
					}
				}
				if(time%T == 0)
				{
					aux_lattice[i][j].lt --;
				}
				if(lattice[i][j].lt == 0 && lattice[i][j].state == '+')
				{	
					aux_lattice[i][j].state = '*';
					aux_lattice[i][j].lt = T;
				}
				else if(lattice[i][j].lt == 0 && lattice[i][j].state == '*')
				{
					aux_lattice[i][j].state = 'x';
					aux_lattice[i][j].lt = T;
				}
			}
		}

		for(i = 0; i < WIDTH; i++)
			for(j = 0; j < HEIGHT; j++)
				lattice[i][j] = aux_lattice[i][j];

	}

}

void start()
{
	Cell **lattice = createLattice();
	runProcess(lattice, 100);
}

Cell **createLattice()
{
	srand(time(NULL));
	Cell **lattice = (Cell**)malloc(WIDTH*sizeof(Cell*));
	int i, j;
	for(i = 0; i < WIDTH; i++)
		lattice[i] = (Cell*)malloc(sizeof(Cell)*HEIGHT);

	int number_infected = 1000*WIDTH/HEIGHT;
	int infectedY, infectedX;

	for(i = 0; i < WIDTH; i++)
	{
		for(j = 0; j < HEIGHT; j++)
		{
			infectedY = rand()%((WIDTH));
			infectedX = rand()%((HEIGHT));
			lattice[i][j].lt = T;

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
