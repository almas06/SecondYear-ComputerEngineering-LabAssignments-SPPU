"""Write a Python program to store first year percentage of students in array. Write
function for sorting array of floating point numbers in ascending order using
a) Selection Sort
b) Bubble sort and display top five scores."""




def getPercentage(n,percent_arr):
    for i in range(0,n):
        print("Enter the percentage of roll no",i+1,":",end="")
        p = input()
        percent_arr.append(p)

def printarray(n,arr):
    print("Percentage list of F.E")
    for p in arr:
        print(p)
        

def BubbleSort(n,percent_arr):
    for i in range(0,n-1):
        for j in range(0,n-1-i):
            if percent_arr[j] > percent_arr[j+1] : 
                percent_arr[j], percent_arr[j+1] = percent_arr[j+1], percent_arr[j] 
    printarray(n,percent_arr)

def SelectionSort(n,percent_arr):
    for i in range(0,n-1):
        min = i
        for j in range(i+1,n):
            if percent_arr[j] < percent_arr[min]:
                min = j
        percent_arr[min], percent_arr[i] = percent_arr[i], percent_arr[min] 

    printarray(n,percent_arr)

def main():
    percent_arr = []

    print("--------------------------")
    print(" Group B - Assignment 14")
    print("--------------------------")
    print("\nNote : Enter F.E Percentage\n")

    n = int(input("Enter number of students :=> "))

    getPercentage(n,percent_arr)
    
    while True:
        print("\n\nSort by -" )
        print("\t1.Bubble sort")
        print("\t2.Selection sort")
        print("\t3.Exit")
        ch = int(input("Enter choice :"))

        if ch==1:
            BubbleSort(n,percent_arr)
        elif ch==2:
            SelectionSort(n,percent_arr)
        elif ch==3:
            quit()
        else:
            print("Wrong choice entered ! Try again")

main()
    
