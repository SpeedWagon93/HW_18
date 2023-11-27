#include <iostream>
#include <string>



class Building
{
    private:

        static int s_idGenerator;
        int m_id;
        std::string m_Address;
        int m_Square;
        int m_numberOfRooms;


    public:

        Building(int ID = 0, std::string Address = "", int Square = 0, int NumberOfRooms = 0){m_id = ID; m_Address = Address; m_Square = Square; m_numberOfRooms = NumberOfRooms;}

        Building(std::string Address, int Square, int NumberOfRooms);

        void GetInfo()
        {
            std::cout << std::endl << "Адрес: " << m_Address << " " << "Общая площадь: " << m_Square << " " << "Количество комнат: " << m_numberOfRooms;
        }

        int GetSquare(){return m_Square;}
        std::string GetAddress(){return m_Address;}


};
int Building::s_idGenerator = 1;
Building* array = new Building[1];
Building* array2 = new Building[1];
int BuildingsQuantity;

Building::Building(std::string Address, int Square, int NumberOfRooms)
        {
            m_id = s_idGenerator++; 
            m_Address = Address; 
            m_Square = Square; 
            m_numberOfRooms = NumberOfRooms;
            for(int i = 0; i < m_id - 1; i++)
            {
                array2[i] = array[i];
            }

            array = new Building[m_id];

            for(int i = 0; i < m_id - 1; i++)
            {
                array[i] = array2[i];
            }
            array2 = new Building[m_id];
            array[m_id - 1] = *this;
            BuildingsQuantity = m_id;
        }





class Townhouse : public Building
{

    private:
        int m_numberOfFloors;

    public:
        Townhouse(std::string Address, int Square, int NumberOfRooms, int NumberOfFloors):Building(Address, Square, NumberOfRooms){m_numberOfFloors = NumberOfFloors;}

        void GetInfo()
        {
            Building::GetInfo();
            std::cout << " " << "Количество этажей: " <<  m_numberOfFloors << std::endl;
        }

};


class Apartment : public Building
{

    private:
    int m_Floor;

    public:
    Apartment(std::string Address, int Square, int NumberOfRooms, int Floor):Building(Address, Square, NumberOfRooms){m_Floor = Floor;}
    void GetInfo()
        {
            Building::GetInfo();
            std::cout << " " << "Этаж: " <<  m_Floor << std::endl;
        }
};


void MaxSquare(Building* Array, int Quantity)
{
    int MaxSquareID = 0;
    for(int i = 0; i < Quantity; i++)
    {
        if(Array[i].GetSquare() > Array[MaxSquareID].GetSquare())
        MaxSquareID = i;
    }
    std::cout << std::endl <<  "Максимальная площадь доступной недвижимости: " << Array[MaxSquareID].GetSquare() << std::endl << "Адрес недвижимости с максимальной площадью: " << Array[MaxSquareID].GetAddress() << std::endl;
}

int main()
{
    Townhouse townhouse("Plochad Lenina", 256, 6, 3);
    Apartment apartment("Shotmana", 40, 2, 5);
    Townhouse townhouse2("Beloostorv", 421, 8, 3);
    Apartment luxApartment("Krasnaya Ploshad", 1000, 50, 1);
    Townhouse townhouse3("Plochad Zhukova", 156, 4, 2);
    

    townhouse.GetInfo(); // информация об объекте типа "таунхаус"
    apartment.GetInfo(); // информация об объекте типа "квартира"

    array[0].GetInfo(); // информация об объекте типа "строение", взятая из массива всех строений в "базе данных"
    array[1].GetInfo();
    array[2].GetInfo();
    array[3].GetInfo();
    array[4].GetInfo();
    MaxSquare(array, BuildingsQuantity); // Вывод некоторой информации о строении с самой большой площадью, среди имеющихся в "базе данных"
}