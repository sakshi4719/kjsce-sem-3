cache = []
recent = []

def calcHitRatio(hit, fault):
    hitRatio = hit / (hit + fault)
    return hitRatio

def updateRecPos(cache, page):
    if cache.index(page) in recent:
        recent.remove(cache.index(page))
    recent.append(cache.index(page))
    return

def LRU(cacheSize, referenceStr):
    hits = 0
    pageFaults = 0
    print()
    for page in referenceStr:
        if page in cache:
            hits += 1
            updateRecPos(cache, page)
        else:
            pageFaults += 1
            if len(cache) != cacheSize:
                cache.append(page)
                updateRecPos(cache, page)
            elif len(cache) == cacheSize:
                cache[recent[0]] = page
                updateRecPos(cache, page)
        print(page, end = "\t|\t")
        for element in cache:
            print(element, end = "\t")
        print()
    hitRatio = calcHitRatio(hits, pageFaults)
    return hits, pageFaults, hitRatio

cache_size = int(input("Enter the cache size: "))
# ref_str = input("Enter the reference string: ")
ref_str = "70120304230321201701"
hits, faults, ratio = LRU(cache_size, ref_str)
print("\nHits = {0}\nPage Faults = {1}\nHit Ratio = {2}".format(hits, faults, ratio))