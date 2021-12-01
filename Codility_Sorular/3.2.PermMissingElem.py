# https://app.codility.com/programmers/lessons/3-time_complexity/

def solution(A):
    if len(A) == 0:
        return 1
    
    eksiksiz = 0
    eksikli = 0
    for i in range(1,len(A) + 2):
        eksiksiz += i
        
    
    for i in A:
        eksikli += i
        
        
    return eksiksiz - eksikli

print(solution([1,2,3,5]))