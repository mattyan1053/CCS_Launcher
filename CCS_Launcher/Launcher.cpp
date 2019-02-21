# pragma once
# include <Siv3D.hpp>
# include "Launcher.hpp"

Launcher::Launcher(const FilePath& path) : m_infoLoader(path) {
	// ディレクトリの状態のロード
	m_apps = m_infoLoader.Load();

	for (int i = 0; i < m_apps.size(); i++) {
		rects.emplace_back(i * 60, 60, 59);
	}

}

void Launcher::update() {

	if (m_process) {
		if (m_process->isRunning()) {
			Window::Minimize();
		}
		else {
			Window::Restore();
			m_process = none;
		}
	}
	else {
		for (int i = 0; i < rects.size(); i++) {
			if (rects[i].leftClicked) {
				m_process = System::CreateProcess(m_apps[i].appData.executePath);
			}
		}
	}

}

void Launcher::draw() const {

	for (const auto& rect : rects) {
		rect.draw();
	}

}