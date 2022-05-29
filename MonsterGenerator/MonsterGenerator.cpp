#include <iostream>
#include <string>

enum MonsterType
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

class Monster
{
private:
    MonsterType m_type{};
    std::string m_name{};
    std::string m_roar{};
    int m_hitPoints{};

};

int main()
{
    std::cout << "Hello World!\n";
}

