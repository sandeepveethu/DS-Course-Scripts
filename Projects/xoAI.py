player = '' #x or o chosen by player
computer = '' #x or o decided by what the player chooses

player_move_seq = list()
comp_move_seq = list()


def print_board(a):
    for i in a:
        print i


def corner(move):
''' player plays on corner tile'''
    if(move==[0,0] or move==[2,0] or move==[0,2] or  move==[2,2]):
        return 1
    else:
        return 0


def center(move):
    if(move==[1,1]):
        return 1
    else :
        return 0

def middle(move):
    if(move==[0,1] or move==[1.0] or move==[1,2] or move==[2,1]):
        return  1
    else:
        return 0


def computer_move(a,move,count):
    priority_move(a,move,count)
    #for the first move, ignore the row and column containing the move
    if(count==1):
        if(corner(move)):
            a[abs(move-2)][abs(move-2)] = computer
        if(center(move)):
            a[0][0] = computer
        if(middle(move)):
            a[1][1] = computer #computer plays on center tile
        board(a)
        wincheck(a)
    if(count==2):













def main():
    a=[[' ',' ',' '],[' ',' ',' '],[' ',' ',' ']]
    print 'Welcome to Tic-Tac-Toe Game'
    print 'X or O ?'
    player = raw_input().lower()
    print 'so you have chosen %s'%player

    if(player=='x'):
        computer='o'
    else:
        computer='x'
    print '\nStarting Game'

    print_board(a)
    count=0
    while(1):
        print 'Enter your move (x,y) (without brackets and comma)'
        print 'Your move : ',
        move = raw_input().split()
        move[0] = int(move[0])
        move[1] = int(move[1])
        a[move[0]][move[1]] = player
        count++
        computer_move(a,move,count)














def wincheck(a):
    p=player
    c=computer
    for i in range(3):
        if(a[i]==[p,p,p]):
            print 'player wins'
            return
        else if(a[i]==[c,c,c]):
            print 'computer wins'
            return

    for i in range(3):
        for j in range(3) :
            if(a[i][j]==a[i+1][j]==a[i+2][j]==p):
                print 'player wins'
                return
            if(a[i][j]==a[i+1][j]==a[i+2][j]==c):
                print 'computer wins'
                return

    if(a[0][0]==a[1][1]==a[2][2]):
        if(a[0][0]==p):
            print 'player wins'
            return
        else if(a[0][0]==c):
            print 'computer wins'
            return

    if(a[0][2]==a[1][1]==a[2][0]):
        if(a[0][2]==p):
            print 'player wins'
            return
        else if(a[0][2]==c):
            print 'computer wins'
            return
