#include "ComplexPlane.h"

//Make the code easier to type with "using namespace"
using namespace sf;
using namespace std;

int main()
{
	// Create a video mode object Vanessa
  	VideoMode vm((vm.getDesktopMode().width / 2), (vm.getDesktopMode().height / 2));

	// Create and open a window for the game Vanessa
	RenderWindow window(vm, "MandelBrot", Style::Default);

  	//construct ComplexPlane Vanessa
  	ComplexPlane plane;

  	// create text and font Vanessa
	sf::Font font;
	font.loadFromFile("Roboto-Light.ttf");
	sf::Text text;
	text.setFont(font);
	text.setString("FIX ME");
	text.setCharacterSize(24);
	text.setFillColor(Color::White);
	text.setPosition(0, 0);

	while (window.isOpen())
  	{
		//handle input segment Vanessa
	  	Event event;
	  	while (window.pollEvent(event))
		{
 		    if (event.type == Event::Closed)
  		    {
  			window.close();
  		    }
  		    if (event.type == sf::Event::MouseButtonPressed)
  		    {
      			if (event.mouseButton.button == sf::Mouse::Left)
      			{
	              
	                }
	            	if (event.mouseButton.button == sf::Mouse::Right)
		    	{
	                	plane.zoomOut();
	                	plane.setCenter(
	            	}
		    }
		}

		if (Keyboard::isKeyPressed(Keyboard::Escape))
	  	{
			window.close();
 	  	}
	      		
	  }

	
	  		
