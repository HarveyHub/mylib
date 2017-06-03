#! /usr/bin/python
#coding:utf-8
import subprocess as sp
timers = [];
cnt = 20;
for i in range(cnt):
    p = sp.Popen(["./target", "-a -b b"], shell=True, stdout=sp.PIPE);
    output = p.stdout.read().split();
    #print output;
    tmp = [];
    for item in output:
        if(item.find("us") > 0):
            tmp.append(item[:item.index("us")]);
    if(len(tmp)>0):
        timers.append(map(float, tmp));

for i in timers:
    print i

#i = 0;
#for item in output:
#    print i, item;
#    i += 1;

