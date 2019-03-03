# pragma once
# include <Siv3D.hpp>
# include "Demo.hpp"
# include "DemoScene.hpp"
# include "WindowSetting.hpp"

void Demo::init() {

	// ウィンドウ設定変更
	if (!Window::SetFullscreen(true, windowSize)) {
		System::Exit();
	}

	// シーン遷移マネージャーの設定
	m_manager.get()->changeBaseScene = [&](String state) {changeScene(state); };
	m_manager.get()->apps = m_data->apps;
	m_manager.get()->appsNum = m_data->apps.size();
	m_manager.get()->playingID = Random<unsigned int>(m_manager.get()->appsNum - 1);
	m_manager.init(m_manager.get()->playingID);

	for (int32 i = 0; i < (int32)m_data->apps.size(); i++) {
		m_manager.add<DemoScene>(i);
	}

	Cursor::SetStyle(CursorStyle::None);

}

void Demo::updateLauncher() {
	m_manager.update();
}

void Demo::draw() const {
	m_manager.draw();
}