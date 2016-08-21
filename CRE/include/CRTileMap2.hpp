/**
* This is a redisign of the first draft of the TileMap class.
* @author Jake Shepherd
*/

#ifndef CRTILEMAP2_HPP
#define CRTILEMAP2_HPP

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <iostream> //TODO: delete this eventually
#include <string>
#include <cstdlib>
#include <vector>
#include <sstream>
#include "CRTypes.hpp"
#include "CREntity2.hpp"
#include "CREntityManager.hpp"
#include "CRGroup.hpp"
#include "pugixml.hpp"

namespace CRE
{

    class TileMapObject
    {
        public:

            TileMapObject(int positionX, int positionY, unsigned int width, unsigned int height)

            {}

            virtual void process_events(){}

            virtual void init(){}

            virtual void cleanup(){}

            virtual void update(float appTime){}

            virtual void draw(){}
    };

    class TileSet
    {
        public:
            /// Let's explain the variables:
            /// _firstGid --> The ... TODO: do this explaination
            unsigned int _firstGid, _tileWidth, _tileHeight, _tileCount,
            _columns, _imageWidth, _imageHeight;

            std::string _imageSource, _tileSetID;

            sf::Texture _tileSetTexture;
    };

    class Layer : public sf::Drawable, public sf::Transformable
    {
        public:

            Layer();

            /**
            * Takes in the string of the gid codes from the Tiled xml data.
            * This function is specifically designed to parse this data from
            * the Tiled xml data and shouldn't be used for other data formats.
            */
            void parse_raw_layer_data(std::string rawData);

            /**
            * Returns the width and height of this layer in number of tiles.
            */
            int get_width() const;
            int get_height() const;
            std::string get_name() const;

            void set_width(int newWidth);
            void set_height(int newHeight);
            void set_tileset(TileSet newTileSet);
            void set_name(std::string newName);

            /// The vector that stores the gid codes
            std::vector<int> _gidCodes;
        private:

            /**
            * Overloaded draw function allows for this class object to be drawn
            * by simply calling window.draw(layerName);
            * This function is private because it should be only called by the
            * the render window class.
            */
            virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

            void stitch_layer();

            //TileSet& get_tileset_with_gid(int gid);

            /// The tileset this layer will use
            TileSet _tileSet;

            //std::vector<TileSet> _tileSets;

            /// The magical vertex array that allows us to reference pieces of
            /// the texture we will be loading from
            sf::VertexArray _verticies;

            /// The width and height of this layer in number of tiles
            sf::Vector2i _dimensions;

            std::string _layerName;
    };

    class TileMap
    {
        public:

            TileMap(std::string tileMapID, std::string xmlDataFilename);
            ~TileMap();

            bool load_data();

            /**
            * Returns true if the tilemap was loaded correctly.
            */
            bool is_loaded() const;

            /**
            * Returns the error message. If no error occured during load,
            * the message returned is "No error"
            */
            std::string get_error() const;

            /**
            * Returns the ID of this TileMap.
            */
            std::string get_ID() const;

            /**
            * Returns a reference to a group contained by the tilemap.
            * Uncaught behavior if the groupID is not found.
            */
            Group& get_group(std::string groupID);

            /**
            * Draws the layers starting at layer layerStart and ending with
            * layer layerStart. Example: draw_layers(0, 3, window) will draw the first
            * four layers of the _layers vector.
            */
            void draw_layers(int layerStart, int layerEnd, sf::RenderTarget & target) const;

        private:


            void parse_data();

            std::string _tileMapID;
            std::string _filename;
            std::string _errorMessage;
            bool _tileDataLoaded;

            std::vector<TileSet> _tilesets;
            std::map<std::string, Group> _objects;

            /// Vector stores the layers for this tile map. These layers can
            /// be directly drawn.
            std::vector<Layer> _layers;

            EntityManager _objectGroup;

            /// The XML Document that will be loaded into memory
            pugi::xml_document _pugiDoc;
    };
}//namespace CRE

#endif
