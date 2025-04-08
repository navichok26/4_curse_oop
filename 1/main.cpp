#include <iostream>
#include <string>

class IProductValidator {
public:
    virtual bool Validate(int price) const = 0;
    virtual ~IProductValidator() {}
};

class DefaultProductValidator : public IProductValidator {
public:
    bool Validate(int price) const override {
        std::cout << "DefaultProductValidator: проверка цены > 0" << std::endl;
        return price > 0;
    }
};

class CustomerServiceProductValidator : public IProductValidator {
public:
    bool Validate(int price) const override {
        std::cout << "CustomerServiceProductValidator: проверка цены > 100000" << std::endl;
        return price > 100000;
    }
};

class Product {
public:
    int price;
    
    bool IsValid(const IProductValidator& validator) {
        return validator.Validate(price);
    }
};

int main() {
    Product prod;
    prod.price = 150000;
    std::cout << "Prod price: " << prod.price << std::endl;

    DefaultProductValidator defaultValidator;
    std::cout << "Валидация с DefaultProductValidator" << std::endl;
    bool resultDefault = prod.IsValid(defaultValidator);
    std::cout << "Результат валидации: " << (resultDefault ? "валидно" : "невалидно") << std::endl << std::endl;

    CustomerServiceProductValidator customerServiceValidator;
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