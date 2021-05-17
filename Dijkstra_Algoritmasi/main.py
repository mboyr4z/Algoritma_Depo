import math

A = [0,"A",       [ [1,2] , [2,1]         ]]
B = [math.inf,"B",[ [0,2] , [5,5] , [4,2] ]]
C = [math.inf,"C",[ [0,1] , [3,1] , [5,2] ]]
D = [math.inf,"D",[ [2,1] , [5,5] , [4,7] ]]
E = [math.inf,"E",[ [3,7] , [1,2]         ]]
F = [math.inf,"F",[ [1,5] , [2,2] , [3,5] ]]

dugumler= [A,B,C,D,E,F]


def dijkstra(dugum):
    for yol in dugum[2]:
        if dugum[0] + yol[1] < dugumler[yol[0]][0]:         # eğer kendi ağırlığı + gideceği yol ağırlığı < gideceği düğüm ağırlık
            dugumler[yol[0]][0] = dugum[0] + yol[1]         # gideceği düğümün ağırlığını güncelle
            dijkstra(dugumler[yol[0]])                     # gideceği düğüme yolla

dijkstra(dugumler[0])
for i in dugumler:
    print(i)