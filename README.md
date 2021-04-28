# Algoritma_Depo


## 1. Gaussian Filtre Gezdirme

Kodlamış olduğumuz algoritmada amaç gaussian yöntemiyle fotoğrafta kenar yumuşatmadır.<br>
Gaussian'ın bu filtresi, kullanıcıdan alınan "input.txt" ye göre boyutlanır ve her bi matris elemanı 0.0370 dir.<br>
input içi;
ilk satır, fotoğraf boyutu,
ikinci satır filtre boyutu,
üçüncü satır max pixsel değeri,
dördüncü satır min pixel değeri

Burada resim, matris olarak ele alınmış ve pixel değerleri random olarak atanmıştır.

   a. Resim alınır, kenarları kendi değerleriyle, (filtre boyutu / 2) kalınlıkla artırılır.(Amaç Yumuşatmayı 0 değerlerinden kurtarmak, en doğru şekilde kendi değerleriyle yaptırmak).
   b. Kenarları belli olan resim 21*21 sabit matris üzerine yapıştırılır.(Üzerinde gezicek olan filtre hiç bi şekilde arraytan taşma hatası almaz).
   
   c. 21*21 matrisin belirli koordinatından başlayarak gezme başlar. üst üste gelen matris değerleri çarpılır ve filtrenin orta elemanına dek gelen, tamamen sıfırlardan oluşan matrise sonuç yapıştırılır. <br><br>
   
   Sonuç = (1.gausPix*1.resimPix + 2.Gaus........... + n*GausPix* n.ResimPix) / n ' dir.(n = filtre boyutu)
   
 <br><br>
 
  Ortaya çıkan ve ortasında input resmi kadar matris barındıran ve kenarları 0 olan matristen 0 olan değerler kesilir. 
  <br> Geriye sadece resim boyutu kadar output matris çıkar.
  
  Ve output matris yazdırılır.



<table>
   <tr>
    <td><img src = "https://user-images.githubusercontent.com/82450697/116204578-9471cc80-a745-11eb-87c3-b31f85e9d4c4.PNG"></td>
    <td><img src = "https://user-images.githubusercontent.com/82450697/116204620-a18ebb80-a745-11eb-9bf8-8f9950791e2a.PNG"></td>
   </tr>
    <tr>
    <td><img src = "https://user-images.githubusercontent.com/82450697/116204652-a6ec0600-a745-11eb-921c-a2165b7fcc46.PNG"></td>
    <td><img src = "https://user-images.githubusercontent.com/82450697/116204689-ad7a7d80-a745-11eb-9df9-d13ee7ed3fb5.PNG"></td>
   </tr>
</table>


