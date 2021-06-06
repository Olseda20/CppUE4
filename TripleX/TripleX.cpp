//adding library (#include is a preprocessor directive) (library is iostream <- this is a headerfile)
#include <iostream>
#include <ctime>


int CodeGen(int Difficulty)
{
    return (Difficulty + (rand() % Difficulty)) ;
} 
bool PlayGame(int Difficulty)
{
    /* Setup section to generate the code for the challenge*/
    //declaration statements
    // int Diff = 3 + Difficulty;
    const int CodeA = CodeGen(Difficulty) , CodeB = CodeGen(Difficulty) , CodeC = CodeGen(Difficulty);
    
    // finding the sum and product of the input values
    int CodeSum = CodeA + CodeB + CodeC;
    int CodeProduct = CodeA * CodeB * CodeC;

    //expression statements
    /*  (std) is a namespace
        (::) is the scope operator
        (cout) is the function within the namespace*/
    std::cout << "- Guess the correct code to be not noob:";
    std::cout << "\n- The sum of the code is: " << CodeSum;
    std::cout << "\n- The product of the code is: " << CodeProduct << std::endl;

    /* Grabbing user guess and letting them know the information of the guess*/
    int GuessA, GuessB, GuessC;
    std::cout << std::endl;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    /* Comparing the user guess to the Code input*/
    if (CodeSum == GuessSum && CodeProduct == GuessProduct)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

void PrintLevel(int Difficulty)
{
    std::cout << "You are currently on level: " << Difficulty << std::endl << std::endl; 
}

//main needed to run the code
int main()
{
    const int MaxDifficulty = 4;
    int LevelDifficulty = 1;
    srand(time(NULL));

    std::cout << "You are noob, to not be noob, pls win game below\n" << std::endl;    

    while (LevelDifficulty <= MaxDifficulty)
    {
        PrintLevel(LevelDifficulty);
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); //clears errors
        std::cin.ignore(); //dicards remaining buffer

        if (bLevelComplete)
            {
                if (LevelDifficulty == MaxDifficulty)
                {
                    std::cout << "damn, nvm actually, apparently you're pro\n\n";
                    return 0;
                }
                else
                {
                    std::cout << "nice but you are still kinda a noob\n\n";
                    ++LevelDifficulty;
                }
            }
        else 
            {
                std::cout << "hah, you suck\n\n";
                return 0;
            }
    }

    return 0;
} 