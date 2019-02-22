# pragma once
# include <Siv3D.hpp>
# include "Detail.hpp"

void Detail::updateLauncher() {

	if (Input::MouseL.clicked) {
		changeScene(L"Select");
	}

	if (Input::MouseR.clicked) {
		m_data->process = System::CreateProcess(m_data->apps[m_data->selectedID].appData.executePath);
	}

}

void Detail::draw() const{

	m_data->apps[m_data->selectedID].appData.screenshot.resize(Window::Size()).draw(0, 0);

}