# pragma once
# include <Siv3D.hpp>
# include "Scene.hpp"

bool CheckWindowState(Optional<ProcessInfo> process) {

	// 起動中のアプリケーションがあれば最小化、終了したら最小化解除
	if (process) {
		if (process->isRunning()) {
			Window::Minimize();
		}
		else {
			Window::Restore();
			process = none;
		}
		return false;
	}

	return true;

}

void BaseScene::update() {

	// 起動中のアプリの状態をチェックしてから情報更新
	if (CheckWindowState(m_data->process)) {
		updateLauncher();
	}

}

