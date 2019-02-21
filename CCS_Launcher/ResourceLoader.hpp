# pragma once
# include <Siv3D.hpp>

class ResourceLoader {
private:

	void loadFonts();

	void loadTextures();

public:
	ResourceLoader();

	void load();

};