//  main.cpp
//  Tic-Tac-Toe
//  Created by Katherine Castro on 2/4/21.
//

#include <iostream>
#include <vector>


class Game
{
    static const int ROWS= 7;
    static const int COLUMNS=14;
    char newArray[ROWS][COLUMNS];
    int selection;                  //menu selection
    int player;                     //stores 1st or 2nd player selection
    std::string playerName;         //name of player
    int count;                      //counts wrong selections
    
    std::vector<std::string> computerOptions = {"A1", "A2", "A3", "B1", "B2", "B3", "C1", "C2", "C3", " "};
    std::vector<std::string> possMoves= {"A1", "A2", "A3", "B1", "B2", "B3", "C1", "C2", "C3"};


public:
    //Class Functions
    void learn();
    void endGame();
    void declareWinner();
    void catGame();
    
    //Displays welcome screen title
    void welcome()
    {
        std::cout << "***********************************" << std::endl;
        std::cout << "           TIC-TAC-TOE             " << std::endl;
        std::cout << "***********************************" << std::endl;

    }
    
    //Generates and displays the playing area grid
    void generateGrid(int x, int y, char symbol, int t)
    {
        
        
        char array[ROWS][COLUMNS]= {{' ',' ',' ',' ','1',' ',' ',' ','2',' ',' ',' ','3',' '},
                                    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                                    {'A',' ',' ',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' '},
                                    {' ',' ',' ','-','-','-','+','-','-','-','+','-','-','-'},
                                    {'B',' ',' ',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' '},
                                    {' ',' ',' ','-','-','-','+','-','-','-','+','-','-','-'},
                                    {'C',' ',' ',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' '}};
        
        //assigns elements of array to newArray
        if(t == 1)
        {
            
            for(int row = 0; row < ROWS; row++)
            {
                for(int col = 0; col < COLUMNS; col++)
                {
                    newArray[row][col] = array[row][col];
                }
                
            }
        }
        
        newArray[x][y]=symbol;  //copies symbol in grid position of new move into newArray
        
        
        //Displays playing grid
        for(int row = 0; row < ROWS; row++)
        {
            std::cout << "        ";
            for(int col = 0; col < COLUMNS; col++)
            {
                std::cout << newArray[row][col];
            }
            std::cout << std::endl;
        }
        
        
       if(t > 2)
       {
        checkWinner(symbol, t);          //calls function to check if there has been a winner
       }
    }

    //Compares grid positions with player symbol after every turn
    //to check if they have three of their symbols in a row to win
    void checkWinner(char sym, int turns)
    {
        char pos1 = newArray[2][4],     //A1
             pos2 = newArray[2][8],     //A2
             pos3 = newArray[2][12],    //A3
             pos4 = newArray[4][4],     //B1
             pos5 = newArray[4][8],     //B2
             pos6 = newArray[4][12],    //B3
             pos7 = newArray[6][4],     //C1
             pos8 = newArray[6][8],     //C2
             pos9 = newArray[6][12];    //C3
        
        
        //A1, A2, A3
        if(pos1== sym && pos2 == sym && pos3 == sym)
        {
            declareWinner();
        }
        
        //B1, B2, B3
        if(pos4== sym && pos5 == sym && pos6 == sym)
        {
            declareWinner();
        }
        
        //C1, C2, C3
        if(pos7== sym && pos8 == sym && pos9 == sym)
        {
            declareWinner();
        }
        
        //A1, B1, C1
        if(pos1 == sym && pos4 == sym && pos7 == sym)
        {
            declareWinner();
        }
        
        //A2, B2, C2
        if(pos2 == sym && pos5 == sym && pos8 == sym)
        {
            declareWinner();
        }
        
        //A3, B3, C3
        if(pos1 == sym && pos6 == sym && pos9 == sym)
        {
            declareWinner();
        }
        
        //A1, B2, C3
        if(pos1 == sym && pos5 == sym && pos9 == sym)
        {
            declareWinner();
        }
        
        //A3, B2, C1
        if(pos3 == sym && pos5 == sym && pos7 == sym)
        {
            declareWinner();
        }
        
        //turn 9 has been played and no winners have been declared
        if(turns > 10)
        {
            catGame();
        }
        
        
    }
    
    //Displays menu and prompts selection of menu options
    void menu()
    {
        bool valid;     //for switch statement in case of invalid selection
        
        std::cout << std::endl;
        std::cout << "     =======================     " << std::endl;
        std::cout << "               MENU             " << std::endl;
        std::cout << "     =======================     " << std::endl;
        std::cout << "       1. Play" << std::endl;
        std::cout << "       2. How to play" << std::endl;
        std::cout << "       3. Quit"<< std::endl<< std::endl;
        std::cout << "      Make a selection: ";
        std::cin >> selection;
        
        
        do{
            switch(selection)
            {
                case 1 :
                    valid = true;
                    std::cout << "Enter a user name: ";
                    std::cin >> playerName;
                    

                    do
                    {
                        std::cout << "Enter a 1 for first player or a 2 for second player: ";
                        std::cin >> player;
                        
                        count++;
                        
                        //
                        if(count == 5)
                        {
                            std::cout << "Sorry, you have exceeded the number of incorrect selections." << std::endl;
                            endGame();
                        }
                    }while(player != 1 && player != 2);
                    
                    play(playerName, player);
                    break;
                    
                case 2 :
                    valid = true;
                    learn();
                    break;
                    
                case 3 :
                    valid = true;
                    endGame();
                    break;
                    
                default:
                    valid = false;
                    std::cout  << "\n*Invalid selection. Please try again.*\n";
                    menu();
            }
        }while(valid == false);
        
    }
    
    
    
