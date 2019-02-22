$ git config --global core.autocrlf true
# amiralbatti
c++ Console Amiral Battı  Oyunu

Programlamaya henüz yeni başladığımda yazmış olduğum amiral battı oyunu (Sorunsuz oynanmaktadır ).
Bir üst beginner seviyesi için kodlar düzeltilmeye ve geliştirilmeye açıktır , exception handling gibi işlemleri eklemek için antrenman olabilir.

#Nasıl Oynanır ? 

-Bilgisayara karşı oynanabilir.

-1+Enter kombinasyonu ile oyun akışı başlar.

![1](https://github.com/fatihmgenc/BattleShips/blob/master/img/img/1.png)

Oyuncular 5 Farklı Türde (uzunlukta) gemiye sahiptir , gemiler yerleştirildikçe miktarları azalır . Yerleştirmeye geminin numarasını seçerek başlayabilirsiniz.

![2](https://github.com/fatihmgenc/BattleShips/blob/master/img/img/2.png)

-Gemi seçiminin ardından yerleştirmeye başlamak istediğiniz konumun satır ve sütun değerlerini girebilirsiniz. Program o noktadan başlayarak gemi uzunluğunca bir sonraki aşamada belirteceğiniz yönde yerleştirecektir . 

![3](https://github.com/fatihmgenc/BattleShips/blob/master/img/img/3.png)

-Geçersiz bir koordinat girmeniz durumunda şu şekilde bir uyarı ile karşılaşırsiniz .

![4](https://github.com/fatihmgenc/BattleShips/blob/master/img/img/4.png)

-Ardından  hangi yöne doğru koyacağınızı seçiniz

![5](https://github.com/fatihmgenc/BattleShips/blob/master/img/img/5.png)

-Bir gemi diğerinin üstünde veya bitişiğinde konumlandırılamaz , kesişen koordinatlarda bir yerleşme seçerseniz bu durumda şöyle bir uyarı alırsınız : 

![6](https://github.com/fatihmgenc/BattleShips/blob/master/img/img/6.png)

-Hatasız yerleştirmeniz sonucunda seçtiğiniz gemi “User Board” kısmında görülecek ve gemi listesindeki how many sütunundan miktar azalacaktır . 

![7](https://github.com/fatihmgenc/BattleShips/blob/master/img/img/7.png)

-Bu işlem bütün gemiler bitinceye kadar tekrarlanır . Yerleştirilmiş bir gemiyi tekrar yerleştirmeye çalışmanız durumunda da şu uyarı ile karşılaşırsınız : 

![8](https://github.com/fatihmgenc/BattleShips/blob/master/img/img/8.png)

-Tüm gemilerinizi sorunsuz yerleştirdikten sonra bilgisayar da gemileri kurallara uygun şekilde yerleştirir ve atışlar başlar . 

-Rakip tahtada ateş edilmemiş hücreler “0” , vurulmuş gemilerin kısımları “2” , ıskalanmış atışlar ise “4” rakamı ile görünür.Kendi tahtanızda gemilerinizin yerini oyun boyunca “1” rakamları ile görebilirsiniz .

![9](https://github.com/fatihmgenc/BattleShips/blob/master/img/img/9.png)

-Atış için satır ardından sütun kordinatını giriniz .

-Daha önce atış yapılmış yada oyun tahtasında olmayan bir koordinat girmeniz durumunda program gerekli uyarıyı verir ve atış tekrarlanır.

![10](https://github.com/fatihmgenc/BattleShips/blob/master/img/img/10.png)
![11](https://github.com/fatihmgenc/BattleShips/blob/master/img/img/11.png)

-Oyun sırasında iki tarafında toplam başarılı atış (vurulma sayısı) sayısı tahtaların altında görülür.

![12](https://github.com/fatihmgenc/BattleShips/blob/master/img/img/12.png)

-Gemi içeren tüm koordinatlar vurulduktan sonra : 

![13](https://github.com/fatihmgenc/BattleShips/blob/master/img/img/13.png)










