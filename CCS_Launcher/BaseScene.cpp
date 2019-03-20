# pragma once
# include <Siv3D.hpp>
# include <Windows.h>
# include "Scene.hpp"

# define NOMINMAX

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
	else if (m_data->handle) {
		if (m_data->handle == 0 || WaitForSingleObject(m_data->handle, 0) == WAIT_OBJECT_0) {
			CloseHandle(m_data->handle); // 使用のおわったハンドルはクローズ
			m_data->handle = 0;
			Window::Restore();
		}
		else {
			Window::Minimize();
		}
	}
	else {
		updateLauncher();
	}

}