    //Gameplay
    int play(std::string userName, int player)
    {
        static const int MAX_MOVES = 10;
        int score;                  //For score at the end of game
        std::string move;           //assigned grid location of chosen move
        bool taken;                 //for taken moves
        bool found = false;         //flag to indicate if the value was found
        int index = 0;              //subscript to search the array
        int position = -1;          //To record the position of the search value
        int r, c;                   //array[] rows and columns
        int n = 1;                  //number of moves taken
        static char cross = 'X';    //For first player
        static char nought = 'O';   //For second player
        char playerSymbol;          //either an X or an O
        int computer;
        int human;
        int turn = 1;                //keeps track of number of turns in a game
        int randomNumber;
        
                
        
        human = player;             //assigns human player a 1 or a 2
        
        //Assigns first and second player to AI or human
        if(human==1)
        {
            computer = 2;
        }
        else if(human == 2)
        {
            computer = 1;
            player = 1;
        }
        
        
        //Loops for no longer than the total amount of moves in a game (9)
        while(n < MAX_MOVES)
        {
            std::cout << "\n***Turn " << turn << "***" << std::endl;
            
            
            //Decide who's turn it is and assigns an X or O to players
            if(player == 1)
            {
                playerSymbol = cross;
                
            }
            else if(player == 2)        //player 2 makes a move
            {
                playerSymbol = nought;
            }
            
            
            //human player
            if(human == player)
            {
                std::cout << "Player " << player << " move: ";
                std::cin >> move;
                
               
            }
            
            
            //computer player
            if(computer == player)
            {
                    randomNumber = (rand() % (computerOptions.size() - 2));
                //std::cout << "Size of randomNumber is " << computerOptions.size() -2 << std::endl;
                //std::cout << "RandomNumber is " << randomNumber << std::endl;
                    move = computerOptions[randomNumber];
                std::cout << "Player " << player << " move: " << move << std::endl;
            }
        
    
            
            //Search algorithm for move in the vector
            while(index < computerOptions.size() && !found)
            {
                if(computerOptions[index] == move)
                {
                    found = true;       //set the flag
                    position = index;   //record the value's subscript
                    
                    
                }
                index++;                //go to next element
            }
            
            index = 0;      //resets index to 0
            found = false;  //resets found condition to false
            
            
            //match move with grid position
            for(int i = 0; i < possMoves.size(); i++)
            {
                if(computerOptions[position] == possMoves[i])
                {
                    switch(i)
                    {
                        case 0:
                            r = 2; c = 4;
                            break;
                        case 1:
                            r = 2; c = 8;
                            break;
                        case 2:
                            r = 2; c = 12;
                            break;
                        case 3:
                            r = 4; c = 4;
                            break;
                        case 4:
                            r = 4; c = 8;
                            break;
                        case 5:
                            r = 4; c = 12;
                            break;
                        case 6:
                            r = 6; c = 4;
                            break;
                        case 7:
                            r = 6; c = 8;
                            break;
                        case 8:
                            r = 6; c = 12;
                            break;
                        default:
                            break;
                    }
                }

                //std::cout << r << ", " << c << std:: endl;
            }
            
            
            generateGrid(r,c, playerSymbol, turn);

            
            //deletes the element of corresponding to the position played in current turn
            computerOptions.erase(computerOptions.begin() + position);
            
            
            
            //switch players
            if(player == 1)
            {
                player = 2;
            }
            else
            {
                player = 1;
            }
            
            turn++;
            n++;
           
        }

        return score;
    }
    
    
};


//Instructions for the game
void Game::learn()
{
    char answer;        //stores answer to exit question

    
    std::cout << "===============\n";
    std::cout << "     Rules\n";
    std::cout << "===============\n";
    std::cout << "Get three of the same symbols in a row vertically, horizontally, or across on the 3x3 grid.\n";
    std::cout << "First player gets Xs and second player gets Os.\n";
    std::cout << "You can play as first or second player.\n";
    std::cout << "Each grid location has a row letter (A, B, or C) and a column number (1, 2, or 3) assigned to it.\n";
    std::cout << "To enter a move, type the row letter and column number together as follows:\n";
    std::cout << "A1, A2, A3, B1, B2, B3, C1, C2, C3\n";
    std::cout << "Then, press the Enter key!\n";
    std::cout << "Whoever gets three of their symbols in a row wins!\n";
    
    
    std::cout << "Return to menu? (Y/N) ";
    std::cin >> answer;
    
    if(answer == 'y' || answer == 'Y')
    {
        menu();
    }
    else{
        learn();
    }
}

//Declares winner with a print statement, then terminates game
void Game::declareWinner()
{
    std::cout << "\n***Player " << player << " is the winner!***" << std::endl;
    endGame();
}

//Declares game a "Cat Game"
void Game::catGame()
{
    std::cout << "\n***Cat game!***\n";
}

//Quits Game
void Game::endGame()
{
    std::cout << "Thanks for playing. Goodbye!\n";
    exit(EXIT_SUCCESS);
}

int main(int argc, const char * argv[])
{

    Game title, men;
    title.welcome();
    men.menu();
    
    
    return 0;
}
