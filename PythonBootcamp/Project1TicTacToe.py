# Initalize board

def InitBoard(boardSize):
    return ([' '] * boardSize)
    

# Board display
def DisplayBoard (board):
    print('   |   |')
    print(' ' + board[7] + ' | ' + board[8] + ' | ' + board[9])
    print('   |   |')
    print('-----------')
    print('   |   |')
    print(' ' + board[4] + ' | ' + board[5] + ' | ' + board[6])
    print('   |   |')
    print('-----------')
    print('   |   |')
    print(' ' + board[1] + ' | ' + board[2] + ' | ' + board[3])
    print('   |   |')

# Board for test
# testBoard = ['#', 'X', 'O', 'X', 'X', 'O', 'X', 'O', 'X', 'O']

# Test board display
# DisplayBoard(testBoard)

# Player input and assign their marker as 'X' or 'O
def PlayerInput ():
    marker = ''
    while not (marker == 'X' or marker == 'O'):
        marker = input('Put X or O: ').upper()
        
    if marker == 'X':
        return ('X', 'O')
    else:
        return ('O', 'X')
    
# Test player input
# print(PlayerInput())

# Place the marker
def PlaceMarker (board, marker, position):
    if position > 9:
        position = 9
    elif position < 1:
        position = 1
    else:
        pass
    
    board[position] = marker
    
# Test the marker place
# PlaceMarker(testBoard, '$', 8)
# DisplayBoard(testBoard)

# Checking who wins
def CheckWin (board, mark):
    return ((board[7] == mark and board[8] == mark and board[9] == mark) or  # Top
    (board[4] == mark and board[5] == mark and board[6] == mark) or         # Middle
    (board[1] == mark and board[2] == mark and board[3] == mark) or         # Bottom
    (board[1] == mark and board[4] == mark and board[7] == mark) or         # Left up
    (board[2] == mark and board[5] == mark and board[8] == mark) or         # Middle up
    (board[3] == mark and board[6] == mark and board[9] == mark) or         # Right up
    (board[1] == mark and board[5] == mark and board[9] == mark) or         # Diagonal
    (board[3] == mark and board[5] == mark and board[7] == mark))           # Diagonal

# Test who wins
'''
PlaceMarker(testBoard, 'X', 7)
print(CheckWin(testBoard, 'X'))
PlaceMarker(testBoard, 'O', 7)
PlaceMarker(testBoard, 'O', 8)
print(CheckWin(testBoard, 'O'))
DisplayBoard(testBoard)
'''

# Randomly choosing who starts
import random

def ChooseFirst ():
    if random.randint(0, 1) == 0:
        return 'Player 1'
    else:
        return 'Player 2'

# Checking board position is empty
def IsFreeSpace (board, position):
    return board[position] == ' '

# Is the board full?
def IsBoardFull (board):
    for i in range(1, len(board)):
        if IsFreeSpace(board, i):
            return False
    
    return True

# Position input from player
def PlayerChoice (board):
    position = 0
    
    while (position < 1 or position > 9) or not IsFreeSpace(board, position):
        position = int(input('Choose your next position (1-9): '))
        
    return position

# Replay game?
def Reply ():
    return input('Would you like to play new game? (Y / N) ').lower().startswith('y')

# === THE TIC-TAC-TOE GAME ===
while True:
    print('The Tic-Tac-Toe Game ')
    
    board = InitBoard(10)
    marker1, marker2 = PlayerInput()
    turn = ChooseFirst()
    print(turn + ' will start')
    
    PlayGame = input('Are you ready to play? (Y / N)').lower()
    if PlayGame[0] == 'y':
        GameOnFlag = True
    else:
        GameOnFlag = False
        
    while GameOnFlag:
        # Player 1 turn
        if turn == 'Player 1':
            marker = marker1
        # Player 2 turn
        else:
            marker = marker2
            
        DisplayBoard(board)
        position = PlayerChoice(board)
        PlaceMarker(board, marker, position)
        DisplayBoard(board)
        
        if CheckWin(board, marker):
            print('Congratulations, {} has won the game!' .format(turn))
            GameOnFlag = False
        else:
            if IsBoardFull(board):
                print('The game is a draw!')
                GameOnFlag = False
            else:
                # Change turn to the next player
                if turn == 'Player 1':
                    turn = 'Player 2'
                else:
                    turn = 'Player 1'     
    
    # Exiting or Reply the game
    if not Reply():
        break
        
    