/**
* ############################################################
* # THIS IS A TEST FILE - IT DOES NOT DEMONSTRATE FULL USAGE #
* # OF THE ENGINE. IT ONLY DEMONSTRATES NEW ITEMS THAT ARE   #
* # BEING TESTED BY THE CR TEAM.                             #
* #                                                          #
* #          MAY THE CODING GODS BLESS THIS CODE!            #
* ############################################################
*/

#ifndef TESTAPP_HPP
#define TESTAPP_HPP

#include "CRApp.hpp"
#include "SplashState.hpp"
#include "TestState.hpp"

class TestApp : public CRE::App
{
    public:
        /**
        *
        */
        TestApp(const std::string theTitle = "Test by Code Red",
            int windowWidth = 800, int windowHeight = 600);

        /**
        *
        */
        virtual ~TestApp();

    protected:
        /**
        *
        */
        virtual void init_asset_handlers(void);

        /**
        *
        */
        virtual void init_screen_factory(void);

        /**
        *
        */
        virtual void handle_cleanup(void);

    private:
};

#endif
