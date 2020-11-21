"""Write a Python program to compute following computation on matrix:
a) Addition of two matrices B) Subtraction of two matrices
c) Multiplication of two matrices d) Transpose of a matrix"""


def printMat(r,c,result):
    for i in range(r):
        for j in range(c):
            print(result[i][j], end =' ')
        print()

def inputMatrix1(r,c):
    mat1 = []
    print("\nEnter the elements for matrix1")
    for i in range(0,r):
        m1=[]
        for j in range(0,c):
            print("mat1[",i,"][",j,"]:",end="")
            m1.append(int(input()))
        mat1.append(m1)
    return mat1

def inputMatrix2(r,c):
    print("Enter the elements for matrix2")
    mat2 = []
    for i in range(0,r):
        m2=[]
        for j in range(0,c):
            print("mat2[",i,"][",j,"]:",end="")
            m2.append(int(input()))
        mat2.append(m2)

    return mat2

def Addition(r,c,mat1,mat2):
    mat1 = inputMatrix1(r,c)
    mat2 = inputMatrix2(r,c)
    result = []
    for i in range(r):
        ans=[]
        for j in range(c):
            ans.append(mat1[i][j] + mat2[i][j])
        result.append(ans)
    print("\n======Addition=====")
    printMat(r,c,result)

def Subtraction(r,c,mat1,mat2):
    mat1 = inputMatrix1(r,c)
    mat2 = inputMatrix2(r,c)
    result=[]
    for i in range(r):
        ans=[]
        for j in range(c):
            ans.append(mat1[i][j] - mat2[i][j])
        result.append(ans)

    print("\n======Subtraction=====")
    printMat(r,c,result)


def Multiplication(r,c,mat1,mat2):
    mat1 = inputMatrix1(r,c)
    mat2 = inputMatrix2(r,c)
    result=[[0 for _ in range(c)] for _ in range(r)]
    for i in range(r):
        for j in range(c):
            for k in range(c):
                result[i][j] +=  mat1[i][k]*mat2[k][j] 
        
    print("\n===Multiplication===")
    printMat(r,c,result)  

def Transpose(r,c,mat1):
    mat1 = inputMatrix1(r,c)
    result=[]
    for i in range(r):
        ans=[]
        for j in range(c):
            ans.append(mat1[j][i])
        result.append(ans)   
    print("\n====Transpose of Matrix====")
    printMat(r,c,result)

def main():
    print("\n**********PRACTICAL ASSIGNMENT-9*************\n")
    r = int(input("Enter no. of rows => "))
    c = int(input("Enter no. of columns  => "))
    mat1=[]
    mat2=[]
    while True:
        print(" \n    1.Addition\n    2.Subtraction")
        print("    3.Multiplication\n    4.Transpose\n    5.Exit")
        
        ch = int(input("Enter choice:"))
       
        if ch==1:
            Addition(r,c,mat1,mat2)
        elif ch==2:
            Subtraction(r,c,mat1,mat2)
        elif ch==3:
            Multiplication(r,c,mat1,mat2)
        elif ch==4:
            Transpose(r,c,mat1)
        elif ch==5:
            print("**********EXIT***********")
            quit()
        else:
            print("Wrong choice entered ! Try again")

main()
   
