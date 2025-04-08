#include <string>
#include <vector>
#include <iostream>

class Image {
private:
    std::vector<char> data;
    int width;
    int height;
    
public:
    Image(int width, int height) : width(width), height(height) {
        std::cout << "Создано изображение размером " << width << "x" << height << std::endl;
    }
    
    int getWidth() const { return width; }
    int getHeight() const { return height; }
    std::vector<char>& getData() { return data; }
    const std::vector<char>& getData() const { return data; }
};

class Url {
private:
    std::string url;
    
public:
    Url(const std::string& url) : url(url) {
        std::cout << "Создан URL: " << url << std::endl;
    }
    std::string getUrl() const { return url; }
};

class Account {
private:
    int id;
    std::string username;
    
public:
    Account(int id, const std::string& username) : id(id), username(username) {
        std::cout << "Создан аккаунт: " << username << " (id: " << id << ")" << std::endl;
    }
    int getId() const { return id; }
    std::string getUsername() const { return username; }
};

class ImageFileManager {
public:
    static void Save(const Image& image, const std::string& path) {
        std::cout << "Файловая система: Сохранение изображения " 
                << image.getWidth() << "x" << image.getHeight() 
                << " в файл '" << path << "'" << std::endl;
    }
    
    static int DeleteDuplicates(const std::string& directory) {
        int count = 3;
        std::cout << "Файловая система: Удаление дубликатов в директории '" 
                << directory << "', удалено " << count << " файлов" << std::endl;
        return count;
    }
};

class ImageProcessor {
public:
    static Image Resize(const Image& image, int height, int width) {
        std::cout << "Процессор изображений: Изменение размера с " 
                << image.getWidth() << "x" << image.getHeight() 
                << " на " << width << "x" << height << std::endl;
        
        Image resized(width, height);
        return resized;
    }
    
    static Image InvertColors(const Image& image) {
        std::cout << "Процессор изображений: Инвертирование цветов изображения " 
                << image.getWidth() << "x" << image.getHeight() << std::endl;
        
        Image inverted(image.getWidth(), image.getHeight());
        return inverted;
    }
};

class AccountImageRepository {
public:
    static void SetImageAsAccountPicture(const Image& image, const Account& account) {
        std::cout << "База данных: Установка изображения " 
                << image.getWidth() << "x" << image.getHeight() 
                << " как аватара для пользователя " 
                << account.getUsername() << std::endl;
    }
    
    static Image GetAccountPicture(const Account& account) {
        std::cout << "База данных: Получение аватара для пользователя " 
                << account.getUsername() << std::endl;
        
        return Image(100, 100);
    }
};

class ImageDownloader {
public:
    static std::vector<char> Download(const Url& imageUrl) {
        std::cout << "Сеть: Загрузка данных изображения с URL: " 
                << imageUrl.getUrl() << std::endl;
        
        std::vector<char> data;
        return data;
    }
    
};

int main() {    
    std::cout << "1. Работа с сетью:" << std::endl;
    Url imageUrl("https://example.com/image.jpg");
    std::vector<char> downloadedImage = ImageDownloader::Download(imageUrl);
    std::cout << std::endl;
    
    Image image(100, 100);
    std::cout << "2. Обработка изображения:" << std::endl;
    Image resizedImage = ImageProcessor::Resize(image, 200, 300);
    Image invertedImage = ImageProcessor::InvertColors(resizedImage);
    std::cout << std::endl;
    
    std::cout << "3. Работа с файловой системой:" << std::endl;
    ImageFileManager::Save(invertedImage, "processed_image.jpg");
    ImageFileManager::DeleteDuplicates("/images/directory");
    std::cout << std::endl;
    
    std::cout << "4. Работа с базой данных:" << std::endl;
    Account userAccount(1, "username");
    AccountImageRepository::SetImageAsAccountPicture(invertedImage, userAccount);
    Image profilePicture = AccountImageRepository::GetAccountPicture(userAccount);
    
    return 0;
}