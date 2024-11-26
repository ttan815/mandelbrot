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

//Define the class headings for ComplexPlane - Tony
class ComplexPlane
{
private:
    VertexArray m_vArray;
    State m_state;
    Vector2f m_mouseLocation;
    Vector2i m_pixel_size;
    Vector2f m_plane_center;
    Vector2f m_plane_size;
    int m_zoomCount;
    float m_aspectRatio;
    size_t countIterations(Vector2f);
    void iterationsToRGB(size_t count, Uint8&, Uint8&, Uint8&);
    Vector2f mapPixelToCoords(Vector2i);
public:
    ComplexPlane(int, int);
    void draw(RenderTarget&, RenderStates) const;
    void updateRender();
    void zoomIn();
    void zoomOut();
    void setCenter(Vector2i);
    void setMouseLocation(Vector2i);
    void loadText(Text& text);
};


#endif