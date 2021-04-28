# Algoritma_Depo

<!--  <a href = "#a_"></a><br> -->
<!--  <a href = "#basliklar"> Konu Başlıklarına Geri Dön</a><br>-->
<div id="basliklar">
   <h3><a href="#a_1">1. Gaussian Filtre Gezdirme</a></h3>
   <h3><a href="#a_2">2. Hash_ile_sozluk_veritabani_bagli_liste</a></h3>
   <h3><a href="#a_3">3. Telefon_tuslama</a></h3>
</div>

<br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>

<div id="a_1">
   
   <h3> Gaussian Filtre Gezdirme </h3>
   <a href = "#basliklar"> Konu Başlıklarına Geri Dön</a><br>
   Kodlamış olduğumuz algoritmada amaç gaussian yöntemiyle fotoğrafta kenar yumuşatmadır.<br>
   Gaussian'ın bu filtresi, kullanıcıdan alınan "input.txt" ye göre boyutlanır ve her bi matris elemanı 0.0370 dir.<br>
   input içi;<br>
   ilk satır, fotoğraf boyutu,<br>
   ikinci satır filtre boyutu,<br>
   üçüncü satır max pixsel değeri,<br>
   dördüncü satır min pixel değeri<br>
   Burada resim, matris olarak ele alınmış ve pixel değerleri random olarak atanmıştır.<br>
   
   <hr>
   <h3>ADIMLAR</h3>
   <ul type="square">
 
   
   <li>Resim alınır, kenarları kendi değerleriyle, (filtre boyutu / 2) kalınlıkla artırılır.(Amaç Yumuşatmayı 0 değerlerinden kurtarmak, en doğru şekilde kendi değerleriyle yaptırmak).</li>
   <li>Kenarları belli olan resim 21*21 sabit matris üzerine yapıştırılır.(Üzerinde gezicek olan filtre hiç bi şekilde arraytan taşma hatası almaz).</li>

   <li>21*21 matrisin belirli koordinatından başlayarak gezme başlar. üst üste gelen matris değerleri çarpılır ve filtrenin orta elemanına dek gelen, tamamen sıfırlardan oluşan matrise sonuç yapıştırılır. </li>
   <li>Sonuç = (1.gausPix*1.resimPix + 2.Gaus........... + n*GausPix* n.ResimPix) / n ' dir.(n = filtre boyutu)</li>

    

   <li>Ortaya çıkan ve ortasında input resmi kadar matris barındıran ve kenarları 0 olan matristen 0 olan değerler kesilir. </li>
   <li>Geriye sadece resim boyutu kadar output matris çıkar.</li>

   <li>Ve output matris yazdırılır.</li>

   <ul>

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
</div>

<hr>

<div id="a_2">
   
   <h3> Hash ile Sözlük Veritabanı </h3>
   <a href = "#basliklar"> Konu Başlıklarına Geri Dön</a><br>
   
   <h3>Amaç :</h3>
   

   * "sozluk.txt" içerisinde sol tarafta türkçeler ve sağ tarafta ingilizceler olmak üzere sözlük vardır
   <img src="https://user-images.githubusercontent.com/82450697/116370214-da489680-a812-11eb-896f-7a820b8a0cf3.PNG">

   
   * Sözlük bu şekilde kullanılabilir ama kelimeleri bulmak bilgisayar için zaman almaktadır.
   <ol>
   <li>Eğer bir türkçe kelimenin ingilizce yerinin hangi satırda olduğunu net olarak bilirsek arama algoritması kullanmaya gerek kalmaz </li>
        
   <li>Program bu yüzden asal çarpan metodu kullanır.</li>
   <li>Sıralı halde bulunan ardışık asallarla kelimede bulunan karakterlerin ASCII lerini birebir çarpıp tooplar</li>
   <li>Kaydedeceğimiz yerin uzunluğuna göre modunu alır ve satır sayısı ortaya çıkar</li>
   <li>Aynı satıra dek gelen kelimeler aralarında belirteç olarak ** tutularak yan yana yazılır. Bu sayede yerleri yine bellidir</li>
   <li>Bu çıktıları "sozluk1.txt" ye kaydeder ve aramayı oradan yapar. Max arama istenilen ingilizce kelimenin satırındaki kelimeler kadardır</li>
   <li>YANİ MÜKEMMEL Bİ ALGORİTMA</li>
   </ol>
   

   
   
  
</div>

