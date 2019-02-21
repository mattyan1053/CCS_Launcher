# pragma once
# include <Siv3D.hpp>
# include "Launcher.hpp"

Launcher::Launcher(const FilePath& path) : m_infoLoader(path) {

	// シーン遷移マネージャーセットアップ
	m_manager.get()->apps = m_infoLoader.load();
	m_manager.get()->process = none;
	m_manager.get()->selectedID = 0U;

	m_manager.add<Select>(L"Select");
	m_manager.add<Detail>(L"Detail");

}

void Launcher::start() {

	while (System::Update()) {
		m_manager.updateAndDraw();
	}

}