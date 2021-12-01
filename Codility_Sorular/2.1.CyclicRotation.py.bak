def solution(A, K):
    B = A.copy()
    for j in range(K):
        for i in range(len(A)):
            A[(i + 1) % len(A)] = B[i]
        B = A.copy()
    return A

print(solution([3,8,9,7,6],3))