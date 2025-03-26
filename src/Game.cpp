#include "Game.h"

#ifdef _WIN32
const std::string SOURCE_PATH = "C:/Users/Arden Stanley/Desktop/stanleya1293/StanleyCraft";
//const std::string SOURCE_PATH = "C:/Users/Arden/source/repos/stanleya1293/StanleyCraft";
#endif

Game::Game() 
{
	m_window = Window(1000, 800, "test");

	Shader shader = Shader(SOURCE_PATH + "/shaders/default.vertex", SOURCE_PATH + "/shaders/default.fragment");
	Camera camera = Camera(glm::vec3(0.0f, 0.0f, 3.0f), m_window);

	m_renderer = Renderer(camera, shader);

	Block block = Block("", glm::vec3(0.0f, 0.0f, 0.0f));
}

const void Game::run()
{
	Renderer::addBlock(block);

	while (Window::isOpen()) {
		Renderer::update();
		Window::update();
	}
}