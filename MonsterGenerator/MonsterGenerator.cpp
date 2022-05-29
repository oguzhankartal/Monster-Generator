#include <array>
#include <ctime> // for time()
#include <cstdlib> // for rand() and srand()
#include <iostream>
#include <string>
#include <string_view>


class Monster
{
public:
    enum class Type
    {
        dragon,
        goblin,
        ogre,
        orc,
        skeleton,
        troll,
        vampire,
        zombie,

        max_monster_types
    };

private:
    Type m_type{};
    std::string m_name{};
    std::string m_roar{};
    int m_hitPoints{};

public:

    Monster(Type type, std::string name, std::string roar, int hitPoints) 
        : m_type{ type }, m_name{ name }, m_roar{ roar }, m_hitPoints{ hitPoints }
    {

    }

    std::string_view getTypeString() const
    {
        switch (m_type)
        {
        case Type::dragon: return "dragon";
        case Type::goblin: return "goblin";
        case Type::ogre: return "ogre";
        case Type::orc: return "orc";
        case Type::skeleton: return "skeleton";
        case Type::troll: return "troll";
        case Type::vampire: return "vampire";
        case Type::zombie: return "zombie";
        default: return "???";
        }
    }

    void print() const
    {
        std::cout << m_name << " the " << getTypeString() << " has " << m_hitPoints << " hit points and says " << m_roar << '\n';
    }

};

class MonsterGenerator
{
public:

    static int getRandomNumber(int min, int max)
    {
        static constexpr double fraction{ 1.0 / (RAND_MAX + 1.0) };  // static used for efficiency, so we only calculate this value once
        // evenly distribute the random number across our range
        return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
    }

    static Monster generateMonster()
    {
        auto type{ static_cast<Monster::Type> (getRandomNumber(0, static_cast<int>(Monster::Type::max_monster_types) - 1)) };
        int hitPoints{ getRandomNumber(1,100) };

        static constexpr std::array s_names { "Miss", "Meg", "Ngu", "Faker", "Tino", "Sud" };
        static constexpr std::array s_roars{ "*ROAR*", "*peep*", "*squeal*", "*whine*", "*hum*", "*burp*" };

        auto name{ s_names[getRandomNumber(0, static_cast<int>(s_names.size() - 1))] };
        auto roar{ s_roars[getRandomNumber(0, static_cast<int>(s_roars.size() - 1))] };

        return { type, name, roar, hitPoints };
    }
};

int main()
{
    Monster m{ MonsterGenerator::generateMonster() };
    
    m.print();

    return 0;
}

