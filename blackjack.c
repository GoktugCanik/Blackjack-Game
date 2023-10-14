#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// a function to draw a random card
int random_card()
	{
	return rand() %13 + 1 ;
	}
// a function to adjust card values
int hand_calculator(int card) 
	{
	if (card >= 10) { return 10; }
	else if (card == 1) { return 11; }

	else { return card; }
	}
	
// the game	
int main() {
	srand(time(NULL));
	int player_hand = 0;
	int dealer_hand = 0;
	int player2_hand = 0;
	char hs;
	
	printf("Let's play Blackjack. \n ");

	while (1) {
		int player_card = random_card();
		int dealer_card = random_card();
		int player2_card = random_card();
		player_hand += hand_calculator(player_card);
		if (dealer_hand < 17) {dealer_hand += hand_calculator(dealer_card);}
		if (player2_hand < 16) {player2_hand += hand_calculator(player2_card);}
		
		printf("\n Your card is %d. Your total hand is %d. \n", player_card, player_hand);
		printf("\n Dealer's card is %d. Dealer's total hand is %d", dealer_card, dealer_hand);
		printf("\n player2's card is %d. player2's total hand is %d", player2_card, player2_hand);

 	
	 	if (player_hand == 21) {
            printf("\n\n Blackjack! You win!\n");
            break;
        } else if (player_hand > 21) {
            printf("\n\n Bust! You lose.\n");
            break;
        }
		
			
		printf("\n\n Do you (H)it or (S)tand ?");
		scanf(" %c", &hs);
		
		 if ( hs == 'S' || hs == 's') {
		 	while ( dealer_hand < 17 )
			{
		 		dealer_card = random_card();
		 		dealer_hand += hand_calculator(dealer_card);
		 		printf("\nDealer's final card is %d. Dealer's total hand is %d \n", dealer_card, dealer_hand);

			}
			while (player2_hand < 16)
			{
				player2_card = random_card();
				player2_hand += hand_calculator(player2_card);
				printf("\nplayer2's final card is %d. player2's total hand is %d", player2_card, player2_hand);
			}
			        
				if (player_hand <= 21) 
				{
					if ( player_hand > dealer_hand && player2_hand > 21 || player_hand > player2_hand && dealer_hand > 21 || player_hand > dealer_hand && player_hand > player2_hand) 
					{
						printf("\nYou win!");
					}
				}
				if (dealer_hand <= 21)
				{
					if(dealer_hand > player_hand && player2_hand > 21 || dealer_hand > player2_hand && player_hand > 21 || dealer_hand > player_hand && dealer_hand > player2_hand)
					{
						printf("\nDealer wins! :(");
					}
				}
				if (player2_hand <= 21)
				{
					if (player2_hand > dealer_hand && player_hand > 21 || player2_hand > player_hand && dealer_hand > 21 || player2_hand > dealer_hand && player2_hand > player_hand)
					{
						printf("\nPlayer2 wins! :(");
					}
				}
				if ( player_hand == dealer_hand && dealer_hand == player2_hand) 
				{
					printf("It is a tie!!");
				}
				if (dealer_hand <21 && player_hand < 21 && dealer_hand == player_hand && player_hand > player2_hand)
				{
					printf("It is a tie!!");
				}
				if ( dealer_hand < 21 && player2_hand < 21 && dealer_hand == player2_hand && dealer_hand > player_hand )
				{
					printf("It is a tie!!");
				}
				if ( player_hand < 21 && player2_hand < 21 && player_hand == player2_hand && player_hand > dealer_hand)
				{
					printf("It is a tie!!");
				}
				if (player_hand > 21 && dealer_hand > 21 && player2_hand > 21) 
				{
					printf("Everyone bust!");
				}
            break;
		 }
	}
    return 0;
}

