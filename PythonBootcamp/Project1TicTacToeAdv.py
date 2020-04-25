# Importing packages
import random
import os

# Clearing console command on Windows
ClearConsole = lambda: os.system('cls')

# Initialize board
def InitBoard (length, marker):
    return ( [marker] * (length + 1) )

# Global variables
boardSize = 5
winMarkNum = 3
boardLength = boardSize ** 2
gameBoard = InitBoard(boardLength, ' ')
gameStateFlag = True
announce = ''

# Resetting game board
def ResetGameBoard ():
    global gameBoard, boardLength, gameStateFlag
    
    gameBoard = InitBoard(boardLength, ' ')
    gameStateFlag = True

# Format single row of board
def FormatBoardRow (board, boardRow):
    rowMin = 1 + (boardRow - 1) * boardSize
    rowMax = rowMin + boardSize - 1
    strRow = ' '
    for i in range(rowMin, rowMax):
        strRow += board[i] + ' | '
    
    strRow += board[rowMax]
    
    return strRow    
    
# Display the board
def DisplayBoard ():
    global gameBoard, boardSize
    
    rowDelimiterStr = '----' * boardSize
    
    for i in range(boardSize, 0, -1):
        print(FormatBoardRow(gameBoard, i))
        if i > 1:
            print(rowDelimiterStr)
        
def InsertBoard (board, marker, position):
    if position < 1:
        position = 1
    elif position > len(board):
        position = len(board)
    else:
        pass
    
    board[position] = marker

def CheckWinRowCol (board, indexList, marker, winTarget, diff):
    j = len(indexList)
    while j > 0:
        winCount = 0
        
        for i in indexList:
            if board[i] == marker:
                winCount += 1
                if winCount == winTarget: return True                   # Player has won
            else:
                winCount = 0
        
        indexList = list(map(lambda x: x + diff, indexList))
        j -= 1
    
    return False

def CheckWinDiagonals (board, indexList, marker, winTarget, diff):  
    while len(indexList) >= winTarget:
        winCount = 0
        
        for i in indexList:
            if board[i] == marker:
                winCount += 1
                if winCount == winTarget: return True           # Player has won
            else:
                winCount = 0

        indexList.pop()                                         # Remove last element from the list
        indexList = list(map(lambda x: x + diff, indexList))    # Increment list
    
    return False

def CheckWin (board, boardSize, boardLength, marker):  
    # Check horizontal
    indexList = list(range(1, boardSize + 1))
    if CheckWinRowCol(board, indexList, marker, winMarkNum, boardSize): return True
    
    # Check vertical
    indexList = list(range(1, boardLength - boardSize + 2, boardSize))
    if CheckWinRowCol(board, indexList, marker, winMarkNum, 1): return True
     
    # Check main diagonals     
    indexList = list(range(1, boardLength + 1, boardSize + 1))
    if CheckWinDiagonals(board, indexList, marker, winMarkNum, 1): return True
    indexList = list(range(boardSize + 1, boardLength, boardSize + 1))
    if CheckWinDiagonals(board, indexList, marker, winMarkNum, boardSize): return True
    
    # Check side diagonals
    indexList = list(range(boardSize, boardLength - boardSize + 2, boardSize - 1))
    if CheckWinDiagonals(board, indexList, marker, winMarkNum, -1): return True
    indexList = list(range(boardSize * 2, boardLength - boardSize + 3, boardSize - 1))
    if CheckWinDiagonals(board, indexList, marker, winMarkNum, boardSize): return True

    return False

# Checking board position is empty
def IsFreeSpace (board, position):
    return board[position] == ' '

# Is the board full?
def IsBoardFull (board):
    if ' ' in board[1:]:
        return False

    return True

# Player input marker and validation
def AskPlayer (board, marker):
    req = 'Choose where to place your ' + marker + ': '
    global boardLength
    
    while True:
        try:
            choice = int(input(req))
            # Protect input from out of range
            if choice < 1: choice = 1
            elif choice > boardLength: choice = boardLength
            else: pass
        except ValueError:
            print('Choose input between 1 - {}' .format(boardLength))
            continue
        
        if IsFreeSpace(board, choice):
            InsertBoard(board, marker, choice)
            break
        else:
            print('The cell is not empty!')
            continue
  

def PlayerChoice (marker):
    global gameBoard, gameStateFlag, announce
    announce = ''
    
    mark = str(marker)
    AskPlayer(gameBoard, mark)
    
    if CheckWin(gameBoard, boardSize, boardLength, mark):
        ClearConsole()
        DisplayBoard()
        announce = mark + " wins!"
        gameStateFlag = False
    else:
        # Display the board
        ClearConsole()
        DisplayBoard()
        
        # Checking for draw
        if IsBoardFull(gameBoard):
            announce = "Draw!"
    
    return gameStateFlag, announce

def PlayGame ():
    ResetGameBoard()
    
    global gameStateFlag, announce
    
    # Set marks
    X = 'X'
    O = 'O'
    
    while True:
        ClearConsole()
        DisplayBoard()
        
        # Player X turn
        gameStateFlag, announce = PlayerChoice(X)
        print(announce)
        if gameStateFlag == False:
            break
        
         # Player O turn
        gameStateFlag, announce = PlayerChoice(O)
        print(announce)
        if gameStateFlag == False:
            break
    
    # Ask player for rematch
    rematch = input('Would you like to play again? Y / N: ').lower()
    
    if rematch[0] == 'y':
        PlayGame()
    else:
        print('Game Over!')
        
PlayGame()
        
        
        


    
