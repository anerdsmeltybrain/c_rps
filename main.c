#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum choices { ROCK = 'r', PAPER = 'p', SCISSORS = 's', YES = 'y', NO = 'n' };

int main() {

	//initialize random seed
	srand(time(NULL));
	int random_var = rand();
	printf("this is a test to see is the random var works: %d \n", random_var);

start:
	//setting my variables
	printf("make a choice between rock(r) paper(p) and scissors(s) then press enter~ \n\n");
	char input[1], comp_input[1];
	int x;

	//computer input
	x = rand() % 3;
	printf("the value of x from computer choice func: %d \n", x);
	char choices[3] = { ROCK, PAPER, SCISSORS };
	comp_input[0] = choices[x];
	printf("this is the computer choice: %c \n", comp_input);

	//player input
	scanf("%c", &input);

	printf(input);
	printf(comp_input);

	if (input[0] == comp_input[0]) {
		printf("\n\tit's a tie\n");
		goto end;
	}


	switch (input[0]) {
		case ROCK:
			if (comp_input[0] == SCISSORS)
				printf(" %c beats %c so you win!!! \n", input[0], comp_input[0]);
			else
				printf(" %s beats %s so you lose... \n", comp_input[0], input[0]);
			break;
		case PAPER:
			if (comp_input[0] == ROCK)
				printf(" %c beats %c so you win!!! \n", input[0], comp_input[0]);
			else
				printf(" %s beats %s so you lose... \n", comp_input[0], input[0]);
			break;
		case SCISSORS:
			if (comp_input[0] == PAPER)
				printf(" %c beats %c so you win!!! \n", input[0], comp_input[0]);
			else
				printf(" %s beats %s so you lose... \n", comp_input[0], input[0]);
			break;
		default:
			printf("not a valid choice\n\n");
			goto start;
	}

end:
	printf("Thanks for playing would you like to play again YES(y) or NO(n)??? \n");

	char confirm;
	scanf(" %c", &confirm);

	switch(confirm) {
		case YES:
			goto start;
		case NO:
			printf("Thank you come again~ \n\n");
	}
	return 0;
}
