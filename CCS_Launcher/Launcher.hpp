# pragma once
# include <Siv3D.hpp>
# include "Defines.hpp"
# include "InfoLoader.hpp"

class Launcher {
private:

	Array<AppInfo> m_apps;
	InfoLoader m_infoLoader;
	Optional<ProcessInfo> m_process;

	Array<Rect> rects;

public:

	Launcher(const FilePath& path);
	void update();
	void draw() const;
};