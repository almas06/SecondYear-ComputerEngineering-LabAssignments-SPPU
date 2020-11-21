"""a) Write a Python program to store roll numbers of student in array who attended
training program in random order. Write function for searching whether particular
student attended training program or not, using Linear search and Sentinel search."""


def GetRollNumbers(rollnum,num):
    print("\nEnter roll num of students who attended training program")
    for i in range(0,num):
        print(i+1,") ",end="")
        r = input()
        rollnum.append(r)

def LinearSearch(rollnum,num):
    searchEle = int(input("Enter the rollno you want to search :=> "))
    for i in range(0,num):
        if int(rollnum[i]) == searchEle:
            print(searchEle,"rollno is present at index ",i)


def SentinelSearch(rollnum,num):
    searchEle = int(input("Enter the rollno you want to search :=> "))

    i = 0 
    rollnum.append(searchEle)    
    while int(rollnum[i]) != searchEle:
        i+=1 
    
    rollnum.pop(searchEle) 
    if (i < num - 1) or (searchEle == int(rollnum[num - 1])):
        print(searchEle,"rollno is present at index ", i)
    else:
        print("\nNot present !!")
         
        

def main():
    print("\nGroup-B Assignment-1\n")
    num = int(input("Enter Number of Students in SE COMP2 :"))
    rollnum = []
    GetRollNumbers(rollnum,num)
    
    while True:
        print("\nSearch roll no by - ")
        print("\t1.Linear Search")
        print("\t2.Sentinel Search")
        print("\t3.Exit")
        ch = int(input("Enter choice :=>"))
        
        if ch==1:
            LinearSearch(rollnum,num)
        elif ch==2:
            SentinelSearch(rollnum, num)
        elif ch==3:
            quit()
        else:
            print("\nWrong choice entered !! Try again")

main()
