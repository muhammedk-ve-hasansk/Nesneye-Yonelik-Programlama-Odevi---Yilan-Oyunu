# Yılan Oyunu (Nesneye Yönelik Programlama Ödevi)

Bu proje, **Nesneye Yönelik Programlama** dersi kapsamında geliştirilmiş bir yılan oyunudur. Oyunda, klasik yılan oyunu mantığına uygun olarak bazı güncellemeler yapıldı, yılanı büyütmek için yemekleri toplayacak ve duvarlara, zehirli meyvelere, bombalara ya da kendinize çarpmadan hayatta kalmaya çalışacaksınız. 

## Özellikler

- **Etkileşimli Oyun:** Klavye kontrolleriyle yılanı hareket ettirin (İster w,a,s,d ister yön tuşlarını kullanın).
- **Basit ve Eğlenceli Grafikler:** Minimalist konsol tabanlı tasarım.
- **Yüksek Performans:** Hafif ve hızlı bir oyun motoru.

## Geliştiriciler

- **Muhammed Kaya**
- **Hasan Server Kamber**

## Oyunun Kuralları

- Yılanı yön tuşlarıyla hareket ettirin.
- Meyveleri(O sembolleri) yiyin, puan kazandırır.
- Zehirli meyvelerden (& sembolleri) kaçının, puan kaybettirir.
- Bombalar (# sembolleri) alanı küçültür.
- Oyun alanından çıkmak kaybettirir.
- Yılanınızın boyutu bir birimden fazlayken eğer ters yöne gitmeye calısırsanız yılan kendi kendini ısaracağı için kaybedersiniz.

## Sistem Gereksinimleri

- **İşletim Sistemi:** Windows (MinGW gerekli)
- **Gerekli Araçlar:**
  - `git`
  - `MinGW` (make komutunu çalıştırmak için)

## Kurulum ve Çalıştırma

Oyunu yüklemek aşağıdaki adımları izleyin:

```
git clone https://github.com/muhammedk-ve-hasansk/Nesneye-Yonelik-Programlama-Odevi---Yilan-Oyunu.git
```
```
cd Nesneye-Yonelik-Programlama-Odevi---Yilan-Oyunu
```
```
mingw32-make
```
```
.\SnakeGame.exe
```
