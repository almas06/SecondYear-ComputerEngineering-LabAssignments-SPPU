#Creating 2 sets using inbuilt set method
myset1 = set()
myset2 = set()

#*****************************************************************************************************************8
def AddElement():
    set_no = int(input("\nEnter set no. in which you want to insert(1/2): "))
    num = int(input("\nEnter number of elements you want to insert : "))
    if set_no==1:
        for i in range(num):
            element=int(input("Enter element :=> "))
            myset1.add(element)
    elif set_no == 2:
        for i in range(num):
            element=int(input("Enter element :=> "))
            myset2.add(element)

#*********************************************************************************************************************
def IfPresent(element):   #To check if element is present or not in one of the set
    if element in myset1 :
        return(2)
    elif element in myset2 :
        return(1)
    else:
        return(0)
#**********************************************************************************************************************
def RemoveElement():
    element=int(input("Enter element to remove :=> "))
    p = IfPresent(element)
    if p==2:
        myset1.remove(element)
        print("\nElement removed successfully from Set-1!!\n")
    elif p==1:
        myset2.remove(element)
        print("\nElement removed successfully from Set-2!!\n")
    else:
        print("\nElement not present\n")

#*************************************************************************************************************************
def SizeOfSet():
    print("\t1.Set-1")
    print("\t2.Set-2")
    c = int(input("Enter choice : "))
    if c==1:
        s = len(myset1)
        print("\nSize of Set-1 is ",s,"\n")
    elif c==2:
        s = len(myset2)
        print("\nSize of Set-2 is ",s,"\n")

#**********************************************************************************************************************
def Union():
    union_set = myset1.union(myset2)
    print("-----------------------------")
    print("Union of Set1 and Set2")
    print(union_set)
    print("-----------------------------")

#*********************************************************************************************************************8
def Intersection():
    intersect_set = myset1.intersection(myset2)
    print("-------------------------------")
    print("Intersection of Set1 and Set2")
    print(intersect_set)
    print("-------------------------------")

#******************************************************************************************************************
def Difference():
    diff_set = myset1.difference(myset2)
    print("-------------------------------")
    print("Difference of Set1 and Set2")
    print(diff_set)
    print("-------------------------------")

#********************************************************************************************************************
def Subset():
    sub1 = myset1.issubset(myset2)
    if sub1==True:
        print("\nSet1 is a subset of Set2")
    else:
        print("\nSet1 is not a subset of Set2")

    sub2 = myset1.issubset(myset2)
    if sub2==True:
        print("\nSet2 is a subset of Set1")
    else:
        print("\nSet2 is not a subset of Set1")
        
#*********************************************************************************************************************
def Display():
    itr1 = iter(myset1)  # Creating Iterators itr1 and itr2 for 
    itr2 = iter(myset2)  # set1 annd set2 respectively
    print("\n------------------------")
    print("Set-1")
    for itr1 in myset1:
        print("-> ",itr1)
    print("\nSet-2")
    for itr2 in myset2:
        print("-> ",itr2)
    print("------------------------")
    
#**********************************************************************************************************************
def main():
    print("-------------------------")
    print("  Group-A Assignment-4")
    print("-------------------------")
    while True :
        print("\t1.Add element")
        print("\t2.Display")
        print("\t3.Remove element")
        print("\t4.Size of set")
        print("\t5.Is element present")
        print("\t6.Intersection")
        print("\t7.Union")
        print("\t8.Difference")
        print("\t9.Subset")
        print("\t10.Exit")
        print("-------------------------")
        ch = int(input("Enter your choice : "))

        if ch==1:
            AddElement()
        elif ch==2:
            Display()
        elif ch==3:
            RemoveElement()
        elif ch==4:
            SizeOfSet()
        elif ch==5:
            ele = int(input("Enter the element you want to check : "))
            ans = IfPresent(ele)
            if ans==2:
                print("\nElement is present in Set1")
            elif ans==1:
                print("\nElement is present in Set2")
            else:
                print("\nElement is not present in either set")
        elif ch==6:
            Intersection()
        elif ch==7:
            Union()
        elif ch==8:
            Difference()
        elif ch==9:
            Subset()
        elif ch==10:
            quit()
        else:
            print("Enter a valid input!!")

main()
    
    
