# pragma once
# include <Siv3D.hpp>
# include "DemoScene.hpp"
# include "WindowSetting.hpp"

void DemoScene::init() {

	m_id = m_data->playingID;
	
	m_isVideo = m_data->apps[m_id].isMovieExist;

	// 付箋位置計算
	m_tagPos.x = int32(Window::Size().x -  (m_tagSize.x *  double(monitorSize.x) / double(windowSize.x) * Cos(20_deg)) + 20);

	// 動画なら再生開始、スクリーンショットなら時間計測開始
	if (m_isVideo) {
		m_data->apps[m_id].appData.demo.play();
	}
	else {
		m_stopwatch.start();
	}

}

void DemoScene::update() {
	
	// マウス操作で選択画面に戻る
	if (Mouse::Delta() != Point::Zero) {
		if (m_isVideo) {
			m_data->apps[m_id].appData.demo.stop();
		}

		Window::Resize(windowSize);
		Window::SetPos(windowPos);
		Window::SetStyle(WindowStyle::Fixed);

		Cursor::SetStyle(CursorStyle::Default);

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

	// 付箋の拡大と回転
	Mat3x2 mat(Mat3x2::Scale(double(monitorSize.x) / double(windowSize.x), m_tagPos).rotate(Radians(20), m_tagPos));

	{
		const Transformer2D transformer(mat, true);
		Tag(m_tagPos, m_tagSize, m_data->apps[m_id].name, Palette::Aliceblue).draw();
	}

}