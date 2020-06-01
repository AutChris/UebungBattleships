#include "Game.h"

Game::Game() {

	//Größe des Boards wird festgelegt
	int x;
	int y;
	int healthyships = 1;
	string zeichen = {};

	//Schiff setzen
	board[1][1].occupied = true;
	board[2][1].occupied = true;


	Ship cruise;


	board[1][1].ship = &cruise;
	board[2][1].ship = &cruise;


	do {
		cout << "Gebe die X Koordinate ein um zu schiessen: " << endl;
		cin >> x;
		cout << "Gebe die Y Koordinate ein um zu schiessen: " << endl;
		cin >> y;


		for (int i = 0; i < 10 + 1; i++) {
			if (i > 0) {
				printf(" %i", i);
			}
			else {
				printf("   ");
			}
		}
		printf("\n");

		for (int i = 0; i < 10 + 1; i++)
		{
			if (i > 0)
			{
				if (i == 1)
				{
					printf("%c", 201);
					printf("%c", 205);
					printf("%c", 205);
				}

				if (i > 1 && i < 10)
				{
					printf("%c", 205);
					printf("%c", 205);
				}

				if (i == 10)
				{
					printf("%c", 205);
					printf("%c", 187);
				}

			}
			else
			{
				printf("   ");
			}
		}

		printf("\n");



		if (board[x][y].occupied == true) {
			zeichen = {"x"};
		}
		else {
			zeichen = {"o"};
		}

		for (int row = 0; row < 10; row++)
		{
			for (int i = 0; i < 10 + 1; i++)
			{
				if (i > 0)
				{
					if (i == 1)
					{
						printf("%c", 186);
						printf("%c", zeichen);
					}

					if (i > 1 && i < 10)
					{
						printf("|");
						printf(".");
					}

					if (i == 10)
					{
						printf("|");
						printf(".");
						printf("%c", 186);
					}
				}
				else
				{
					printf(" %c ", 65 + row);
				}

			}

			printf("\n");

			for (int i = 0; i < 10 + 1; i++)
			{
				if (row < 10 - 1) {
					if (i > 0)
					{
						if (i == 10)
						{
							printf("-%c", 185);
						}
						else
						{
							printf("--");
						}
					}
					else
					{
						printf("   %c", 204);
					}
				}
				else
				{
					if (i > 0)
					{
						if (i == 10)
						{
							printf("%c%c", 205, 188);
						}
						else
						{
							printf("%c%c", 205, 205);
						}
					}
					else
					{
						printf("   %c", 200);
					}

				}
			}

			printf("\n");
		}

	

		if (board[x][y].geshooted == 1) {

			if (board[x][y].occupied == true)
			{
				board[x][y].ship->life--; //Gehirnstütze für Christian deutet so viel wie:board[x][y].ship->life = board[x][y].ship->life -1 
				cout << "Schiff getroffen!" << endl;
				if (board[x][y].ship->life == 0)
				{
					healthyships--;
					cout << "Schiff wurde versenkt!" << endl;
				}

			}
			else
			{
				cout << "Schiff wurde nicht getroffen" << endl;
			}
			board[x][y].geshooted--;
		}
		else
		{
			cout << "Diese Stelle wurde schon beschossen!" << endl;
		}
	}


	while (healthyships != 0);
	
	
}


