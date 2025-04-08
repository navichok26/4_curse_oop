#include <iostream>
#include <memory>

class AbstractEntity {
public:
    virtual ~AbstractEntity() {}
};

class AccountEntity : public AbstractEntity {
public:
    AccountEntity() { std::cout << "AccountEntity создан" << std::endl; }
};

class RoleEntity : public AbstractEntity {
public:
    RoleEntity() { std::cout << "RoleEntity создан" << std::endl; }
};

class IRepository {
public:
    virtual void Save(std::shared_ptr<AbstractEntity> entity) = 0;
    virtual ~IRepository() {}
};

class AccountRepository : public IRepository {
public:
    void Save(std::shared_ptr<AbstractEntity> entity) override {
        if (std::dynamic_pointer_cast<AccountEntity>(entity)) {
            std::cout << "AccountRepository: сохранение AccountEntity" << std::endl;
        } else {
            std::cout << "AccountRepository: неверный тип сущности" << std::endl;
        }
    }
};

class RoleRepository : public IRepository {
public:
    void Save(std::shared_ptr<AbstractEntity> entity) override {
        if (std::dynamic_pointer_cast<RoleEntity>(entity)) {
            std::cout << "RoleRepository: сохранение RoleEntity" << std::endl;
        } else {
            std::cout << "RoleRepository: неверный тип сущности" << std::endl;
        }
    }
};

int main() {
    auto accountEntity = std::make_shared<AccountEntity>();
    auto roleEntity = std::make_shared<RoleEntity>();
    
    std::shared_ptr<IRepository> accountRepo = std::make_shared<AccountRepository>();
    std::shared_ptr<IRepository> roleRepo = std::make_shared<RoleRepository>();

    accountRepo->Save(accountEntity);
    roleRepo->Save(roleEntity);

    accountRepo->Save(roleEntity);
    roleRepo->Save(accountEntity);

    return 0;
}