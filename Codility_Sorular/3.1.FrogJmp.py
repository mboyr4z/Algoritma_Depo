#https://app.codility.com/programmers/lessons/3-time_complexity/

def solution(X, Y, D):
    if(X == Y):
        return 0
    return int((Y - X - 1) / D) + 1

print(solution(10, 30, 20))