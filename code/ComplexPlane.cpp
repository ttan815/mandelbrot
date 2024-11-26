#include "ComplexPlane.h"

ComplexPlane::ComplexPlane(int pixelWidth, int pixelHeight) {
	m_pixel_size = pixelWidth * pixelHeight;
	m_aspectRatio = static_cast<float>(pixelHeight) / pixelWidth;
	m_plane_center = { 0,0 };
	m_plane_size = { BASE_WIDTH, BASE_HEIGHT * m_aspectRatio };
	m_zoomCount = 0;
	m_state = State::CALCULATING;
	m_vArray.setPrimitiveType(sf::Points);
	m_vArray.resize(m_pixel_size);
}
void ComplexPlane::draw(RenderTarget& target, RenderStates states) const {
	target.draw(m_vArray);
}
void ComplexPlane::updateRender(){
	if (m_State == CALCULATING) {
		for (int i = 0; i < m_pixel_size.y; i++) {
			for (int j = 0; j < m_pixel_size.x; j++) {
				vArray[j + i * pixelWidth].position = { (float)j,(float)i };
				Vector2f coord = mapPixelToCoords(Vector2i(j, i));
				size_t numberOfIterations = countIterations(coord);
				Uint8 r, g, b;
				iterationsToRGB(numberOfIterations, r, g, b);
				vArray[j + i * pixelWidth].color = { r,g,b };
				
			}
		}
	}
	m_state = State::DISPLAYING;
}
void ComplexPlane::zoomIn(){
	m_zoomCount++;
	float x = BASE_WIDTH * (pow(BASE_ZOOM, m_zoomCount));
	float y = BASE_HEIGHT * m_aspectRatio * (pow(BASE_ZOOM, m_zoomCount));
	m_plane_size = { x,y };
	m_state = State::CALCULATING;
}
void ComplexPlane::zoomOut(){
	m_zoomCount--;
	float x = BASE_WIDTH * (pow(BASE_ZOOM, m_zoomCount));
	float y = BASE_HEIGHT * m_aspectRatio * (pow(BASE_ZOOM, m_zoomCount));
	m_plane_size = { x,y };
	m_state = State::CALCULATING;
}
void ComplexPlane::setCenter(Vector2i mousePixel){
	Vector2f coord = mapPixelToCoords(Vector2i(mousePixel.x, mousePixel.y));
	m_plane_center = coord;
	m_state = State::CALCULATING;
}
void ComplexPlane::setMouseLocation(Vector2i mousPixel){
	Vector2f coord = mapPixelToCoords(Vector2i(mousPixel.x, mousPixel.y));
	m_mouseLocation = coord;
}
// Functions above created by Tony
void ComplexPlane::loadText(Text& text){
	void ComplexPlane::loadText(sf::Text & text) {
		std::stringstream ss;
		ss << "Mandelbrot Set\n";
		ss << "Center Coords: ("
			<< m_plane_center.x << ", "
			<< m_plane_center.y << ")\n";
		ss << "Cursor Coords: ("
			<< m_mouseLocation.x << ", "
			<< m_mouseLocation.y << ")\n";

		ss << "Left-click to Zoom in\n";
		ss << "Right-click to Zoom out\n";

		text.setString(ss.str());
	}
}
size_t ComplexPlane::countIterations(Vector2f coord){}
void ComplexPlane::iterationsToRGB(size_t count, Uint8& r, Uint8& g, Uint8& b){}
Vector2f ComplexPlane::mapPixelToCoords(Vector2i mousePixel){}