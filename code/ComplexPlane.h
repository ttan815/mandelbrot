#ifndef ComplexPlane_H
#define ComplexPlane_H

#include <iostream>
// Include important C++ libraries here - Tony
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <complex>

const unsigned int MAX_ITER = 64;
const float BASE_WIDTH = 4.0;
const float BASE_HEIGHT = 4.0;
const float BASE_ZOOM = 0.5;

// Declare header for class State Enum With Variables CALCULATING and DISPLAYING - Tony
enum class State
{
    CALCULATING,
    DISPLAYING,
};

// Define the class headings for ComplexPlane - Tony
class ComplexPlane
{
private:
    sf::VertexArray m_vArray;
    State m_state;
    sf::Vector2f m_mouseLocation;
    sf::Vector2i m_pixel_size;    
    sf::Vector2f m_plane_center; 
    sf::Vector2f m_plane_size;    
    int m_zoomCount;
    float m_aspectRatio;

    size_t countIterations(sf::Vector2f); 
    void iterationsToRGB(size_t count, sf::Uint8& red, sf::Uint8& green, sf::Uint8& blue);
    sf::Vector2f mapPixelToCoords(sf::Vector2i); 

public:
    ComplexPlane(int, int);
    void draw(sf::RenderTarget&, sf::RenderStates) const; 
    void updateRender();
    void zoomIn();
    void zoomOut();
    void setCenter(sf::Vector2i); 
    void setMouseLocation(sf::Vector2i); 
    void loadText(sf::Text& text); 
};

#endif
