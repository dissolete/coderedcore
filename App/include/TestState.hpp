/**
* ############################################################
* # THIS IS A TEST FILE - IT DOES NOT DEMONSTRATE FULL USAGE #
* # OF THE ENGINE. IT ONLY DEMONSTRATES NEW ITEMS THAT ARE   #
* # BEING TESTED BY THE CR TEAM.                             #
* #                                                          #
* #          MAY THE CODING GODS BLESS THIS CODE!            #
* ############################################################
*/

#ifndef TESTSTATE_HPP
#define TESTSTATE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>
#include <iostream> //for testing purposes and debugging
#include "TestApp.hpp"
#include "CRState.hpp"
#include "CRTypes.hpp"
#include "CRConstants.hpp"
#include "CRTileMap2.hpp"
#include "CREntity2.hpp"

class TestState : public CRE::State
{
    public:

        /**
        *
        */
        TestState(std::string stateID, CRE::App & theApp);

        /**
        *
        */
        virtual ~TestState();

        /**
        *
        */
        virtual void init();

        /**
        *
        */
        virtual void reinit();

        /**
        *
        */
        virtual void pause();

        /**
        *
        */
        virtual void resume();

        /**
        *
        */
        virtual void handle_events(sf::Event theEvent);

        /**
        *
        */
        virtual void update(void);

        /**
        *
        */
        virtual void update_variable(float elapsedTime);

        /**
        *
        */
        virtual void draw(void);

    protected:

        /**
        *
        */
        virtual void handle_cleanup(void);

    private:
        CRE::TileMap testTileMap;
        CRE::Entity * testEntity;
};

#endif
