#https://app.codility.com/programmers/lessons/2-arrays/ 

def solution(A):
    uzunluk = len(A)
    if(uzunluk == 1):
        return A[0]
    
    A = sorted(A)
    
    for i in range(0,uzunluk - 2,2):
        if(A[i] != A[i + 1]):
            return A[i]
    return A[-1]


print(solution([1,1,3,3,4,4,2,2,7,7,9]))