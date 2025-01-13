def booth(mcand, mplier):
    M = decToBin(abs(mcand))
    Q = decToBin(abs(mplier))
    Q_1 = '0'
    n, M, Q = bits(M, Q)
    if mcand < 0:
        M = twosComplement(M)
    if mplier < 0:
        Q = twosComplement(Q)
    negM = twosComplement(M)
    A = '0' * n

    print("A\t\tQ\t\tQ-1\t\tM\t\tn")
    print("\t\t{0}\t\t\t\t{1}\t\t".format(mplier, mcand))
    print("--------------------------------------------------------------------------------")
    print("{0}\t\t{1}\t\t{2}\t\t{3}\t\t{4}".format(A, Q, Q_1, M, n))
    print("--------------------------------------------------------------------------------")    

    while n != 0:
        if Q[-1] + Q_1 in ['00', '11']:
            A, Q, Q_1 = ars(A, Q, Q_1)
            print("{0}\t\t{1}\t\t{2}\t\t{3}\t\t{4}  Shift".format(A, Q, Q_1, M, n-1))
        elif Q[-1] + Q_1 in ['01']:
            A = binAdd(A, M)
            print("{0}\t\t{1}\t\t{2}\t\t{3}\t\t   A <- A + M".format(A, Q, Q_1, M))
            A, Q, Q_1 = ars(A, Q, Q_1)
            print("{0}\t\t{1}\t\t{2}\t\t{3}\t\t{4}  Shift".format(A, Q, Q_1, M, n-1))
        elif Q[-1] + Q_1 in ['10']:
            A = binAdd(A, negM)
            print("{0}\t\t{1}\t\t{2}\t\t{3}\t\t   A <- A - M".format(A, Q, Q_1, M))
            A, Q, Q_1 = ars(A, Q, Q_1)
            print("{0}\t\t{1}\t\t{2}\t\t{3}\t\t{4}  Shift".format(A, Q, Q_1, M, n-1))
        print("--------------------------------------------------------------------------------")
        n -= 1
    print(A + Q,'product in binary')
    return binToDec(A + Q)

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

def ars(A, Q, Q_1):
    #print(A, Q, Q_1, 'ars before')
    Q_1 = Q[-1]
    Q = A[-1] + Q[:-1]
    A = A[0] + A[:-1]
    #print(A, Q, Q_1, 'ars after')
    return A, Q, Q_1

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

num1 = int(input("Enter multiplicand: "))
num2 = int(input("Enter multiplier: "))
print(booth(num1, num2), 'product in decimal')
