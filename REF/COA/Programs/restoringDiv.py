def restoreDiv(dividend, divisor):
    if dividend < 0 or divisor < 0:
        print("Restoring division algorithm does not work with negative numbers.")
        exit(1)
    if divisor == 0:
        print("Division with 0 not possible")
        exit(1)
    Q = decToBin(dividend)
    M = decToBin(divisor)
    n, M, Q = bits(M,Q)
    negM = twosComplement(M)
    A = '0' * n

    print("A\t\tQ\t\tM\t\tn")
    print("\t\t{0}\t\t{1}\t\t".format(dividend, divisor))
    print("-----------------------------------------------------------------------------")
    print("{0}\t\t{1}\t\t{2}\t\t{3}".format(A, Q, M, n))
    print("-----------------------------------------------------------------------------")

    while n != 0:
        A, Q = als(A, Q)
        print("{0}\t\t{1}\t\t{2}\t\t\t\tLeft Shift".format(A, Q, M))
        A = binAdd(A, negM)
        print("{0}\t\t{1}\t\t{2}\t\t\t\tA <- A - M".format(A, Q, M))
        if A[0] == '1':
            Q = Q.replace('x', '0')
            print("{0}\t\t{1}\t\t{2}\t\t\t\t".format(A, Q, M))
            A = binAdd(A, M)
            print("{0}\t\t{1}\t\t{2}\t\t{3}\t\tA <- A + M".format(A, Q, M, n-1))
        elif A[0] == '0':
            Q = Q.replace('x', '1')
            print("{0}\t\t{1}\t\t{2}\t\t{3}\t\t".format(A, Q, M, n-1))
        #print(A, Q)
        print("-----------------------------------------------------------------------------")
        n -= 1
    
    print("Quotient = ", Q, "\tRemainder = ", A, "\tBINARY", sep = "")
    Q = binToDec(Q)
    A = binToDec(A)
    return Q, A

def decToBin(num):
    binary = ""
    while num >= 1:
        quo, rem = num // 2, num % 2
        binary += str(rem)
        num = quo
    binary = binary[::-1]
    #print(binary, 'dectobin')
    return binary

def binToDec(num):
    if num.startswith('1'):
        num = twosComplement(num)
        return -int(num, 2)
    else:
        return int(num, 2)

def twosComplement(bin_num):
    bin_num = bin_num.replace('0','x')
    bin_num = bin_num.replace('1','0')
    bin_num = bin_num.replace('x','1')
    length = len(bin_num)
    bin_num = binAdd(bin_num, '0'*(length-1)+'1')
    #print(bin_num,'bin_num')
    return bin_num

def binAdd(num1, num2):
    #print(num1, num2)
    carry = '0'
    addition = ""
    i = -1
    while i != -len(num1)-1:
        if carry + num1[i] + num2[i] in ['000']:
            carry = '0'
            addition += '0'
        elif carry + num1[i] + num2[i] in ['001', '010', '100']:
            carry = '0'
            addition += '1'
        elif carry + num1[i] + num2[i] in ['110', '101', '011']:
            carry = '1'
            addition += '0'
        elif carry + num1[i] + num2[i] in ['111']:
            carry = '1'
            addition += '1'
        i -= 1
    addition = addition[::-1]
    #print(addition, 'addition')
    return addition

def als(A, Q):
    #print(A, Q, 'als before')
    A = A[1:] + Q[0]
    Q = Q[1:] + 'x'
    #print(A, Q, 'als after')
    return A, Q

def bits(str1, str2):
    lstr1 = len(str1)
    lstr2 = len(str2)
    if lstr1 < lstr2:
        while lstr1 < lstr2:
            str1 = '0' + str1
            lstr1 += 1
    elif lstr2 < lstr1:
        while lstr2 < lstr1:
            str2 = '0' + str2
            lstr2 += 1
    if str1[0] == '1' or str2[0] == '1':
        str1 = '0' + str1
        str2 = '0' + str2
    #print(str1, str2, 'bits')
    return len(str1), str1, str2

num1 = int(input("Enter dividend: "))
num2 = int(input("Enter divisor: "))
quo, rem = restoreDiv(num1, num2)
print("Quotient = ", quo, "\t\tRemainder = ", rem, "\t\tDECIMAL", sep = "")
