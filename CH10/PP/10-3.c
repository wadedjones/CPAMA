/* Modify poker.c again to put num_in_rank, num_in_suit and card exists into
 * a 5 x 2 array */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5

/* external variables */
bool straight, flush, four, three;
int pairs; /* can be 0, 1, or 2 */

/* prototypes */
void read_cards(int hand[5][2]);
void analyze_hand(int hand[5][2]);
void print_result(void);

int main(void) {
  int hand[5][2] = {0};
  for (;;) {
    read_cards(hand);
    analyze_hand(hand);
    print_result();
  }

  return 0;
}

void read_cards(int hand[5][2]) {
  char ch, rank_ch, suit_ch;
  int rank, suit, card_row, card_col;
  bool bad_card;
  int cards_read = 0;

  for (card_row = 0; card_row < NUM_CARDS; card_row++) {
    for (card_col = 0; card_col < 2; card_col++) {
      hand[card_row][card_col] = 0;
    }
  }
  card_row = card_col = 0;

  while (cards_read < NUM_CARDS) {
    bad_card = false;

    printf("Enter a card: ");

    rank_ch = getchar();
    switch (rank_ch) {
      // clang-format off
    case '0': exit(EXIT_SUCCESS);
    case '2': rank = 0; break;
    case '3': rank = 1; break;
    case '4': rank = 2; break;
    case '5': rank = 3; break;
    case '6': rank = 4; break;
    case '7': rank = 5; break;
    case '8': rank = 6; break;
    case '9': rank = 7; break;
    case 't': case 'T': rank = 8; break;
    case 'j': case 'J': rank = 9; break;
    case 'q': case 'Q': rank = 10; break;
    case 'k': case 'K': rank = 11; break;
    case 'a': case 'A': rank = 12; break;
    default: bad_card = true;
    }

    suit_ch = getchar();
    switch (suit_ch) {
      // clang-format off
			case 'c': case 'C': suit = 0; break;
			case 'd': case 'D': suit = 1; break;
			case 'h': case 'H': suit = 2; break;
			case 's': case 'S': suit = 3; break;
			default: bad_card = true;
    }

		while ((ch = getchar()) != '\n') {
			if (ch != ' ') bad_card = true;
		}

		if (bad_card) {
			printf("Bad card; ignored.\n");
		} else if (hand[card_row - 1][card_col] == rank && hand[card_row - 1][card_col + 1] == suit) {
			printf("Duplicate card; ignored.\n");
		} else {
			hand[card_row][card_col] = rank;
			hand[card_row++][++card_col] = suit;
			cards_read++;
			card_col = 0;
		}
  }
}

void analyze_hand(int hand[5][2]) {
	int num_consec = 0;
	int card_row, card_col;
	straight = false;
	flush = false;
	four = false;
	three = false;
	pairs = 0;

	/* check for flush */
	int suit = hand[0][1];
	int i = 0;
	while (hand[i][1] == suit) {
		i++;
	}
	if (i == NUM_CARDS) {
		flush = true;
	}

	/* check for straight */
	int high, low, total = 0;
	high = low = hand[0][0];
	for (i = 0; i < NUM_CARDS; i++) {
		if (hand[i][0] >= high) {
			high = hand[i][0];
		}
		if (hand[i][0] <= low) {
			low = hand[i][0];
		}
		total += hand[i][0];
	}
	if ((high - low == 4) && (total % 5 == 0)) {
		straight = true;
		return;
	}

	/* check for 4, 3, and pairs */
	// c1, c2, c3, c4, c5
	int rank[13] = {0};
	for (i = 0; i < NUM_CARDS; i++) {
		rank[hand[i][0]]++;
	}
	for (i = 0; i < 13; i++) {
		if (rank[i] == 4) four = true;
		if (rank[i] == 3) three = true;
		if (rank[i] == 2) pairs++;
	}
}

void print_result(void) {
	if (straight && flush) {
		printf("Straight flush");
	} else if (four) {
		printf("Four of a kind");
	} else if (three && pairs == 1) {
		printf("Full house");
	} else if (flush) {
		printf("Flush");
	} else if (straight) {
		printf("Straight");
	} else if (three) {
		printf("Three of a kind");
	} else if (pairs == 2) {
		printf("Two pairs");
	} else if (pairs == 1) {
		printf("Pair");
	} else {
		printf("High card");
	}
	printf("\n");
}
