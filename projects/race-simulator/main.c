#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// NOTE: Structures section
struct Race {
	int numberOfLaps;
	int currentLap;
	char firstPlaceDriverName[25];
	char firstPlaceRaceCarColor[15];
};

struct RaceCar {
	char driverName[20];
	char raceCarColor[15];
	int totalLapTime;
};

// NOTE: Print functions section
void printIntro() {
	printf("Welcome to our main event digital race fans!\n");
	printf("I hope everybody has their snacks because we are about to begin!\n");
}

void printCountdown() {
	printf("Racers Ready! In...\n5\n4\n3\n2\n1\nRace!");
}

void printFirstPlaceAfterLap(struct Race race) {
	printf("After lap number %d\n", race.currentLap);
	printf("First place is: %s in the %s race car!\n", race.firstPlaceDriverName, race.firstPlaceRaceCarColor);
}

void printCongratulation(struct Race race) {
	printf("Let's all congratulate %s in the %s race car for an amazing performance.\n", race.firstPlaceDriverName, race.firstPlaceRaceCarColor);
	printf("It truly was a great race and everybody have a goodnight!");
}

// NOTE: Logic functions section
int calculateTimeToCompleteLap() {
	int speed        = rand() % 3 + 1;
	int acceleration = rand() % 3 + 1;
	int nerves       = rand() % 3 + 1;

	return speed + acceleration + nerves;
}

/// update total lap time of a race car
void updateRaceCar(struct RaceCar *raceCar) {
	raceCar->totalLapTime = calculateTimeToCompleteLap();
}

/// update driver and car in first place
void updateFirstPlace(struct Race *race, struct RaceCar *raceCar1, struct RaceCar *raceCar2) {
	if (raceCar1->totalLapTime >= raceCar2->totalLapTime) {
		strcpy(race->firstPlaceDriverName, raceCar1->driverName);
		strcpy(race->firstPlaceRaceCarColor, raceCar1->raceCarColor);
	} else {
		strcpy(race->firstPlaceDriverName, raceCar2->driverName);
		strcpy(race->firstPlaceRaceCarColor, raceCar2->raceCarColor);
	}
}

/// initialize a Race struct and simulate race
void startRace(struct RaceCar *raceCar1, struct RaceCar *raceCar2) {
	struct Race race = {
		.numberOfLaps = 5,
		.currentLap = 1,
		.firstPlaceRaceCarColor = "",
		.firstPlaceDriverName = "",
	};

	for (int i = 0; i < race.numberOfLaps; i++) {
		updateRaceCar(raceCar1);                     // update lap time
		updateRaceCar(raceCar2);
		updateFirstPlace(&race, raceCar1, raceCar2); // update race info
		printFirstPlaceAfterLap(race);               // printf information about first place
		race.currentLap++;                           // increment lap number
	}
	printCongratulation(race);
}

int main() {
	// to je treba klicat v main
	srand(time(NULL));

	struct RaceCar raceCar1 = {
		.driverName = "Lana Grudnik",
		.raceCarColor = "Matte Black",
		.totalLapTime = 0
	};
	struct RaceCar raceCar2 = {
		.driverName = "Jan Panjan",
		.raceCarColor = "Neon Red",
		.totalLapTime = 0
	};

	printIntro();
	printCountdown();
	startRace(&raceCar1, &raceCar2);

	// :D

    return 0;
}
