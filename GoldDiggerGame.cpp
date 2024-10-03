#include <iostream>
#include <random>

using namespace std;

int main()
{
    int n = 0;
    cout << "Enter Grid Size: ";
    cin >> n;

    int grid[n][n];

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 1);  // For 0 and 1

    // Fill grid with random 0s and 1s
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            grid[i][j] = dis(gen);  // Randomly assign 0 or 1
        }
    }






    cout << "\n\n************************* Let's Play The Game *************************\n\n\n";

    // Initialize mat_ch to store '*' for unrevealed cells
    char mat_ch[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mat_ch[i][j] = '*';  // Set all cells to '*'
        }
    }




    int reward = 0;
    int row, col = 0;




    // Game continues until reward exceeds certain limit
    do {
        
        // Display current state of the game board
        cout << "\nCurrent Board:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << mat_ch[i][j] << " ";
            }
            cout << endl;
        }

        // Take user input for row and column
        cout << "\nEnter the row & column number: ";
        cin >> row >> col;
        cout << endl << endl;

        // Check if the input is within valid bounds
        if (row > 0 && row <= n && col > 0 && col <= n) {
            // Adjust for 0-based indexing
            row--;
            col--;

            // If gold (1) is found
            if (grid[row][col] == 1) {
                reward += (n / 2);  // Increase reward
                cout << "You Found Gold! Yayyy ----> (reward = " << reward << ")\n";
                cout<< "Reward left to Win = "<<((n*n)-reward);
                mat_ch[row][col] = '1';  // Reveal gold in mat_ch
            }
            // If bomb (0) is found
            else {
                reward -= ((n / 2));  // Decrease reward
                cout << "Oops...You Found Bomb! ----> (reward = " << reward << ")\n";
                cout<< "Reward left to Win = "<<((n*n)-reward);
                mat_ch[row][col] = '0';  // Reveal bomb in mat_ch
            }
        } else {
            cout << "Invalid input! Please enter valid row and column numbers within range.\n";
        }
        
        
    } while (reward < (n * n) && reward > -(n * n));  // Game continues until reward exceeds the board size






    // Final board after game ends
    cout << "\n\nFinal Board:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << mat_ch[i][j] << " ";
        }
        cout << endl;
    }

    if (reward >= (n * n)) {
        cout << "\nCongratulations! You won the game with a reward of " << reward << "!\n";
    } else {
        cout << "\nGame Over! You lost with a reward of " << reward << ".\n";
    }

    return 0;
}

