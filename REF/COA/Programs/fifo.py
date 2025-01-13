def FIFO(cacheSize, referenceStr):
    cache = []
    hits = 0
    pageFaults = 0
    ptr = 0
    print()
    for page in referenceStr:
        if page in cache:
            hits += 1
        else:
            pageFaults += 1
            if len(cache) != cacheSize:
                cache.append(page)
            elif len(cache) == cacheSize:
                cache[ptr] = page
                ptr += 1
                if ptr == cacheSize:
                    ptr = 0
        print(page, end = "\t|\t")
        for element in cache:
            print(element, end = "\t")
        print()
    hitRatio = calcHitRatio(hits, pageFaults)
    return hits, pageFaults, hitRatio

def calcHitRatio(hit, fault):
    hitRatio = hit / (hit + fault)
    return hitRatio

cache_size = int(input("Enter the cache size: "))
ref_str = input("Enter the reference string: ")
# ref_str = "70120304230321201701"
hits, faults, ratio = FIFO(cache_size, ref_str)
print("\nHits = {0}\nPage Faults = {1}\nHit Ratio = {2}".format(hits, faults, ratio))
