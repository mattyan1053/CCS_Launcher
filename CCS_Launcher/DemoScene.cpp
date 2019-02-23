# pragma once
# include <Siv3D.hpp>
# include "DemoScene.hpp"
# include "WindowSetting.hpp"

void DemoScene::init() {

	m_id = m_data->playingID;
	
	m_isVideo = m_data->apps[m_id].isMovieExist;

	// 動画なら再生開始、スクリーンショットなら時間計測開始
	if (m_isVideo) {
		m_data->apps[m_id].appData.demo.play();
	}
	else {
		m_stopwatch.start();
	}

}

void DemoScene::update() {
	
	// 左クリックで選択画面に戻る
	if (Input::MouseL.clicked) {
		if (m_isVideo) {
			m_data->apps[m_id].appData.demo.stop();
		}
		if (!Window::SetFullscreen(false, windowSize)) {
			System::Exit();
		}
		Window::SetPos(windowPos);
		m_data->changeBaseScene(L"Select");
	}

	if (m_isVideo) {
		m_data->apps[m_id].appData.demo.update();

		// シーン切り替え
		if (m_data->apps[m_id].appData.demo.getLengthSec() - m_data->apps[m_id].appData.demo.getPosSec() < 1.0) {
			m_data->apps[m_id].appData.demo.stop();
			m_data->playingID = Random<unsigned int>(m_data->appsNum - 1);
			changeScene(m_data->playingID);
		}
	}
	else {
		// シーン切り替え
		if (m_stopwatch.s() > waitTime) {
			m_data->playingID = Random<unsigned int>(m_data->appsNum - 1);
			changeScene(m_data->playingID);
		}
	}

}

void DemoScene::draw() const {

	if (m_isVideo) {
		m_data->apps[m_id].appData.demo.getFrameTexture().resize(Window::Size()).draw();
	}
	else {
		m_data->apps[m_id].appData.screenshot.resize(Window::Size()).draw();
	}

}