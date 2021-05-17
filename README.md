# Algoritma_Depo

<!--  <a href = "#a_"></a><br> -->
<!--  <a href = "#basliklar"> Konu Başlıklarına Geri Dön</a><br>-->
<div id="basliklar">
   <h3><a href="#a_1">1. Gaussian Filtre Gezdirme</a></h3>
   <h3><a href="#a_2">2. Hash_ile_sozluk_veritabani_bagli_liste</a></h3>
   <h3><a href="#a_3">3. Telefon_tuslama</a></h3>
   <h3><a href="#a_4">4. Dijkstra Algoritması</a></h3>
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
   üçüncü satır max pixsel değeri<br>
   dördüncü satır min pixel değeri<br>
   Burada resim, matris olarak ele alınmış ve pixel değerleri random olarak atanmıştır.<br>
   
   <hr>
   <h3>ADIMLAR</h3>
   <ul type="square">
 
   
   <li>Resim alınır, kenarları kendi değerleriyle, (filtre boyutu / 2) kalınlıkla artırılır.(Amaç Yumuşatmayı 0 değerlerinden kurtarmak, en doğru şekilde kendi değerleriyle yaptırmak).</li>
   <li>Kenarları belli olan resim 21*21 sabit matris üzerine yapıştırılır.(Üzerinde gezicek olan filtre hiç bi şekilde arraydan taşma hatası almaz).</li>

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

   <hr>
   <h3>ADIMLAR</h3>
   <ul type="square">
   <li>Eğer bir türkçe kelimenin ingilizce yerinin hangi satırda olduğunu net olarak bilirsek arama algoritması kullanmaya gerek kalmaz </li>        
   <li>Program bu yüzden asal çarpan metodu kullanır.</li>
   <li>Sıralı halde bulunan ardışık asallarla kelimede bulunan karakterlerin ASCII lerini birebir çarpıp tooplar</li>
   <li>Kaydedeceğimiz yerin uzunluğuna göre modunu alır ve satır sayısı ortaya çıkar</li>
   <li>Aynı satıra dek gelen kelimeler aralarında belirteç olarak ** tutularak yan yana yazılır. Bu sayede yerleri yine bellidir</li>
   <li>Bu çıktıları "sozluk1.txt" ye kaydeder ve aramayı oradan yapar. Max arama istenilen ingilizce kelimenin satırındaki kelimeler kadardır</li>
   <li>YANİ MÜKEMMEL Bİ ALGORİTMA</li>
   </ul>
   
   <h3>ORTAYA ÇIKAN YENİ SÖZLÜK</h3>
   <img src="https://user-images.githubusercontent.com/82450697/116376380-e0417600-a818-11eb-822b-af489eb0a011.PNG">
   
   <h3>PROGRAMIN ÇALIŞIR HALİ</h3>
   <img src="https://user-images.githubusercontent.com/82450697/116376472-f818fa00-a818-11eb-9480-dbaedb41162f.PNG">
   <hr>

</div>

<hr>


<div id="a_3">
   
   <h3> Telefon Tuşlaması </h3>
   <a href = "#basliklar"> Konu Başlıklarına Geri Dön</a><br>
   <img src="https://user-images.githubusercontent.com/82450697/116377068-80979a80-a819-11eb-825c-3d2b55295cbc.PNG">
   <ul type="square">
   <li>Program "0" girdisi alana kadar devam eder ve çıktıyı ekrana verir</li>
   </ul>
</div>


<hr>

<div id="a_4">
   
   <h3> Dijkstra Algoritması </h3>
   <a href = "#basliklar"> Konu Başlıklarına Geri Dön</a><br>
   <img src="https://user-images.githubusercontent.com/82450697/118476024-ad9ee500-b715-11eb-97d7-28c01fdd1d30.png">
   <ul type="square">
   <li>Amacımız Yukarıdaki Şekilde 'A' düğümünden başlayıp diğer düğümlere olan en kısa uzaklığı bulmaktır. </li>
   <li>Kodlamaya uygun hale getirebilmek amacıyla her düğümü bir liste halinde tanımlıyoruz.Aşağıdaki Şekildeki gibi..</li><br>
   <img src="https://user-images.githubusercontent.com/82450697/118476260-f2c31700-b715-11eb-9d57-a51cf39d0d2b.PNG">
   <li>Yukarıdaki kodda tanımlanan düğümlerin ilk indisi başlangıçıtan kendisine olan uzaklık. 'A' düğümü '0', diğer düğümler ise 'sonsuz' değerle başlar</li>
   <li>İkinci Indisi kendi harfi, Üçüncü indis ise liste halinde bağlantısı olan düğümlerdir, tabi o düğümlerin id sini ve o düğüme olan uzaklığı liste halinde tutar</li>
   <li>Recursive fonksiyonumuza başta 'A' düğümünü ve koşulla birlikte gitmesi gereken düğümleri sırasıyla recursive döndürüyoruz</li>
   
   Fonksiyonumuz : <br>
   <img src="https://user-images.githubusercontent.com/82450697/118476838-b17f3700-b716-11eb-97ff-c53f0b03891f.PNG">
   
   Almış olduğumuz çıktının görsel hali ve Konsolda düğümlerin gösterilmesi
   <br>
   <table>
   <tr>
      <td><img src="https://user-images.githubusercontent.com/82450697/118477122-058a1b80-b717-11eb-9c74-1cf4a7f97138.png"></td>
      <td><img src="https://user-images.githubusercontent.com/82450697/118477088-fb681d00-b716-11eb-823e-3d537788bccc.PNG"></td>
   </tr>
   </table>
   Algoritma Hakkında Daha Kapsamlı Bilgi İçin : <a href = "https://bilgisayarkavramlari.com/2010/05/13/dijkstra-algoritmasi-2/">Şadi Baba Dijkstra Konu Anlatım</a>
   </ul>
</div>

<hr>
