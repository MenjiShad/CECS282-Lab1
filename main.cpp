#include <iostream>
#include <random>

using namespace std;

int main(int argc, char* argv[]) {
	// Choose prize door at random
	random_device rd;

	default_random_engine engine(rd());

	// Chooses a number between 1 and 3. Door 1, 2, or 3
	uniform_int_distribution<int> distr(1, 3); 
	int winDoor = distr(engine);

	// Prompt user to pick a door
	int userPick;
	do {
	cout << "Please pick a door. 1, 2, or 3?" << endl;
	cin >> userPick;
	if (userPick < 1 || userPick > 3)
		cout << "Choose an appropriate door." << endl;
	} while (userPick < 1 || userPick > 3);

	/* Monty Hall Problem
	 Reveal a door that has a goat
	 but is not the user's door
	 If the user picked the winning door
	 Randomly select one of the other two doors */
	int revealDoor;
	if (userPick == winDoor) {
		do {
		revealDoor = distr(engine);
		} while (revealDoor == userPick); // If revealDoor is equal to userPick, roll again
		cout << "Behind door " << revealDoor << " is a goat!" << endl;
	} else {
		// If the winning door is Door 1
		// and the user did not pick it
		if (winDoor == 1) {
			// Reveal the GOAT door that is NOT the user's door
			if (userPick == 2) {
				cout << "Behind door 3 is a goat!" << endl;
				revealDoor = 3;
			} else {
				cout << "Behind door 2 is a goat!" << endl;
				revealDoor = 2;
			}
		} else if (winDoor == 2) { // If winning door is Door 2
			if (userPick == 3) {
				cout << "Behind door 1 is a goat!" << endl;
				revealDoor = 1;
			} else {
				cout << "Behind door 3 is a goat!" << endl;
				revealDoor = 3;
			}
		} else { // if winning door is Door 3
			if (userPick == 2) {
				cout << "Behind door 1 is a goat!" << endl;
				revealDoor = 1;
			} else {
				cout << "Behind door 2 is a goat! " << endl;
				revealDoor = 2;
			}
		}
	}

	// Does the user want to switch doors?
	cout << "Do you wish to switch doors? (y/n)" << endl; 
	char choice;
	cin >> choice;
	// If the user chooses to switch doors, 
	// switch the userPick to the unopened door
	// Alternate: replace all the "if" statements with something smaller
	// Solution: Total value of doors --> 1 + 2 + 3 == 6
	// The switch door's value = 6 - (user's door) - (revealed door)
	if (choice == 'Y' || choice == 'y') {
		/*if (userPick == 1 && revealDoor == 2)
			userPick = 3;
		else if (userPick == 1 && revealDoor == 3)
			userPick = 2;
		else if (userPick == 2 && revealDoor == 1)
			userPick = 3;
		else if (userPick == 2 && revealDoor == 3)
			userPick = 1;
		else if (userPick == 3 && revealDoor == 1)
			userPick = 2;
		else if (userPick == 3 && revealDoor == 2)
			userPick = 1; */
		userPick = 6 - userPick - revealDoor;
		cout << "Switched to door " << userPick << endl;
	}
	// If the user's door matches the winning door
	if (userPick == winDoor) {
		cout << "Congratulations!" << endl;
		// Roll random prize
		uniform_int_distribution<int> prizeRoll(1, 5);
		int prizePick = prizeRoll(engine);
		cout << "You get prize number " << prizePick << "!\n";
		switch (prizePick) {
			case 1: cout << "You got $250.00!" << endl;
				break;
			case 2: cout << "You got a massage chair!" << endl;
				break;
			case 3: cout << "You got a durian fruit!" << endl;
				break;
			case 4: cout << "You got a rice cooker!" << endl;
				break;
			case 5: cout << "You got two watermelons!" << endl;
				break;
		}
	} else
		cout << "Too bad! You got a goat. Better luck next time." << endl;

	int cont;
	cout << "Press any key to continue..." << endl;
	cin >> cont;
}
