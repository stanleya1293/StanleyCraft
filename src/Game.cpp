#include "Game.h"

#ifdef _WIN32
//const std::string SOURCE_PATH = "C:/Users/Arden Stanley/Desktop/stanleya1293/StanleyCraft";
const std::string SOURCE_PATH = "C:/Users/Arden/source/repos/stanleya1293/StanleyCraft";
#endif

void Game::initialize() {
	Window::initialize(1000, 800, "test");

	Shader shader = Shader(SOURCE_PATH + "/shaders/default.vertex", SOURCE_PATH + "/shaders/default.fragment");
	Camera camera = Camera(glm::vec3(0.0f, 0.0f, 3.0f), Window::getAspectRatio());

	Renderer::initialize(camera, shader);

	Block block = Block("", glm::vec3(0.0f, 0.0f, 0.0f));
	Renderer::addBlock(block);

	InputHandler::initialize();
}

void Game::run() {
	while (Window::isOpen()) {
		Renderer::update();
		InputHandler::processInput();
		Window::update();
	}
}