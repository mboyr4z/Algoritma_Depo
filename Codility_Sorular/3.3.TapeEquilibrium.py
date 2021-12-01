

def solution(A):
    # boyle sorunun!
    minFark = float("inf")
    sag = sum(A) 
    sol = 0
    
    for i in range(0, len(A) - 1):
        sol += A[i]
        sag -= A[i]
        
        
        fark = abs(sol - sag)
            
        if fark < minFark:
            minFark = fark
            
    return minFark
        
        
print(solution([1,2,3,4,5]))