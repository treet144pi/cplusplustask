#include <iostream>
#include <string>
using namespace std;

/*
* Абстрактные классы
* Чисто виртуальные функции
* virtual
* override
*/
/*
если не переопределить чисто виртуальную функцию в производном классе
то этот наследник станет тоже абстрактным и нельзя
создавать его обьекты
благодаря виртуальным функциям  поведение определяется типом обьекта а не типом указателя
*/
class Weapon
{
public:
virtual void Shoot() = 0;

};

class Gun : public Weapon
{
public:
void Shoot() override
{
cout << "BANG!" << endl;
}
};

class SubmachineGun :public Gun
{
public:
void Shoot() override
{
cout << "BANG! BANG! BANG!" << endl;
}
};

class Bazooka :public Weapon
{
public:
void Shoot() override
{
cout << "BADABUB!!!" << endl;
}
};

class Knife :public Weapon
{
public:
void Shoot() override
{
cout << "VJUH!!!" << endl;
}

};

/*
благодаря виртуальны м функциям мы можем если мы имеем указатель на базовый класс то мы
имеем поведение классов наследников
через указатель на базовый класс можно работать
с методами производных классов
Также указатель на базовый класс может быть присвоен адрес наследника этого класса(указатель на базовый клас может хранить адрес обьекта производного класса)
Также еще одно свойство на абстрактный класс мы не можем создать обьект но можем создать указатель
*/
class Player
{
public:
void Shoot(Weapon *weapon)
{
weapon->Shoot(); // полиморфизм
}
};

int main()
{
setlocale(LC_ALL, "ru");

Gun gun;

SubmachineGun machinegun;

Bazooka bazooka;

Knife knife;

Player player;
player.Shoot(&knife);

return 0;
}
