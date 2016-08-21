#include "CRTileMapManager.hpp"

namespace CRE
{
    TileMapManager::TileMapManager():
        _tilemaps(),
        _activeMap(NULL)
    {
    }

    TileMapManager::~TileMapManager()
    {
        // Properly cleanup all tilemaps in this manager
        for(auto it = _tilemaps.begin(); it != _tilemaps.end(); ++it)
        {
            // Get a reference to this Tilemap
            TileMap * aTileMap = it->second;

            // Remove the pair from the map
            _tilemaps.erase(it);

            // Delete the tilemap
            delete aTileMap;

            // Remove local pointer
            aTileMap = NULL;
        }
    }

    void TileMapManager::load_new_tilemap(std::string tileMapName, std::string tileMapLocation)
    {
        // Check if the tileMap doesn't exist already
        if( _tilemaps.find(tileMapName) == _tilemaps.end())
        {
            // Create new tilemap object
            TileMap * newTileMap = new(std::nothrow) TileMap(tileMapName,
                                                            tileMapLocation);
            // Load in the data
            newTileMap->load_data();

            // Check if the tilemap loaded correctly
            if( not newTileMap->is_loaded() )
            {
                // TODO: Log that the tilemap was not loaded correctly
            }
            else
            {
                // Set active tilemap to this new tilemap
                _activeMap = newTileMap;
            }
        }
        else
        {
            // TODO: Log that the tilemap already exists
        }
    }

    void TileMapManager::set_active(std::string tileMapName)
    {
        // Check if the tilemap exists
        if( _tilemaps.find(tileMapName) != _tilemaps.end() )
        {
            _activeMap = _tilemaps.at(tileMapName);
        }
        else
        {
            // TODO: Log that the tileMap could not be found
        }
    }

    TileMap& TileMapManager::get_tilemap(std::string tileMapName)
    {
        // TODO: What to do if the tilemap doesn't exist?
        return *(_tilemaps.at(tileMapName));
    }

    TileMap& TileMapManager::get_active()
    {
        // TODO: What to do if there are no tilemaps?
        return *_activeMap;
    }
}
