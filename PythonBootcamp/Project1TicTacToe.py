
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
    
# Test board display
testBoard = ['#', 'X', 'O', 'X', 'X', 'O', 'X', 'O', 'X', 'O']
DisplayBoard(testBoard)

# Take in a player input and assign their marker as 'X' or 'O
def PayerInput ():
    marker = ''
    while not (marker == 'X' or marker == 'O'):
        marker = input('Put X or O').upper()