# pragma once
# include <Siv3D.hpp>
# include "Detail.hpp"

Detail::Detail() {

}

void Detail::updateLauncher() {

	if (Input::MouseL.clicked) {
		changeScene(L"Select");
	}

}

void Detail::draw() const{

	m_data->apps[0].appData.screenshot.resize(1000,600).draw(0, 0);

}