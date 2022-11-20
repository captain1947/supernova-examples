#include <iostream>
#include <unordered_map>

#include "../supernova/engine.h"


using namespace std;



int main(int argc, char* argv[]) {

	const int SCREENW = 800, SCREENH = 600;
	unordered_map<string, EventKey> EVENT_KEYS= {};

	Window window("Fog of War", SCREENW, SCREENH);
	Renderer renderer(window);

	Texture bg_img(renderer, "image.png");
	Texture fow_tex(renderer, Vector{800, 600});

	Clock clock;
	Events events;
	Mouse mouse = Mouse();

	bool running;
	double dt;

	renderer.clear({0, 0, 0});
	bg_img.render(bg_img.get_rect());

	while (running) {
		dt = clock.tick(60);

		events.process_events(running, EVENT_KEYS, mouse);

		renderer.set_target(fow_tex);
		renderer.clear({0, 0, 0});
		renderer.draw_circle({400, 300}, 200, {255, 255, 255, 255});
		renderer.present();
		renderer.set_target();
		renderer.present();
	}

	fow_tex.destroy();
	bg_img.destroy();
	renderer.destroy();
	window.destroy();

    return 0;
}