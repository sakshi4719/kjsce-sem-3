def memoryBlock(words, blocks, memoryElements):
    memory = []
    for i in range(blocks):
        block = tuple(memoryElements[(4*i):(4*i+words)])
        memory.append(block)
    for i in range(blocks):
        print("Block", i, "contains:", end = "")
        for element in memory[i]:
            print("", element, end = "")
        print()
    return memory

def cacheDirect(memory):
    print("Direct mapping".center(30, '-'))
    directMapping = []
    for i in range(len(memory)):
        cache = []
        print("Cache line {0} contains: ".format(i), end = "")
        for j in range(len(memory[i])):
            cache.append(memory[j][i])
        for element in cache:
            print("", element, end = "")
        print()
    directMapping.append(cache)

def cacheSetAssociative(memory, setCount):
    print('\n', "Associative mapping".center(30, '-'), sep = "")
    setAssociativeMapping = []
    for i in range(setCount):
        cacheBlock = []
        print("Cache {0}".format(i+1).center(28, '-'))
        for j in range(len(memory)):
            cache = []
            print("Cache line {0} contains: ".format(j), end = "")     
            for k in range(len(memory[i])//setCount):
                cache.append(memory[(k*setCount)+i][j])
            for element in cache:
                print("", element, end = "")
            print()
            cacheBlock.append(cache)
        setAssociativeMapping.append(cacheBlock)
            
            

words = int(input("Enter the number of words in each block: "))
blocks = int(input("Enter the number of blocks in memory: "))
setCount = int(input("Enter the number of sets in associative mapping: "))
ref_str = input("Enter elements in memory: ")

print('\n', "Each block in memory".center(35, '-'), sep = "")
blockMemory = memoryBlock(words, blocks, ref_str)
print('\n', "Cache lines in cache".center(35, '-'), sep = "")
cacheDirect(blockMemory)
cacheSetAssociative(blockMemory, setCount)

