# pragma once
# include <Siv3D.hpp>
# include "Select.hpp"

Select::Select() {

}

void Select::updateLauncher() {

	if (Input::MouseL.clicked) {
		changeScene(L"Detail");
	}

}

void Select::draw() const {

	FontAsset(L"nomal")(m_data->apps[0].name).draw(20, 20);
	m_data->apps[0].appData.screenshot.resize(300, 300).draw(20, 60);

}