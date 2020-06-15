#include <iostream>

using namespace std;

//FUNCTION TO MOVE THE DISKS FOR THE STATIC BOARD
void moveDisk(int rowOfDisk, int board[][3], int fromColumn, int toColumn, int rows)
{
    //Variable that holds the lowest number row in the target column
    int toLowestRow;
    
    //Selects the top disk of the ORIGIN column
    for (int i = rows - 1; i >= 0 && board[i][fromColumn] != 0; i--)
        rowOfDisk = i;
        
    //Searches for the lowest row in the 
    //target column (excludes last row in the array)
    for(int i = 0; i < rows - 1; ++i)
    {
        //Checks the row below for a DISK
        if(board[i + 1][toColumn] != 0)
        {
            //Updates the lowest row
            toLowestRow = i;
            break;    
        }
        
    }
    
    //Checks the last row if its the lowest row
    if(board[rows - 1][toColumn] == 0)
        toLowestRow = rows - 1;
        
    //Moves the disk from its spot to the new target spot
    board[toLowestRow][toColumn] = board[rowOfDisk][fromColumn];
    
    //Clears the old target
    board[rowOfDisk][fromColumn] = 0;
}


//FUNCTION TO MOVE THE DISKS FOR THE DYNAMIC BOARD
void moveDynamicDisk(int rowOfDisk, int **board, int fromColumn, int toColumn, int rows)
{
    //Variable that holds the lowest number row in the target column
    int toLowestRow;
    
    //Selects the top disk of the ORIGIN column
    for (int i = rows - 1; i >= 0 && board[i][fromColumn] != 0; i--)
        rowOfDisk = i;
        
    //Searches for the lowest row in the 
    //target column (excludes last row in the array)
    for(int i = 0; i < rows - 1; ++i)
    {
        //Checks the row below for a DISK
        if(board[i + 1][toColumn] != 0)
        {
            //Updates the lowest row
            toLowestRow = i;
            break;    
        }
        
    }
    
    //Checks the last row if its the lowest row
    if(board[rows - 1][toColumn] == 0)
        toLowestRow = rows - 1;
        
    //Moves the disk from its spot to the new target spot
    board[toLowestRow][toColumn] = board[rowOfDisk][fromColumn];
    
    //Clears the old target
    board[rowOfDisk][fromColumn] = 0;
}


//FUNCTION THAT CREATES A BOARD FOR DYNAMIC IMPLEMENTATION
int** createBoard(int numberOfDisks)
{
    //Initializes memeory for the 1st dimension of board
    int ** board = new int*[numberOfDisks];
    
    //Initializes memory for the 2nd dimension of board
    for(int i = 0; i < numberOfDisks; ++i) 
    {
        //There will always be 3 columns
        board[i] = new int[3];
    }
    
    //Goes through the rows
    for (int i = 0; i < numberOfDisks; i++)
    {
        //Puts disks in the first column
        board[i][0] = i + 1;
        
        //Makes everything else zero 
        //(columns past the first)
        for (int j = 1; j < 3; j++)
            board[i][j] = 0;
            
    }
    return board;
}

//FUNCTION TO DELETE THE DYNAMIC BOARD
void deleteArray(int** board, int rows)
{
    for(int i = 0; i < rows; ++i)
    {
        delete[] board[i];
    }
    delete[] board;
}

//FUNCTION TO PRINT THE BOARD FOR STATIC IMPLEMENTATION
void printBoard(int board[][3], int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < 3; j++)
            cout << board[i][j] << ' ';
            
        cout << endl;
    }
    
    cout << "- - -" << endl;
}

//FUNCTION TO PRINT THE BOARD FOR DYNAMIC IMPLEMENTATION
void printDynamicBoard(int **board, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < 3; j++)
            cout << board[i][j] << ' ';
            
        cout << endl;
    }
    
    cout << "- - -" << endl;
}

//TOWERS OF HANOI FUNCTION FOR THE STATIC IMPLEMENTATION
void towersStatic(int numberOfDisks, int board[][3], int fromColumn, int toColumn, int spareColumn, int rows)
{
    if(numberOfDisks >= 1)
    {
        towersStatic(numberOfDisks - 1, board, fromColumn, spareColumn, toColumn, rows);
        
        moveDisk(numberOfDisks - 1, board, fromColumn, toColumn, rows);
        printBoard(board, rows);
        
        towersStatic(numberOfDisks-1, board, spareColumn, toColumn, fromColumn, rows);
        
    }
}

//TOWERS OF HANOI FOR THE DYNAMIC IMPLEMENTATION
void towersDynamic(int numberOfDisks, int **board, int fromColumn, int toColumn, int spareColumn, int rows)
{
    if(numberOfDisks >= 1)
    {
        towersDynamic(numberOfDisks - 1, board, fromColumn, spareColumn, toColumn, rows);
        
        moveDynamicDisk(numberOfDisks - 1, board, fromColumn, toColumn, rows);
        printDynamicBoard(board, rows);
        
        towersDynamic(numberOfDisks-1, board, spareColumn, toColumn, fromColumn, rows);
        
    }
}

int main()
{
    //STATIC IMPLEMENTATION
    cout << "STATIC IMPLEMENTATION*****************************************************************" << endl;

    //Static 3x3 Board
    int staticBoard[3][3] = {{1,0,0},{2,0,0},{3,0,0}};
    
    //Shows the initial Board
    printBoard(staticBoard, 3);
    
    //Runs towers of hanoi function
    towersStatic(3, staticBoard, 0, 2, 1, 3);
    
    
    //DYNAMIC IMPLEMENTATION
    
    //This variable stores the # of disks in the 
    //tower when prompting the user for # of disks
    int numberOfDisks;
    
    cout << "DYNAMIC IMPLEMENTATION*****************************************************************" << endl;
    cout << "How many disks do you want? ";
    cin >> numberOfDisks;
    
    //Initialization of the dynamic board
    int **dynamicBoard = createBoard(numberOfDisks);
    
    printDynamicBoard(dynamicBoard, numberOfDisks);
    towersDynamic(numberOfDisks, dynamicBoard, 0, 2, 1, numberOfDisks);

    deleteArray(dynamicBoard, numberOfDisks);

    return 0;
}
