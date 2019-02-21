# pragma once
# include <Siv3D.hpp>
# include "Scene.hpp"

void BaseScene::update() {

	// 起動中のアプリケーションがあれば最小化、終了したら最小化解除
	// 起動中のアプリがなければ情報更新
	if (m_data->process) {
		if (m_data->process->isRunning()) {
			Window::Minimize();
		}
		else {
			Window::Restore();
			m_data->process = none;
		}
	}
	else {
		updateLauncher();
	}

}

