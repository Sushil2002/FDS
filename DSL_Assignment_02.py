print("\n\nWrite a python program to compute following operation in string:")
print("a)to display word with the longest length")
print("b)to determine the frequency of occurrence of particular character in the string")
print("c)to check whether the string is palindrome or not")
print("d)to display index of first appearance of the substring")
print("e)to count the occurrence of each word in a given string\n")
def longest():  # to print longest length of word in given string
    str1 = input("Enetr the string : ")
    list = str1.split()
    print(list)
    n = 0  # n is the length of particular word after spliting.
    for i in range(len(list)):
        if n < len(list[i]):
            n = len(list[i])
    print("longest length word is : ", list[i])


def frequency():  # to calculate the single char how many times is present ,for that we need to
    # compare the char with given string(str1)
    str1 = input("Enter the string:")
    char = input("Enter the character to be count:")
    print("Given string:", str1)
    count = 0
    for i in range(len(str1)):
        if (
            char == str1[i]
        ):  # compare the char with each letter in str1(for identify the each letter)
            count = count + 1
    print(char, "is", count, "times present in given string.")


def palindrome():  # the revese word must be same eg. madam,dad
    str = input("Enter the word:")
    m = str[::-1]
    if str == m:
        print("It's a palindrome")
    else:
        print("It's not a palindrome")


def apperance():
    str1 = input("Enter the string:")
    sub_string = input("Enter the sub_string:")
    sublen = len(sub_string)
    index = 0  # index denotes the indexing of str1.
    j = 0  # j denotes the indexing of sub_string.
    for i in range(len(str1)):
        if sub_string[j] == str1[i]:
            j = j + 1
            if j == sublen:
                index = i - (sublen - 1)
                break
            else:
                j = 0
    print("sub_string index:", index)


def occurance():
    str1 = input("enetr the string:")
    str1 = str1.split()
    print(str1)
    i = 0
    while i < len(str1):
        count = 0
        for j in str1:
            if str1[i] == j:
                count = count + 1
        print(str1[i], count, "times")
    i = i + 1


while True:
    choice = int(input("Enter the choice:"))
    if choice == 1:
        longest()
    elif choice == 2:
        frequency()
    elif choice == 3:
        palindrome()
    elif choice == 4:
        apperance()
    elif choice == 5:
        occurance()
    else:
        break
    stop = input("would you like to continue(y/n):")
    if stop == "n":
        print("THANK YOU!!")
        break
