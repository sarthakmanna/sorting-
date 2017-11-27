#! /usr/bin/python

# To change this license header, choose License Headers in Project Properties.
# To change this template file, choose Tools | Templates
# and open the template in the editor.

import random

__author__ = "sarthakmanna"
__date__ = "$28 Nov, 2017 2:27:26 AM$"

# Bogo Sort/Permutation Sort/Stupid Sort/Shotgun Sort/Monkey Sort
# (According to https://en.wikipedia.org/wiki/Bogosort)     ;)

def isSorted(ar):
    for i in range(1,len(ar)):
        if ar[i-1]>ar[i]:
            return False
    return True

print "Input Size of Input Array: ",
n=int(raw_input().strip())
ar=[]

for i in xrange(n):
    print "Input Element %d:"%(i+1),
    ar.append(int(raw_input().strip()))

print "Input Array:",ar
print "Now keep Waiting while the array is being Sorted !!!....\n"

while isSorted(ar)==False:
    random.shuffle(ar)

print "Finally..."
print "Sorted Array:",ar