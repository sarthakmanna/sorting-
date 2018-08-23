import time as tm
import matplotlib.pyplot as pl
import random as rd

LOWER, UPPER, STEP = 1000, 10000, 500


def generate(size):
    return [rd.randint(0, int(1e18)) for i in xrange(size)]


def sort(ar):
    # https://interactivepython.org/courselib/static/pythonds/SortSearch/TheMergeSort.html
    def mergeSort(alist):
        if len(alist) > 1:
            mid = len(alist) // 2
            lefthalf, righthalf = alist[:mid], alist[mid:]
            mergeSort(lefthalf)
            mergeSort(righthalf)
            i = j = k = 0
            while i < len(lefthalf) and j < len(righthalf):
                if lefthalf[i] < righthalf[j]:
                    alist[k] = lefthalf[i]
                    i = i + 1
                else:
                    alist[k] = righthalf[j]
                    j = j + 1
                k = k + 1
            while i < len(lefthalf):
                alist[k] = lefthalf[i]
                i = i + 1
                k = k + 1
            while j < len(righthalf):
                alist[k] = righthalf[j]
                j = j + 1
                k = k + 1

    mergeSort(ar)
    return ar


# Testing sorted Array
size1, time1 = [], []
for i in xrange(LOWER, UPPER + 1, STEP):
    ar = sorted(generate(i))
    print ar
    stTime = tm.time()
    sorAr = sort(ar[::])
    endTime = tm.time()
    if sorAr == sorted(ar):
        print "OK, Sorted..."
    else:
        print "Error!!! not Sorted..."
        exit(1)
    size1.append(i)
    time1.append(endTime - stTime)
print size1
print time1


# Testing reverse-sorted Array
size2, time2 = [], []
for i in xrange(LOWER, UPPER + 1, STEP):
    ar = sorted(generate(i))[::-1]
    print ar
    stTime = tm.time()
    sorAr = sort(ar[::])
    endTime = tm.time()
    if sorAr == sorted(ar):
        print "OK, Sorted..."
    else:
        print "Error!!! not Sorted..."
        exit(1)
    size2.append(i)
    time2.append(endTime - stTime)
print size2
print time2


# Testing unsorted Array with elements in any order
size3, time3 = [], []
for i in xrange(LOWER, UPPER, STEP):
    ar = generate(i)
    print ar
    stTime = tm.time()
    sorAr = sort(ar[::])
    endTime = tm.time()
    if sorAr == sorted(ar):
        print "OK, Sorted..."
    else:
        print "Error!!! not Sorted..."
        exit(1)
    size3.append(i)
    time3.append(endTime - stTime)
print size3
print time3


pl.title("Merge Sort Analysis")
pl.xlabel("Size of Array")
pl.ylabel("Time taken (in milli-seconds)")

pl.plot(size1, time1, label = 'Sorted')
pl.plot(size2, time2, label = 'Reverse-sorted')
pl.plot(size3, time3, label = 'Unsorted')
pl.legend(loc = 'upper left')

pl.show()