#include <iostream>
#include <memory>
#include <string>

class IProductValidator {
public:
    virtual bool Validate(int price) = 0;
    virtual ~IProductValidator() {}
};

class DefaultProductValidator : public IProductValidator {
public:
    bool Validate(int price) override {
        std::cout << "DefaultProductValidator: проверка цены > 0" << std::endl;
        return price > 0;
    }
};

class CustomerServiceProductValidator : public IProductValidator {
public:
    bool Validate(int price) override {
        std::cout << "CustomerServiceProductValidator: проверка цены > 100000" << std::endl;
        return price > 100000;
    }
};

class Product {
public:
    int price;
    
    bool IsValid(std::shared_ptr<IProductValidator> validator) {
        if (!validator) {
            std::cout << "Ошибка: валидатор не задан." << std::endl;
            return false;
        }
        return validator->Validate(price);
    }
};

int main() {
    Product prod;
    prod.price = 150000;
    std::cout << "Prod price: " << prod.price << std::endl;

    std::shared_ptr<IProductValidator> defaultValidator = std::make_shared<DefaultProductValidator>();
    std::cout << "Валидация с DefaultProductValidator" << std::endl;
    bool resultDefault = prod.IsValid(defaultValidator);
    std::cout << "Результат валидации: " << (resultDefault ? "валидно" : "невалидно") << std::endl << std::endl;

    std::shared_ptr<IProductValidator> customerServiceValidator = std::make_shared<CustomerServiceProductValidator>();
    std::cout << "Валидация с CustomerServiceProductValidator" << std::endl;
    bool resultCustomerService = prod.IsValid(customerServiceValidator);
    std::cout << "Результат валидации: " << (resultCustomerService ? "валидно" : "невалидно") << std::endl << std::endl;

    prod.price = 100;
    std::cout << "Prod price: " << prod.price << std::endl;

    std::cout << "Валидация с DefaultProductValidator" << std::endl;
    resultDefault = prod.IsValid(defaultValidator);
    std::cout << "Результат валидации: " << (resultDefault ? "валидно" : "невалидно") << std::endl << std::endl;

    std::cout << "Валидация с CustomerServiceProductValidator" << std::endl;
    resultCustomerService = prod.IsValid(customerServiceValidator);
    std::cout << "Результат валидации: " << (resultCustomerService ? "валидно" : "невалидно") << std::endl;


    return 0;
}