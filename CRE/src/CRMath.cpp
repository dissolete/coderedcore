#include "CRMath.hpp"

/* 
I love this comment about C++ styled casts.

"Casts are inherently ugly -- you as a programmer are overruling how the compiler 
would ordinarily treat your code. You are saying to the compiler, "I know better 
than you." That being the case, it makes sense that performing a cast should be 
a moderately painful thing to do, and that they should stick out in your code, 
since they are a likely source of problems." 
*/

namespace CRE
{

    ////////////////////////////////////////////////////////////////////////////

    ///////////////////////
    /* Random generation */
    ///////////////////////

    void set_seed(uint32_t theSeed)
    {
        srand(theSeed);
    }

    float random(float min, float max)
    {
        return static_cast<double>(rand()) / RAND_MAX * max + min;
    }


    int random(int min, int max)
    {
        return static_cast<double>(rand()) / RAND_MAX * max + min;
    }


    uint32_t random(uint32_t min, uint32_t max)
    {
        return static_cast<double>(rand()) / RAND_MAX * max + min;
    }

    ////////////////////////////////////////////////////////////////////////////

    /////////////////////////
    /* Vector manipulation */
    /////////////////////////

    float dot_product(sf::Vector2f vectorA, sf::Vector2f vectorB)
    {
        return vectorA.x * vectorB.x + vectorA.y * vectorB.y;
    }

    sf::Vector2f normalize_vector(sf::Vector2f theVector)
    {
        float magnitude = sqrt( (theVector.x * theVector.x) + (theVector.y * theVector.y) );
        sf::Vector2f normal = sf::Vector2f( theVector.x / magnitude, theVector.y / magnitude );
        return normal;
    }

    sf::Vector2f vector_between_points(const sf::Vector2f & vectorOne, const sf::Vector2f & vectorTwo)
    {
        sf::Vector2f parallelVector(vectorTwo.x - vectorOne.x, vectorTwo.y - vectorOne.y);
        return parallelVector;
    }

    ////////////////////////////////////////////////////////////////////////////

    //////////////////////////
    /* Trigonometry helpers */
    //////////////////////////

    float to_degrees(float radians)
    {
        return radians * 180 / PI;
    }

    float to_radians(float degrees)
    {
        return degrees * PI / 180;
    }
}