#include <iostream>
#include "Field.h"
#include "Ship.h"

using namespace std;

int main() {
	Field board[5][5];
	int x;
	int y;
	int healthyships = 1;

	//Schiffe setzen
	board[1][1].occupied = true;
	board[2][1].occupied = true;

	board[1][1].geshooted = 1;
	board[2][1].geshooted = 1;

	Ship cruise;

	board[1][1].ship = &cruise;
	board[2][1].ship = &cruise;


	do {
		try {
		 cout << "Gebe die X Koordinate ein um zu schiessen: " << endl;
		 cin >> x;
		 cout << "Gebe die Y Koordinate ein um zu schiessen: " << endl;
		 cin >> y;
		

			if (board[x][y].geshooted == 1) {

				if (board[x][y].occupied == true)
				{
					board[x][y].ship->life--; //Gehirnst�tze f�r Christian deutet so viel wie:board[x][y].ship->life = board[x][y].ship->life -1 
					cout << "Schiff getroffen!";
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
		


		catch (int ex) { //Datentyp der bei Throw geworfen wurde
			cerr << "Gebe gueltige Kordinaten ein!" << endl;
		}
	}
	while (healthyships != 0);
		
	

	return 0;
}