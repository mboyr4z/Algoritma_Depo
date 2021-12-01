
#https://app.codility.com/programmers/lessons/1-iterations/

dizi = []
def solution(N):
    while(int(N) > 0):
        kalan = int(N % 2) 
        dizi.append(kalan)
        N /= 2;
    
    sayac = 0
    dizi.reverse()
    araliklar = []
    for i in range(len(dizi)):
        if(dizi[i] == 0):
            sayac += 1
        else:
            araliklar.append(sayac)
            sayac = 0
            
    return max(araliklar)
            

print(solution(18));
