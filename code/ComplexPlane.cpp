#include "ComplexPlane.h"

ComplexPlane::ComplexPlane(int pixelWidth, int pixelHeight)
{
    m_pixel_size = {pixelWidth, pixelHeight};
    m_aspectRatio = static_cast<float>(pixelHeight) / pixelWidth;
    m_plane_center = {0, 0};
    m_plane_size = {BASE_WIDTH, BASE_HEIGHT * m_aspectRatio};
    m_zoomCount = 0;
    m_state = State::CALCULATING;
    m_vArray.setPrimitiveType(sf::Points);
    m_vArray.resize(pixelWidth * pixelHeight);
}

void ComplexPlane::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(m_vArray, states);
}

void ComplexPlane::updateRender()
{
    if (m_state == State::CALCULATING)
    {
        for (int i = 0; i < m_pixel_size.y; i++)
        {
            for (int j = 0; j < m_pixel_size.x; j++)
            {
                m_vArray[j + i * m_pixel_size.x].position = {(float)j, (float)i};
                sf::Vector2f coord = mapPixelToCoords({j, i});
                size_t numberOfIterations = countIterations(coord);
                sf::Uint8 r, g, b;
                iterationsToRGB(numberOfIterations, r, g, b);
                m_vArray[j + i * m_pixel_size.x].color = {r, g, b};
            }
        }
    }
    m_state = State::DISPLAYING;
}

void ComplexPlane::zoomIn()
{
    m_zoomCount++;
    m_plane_size = {
        BASE_WIDTH * std::pow(BASE_ZOOM, m_zoomCount),
        BASE_HEIGHT * m_aspectRatio * std::pow(BASE_ZOOM, m_zoomCount)};
    m_state = State::CALCULATING;
}

void ComplexPlane::zoomOut()
{
    m_zoomCount--;
    m_plane_size = {
        BASE_WIDTH * std::pow(BASE_ZOOM, m_zoomCount),
        BASE_HEIGHT * m_aspectRatio * std::pow(BASE_ZOOM, m_zoomCount)};
    m_state = State::CALCULATING;
}

void ComplexPlane::setCenter(sf::Vector2i mousePixel)
{
    m_plane_center = mapPixelToCoords(mousePixel);
    m_state = State::CALCULATING;
}

void ComplexPlane::setMouseLocation(sf::Vector2i mousePixel)
{
    m_mouseLocation = mapPixelToCoords(mousePixel);
}

void ComplexPlane::loadText(sf::Text &text)
{
    std::stringstream ss;
    ss << "Mandelbrot Set\n";
    ss << "Center Coords: (" << m_plane_center.x << ", " << m_plane_center.y << ")\n";
    ss << "Cursor Coords: (" << m_mouseLocation.x << ", " << m_mouseLocation.y << ")\n";
    ss << "Left-click to Zoom in\n";
    ss << "Right-click to Zoom out\n";

    text.setString(ss.str());
}

size_t ComplexPlane::countIterations(sf::Vector2f coord)
{
    std::complex<double> c(coord.x, coord.y);
    std::complex<double> z(0, 0);
    int i = 0;
    while (std::abs(z) < 2.0 && i < 64)
    {
        z = z * z + c;
        i++;
    }
    return i;
}

void ComplexPlane::iterationsToRGB(size_t count, sf::Uint8 &r, sf::Uint8 &g, sf::Uint8 &b)
{
    {
        if (count == 64)
            r = 0, g = 0, b = 0;
        else if (count > 50)
            r = 50, g = 50, b = 50;
        else if (count > 40)
            r = 100, g = 100, b = 100;
        else if (count > 30)
            r = 150, g = 150, b = 150;
        else if (count > 20)
            r = 200, g = 200, b = 200;
        else if (count > 10)
            r = 250, g = 250, b = 250;
        else
            r = 255, g = 255, b = 255;
    }
}

Vector2f ComplexPlane::mapPixelToCoords(Vector2i mousePixel)
{
    float xCoord = ((mousePixel.x - 0) / float(m_pixel_size.x - 0)) * m_plane_size.x + (m_plane_center.x - m_plane_size.x / 2.0);
    float yCoord = ((mousePixel.y - m_pixel_size.y) / float(0 - m_pixel_size.y)) * m_plane_size.y + (m_plane_center.y - m_plane_size.y / 2.0);
    Vector2f coords(xCoord, yCoord);
    return coords;
}