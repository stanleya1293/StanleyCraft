#include "Game.h"

#ifdef _WIN32
const std::string SOURCE_PATH = "C:/Users/Arden Stanley/Desktop/stanleya1293/StanleyCraft";
//const std::string SOURCE_PATH = "C:/Users/Arden/source/repos/stanleya1293/StanleyCraft";
#endif

Game::Game() : m_window(nullptr), m_renderer(nullptr) {
	m_window = std::make_unique<Window>(1000, 800, "test");

	Shader shader = Shader (SOURCE_PATH + "/shaders/default.vertex", SOURCE_PATH + "/shaders/default.fragment");
	Camera *camera = new Camera(glm::vec3(0.0f, 0.0f, 3.0f), m_window->getAspectRatio());

	m_renderer = std::make_unique<Renderer>(shader, camera);


	m_window->addKeyCallback(Keys::A, [=]() { camera->move(Camera::Left); });
	m_window->addKeyCallback(Keys::W, [=]() { camera->move(Camera::Forward); });
	m_window->addKeyCallback(Keys::D, [=]() { camera->move(Camera::Right); });
	m_window->addKeyCallback(Keys::S, [=]() { camera->move(Camera::Backward); });
}

void Game::run() {
	while (m_window->isOpen()) {
		m_renderer->update();
		m_window->update();
	}
}