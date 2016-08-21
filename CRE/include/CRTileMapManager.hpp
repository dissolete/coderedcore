#ifndef CRTILEMAPMANAGER_HPP
#define CRTILEMAPMANAGER_HPP

#include "CRTypes.hpp"
#include "CRTileMap2.hpp"

namespace CRE
{
    class TileMapManager
    {
        public:

            /**
            *
            */
            TileMapManager();

            /**
            *
            */
            ~TileMapManager();

            /**
            * Loads in a new tilemap and logs if there was a failure.
            */
            void load_new_tilemap(std::string tileMapName, std::string tileMapLocation);

            /**
            *
            */
            void set_active(std::string tileMapName);

            /**
            *
            */
            TileMap& get_tilemap(std::string tileMapName);

            /**
            *
            */
            TileMap& get_active();

        private:

            /// Map stores all of the tilemaps loaded into the game
            std::map<std::string, TileMap*> _tilemaps;

            /// This is the tilemap that gets rendered to the screen
            TileMap * _activeMap;
    };
}

#endif
