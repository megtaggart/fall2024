#include <stdio.h>

void findCombinations(int score) {
    int td_6, td_7, td_8, fg, safety;
    
    // loop through all possible combinations 
    for (td_6 = 0; td_6 <= score / 6; td_6++) {
        for (td_7 = 0; td_7 <= score / 7; td_7++) {
            for (td_8 = 0; td_8 <= score / 8; td_8++) {
                for (fg = 0; fg <= score / 3; fg++) {
                    for (safety = 0; safety <= score / 2; safety++) {
                        // check if combination adds up to the target score
                        if (td_6 * 6 + td_7 * 7 + td_8 * 8 + fg * 3 + safety * 2 == score) {
                            printf("%d TD (6 pts), %d TD+1pt (7 pts), %d TD+2pt (8 pts), %d FG (3 pts), %d Safety (2 pts)\n",
                                   td_6, td_7, td_8, fg, safety);
                        }
                    }
                }
            }
        }
    }
}

int main() {
    int score;

    //continuing to ask for input
    while (1) {
        printf("Enter the NFL score (0 or 1 to STOP): ");
        scanf("%d", &score);
        
        // stop the program if 1 or 0 is input
        if (score <= 1) {
            printf("Exiting the program...\n");
            break;
        }

        // display possible combinations
        printf("Possible combinations of scoring plays for a team’s score is %d:\n", score);
        findCombinations(score);
    }

    return 0;
}
