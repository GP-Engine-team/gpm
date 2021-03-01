#include "Random.hpp"

void initSeed()
{
    std::srand(time(NULL));
}

void initSeed(float seed)
{
    srand(seed);
}

template<typename T = float> 
auto unitValue() -> std::enable_if_t<std::is_floating_point<T>::value, T>
{
    return static_cast <T> (rand()) / static_cast <T> (RAND_MAX);
} 

template<typename T = int> 
auto unitValue() -> std::enable_if_t<std::is_integral<T>::value, T>
{
    return static_cast<T>(rand() % static_cast<T>(2));
}

template<typename T = float>
auto ranged(const T& max) -> std::enable_if_t<std::is_floating_point<T>::value, T>
{
    return max <= std::numeric_limits<T>::epsilon() ? static_cast<T>(0) : static_cast <T> (rand()) / (static_cast <T> (RAND_MAX / max));
}

template<typename T = int>
auto ranged(const T& max) -> std::enable_if_t<std::is_integral<T>::value, T>
{
    return max <= std::numeric_limits<T>::epsilon() ? static_cast<T>(0) : ranged<T>(0, max);
}

template<typename T>
auto ranged(const T& min, const T& max)  -> std::enable_if_t<std::is_floating_point<T>::value, T>
{
    return max - min <= std::numeric_limits<T>::epsilon() ? max : min + static_cast <T> (rand()) /( static_cast <T> (RAND_MAX/(max - min)));
}

template<typename T>
auto ranged(const T& min, const T& max) -> std::enable_if_t<std::is_integral<T>::value, T>
{
    return max - min <= std::numeric_limits<T>::epsilon() ? max : min + static_cast <T> (rand()) / (static_cast <T> (RAND_MAX/((max + static_cast<T>(1)) - min)));
}

Vec2 circularCoordinate(const Vec2& center, float range)
{
    float randValue = static_cast<float>(rand());
    float scale = unitValue<float>();
    return Vec2{center.x + range * std::cos(randValue) * scale, center.y + range * std::sin(randValue) * scale};
}

Vec2 peripheralCircularCoordinate(const Vec2& center, float range)
{
    float randValue = static_cast<float>(rand());
    return Vec2{center.x + range * std::cos(randValue), center.y + range * std::sin(randValue)};
}

Vec2 unitPeripheralCircularCoordinate()
{
    float randValue = static_cast<float>(rand());
    return Vec2{std::cos(randValue), std::sin(randValue)};
}

Vec3 unitPeripheralSphericalCoordonate()
{
    float phi   = ranged<float>(0.f, TWO_PI);
    float theta = ranged<float>(0.f, TWO_PI);
    return Vec3{std::sin(phi) * std::cos(theta), std::sin(phi) * std::sin(theta), std::cos(phi)};
}

Vec3 sphericalCoordinate(const Vec3& center, float range)
{
    return (center + unitPeripheralSphericalCoordonate()) * unitValue<float>() * range;
}

Vec3 peripheralSphericalCoordinate(const Vec3& center, float range)
{
    return (center + unitPeripheralSphericalCoordonate()) * range;
}

Vec2 peripheralSquareCoordinate(const Vec2& center, float extX, float extY)
{           
    if (unitValue<bool>())
    {
        if (unitValue<bool>())
        {
            return Vec2{center.x -extX, center.y + ranged<float>(-extY, extY)};
        }
        return Vec2{center.x + extX, center.y + ranged<float>(-extY, extY)};
    }

    if (unitValue<bool>())
    {
        return Vec2{center.x + ranged<float>(-extX, extX), center.y - extY};
    }
    return Vec2{center.x + ranged<float>(-extX, extX), center.y + extY};
}

Vec2 squareCoordinate(const Vec2& center, float extX, float extY)
{           
    return Vec2{center.x + ranged<float>(-extX, extX), center.y + ranged<float>(-extY, extY)};
}

Vec2 unitPeripheralSquareCoordinate()
{
    return Vec2{unitValue<float>(), unitValue<float>()};
}       

Vec3 peripheralCubiqueCoordinate(const Vec3& center, float extX, float extY, float extZ)
{    
    if (unitValue<bool>())
    {
        if (unitValue<bool>())
        {
            return Vec3{center.x -extX, center.y + ranged<float>(-extY, extY), center.z + ranged<float>(-extZ, extZ)};
        }
        return Vec3{center.x + extX, center.y + ranged<float>(-extY, extY), center.z + ranged<float>(-extZ, extZ)};
    }

    if (unitValue<bool>())
    {
        if (unitValue<bool>())
        {
            return Vec3{center.x + ranged<float>(-extX, extX), center.y -extY, center.z + ranged<float>(-extZ, extZ)};
        }
        return Vec3{center.x + ranged<float>(-extX, extX), center.y + extY, center.z + ranged<float>(-extZ, extZ)};
    }

    if (unitValue<bool>())
    {
        return Vec3{center.x + ranged<float>(-extX, extX), center.y + ranged<float>(-extY, extY), center.z -extZ};
    }
    return Vec3{center.x + ranged<float>(-extX, extX), center.y + ranged<float>(-extY, extY), center.z + extZ};
}


Vec3 cubiqueCoordinate(const Vec3& center, float extX, float extY, float extZ)
{           
    return Vec3{center.x + ranged<float>(-extX, extX), center.y + ranged<float>(-extY, extY), center.z + ranged<float>(-extZ, extZ)};
}

Vec3 unitPeripheralCubiqueCoordinate()
{
    return Vec3{unitValue<float>(), unitValue<float>(), unitValue<float>()};
}

bool ranPercentProba(float percent)
{ 
    return ranged<float>(0.f, 100.f) <= percent;
}