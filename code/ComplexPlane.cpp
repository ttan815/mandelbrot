#include "ComplexPlane.h"

ComplexPlane::ComplexPlane(int pixelWidth, int pixelHeight) {}
void ComplexPlane::draw(RenderTarget& target, RenderStates states) const{}
void ComplexPlane::updateRender(){}
void ComplexPlane::zoomIn(){}
void ComplexPlane::zoomOut(){}
void ComplexPlane::setCenter(Vector2i mousePixel){}
void ComplexPlane::setMouseLocation(Vector2i mousPixel){}
void ComplexPlane::loadText(Text& text){}
size_t ComplexPlane::countIterations(Vector2f coord){}
void ComplexPlane::iterationsToRGB(size_t count, Uint8& r, Uint8& g, Uint8& b){}
Vector2f ComplexPlane::mapPixelToCoords(Vector2i mousePixel){}