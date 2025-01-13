def ieeeRep(decimal):
    print("\nOriginal Number:\n{0}".format(decimal))
    bin_num = convertToBin(decimal)
    print("\nNumber converted to binary:\n{0}".format(bin_num))
    normalized_bin = normalize(bin_num)
    print("\nNormalized binary number:\n{0}".format(normalized_bin))
    ieeeSingle, ieeeDouble = convertToIEEE(decimal, normalized_bin)
    print("\nIEEE Single Precision Representation:\n{0}".format(ieeeSingle))
    print("\nIEEE Double Precision Representation:\n{0}".format(ieeeDouble))
    return

def convertToBin(decimal):
    inte, deci = tuple(decimal.split('.'))
    bin_int = decToBin_Int(inte)
    bin_dec = decToBin_Dec(deci)
    bin_num = bin_int + '.' + bin_dec
    return bin_num

def decToBin_Int(num):
    if num == "0":
        return "0"
    binary = ""
    num = int(num)
    newNum = abs(num)
    while newNum >= 1:
        quo, rem = newNum // 2, newNum % 2
        binary += str(rem)
        newNum = quo
    binary = binary[::-1]
    if num < 0:
        binary = '-' + binary
    return binary

def decToBin_Dec(num):
    binary = ""
    num = float('0.' + num)
    for i in range(20):
        num = 2 * num
        if num == 1:
            binary += '1'
            break
        elif num > 1:
            binary += '1'
            num -= 1
        elif num < 1:
            binary += '0'
    return binary

def normalize(num):
    initial = num.index('.')
    num = num.replace('.', '')
    num = num[: num.index('1') + 1] + '.' + num[num.index('1') + 1 :]
    final = num.index('.')
    expo = initial - final
    num = num + 'E' + str(expo)
    return num

def convertToIEEE(dec_num, normalized):
    singleIEEE = ""
    doubleIEEE = ""
    singleBias = 127
    doubleBias = 1023
    expo = int(normalized[normalized.index('E') + 1 :])

    if float(dec_num) >= 0:
        singleIEEE += '0'
        doubleIEEE += '0'
    elif float(dec_num) < 0:
        singleIEEE += '1'
        doubleIEEE += '1'
    
    singleExponent = decToBin_Int(singleBias + expo)
    if len(singleExponent) == 7:
        singleExponent = '0' + singleExponent
    singleIEEE += singleExponent[-8:]
    doubleExponent = decToBin_Int(doubleBias + expo)
    if len(doubleExponent) == 10:
        doubleExponent = '0' + doubleExponent
    doubleIEEE += doubleExponent[-11:]

    mantissa = normalized[normalized.index('.') + 1 : normalized.index('E')]
    singleMantissa = padZero(mantissa, 23)
    doubleMantissa = padZero(mantissa, 52)
    singleIEEE += singleMantissa
    doubleIEEE += doubleMantissa

    return singleIEEE, doubleIEEE

def padZero(num, tot_len):
    extraZeros = tot_len - len(num)
    num = num + (extraZeros * '0')
    return num

num = input("Enter a floating point number: ")
ieeeRep(num)