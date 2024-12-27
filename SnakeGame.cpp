#include "SnakeGame.h" 
#include "Fruit.h"
#include "Poison.h"
#include "Bomb.h"
#include <vector> // vector sinifi icin kullanacagimiz kutuphane
#include "GameObject.h"
#include <iostream> // cout ve cin kullacagimiz kutuphane
#include <fstream> // Dosya islemleri icin
#include <ctime> // srand fonksiyonu icin
#include <conio.h> // _kbhit ve _getch fonksiyonlari icin
#include <windows.h> // Sleep fonksiyonu icin

SnakeGame::SnakeGame() {
    width = 50;
    height = 20;
    score = 0;
    gameOver = false;
    x = width / 2;
    y = height / 2;
    direction = ' ';
    srand(time(0));
    snakeBody.push_back({x, y});
    generateGameObjects();
}
//oyun sonlandiginda nesneleri silen destructor
    SnakeGame::~SnakeGame() {
        for (auto obj : objects) {
            delete obj;
        }
    }

   //oyunun skorunu dosyaya kaydeden fonksiyon
void SnakeGame::saveScore() {
        std::ofstream file("scores.txt", std::ios::app); // Dosyayi aciyoruz
        if (file.is_open()) {   // Dosya acildiysa devam ediyoruz
            file << score << std::endl; // Skoru dosyaya yaziyoruz
            file.close(); // Dosyayi kapatiyoruz
        }
    }
    //dosyadan skorlari okuyup ekrana yazdiran fonksiyon
    void SnakeGame::displayScores() {
        std::ifstream file("scores.txt"); // Dosyayi okuyoruz
        std::string line;   // Dosyadan okunan satiri tutacak degisken
        std::cout << "\n--- Eski Skorlar ---\n";     // Eski skorlar basligi
        while (getline(file, line)) {   // Dosyadan satir satir okumak icin dongu baslatiyoruz
            std::cout << line << std::endl;   // Okunan satiri ekrana yazdiriyoruz
        }
        file.close();   // Dosyayi kapatiyoruz
    }

    //dosyadaki skorlari silen fonksiyon
    void SnakeGame::deleteScores() {
        std::ofstream file("scores.txt", std::ios::trunc);  // Dosyayi sifirliyoruz
        file.close(); // Dosyayi kapatiyoruz
        std::cout << "Eski skorlar silindi.\n"; // Kullaniciya mesaj veriyoruz
    }
  //oyun nesnelerini olusturan fonksiyon
    void SnakeGame::generateGameObjects() {
        // Nesneleri temizleyip yeniden olusturyoruz
        objects.clear(); // Nesneleri temizliyoruz
        objects.push_back(new Fruit(rand() % width, rand() % height));  // Meyve ekliyoruz
        objects.push_back(new Poison(rand() % width, rand() % height));   // Zehir ekliyoruz
        objects.push_back(new Bomb(rand() % width, rand() % height));   // Bomba ekliyoruz
    }
 //oyun alanini cizen fonksiyon
    void SnakeGame::draw() {
     system("cls"); // Konsolu temizliyoruz
        // Oyun alaninin ust kismini ciziyoruz
        for (int i = 0; i < width + 2; i++) std::cout << "#";
        std::cout << std::endl;
        // Oyun alaninin ortasini ciziyoruz
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (j == 0) std::cout << "#"; // Oyun alaninin sol kenarini ciziyoruz

                if (i == y && j == x) {
                    std::cout << "O"; // Yilanin basini ciziyoruz
                } else {
                    bool printed = false; // Ekrana yazdirildi mi kontrolu
    
                //yilanin govdesini cizen dongu
                    for (size_t k = 1; k < snakeBody.size(); k++) { 
                    if (snakeBody[k -1].first == j && snakeBody[k-1].second == i) {
                        std::cout << "O";            //yilanin govdesini bir birim artiriyoruz
                        printed = true; 
                        break;
                    }
                    }
                    // Nesne kontrolu
                    if (!printed) {
                        bool objectPrinted = false; // Nesne ekrana yazdirildi mi kontrolu
                        for (auto obj : objects) { 
                            if (obj->x == j && obj->y == i) { 
                                obj->render(); // Nesneyi ciziyoruz 
                                objectPrinted = true;
                                break;
                            }
                        }
                        if (!objectPrinted)
                            std::cout << " "; // Eger nesne yoksa bosluk yazdiriyoruz
                    }
                }

                if (j == width - 1) std::cout << "#"; // Oyun alaninin sag kenarini ciziyoruz
            }
            std::cout << std::endl; // Her satirin sonunda bir alt satira geciyoruz
        }

        for (int i = 0; i < width + 2; i++) std::cout << "#"; // Oyun alaninin alt kismini ciziyoruz
        std::cout << std::endl;
        std::cout << "Skor: " << score << std::endl; // Skoru ekrana yazdiriyoruz
}

