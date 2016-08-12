#include "CRTileMap2.hpp"

namespace CRE
{
    Layer::Layer() :
        _gidCodes(),
        //_tileSets(),
        _verticies(),
        _dimensions(),
        _layerName()
    {}

    void Layer::parse_raw_layer_data(std::string rawData)
    {
        std::stringstream ss(rawData);
        std::string number;

        while(std::getline(ss, number, ','))
        { 
            // Some of these resulting strings have endline chars. Remove them.
            number.erase(std::remove(number.begin(), number.end(), '\n'), number.end());
            
            // Convert the string into an int and add it to the vector
            _gidCodes.push_back(std::stoi(number));
        }

        stitch_layer();
    }

    int Layer::get_width() const
    {
        return _dimensions.x;
    }

    int Layer::get_height() const
    {
        return _dimensions.y;
    }

    std::string Layer::get_name() const
    {
        return _layerName;
    }

    void Layer::set_width(int newWidth)
    {
        if( newWidth > 0 ) _dimensions.x = newWidth;
    }

    void Layer::set_height(int newHeight)
    {
        if( newHeight > 0) _dimensions.y = newHeight;
    }

    void Layer::set_tileset(TileSet newTileSet)
    {
        _tileSet = newTileSet;
    }

    void Layer::set_name(std::string newName)
    {
        _layerName = newName;
    }

    // TileSet& Layer::get_tileset_with_gid(int gid)
    // {
    //     for(auto it = _tileSets.begin(); it != _tileSets.end(); ++it)
    //     {
    //         //auto nx = std::next(it, 1);
    //         if(gid >= it->_firstGid and gid < it->_firstGid + it->_tileCount)
    //         {
    //             // We found the correct tileset, so return it
    //             return *it;
    //         }

    //     }
    // }

    void Layer::stitch_layer()
    {
        // Resize the vertex array to fit the layer size
        _verticies.setPrimitiveType(sf::Quads);
        _verticies.resize(_dimensions.x * _dimensions.y * 4);

        for(unsigned int i = 0; i < _dimensions.x; ++i)
            for(unsigned int j = 0; j < _dimensions.y; ++j)
            {
                int gid = _gidCodes[i + j * _dimensions.x] - 1;

                int tu = gid % (_tileSet._imageWidth / _tileSet._tileWidth);
                int tv = gid / (_tileSet._imageWidth / _tileSet._tileWidth);

                sf::Vertex * quad = &_verticies[(i + j * _dimensions.x) * 4];

                // define its 4 corners
                quad[0].position = sf::Vector2f(i * _tileSet._tileWidth, j * _tileSet._tileHeight);
                quad[1].position = sf::Vector2f((i + 1) * _tileSet._tileWidth, j * _tileSet._tileHeight);
                quad[2].position = sf::Vector2f((i + 1) * _tileSet._tileWidth, (j + 1) * _tileSet._tileHeight);
                quad[3].position = sf::Vector2f(i * _tileSet._tileWidth, (j + 1) * _tileSet._tileHeight);

                // define its 4 texture coordinates
                quad[0].texCoords = sf::Vector2f(tu * _tileSet._tileWidth, tv * _tileSet._tileHeight);
                quad[1].texCoords = sf::Vector2f((tu + 1) * _tileSet._tileWidth, tv * _tileSet._tileHeight);
                quad[2].texCoords = sf::Vector2f((tu + 1) * _tileSet._tileWidth, (tv + 1) * _tileSet._tileHeight);
                quad[3].texCoords = sf::Vector2f(tu * _tileSet._tileWidth, (tv + 1) * _tileSet._tileHeight);

            }
    }

    void Layer::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        // apply the transform
        states.transform *= getTransform();

        // apply the tileset texture
        states.texture = &_tileSet._tileSetTexture;

