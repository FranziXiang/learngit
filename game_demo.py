#!/usr/bin/env python
# coding=utf-8

import random
import time
dict = {0:'scissors',1:'rock',2:'paper'}
print "--------Game Start--------"
print "--------q : Quit----------"
while 1:
    print
    print "Enter scissors rock or paper:",
    user=raw_input()
    computer =  random.randint(0,2)
    if user=='scissors':
        user_input=0
    elif user=='rock':
        user_input=1
    elif user=='paper':
        user_input=2
    elif user=='q':
        print
        print "--------Game Over--------"
        quit()
    else:
        print "Input error."
        continue
    print "computer is:",dict[computer]
    if user_input%2==0 and computer==0 and user_input!=0:
        user_input=-1
    if computer%2==0 and user_input==0 and computer!=0:
        computer=-1
    if computer>user_input:
        print "You lose!"
    elif computer==user_input:
        print "Draw!"
    else :
        print "You win!"
    time.sleep(1)
