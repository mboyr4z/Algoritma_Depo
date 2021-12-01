# https://app.codility.com/programmers/lessons/4-counting_elements/
# Soruda 1 den X e kadar olan sayılar dizide ilk hangi noktaya kadar tamamlanıyor onu soruyor. 


def solution(X, A):
    
    
    yapraklar = {}
    sayac = 0
    for dusenNokta in A:
        yapraklar[dusenNokta] = True
        sayac += 1
        if len(yapraklar) == X:
            return sayac - 1
    return -1

        
        
print(solution(5, [1,3,1,5,4,2,5,4]))