        // draw the vertex array
        target.draw(_verticies, states);
    }

    //********************************************************************
    //********************************************************************

    TileMap::TileMap(std::string tileMapID, std::string xmlDataFilename) :
        _tileMapID(tileMapID),
        _filename(xmlDataFilename),
        _errorMessage(),
        _tileDataLoaded(false),
        _tilesets(),
        _objectGroup(),
        _pugiDoc()
    {}

    bool TileMap::load_data()
    {

        // Load pugi document into memory
        pugi::xml_parse_result result = _pugiDoc.load_file(_filename.c_str(), 
            pugi::parse_default|pugi::parse_declaration|pugi::parse_cdata);

        // Set bool for successful load or not
        _tileDataLoaded = (result.description() == "No error") or result;

        // Set error message. If there was not error, this string gets set to "No error"
        _errorMessage = result.description();

        // Now parse the data
        if( _tileDataLoaded )
            parse_data();

        return _tileDataLoaded;

    }

    bool TileMap::is_loaded() const
    {
        return _tileDataLoaded;
    }

    std::string TileMap::get_error() const
    {
        return _errorMessage;
    }

    std::string TileMap::get_ID() const
    {
        return _tileMapID;
    }

    void TileMap::draw_layers(int start, int finish, sf::RenderTarget & target) const
    {
        for(int i = start; i <= finish; ++i)
            target.draw(_layers[i]);
    }

    void TileMap::parse_data()
    {

        // Function variables
        Layer tempLayer;
        TileSet tempTileSet;
        TileMapObject * object;
        int posX, posY;
        unsigned int objectWidth, objectHeight;
        std::string objectID;

        // Get head node for the document tree
        pugi::xml_node root = _pugiDoc.document_element();

        // Iterate through children of root node
        for(pugi::xml_node child : root.children())
        {
            // Check if the node is a tileset, there should be only one of these.
            // If there are more than one, new tilesets will be created, but only
            // the first tileset is used to draw the layers. I hope to fix this
            // in the future.
            if(std::string(child.name()) == "tileset")
            {
                // Get firstGid
                tempTileSet._firstGid = std::atoi(child.attribute("firstgid").value());

                // Get tileWidth
                tempTileSet._tileWidth = std::atoi(child.attribute("tilewidth").value());

                // Get tileheight
                tempTileSet._tileHeight = std::atoi(child.attribute("tileheight").value());

                // Get tileCount
                tempTileSet._tileCount = std::atoi(child.attribute("tilecount").value());

                // Get num columns
                tempTileSet._columns = std::atoi(child.attribute("columns").value());

                // Get tileSetID
                tempTileSet._tileSetID = std::string(child.attribute("name").value());

                // Get image source for the tileSet
                tempTileSet._imageSource = "Resources/" + std::string(child.child("image").attribute("source").value());

                // Get image width and height
                tempTileSet._imageWidth = std::atoi(child.child("image").attribute("width").value());
                tempTileSet._imageHeight = std::atoi(child.child("image").attribute("height").value());

                tempTileSet._tileSetTexture.loadFromFile(tempTileSet._imageSource);
                
                // And finally, add this tempTileSet to the tileSetVector
                _tilesets.push_back(tempTileSet);
            }
            else if(std::string(child.name()) == "layer")
            {
                // Get the name of this layer
                tempLayer.set_name(std::string(child.attribute("name").value()));

                // Set the dimensions of the layer
                tempLayer.set_width(std::atoi(child.attribute("width").value()));
                tempLayer.set_height(std::atoi(child.attribute("height").value()));

                // Set the layer's tileset
                tempLayer.set_tileset(_tilesets[0]);

                // Get the gid codes and stitch the layer
                tempLayer.parse_raw_layer_data(std::string(child.child("data").child_value()));

                // Add layer to the layer vector
                _layers.push_back(tempLayer);

                // Reset the temp layer's gid codes
                tempLayer._gidCodes.clear();
            }
            else if(std::string(child.name()) == "objectgroup")
            {
                // TODO: Define an EntityGroup class that will replace
                // the entity manager class. Then create a map or vector
                // of these groups for each of the types of collision.
                // THIS PORTION OF THE CODE DOES NOT WORK AS INTENDED!!!!
                // DO THE TODO ABOVE!!!!
                pugi::xml_node objectNode = child.child("object");

                // Iterate through the children of the object group
                // We will specify specific types as follows:
                // Collision-rect for objects that are rectangles
                // Collision-ellipse for objects that are circles
                // Collision-polygon for objects defined by polygons
                if( std::string(child.attribute("name").value()) == "Collision-rect")
                {
                    // Get the ID of the object
                    objectID = std::string(objectNode.attribute("id").value());

                    // Get the X and Y position
                    posX = std::atoi(objectNode.attribute("x").value());
                    posY = std::atoi(objectNode.attribute("y").value());

                    // Get width and height
                    objectWidth = std::atoi(objectNode.attribute("width").value());
                    objectHeight = std::atoi(objectNode.attribute("height").value());

                    // Create new entity with these values
                    object = new TileMapObject(posX, posY, objectWidth, objectHeight);

                    // Add this entity to the tilemap's entitymanager
                    _objectGroup.add_entity("Rect: " + objectID, object);

                    // Remove local pointer
                    object = NULL;
                }
            }
        }

    }


}//namspeace CRE
