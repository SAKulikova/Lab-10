//Лабораторная работа №10 «Практика по классам»
//Вам даны два объекта, которые связаны между собой. Необходимо создать 2 класса, описывающие эти объекты и принадлежность 2го объекта 1ому.
//Экземпляры классом храните в хипе.
//Провайдер и абоненты.
#include <iostream>
#include <vector>
class Subscriber
{
private:
    unsigned int m_id;
    std::string m_name;
public:
    Subscriber(int id, std::string name)
    {
        m_id = id;
        m_name = name;
    }
    std::string Name()
    {
        return m_name;
    }
};
class Provider{
private :
    unsigned int m_id;
    std::string m_name;
    std::vector<Subscriber*> m_subscribers;
public:
    Provider(int id, std::string name)
    {
        m_id = id;
        m_name = name;
    }

    void AddSubs (Subscriber* subscriber)
    {
        m_subscribers.push_back(subscriber);
    }
    void PrintSubs (){
        for (size_t i=0; i<m_subscribers.size(); i++)
            std::cout<< m_subscribers[i]-> Name()<< std::endl;
    }

};

int main()
{
    Provider* provider1 = new Provider(0, "Ростелеком");
    Provider* provider2 = new Provider(0, "Билайн");
    Provider* provider3 = new Provider(0, "Мегафон");
    provider1 -> PrintSubs();
    provider2 -> PrintSubs();
    provider3 -> PrintSubs();
    Subscriber* subscriber1 = new Subscriber(0,"Иванов Иван Иванович");
    Subscriber* subscriber2 = new Subscriber(0,"Николаева Валерия Романовна");
    Subscriber* subscriber3 = new Subscriber(0,"Уткина Владислава Всеволодовна");
    Subscriber* subscriber4 = new Subscriber(0,"Новиков Марк Олегович");
    Subscriber* subscriber5 = new Subscriber(0,"Зайцева Екатерина Вадимовна");
    provider1 -> AddSubs(subscriber1);
    provider1 -> AddSubs(subscriber5);
    provider2 -> AddSubs(subscriber3);
    provider3 -> AddSubs(subscriber2);
    provider3 -> AddSubs(subscriber4);
    provider1 -> PrintSubs();


    delete provider1;
    delete provider2;
    delete provider3;
    return 0;
}
