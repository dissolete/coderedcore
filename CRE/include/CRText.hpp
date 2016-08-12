/**
* Text wrapper class used by the text manager. This wrapper class simply
* stores the SFML font and text objects used by the SFML library to
* render text to the SFML render window. This wrapper class also stores
* the string identifier for this text.
*/

#ifndef CRTEXT_HPP
#define CRTEXT_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>

namespace CRE
{
	class Text
	{
		public:

			/**
			* Constructor for this wrapper class.
			*/
			Text(const std::string textID, std::string textString, const sf::Font& font,
					unsigned int charSize = 30) :
				_textID(textID),
				_text(textString, font, charSize)

			{}

			/**
			* Returns the string ID for this wrapper class
			*/
			std::string get_ID()
			{
				return _textID;
			}

			// The font used for this text
			sf::Font _textFont;

			// The actual text
			sf::Text _text;

		private:

            // The string identifier for this text
            const std::string _textID;

	};

}

#endif