//kullanicinin klavyede bastigi tuslari algilayan fonksiyon
void SnakeGame::input() {
    if (_kbhit()) {
        char ch = _getch(); // Kullanicinin bastigi tusu okuyoruz
        switch (ch) {
            case 'w': 
            case 0x48:  // Yon tusu yukari (0x48 == UP Arrow)
                direction = 'w'; // Yonu yukari olarak ayarliyoruz
                break;
            case 's':
            case 0x50:  // Yon tusu asagi (0x50 == DOWN Arrow)
                direction = 's'; // Yonu asagi olarak ayarliyoruz
                break; 
            case 'a':
            case 0x4B:  // Yon tusu sola (0x4B == LEFT Arrow)
                direction = 'a'; // Yonu sol olarak ayarliyoruz
                break;
            case 'd':
            case 0x4D:  // Yon tusu saga (0x4D == RIGHT Arrow)
                direction = 'd'; // Yonu sag olarak ayarliyoruz
                break;
        }
    }
}

//oyunun mantigini kontrol eden fonksiyon
    void SnakeGame::logic() {
      int prevX = snakeBody[0].first; // Yilanin basinin x koordinati
        int prevY = snakeBody[0].second; // Yilanin basinin y koordinati
        int prev2X, prev2Y; // Yilanin vucudunun bir onceki elemanlarinin x ve y koordinatlari
        snakeBody[0].first = x; // Yilanin basinin x koordinatini guncelliyoruz
        snakeBody[0].second = y; //Yilanin basinin y koordinatini guncelliyoruz
        
        // Yilanin hareket yonune gore x ve y koordinatlarini guncelliyoruz
        switch (direction) {
            case 'w': y--; break; // Yon yukari ise y koordinatini bir azaltiyoruz
            case 's': y++; break; // Yon asagi ise y koordinatini bir artiriyoruz
            case 'a': x--; break; // Yon sola ise x koordinatini bir azaltiyoruz
            case 'd': x++; break; // Yon saga ise x koordinatini bir artiriyoruz
        }

        //Yilanin vucudunu guncelliyoruz
        for (size_t i = 1; i < snakeBody.size(); i++) {
            prev2X = snakeBody[i].first; // Yilanin vucudunun bir onceki elemanlarinin x koordinati
            prev2Y = snakeBody[i].second; // Yilanin vucudunun bir onceki elemanlarinin y koordinati
            snakeBody[i].first = prevX; // Yilanin vucudunun x koordinatini guncelliyoruz
            snakeBody[i].second = prevY; // Yilanin vucudunun y koordinatini guncelliyoruz
            prevX = prev2X; // Yilanin vucudunun bir onceki elemanlarinin x koordinatini guncelliyoruz
            prevY = prev2Y; // Yilanin vucudunun bir onceki elemanlarinin y koordinatini guncelliyoruz
        }

        // Nesnelerle etkilesim kontrolu
        for (size_t i = 0; i < objects.size(); i++) {
            if (x == objects[i]->x && y == objects[i]->y) { // Eger yilan nesneye ulastiysa
                objects[i]->interact(score, gameOver, snakeBody, width, height); // Nesneyle etkilesime geciyoruz
                delete objects[i]; // Nesneyi siliyoruz
                objects.erase(objects.begin() + i); // Nesneyi vektorden siliyoruz
                generateGameObjects(); // Yeni nesneleri olusturuyoruz
                break;
            }
        }

        // Duvarlara carpma kontrolu 
        if (x < 0 || x >= width || y < 0 || y >= height) { // Eger yilan duvara carptiysa
            gameOver = true; // Oyunu bitiriyoruz
        } else {
            gameOver = false; // Eger duvara carpilmadiysa oyunu devam ettiriyoruz
        }

        // Kendi kendine carpma kontrolu
        for (size_t i = 1; i < snakeBody.size(); i++) {
            if (snakeBody[i].first == x && snakeBody[i].second == y){ // Eger yilan kendi kendine carptiysa
                gameOver = true; // Oyunu bitiriyoruz
            }
        }
}

    //oyunun bitip bitmedigini kontrol eden fonksiyon
    bool SnakeGame::isGameOver() {
        return gameOver;
    }

    //oyunun calistigi fonksiyon
    void SnakeGame::run() {
        while (!isGameOver()) { // Oyun devam ettigi surece donguyu devam ettiriyoruz
            draw(); // Oyun alanini ciziyoruz
            input(); // Kullanicinin klavyede bastigi tuslari algiliyoruz
            logic(); // Oyunun mantigini kontrol ediyoruz
            Sleep(100); // 100 milisaniye bekleme
        }
        saveScore(); // Skoru dosyaya kaydediyoruz
        std::cout << "Kaybettiniz! Final Skorunuz: " << score << std::endl; // Oyun bittiginde skoru ekrana yazdiriyoruz
    }

