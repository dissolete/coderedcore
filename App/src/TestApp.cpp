/**
* ############################################################
* # THIS IS A TEST FILE - IT DOES NOT DEMONSTRATE FULL USAGE #
* # OF THE ENGINE. IT ONLY DEMONSTRATES NEW ITEMS THAT ARE   #
* # BEING TESTED BY THE CR TEAM.                             #
* #                                                          #
* #          MAY THE CODING GODS BLESS THIS CODE!            #
* ############################################################
*/


#include "TestApp.hpp"

TestApp::TestApp(const std::string theTitle, int windowWidth, int windowHeight) :
    CRE::App(theTitle, windowWidth, windowHeight)
{}

TestApp::~TestApp()
{}

void TestApp::init_asset_handlers(void)
{
    //_textManager.set_font("resources/cour.ttf");
}

void TestApp::init_screen_factory(void)
{

    _window.setKeyRepeatEnabled(false);

    // Add game states here
    _stateManager.add_active_state(new(std::nothrow) TestState("TestState", *this));
    _stateManager.add_active_state(new(std::nothrow) CRE::SplashState(*this));
}

void TestApp::handle_cleanup()
{
    // Destroy anything that was allocated in this class here
}