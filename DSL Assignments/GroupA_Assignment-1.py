
def removeDuplicates(arr):
    n = len(arr)
    for i in range(n-1):
        for j in range(i+1,n-1):
            if arr[i] == arr[j]:
                arr.remove(arr[i])
    return arr


def accept(game):
    n = int(input("Enter the number of student who play %s: "%game))
    print("Enter the roll no. of student who plays %s "%game)
    gameArr = []
    for i in range(n):
        gameArr.append(int(input("Roll no. :")))
    return gameArr

def playBothTwoGames(cricket, badminton):
    roll = []
    for i in cricket:
        for k in badminton:
            if i == k:
                roll.append(i)
                break
    return roll

def crickOrBad(cricket, badminton):
    arr = playBothTwoGames(cricket, badminton)
    roll = cricket + badminton
    for i in arr:
        for j in roll:
            if i == j:            #if the student plays badminton, it should not be in the ans
                roll.remove(i)
    return roll
    
def crickNorBad(cricket, badminton, football):
    arr = crickOrBad(cricket, badminton)
    roll = []
    for i in football:
        onlyFootball = True
        for j in arr:
            if i == j:
                onlyFootball = False
                break
        if onlyFootball:
            roll.append(i)
    return  roll 
                
def crickAndFootNotBad(cricket, badminton, football):
    arr = playBothTwoGames(cricket, football) 
    roll = []
    for i in arr:
        onlyCricFoot = True
        for j in badminton:
            if i==j:                   #if the student plays badminton, it should not be in the ans
                onlyCricFoot = False
                break
        if onlyCricFoot:
            roll.append(i)
    return roll

                
def main():
    cricket = removeDuplicates(accept('Cricket'))
    football = removeDuplicates(accept('Football'))
    badminton = removeDuplicates(accept('Badminton'))
    print("******************************************************************************")
    print("Enter 1 to get list of students who play both cricket and badminton")
    print("Enter 2 to get list of students who play either cricket or badminton but not both")
    print("Enter 3 to get list of students who play neither cricket nor badminton")
    print("Enter 4 to get list of students who play cricket and football and not badminton")
    print("Enter 5 to Exit")
    print("******************************************************************************")
    
    while True:
        ch = int(input("Enter your choice: "))
        if ch==1:
            print("Students that play cricket and badminton:",playBothTwoGames(cricket, badminton))
            print("******************************************************************************")
        elif ch==2:
            print("Students that play cricket or badminton but not both:",crickOrBad(cricket, badminton))
            print("******************************************************************************")
        elif ch==3:
            print("Students who play neither cricket nor badminton:",crickNorBad(cricket, badminton, football))
            print("******************************************************************************")
        elif ch==4:
            print("Students who play cricket and football and not badminton:",crickAndFootNotBad(cricket, badminton, football))
            print("******************************************************************************")        
        elif ch==5:
            print("*****************************")
            print("Program Terminated")
            exit()
        else:
            print("Invalid Input!!")
            menu()
        
main()
