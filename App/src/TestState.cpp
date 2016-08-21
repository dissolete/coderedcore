/**
* ############################################################
* # THIS IS A TEST FILE - IT DOES NOT DEMONSTRATE FULL USAGE #
* # OF THE ENGINE. IT ONLY DEMONSTRATES NEW ITEMS THAT ARE   #
* # BEING TESTED BY THE CR TEAM.                             #
* #                                                          #
* #          MAY THE CODING GODS BLESS THIS CODE!            #
* ############################################################
*/

#include "TestState.hpp"

TestState::TestState(std::string stateID, CRE::App & theApp):
    CRE::State(stateID, theApp),
    testTileMap("TestMap", "Resources/TileMaps/untitled2.tmx")
{}

TestState::~TestState()
{}

void TestState::init()
{
    // // Initialize parent state
     CRE::State::init();
     testTileMap.load_data();

     testEntity = new CRE::Entity("Test");

     testEntity->_properties.add<int>("HP", 10);
     testEntity->_properties.add<sf::Sprite>("Sprite", sf::Sprite());
     testEntity->_properties.add< std::vector<int> >("Vector", std::vector<int>());


    // testTileMap = new CRE::TileMap("TestMap", "Resources/TileMaps/tileMap2.tmx");
    // testTileMap->load_data();
    // //if( testTileMap->load_tile_data("Resources/TileMaps/tileMap1.txt") )
    // //    std::cout << "Map loaded\n";

}

void TestState::reinit()
{}

void TestState::pause()
{
    // Pause parent state
    CRE::State::pause();
}

void TestState::resume()
{
    // Resume parent state
    CRE::State::resume();
}

void TestState::handle_events(sf::Event theEvent)
{
    if( theEvent.type == sf::Event::MouseButtonPressed )
    {
        std::cout << "Entity " << testEntity->get_ID() << " has order "
            << testEntity->get_order() << std::endl;

        auto entityVector = testEntity->_properties.get< std::vector<int> >("Vector");

        // std::cout << "Mouse click" << std::endl;

        // if(testTileMap.is_loaded())
        // {
        //     std::cout << "The TileMap is loaded." << std::endl;
        //     for(CRE::Layer layer : testTileMap._layers)
        //     {
        //         std::cout << layer.get_name() << std::endl;
        //     }
        // }
        // else
        // {
        //     std::cout << "The TileMap is not loaded." << std::endl;
        // }

        // std::cout << "The error message is: " << testTileMap.get_error() << std::endl;

        // for( CRE::Layer layer : testTileMap._layers )
        // {
        //     std::cout << layer.get_name() << std::endl;
        // }
        // std::cout << "The tile map is loaded: " << testTileMap->is_loaded() << std::endl;
        // std::cout << "The error message is: " << testTileMap->get_error() << std::endl;
        // std::cout << "Here is the data: " << std::endl;

        // testTileMap->parse_data();

        // std::cout << testTileMap->get_width_pixel() << std::endl;
        // std::cout << testTileMap->get_height_pixel() << std::endl;
        // std::cout << testTileMap->get_width_tiles() << std::endl;
        // std::cout << testTileMap->get_height_tiles() << std::endl;
        // std::cout << testTileMap->get_tile_width() << std::endl;
        // std::cout << testTileMap->get_tile_height() << std::endl;


    }
}

void TestState::update(void)
{}

void TestState::update_variable(float elapsedTime)
{}

void TestState::draw(void)
{
    _theApp._window.clear(sf::Color::Black);
    testTileMap.draw_layers(0, 0, _theApp._window);

}

void TestState::handle_cleanup(void)
{
    delete testEntity;
    // std::cout << "TestState::handle_cleanup() -\n";
    // delete testTileMap;
    // testTileMap = NULL;
}
